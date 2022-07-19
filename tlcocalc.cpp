#include "tlcocalc.h"
#include "ui_tlcocalc.h"

#include "physiology.h"

#include <QMessageBox>

extern Physiology physiology;

tlcocalc::tlcocalc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tlcocalc)
{
    ui->setupUi(this);
}

tlcocalc::~tlcocalc()
{
    delete ui;
}

void tlcocalc::on_calculateButton_clicked()
{
    double hb, hct, predTLco, measTLco;
    double cotes, dina, marr, moh;
    bool ok, predTLCOok = false, measTLCOok = false, hBok = false, hctok = false;

    hb = ui->hbLine->text().toDouble(&ok);
    if(ok) hBok = physiology.validate("Haemoglobin", hb);

    hct = ui->hctLine->text().toDouble(&ok);
    if(ok) hctok = physiology.validate("Haematocrit", hct);

    predTLco = ui->predtlcoLine->text().toDouble(&ok);
    if(ok) predTLCOok = physiology.validate("TLco", predTLco);

    measTLco = ui->meastlcoLine->text().toDouble(&ok);
    if(ok) measTLCOok = physiology.validate("TLco", measTLco);

    if(predTLCOok && measTLCOok) {
        if(hBok) {
            // https://www.pftforum.com/blog/correcting-dlco-for-hemoglobin/
            // 0.46872 in Marrades formula as 1.4 x 0.3348 (ml / min mmHg to mmol / min kPa)
            cotes = predTLco * ((1.7 * hb) / ((ui->maleRadio->isChecked() ? 10.22 : 9.38) + hb));
            dina = measTLco * (1.0 / (0.06965 * hb));
            marr = measTLco + 0.46872 * ((ui->maleRadio->isChecked() ? 14.6 : 13.4) - hb);

            ui->cotespredLabel->setNum(cotes);
            ui->dinapredLabel->setNum(dina);
            ui->marrpredLabel->setNum(marr);

            ui->cotespercentLabel->setNum(100 * measTLco / cotes);
            ui->dinapercentLabel->setNum(100 * dina / predTLco);
            ui->marrpercentLabel->setNum(100 * marr / predTLco);
        }
        else {
            ui->cotespredLabel->setText("-");
            ui->dinapredLabel->setText("-");
            ui->marrpredLabel->setText("-");

            ui->cotespercentLabel->setText("-");
            ui->dinapercentLabel->setText("-");
            ui->marrpercentLabel->setText("-");
        }

        if(hctok) {
            moh = 1.35 * (44 - hct);
            ui->mohpercentLabel->setNum(moh + 100 * measTLco / predTLco);
        }
        else ui->mohpercentLabel->setText("-");
    }
    else {
        QMessageBox msg(this);

        ui->cotespredLabel->setText("-");
        ui->dinapredLabel->setText("-");
        ui->marrpredLabel->setText("-");

        ui->cotespercentLabel->setText("-");
        ui->dinapercentLabel->setText("-");
        ui->marrpercentLabel->setText("-");
        ui->mohpercentLabel->setText("-");

        msg.setWindowTitle("Insufficient or invalid information");
        msg.setText("Check TLco and haemoglobin values are present. Hb should be in g/dL and TLco in mmol / min kPa.");
        msg.setIcon(QMessageBox::Warning);
        msg.exec();
    }
}

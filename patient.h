#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QDate>

class Patient
{
public:
    Patient();
    Patient(QString r);

    static bool validate_rxr(QString r);
    static bool validate_nhs(QString n);
    static QString clean_rxr(QString r);
    static QString clean_nhs(QString n);

private:
    bool valid;         // Valid patient - has minimum of RXR
    int db_id;          // Database table id
    QString RXR;        // RXR number
    QString NHS;        // NHS number
    QString fname;      // First name
    QString sname;      // Surname
    QDate dob;          // Date of birth
};

#endif // PATIENT_H

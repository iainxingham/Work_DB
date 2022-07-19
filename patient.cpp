#include "patient.h"

#include <QRegularExpression>

Patient::Patient()
{
    valid = false;
}

Patient::Patient(QString r)
{
    QString r1 = clean_rxr(r);

    if(validate_rxr(r1)) {
        RXR = r1;
        valid = true;
    }
    else valid = false;
}

bool Patient::validate_rxr(QString r)
{
    static QRegularExpression re("^rxr\\s*\\d\\d\\d\\d\\d\\d\\d$", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch m = re.match(r.trimmed().toUpper(), 0);
    return m.hasMatch();
}

bool Patient::validate_nhs(QString n)
{
    static QRegularExpression re("^\\d\\d\\d\\s*\\d\\d\\d\\s*\\d\\d\\d\\d$");

    QRegularExpressionMatch m = re.match(n.trimmed(), 0);
    return m.hasMatch();
}

QString Patient::clean_rxr(QString r)
{
    return r.trimmed().toUpper();
}

QString Patient::clean_nhs(QString n)
{
    return n.trimmed();
}

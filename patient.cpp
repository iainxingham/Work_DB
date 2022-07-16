#include "patient.h"

#include <QRegularExpression>

Patient::Patient()
{
    valid = false;
}

Patient::Patient(QString r)
{
    QString r1 = r.trimmed().toUpper();

    if(validate_rxr(r1)) {
        RXR = r1;
        valid = true;
    }
    else valid = false;
}

bool Patient::validate_rxr(QString r)
{
    static QRegularExpression re("rxr\\d\\d\\d\\d\\d\\d\\d", QRegularExpression::CaseInsensitiveOption);

    QRegularExpressionMatch m = re.match(r, 0);
    return m.hasMatch();
}

bool Patient::validate_nhs(QString n)
{
    static QRegularExpression re("\\d\\d\\d\\s*\\d\\d\\d\\s*\\d\\d\\d\\d");

    QRegularExpressionMatch m = re.match(n, 0);
    return m.hasMatch();
}

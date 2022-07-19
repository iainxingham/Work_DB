#ifndef PHYSIOLOGY_H
#define PHYSIOLOGY_H

// A class to maintain "reasonable" values of various physiological quantities

#include <QMap>
#include <QString>

struct MinMax
{
    double min;
    double max;
};

class Physiology
{
public:
    Physiology();

    void setlimit(QString s, double min, double max);
    bool validate(QString s, double val);

private:
    QMap<QString, MinMax> limits;
};

#endif // PHYSIOLOGY_H

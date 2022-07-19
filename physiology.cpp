#include "physiology.h"

Physiology::Physiology()
{

}

void Physiology::setlimit(QString s, double min, double max)
{
    MinMax m;

    m.min = min;
    m.max = max;
    limits.insert(s, m);
}

bool Physiology::validate(QString s, double val)
{
    if(!limits.contains(s)) return false;
    if(val < limits[s].min) return false;
    if(val > limits[s].max) return false;

    return true;
}

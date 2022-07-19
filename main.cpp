#include "home.h"
#include "physiology.h"

#include <QApplication>

#define _MAIN_CPP_
Physiology physiology;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Replace in future with load from database
    physiology.setlimit("TLco", 2.0, 200.0);
    physiology.setlimit("Haemoglobin", 2.0, 25.0);
    physiology.setlimit("Haematocrit", 5.0, 95.0);

    Home w;
    w.show();
    return a.exec();
}

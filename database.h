#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>

class Database
{
public:
    Database();
    Database(QString file);
    ~Database();

    bool isOpen() {return active_connection;}

private:
    QSqlDatabase conn;
    bool active_connection;
};

#endif // DATABASE_H

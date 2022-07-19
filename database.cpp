#include "database.h"

Database::Database()
{
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName("temp.db");
    active_connection = conn.open();
}

Database::Database(QString file)
{
    conn = QSqlDatabase::addDatabase("QSQLITE");
    conn.setDatabaseName(file);
    active_connection = conn.open();
}

Database::~Database()
{
    conn.close();
}

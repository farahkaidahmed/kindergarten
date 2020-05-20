#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql>
#include <QSqlDatabase>
#include <QDebug>

class connection
{
private:
    QSqlDatabase db;
public:
    connection();
    ~connection();
};

#endif // CONNECTION_H

#ifndef NOTIFICATION_H
#define NOTIFICATION_H
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSystemTrayIcon>

class notification
{
private:
    int id;
public:
    notification();
    void Alerte_Ajout();

};
#endif // NOTIFICATION_H

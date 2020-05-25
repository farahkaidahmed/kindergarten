#include "notification.h"

notification::notification()
{

}
void notification::Alerte_Ajout()
{

    //QString res= QString::number(id);
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

  notifyIcon->setIcon(QIcon("notification.jpg"));

    notifyIcon->show();
    notifyIcon->showMessage("Classe","On peut pas ajouter cette Classe",QSystemTrayIcon::Warning,1500);
}


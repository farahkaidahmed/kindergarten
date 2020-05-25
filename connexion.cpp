#include "connexion.h"

Connexion::Connexion()
{}

bool Connexion::ouvrirConnexion()
{bool test=false;

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_projet2A");
    db.setUserName("amina");//inserer nom de l'utilisateur
    db.setPassword("aminake");//inserer mot de passe de cet utilisateur

    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setDatabaseName("amina");
        db.setHostName("127.0.0.1");
        db.setUserName("root");//inserer nom de l'utilisateur
        db.setPassword("");//inserer mot de passe de cet utilisateur
        db.setPort(3306);*/
if (db.open())
    test=true;
return  test;
}
void Connexion::fermerConnexion()
{db.close();}

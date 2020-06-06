#ifndef CONGE_H
#define CONGE_H
#include "profils.h"
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Conge
{
public:
    Conge();
    Conge(int,int,QString ,QString );

    QString get_dated();
    QString  get_datef();
    int get_idC();
    int get_id();

   bool ajouter();
   bool supprimer(int idd);
   QSqlQueryModel * afficher();
    bool modifier(int ,int, QString , QString );
    QSqlQueryModel * afficher_tri();

    QSqlQueryModel *rechercher(int);


private:
    int id;
    int idC;


     QString dated;
     QString datef;
};

#endif // CONGE_H







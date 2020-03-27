#include "salle.h"
#include <QDebug>
#include "connexion.h"
salle::salle()
{
nom="";
num=0;
max=0;
}
salle::salle(QString nom,int num,int max)
{
  this->nom=nom;
  this->num=num;
  this->max=max;
}
QString salle::get_nom(){return  nom;}
int salle::get_num(){return  num;}
int salle::get_max(){return  max;}

bool salle::ajouter()
{
QSqlQuery query;
QString res= QString::number(num);
query.prepare("INSERT INTO salle (NOM, NUM, MAX) "
                    "VALUES (:nom, :num, :max)");
query.bindValue(":nom", nom);
query.bindValue(":num", res);
query.bindValue(":max", max);

return    query.exec();
}

QSqlQueryModel * salle::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from salle");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Max "));
    return model;
}

bool salle::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from salle where Num = :id ");
query.bindValue(":id", res);
return    query.exec();
}

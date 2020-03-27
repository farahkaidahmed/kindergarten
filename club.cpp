#include "club.h"
#include <QDebug>
#include "connexion.h"
club::club()
{
nom="";
id=0;
prix=0;
num_salle=0;
}
club::club(QString nom,int id,int prix,int num_salle)
{
  this->nom=nom;
  this->id=id;
  this->prix=prix;
  this->num_salle=num_salle;
}
QString club::get_nom(){return  nom;}
int club::get_id(){return  id;}
int club::get_prix(){return  prix;}
int club::get_num_salle(){return  num_salle;}

bool club::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO club (NOM, ID, PRIX, NUM_SALLE) "
                    "VALUES (:nom, :id, :prix, :num_salle)");
query.bindValue(":nom", nom);
query.bindValue(":id", res);
query.bindValue(":prix", prix);
query.bindValue(":num_salle", num_salle);

return    query.exec();
}

QSqlQueryModel * club::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from club");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Num_salle"));
    return model;
}

bool club::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from club where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}


#include "profils.h"
#include <QDebug>
#include "connexion.h"
#include <QString>
#include <QtSql/QSqlQuery>



Profils::Profils()
{
   id=0;
   nom="";
   prenom="";
   salaire=0;
   etat="";

}


Profils::Profils(int id,int salaire,QString nom,QString prenom,QString etat)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->salaire=salaire;
  this->etat=etat;
}
int Profils::get_id(){return  id;}
QString Profils::get_nom(){return  nom;}
QString Profils::get_prenom(){return prenom;}
QString Profils::get_etat(){return  etat;}
int Profils::get_salaire(){return salaire;}



bool Profils::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO profils (ID, NOM, PRENOM, SALAIRE, ETAT) "
                    "VALUES (:id, :nom, :prenom, :salaire, :etat)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":salaire", salaire);
query.bindValue(":etat", etat);

return    query.exec();
}

QSqlQueryModel * Profils::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from profils");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
    return model;
}

bool Profils::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from profils where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

//NOM=:nom,PRENOM=:prenom,

bool Profils::modifier(int id)
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("UPDATE Profils set ID=:id, SALAIRE=:salaire,  ETAT=:etat where ID=:id");
query.bindValue(":id", res);
query.bindValue(":salaire", salaire);
//query.bindValue(":nom", nom);
//query.bindValue(":prenom", prenom);
query.bindValue(":etat", etat);

return    query.exec();
}

QSqlQueryModel * Profils::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Profils order by id");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("etat "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("salire "));



    return model;
}




QSqlQueryModel * Profils ::rechercher(int id){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from profils where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("saliare"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));

    return model;
}

int Profils::stat_moins()
{   int moins =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM Profils ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM Profils WHERE  salaire <2000");
     while(query.next())
                 {
                     moins = moins + 1;

                 }
     return ((moins*100)/total);

}


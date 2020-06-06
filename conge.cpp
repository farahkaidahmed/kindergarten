#include "conge.h"


#include <QDebug>
#include "connexion.h"

Conge::Conge()
{





   idC=0;
   id=0;
   dated="";
   datef="";


}


Conge::Conge(int idC,int id,QString dated,QString datef)
{
  this->idC=idC;
  this->id=id;
  this->dated=dated;
  this->datef=datef;

}
int Conge::get_idC(){return  idC;}
int Conge::get_id(){return  id;}
QString Conge::get_dated(){return  dated;}
QString Conge::get_datef(){return datef;}



bool Conge::ajouter()
{
QSqlQuery query;
QString res= QString::number(idC);
query.prepare("INSERT INTO Conge (IDC,ID,DATED,DATEF) "
                    "VALUES (:idC,:id, :dated, :datef)");
query.bindValue(":idC", res);
query.bindValue(":id", id);
query.bindValue(":dated",dated);
query.bindValue(":datef", datef);


return    query.exec();
}

QSqlQueryModel * Conge ::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from Conge");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("idC"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dated "));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("datef"));

    return model;
}

bool Conge::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Conge where IDC = :idC ");
query.bindValue(":idC", res);
return    query.exec();
}

bool Conge::modifier(int idC,int id, QString dated, QString datef)

{
QSqlQuery query;
QString res= QString::number(idC);
query.prepare("UPDATE Conge set IDC=:idC, ID=:id, DATED=:dated,  DATEF=:datef where IDC=:idC");
query.bindValue(":idc", res);
query.bindValue(":id", id);
query.bindValue(":dated", dated);
query.bindValue(":datef", datef);




return    query.exec();
}

QSqlQueryModel * Conge::afficher_tri()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Conge order by idC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("dated "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datef"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("id"));




    return model;
}




QSqlQueryModel * Conge ::rechercher(int idC){

    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from Conge where idC =:idC");
    query.bindValue(":idC",idC);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("idC"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("dated"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("datef"));

    return model;
}











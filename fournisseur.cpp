#include "fournisseur.h"
#include <QApplication>
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlQuery"
#include <QString>
#include <QApplication>
#include "QSqlQuery"
#include "QMessageBox"
#include "QSqlQuery"
#include <QDebug>
#include <QString>
fournisseur::fournisseur()
{}


bool fournisseur::ajout_fournisseur(fournisseur &F)
{
    QSqlQuery query;


    QString b=QString::number(F.Getnumero_telephone()) ;

    query.prepare("INSERT INTO fournisseur (nom,numero_telephone,email,adresse,appreciation) "
                  "VALUES (:nom, :numero_telephone, :email, :adresse, :appreciation)");

    query.bindValue(0,F.Getnom());
    query.bindValue(1,b);
    query.bindValue(2,F.Getemail());
    query.bindValue(3,F.Getadresse());
    query.bindValue(4,F.Getappreciation());
    if(query.exec()){
       return true;
    }
   else return false;

}
QSqlQueryModel *fournisseur::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from fournisseur");
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero de telephone"));

    model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("appreciation"));
    return model;
}
bool fournisseur::supprimer_fournisseur(QString nom)
{
QSqlQuery query;
    QString ID1=nom;
    query.prepare("delete from fournisseur where nom=?");
    query.addBindValue(ID1);
    return (query.exec());
}
bool fournisseur::modifier_fournisseur(fournisseur &F)
 {
    QSqlQuery query;
    query.prepare("update fournisseur set id_fournisseur = ? ,nom = ?,"
                  " numero_telephone = ?, email = ?, adresse = ?, appreciation = ?"
                  " where id_fournisseur = ?"
                  );
    query.addBindValue(F.Getid_fournisseur());
    query.addBindValue(F.Getnom());
    query.addBindValue(F.Getnumero_telephone());
    query.addBindValue(F.Getemail());
    query.addBindValue(F.Getadresse());
    query.addBindValue(F.Getappreciation());
    query.addBindValue(F.Getid_fournisseur());
    if(query.exec()){
        return true;
    }
    else
        return false;
 }
bool fournisseur::rechercherfournisseur(QString val,fournisseur &F){
    QSqlQuery query;

    query.prepare("select * from fournisseur where id_fournisseur = '"+val+"' or nom='"+val+"'or email='"+val+"'or adresse='"+val+"'or numero_telephone='"+val+"'or appreciation='"+val+"'");
    if(query.exec()){
        while(query.next()){
F.setid_fournisseur(query.value(0).toInt());
            F.setnom(query.value(1).toString());
            F.setnumero_telephone(query.value(2).toInt());
            F.setemail(query.value(3).toString());
            F.setadresse(query.value(4).toString());
            F.setappreciation(query.value(5).toString());
        }
        return true;
    }
    else
        return false;
}
QSqlQueryModel * fournisseur::rechercher(QString nom)
{
  QSqlQueryModel * model= new QSqlQueryModel();

    QString str="select * from Fournisseur where nom like'%"+nom+"%'";

   model->setQuery(str);
  model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
   model->setHeaderData(2, Qt::Horizontal, QObject::tr("numero_telephone"));
   model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
   model->setHeaderData(4, Qt::Horizontal, QObject::tr("adresse"));
   model->setHeaderData(5, Qt::Horizontal, QObject::tr("appreciation"));

    return model;

}
QSqlQueryModel * fournisseur::rechercherf(QString val)
{
  QSqlQueryModel * model= new QSqlQueryModel();
  QSqlQuery query;

    QString str="select * from fournisseur where nom like'%"+val+"%'";

   model->setQuery(str);


   query.addBindValue(val);


    return model;

}
QSqlQueryModel * fournisseur::rechercherr()
{

    QSqlQuery query;
    QSqlQueryModel* model = new QSqlQueryModel();
    query.prepare("select nom from fournisseur ");
    if(query.exec()){
        model->setQuery(query);
    }
return model;
}

float fournisseur::pourcentage_h()
{
QSqlQueryModel *model1 = new QSqlQueryModel() ;
    QSqlQueryModel *model = new QSqlQueryModel() ;
   QSqlQuery afficheeh;
   model->setQuery("select * from fournisseur ");
   if(afficheeh.exec("select * from fournisseur where appreciation='Nouveau' "))
   qDebug()<<"bb";

   model1->setQuery(afficheeh);
   int nbr_total = 0 ;
   int nbr_hygiene = 0 ;
   int pourcentage_h = 0 ;
   nbr_total = model->rowCount();

   nbr_hygiene = model1->rowCount();
   qDebug()<<"hygiene="<<nbr_hygiene<<"total="<<nbr_total;
   pourcentage_h = (nbr_hygiene * 100) / nbr_total ;

   return pourcentage_h;
}
float fournisseur::pourcentage_e()
{
QSqlQueryModel *model1 = new QSqlQueryModel() ;
    QSqlQueryModel *model = new QSqlQueryModel() ;
   QSqlQuery afficheeh;
   model->setQuery("select * from fournisseur ");
   if(afficheeh.exec("select * from fournisseur where appreciation='Excellent' "))
   qDebug()<<"bb";

   model1->setQuery(afficheeh);
   int nbr_total = 0 ;
   int nbr_hygiene = 0 ;
   int pourcentage_e = 0 ;
   nbr_total = model->rowCount();

   nbr_hygiene = model1->rowCount();
   qDebug()<<"hygiene="<<nbr_hygiene<<"total="<<nbr_total;
   pourcentage_e = (nbr_hygiene * 100) / nbr_total ;

   return pourcentage_e;
}
float fournisseur::pourcentage_m()
{
QSqlQueryModel *model1 = new QSqlQueryModel() ;
    QSqlQueryModel *model = new QSqlQueryModel() ;
   QSqlQuery afficheeh;
   model->setQuery("select * from fournisseur ");
   if(afficheeh.exec("select * from fournisseur where appreciation='Moyen' "))
   qDebug()<<"bb";

   model1->setQuery(afficheeh);
   int nbr_total = 0 ;
   int nbr_hygiene = 0 ;
   int pourcentage_m = 0 ;
   nbr_total = model->rowCount();

   nbr_hygiene = model1->rowCount();
   qDebug()<<"hygiene="<<nbr_hygiene<<"total="<<nbr_total;
   pourcentage_m = (nbr_hygiene * 100) / nbr_total ;

   return pourcentage_m;
}
float fournisseur::pourcentage_b()
{
QSqlQueryModel *model1 = new QSqlQueryModel() ;
    QSqlQueryModel *model = new QSqlQueryModel() ;
   QSqlQuery afficheeh;
   model->setQuery("select * from fournisseur ");
   if(afficheeh.exec("select * from fournisseur where appreciation='Bon' "))
   qDebug()<<"bb";

   model1->setQuery(afficheeh);
   int nbr_total = 0 ;
   int nbr_hygiene = 0 ;
   int pourcentage_b = 0 ;
   nbr_total = model->rowCount();

   nbr_hygiene = model1->rowCount();
   qDebug()<<"hygiene="<<nbr_hygiene<<"total="<<nbr_total;
   pourcentage_b = (nbr_hygiene * 100) / nbr_total ;

   return pourcentage_b;
}

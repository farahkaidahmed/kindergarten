#include "emploi.h"
#include<QDebug>
emploi::emploi()
{
    id_emploi=0;
    heure=heure.currentTime();
  datee=datee.currentDate();
   seance ="";
num_classe=0;
}
emploi::emploi(int id_emploi,QTime heure,QDate datee,QString seance,int num_classe)
{

    this->id_emploi=id_emploi;
    this->heure=heure;
    this->datee=datee;
    this->seance=seance;
    this->num_classe=num_classe;
}
int emploi::get_id_emploi(){return id_emploi;}
QTime emploi::get_heure(){return heure;}
QDate emploi::get_datee(){return datee;}
 int emploi::get_num_classe(){return num_classe;}
 bool emploi::ajouter()
 {
     QSqlQuery query;

      QString id_emp= QString:: number(id_emploi);
     QString num_class= QString::number(num_classe);

     query.prepare("INSERT INTO EMPLOI (IDEMPLOI,HEURE,DATEE,SEANCE,NUM_CLASSE) "
                     "VALUES (:ID_EMPLOI,:HEURE,:DATEE,:SEANCE,:NUM_CLASSE)");


     query.bindValue(":ID_EMPLOI", id_emp);
     query.bindValue(":HEURE", heure);
     query.bindValue(":DATEE", datee);
     query.bindValue(":SEANCE", seance);

     query.bindValue(":NUM_CLASSE", num_class);

     return query.exec();
 }
 QSqlQueryModel * emploi::afficher()
 {
     QSqlQueryModel * model= new QSqlQueryModel();

     model->setQuery("SELECT * FROM EMPLOI");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOI"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("DATEE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("SEANCE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("HEURE"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_CLASSE"));

     return model;
 }

 bool emploi::supprimer(int id_emploi)
 {
     int count=0;
     QSqlQuery query;
     QSqlQuery query1;
     QString res= QString::number(id_emploi);
     query1.prepare("SELECT IDEMPLOI FROM EMPLOI WHERE IDEMPLOI = :id_emploi");
     query1.bindValue(":id_emploi", res);
     if (query1.exec())
     {
         while(query1.next()==true)
                                {

                                    count++;

                                }
                                if(count==1)
                                {
                                     query.prepare("DELETE EMPLOI WHERE IDEMPLOI=:id_emploi");
                                     query.bindValue(":id_emploi",res);
                                }


     }
     return    query.exec();
 }
 emploi emploi::get_emploi(int id_emploi)
 {
     emploi *p = new emploi();
    QSqlQuery q;
     q.prepare("SELECT * FROM EMPLOI WHERE IDEMPLOI=:ID_EMPLOI");
     q.bindValue(":ID_EMPLOI",id_emploi);
     q.exec();
     while (q.next()) {
             p->set_id_emploi(q.value(0).toInt());
             p->set_heure(q.value(1).toTime());
             p->set_datee(q.value(2).toDate());
             p->set_seance(q.value(3).toString());
             p->set_num_classe(q.value(4).toInt());
         }
 return *p;
 }
 bool emploi::modifier()
 {
     QSqlQuery query;
     QString id_emp= QString::number(id_emploi);
     QString num_class= QString:: number(num_classe);
     query.prepare("UPDATE EMPLOI SET HEURE=:HEURE,DATEE=:DATEE,SEANCE=:SEANCE, NUM_CLASSE=:NUM_CLASSE WHERE IDEMPLOI=:ID_EMPLOI");

     query.bindValue(":ID_EMPLOI", id_emp);
     query.bindValue(":HEURE", heure);
     query.bindValue(":DATEE", datee);
     query.bindValue(":SEANCE", seance);

     query.bindValue(":NUM_CLASSE", num_class);
     return    query.exec();
 }
 QSqlQueryModel *emploi::rechercher(const QString &c)
 {
     QSqlQueryModel * model= new QSqlQueryModel();
     model->setQuery("SELECT*FROM EMPLOI WHERE (SEANCE LIKE '"+c+"%')");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_EMPLOI"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("HEURE"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("DATEE"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("SEANCE"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUM_CLASSE"));
     return model;
 }
 bool emploi::checked(QDate datee,QTime heure,int num_classe){
     QSqlQuery query;

      QString res= QString::number(num_classe);

     query.prepare("SELECT * FROM EMPLOI WHERE DATEE=:DATEE AND HEURE=:HEURE AND NUM_CLASSE=:NUM_CLASSE");
     query.bindValue(":DATEE", datee);
     query.bindValue(":HEURE", heure);
   query.bindValue(":NUM_CLASSE", res);
     int count=0;
     if (query.exec())
     {
         while(query.next()==true)
                                {

                                    count++;

                                }
                                if(count==0)
                                {
                                     return false;
                                }
                                else{
                                    return true;
                                }


     }



 }






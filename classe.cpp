#include "classe.h"
#include<QDebug>
Classe::Classe()
{
    num_classe=0;
    niveau="";
   Maitresse="";
   num_salle =0;

}
Classe::Classe(int num_classe,int  num_salle,QString niveau,QString Maitresse)
{

    this->num_classe=num_classe;
    this->niveau=niveau;
    this->Maitresse=Maitresse;
    this->num_salle=num_salle;
}
int Classe::get_num_classe(){return num_classe;}
QString Classe::get_niveau(){return niveau;}
QString Classe::get_Maitresse(){return Maitresse;}
int Classe::get_num_salle(){return num_salle;}

bool Classe::ajouter()
{
    QSqlQuery query;
    QString num_class= QString::number(num_classe);
    QString num_sall= QString:: number(num_salle);
    query.prepare("INSERT INTO CLASSE (NUM_CLASSE,NIVEAU,MAITRESSE,NUM_SALLE) "
                    "VALUES (:NUM_CLASSE,:NIVEAU,:MAITRESSE,:NUM_SALLE)");
    query.bindValue(":NUM_CLASSE", num_class);
    query.bindValue(":NIVEAU", niveau);
    query.bindValue(":MAITRESSE", Maitresse);
    query.bindValue(":NUM_SALLE", num_sall);
    return query.exec();


}

QSqlQueryModel * Classe::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM CLASSE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CLASSE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NIVEAU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAITRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_SALLE"));

    return model;
}

bool Classe::supprimer(int num_classe)
{
    int count=0;
    emploi e;
    QSqlQuery query;
    QSqlQuery query1;
    QSqlQuery q;
    QString res= QString::number(num_classe);
    query1.prepare("SELECT NUM_CLASSE FROM CLASSE WHERE NUM_CLASSE = :num_classe");
    query1.bindValue(":num_classe", res);
    if (query1.exec())
    {
        while(query1.next()==true)
                               {

                                   count++;

                               }
                               if(count==1)
                               {
                                   q.prepare("SELECT IDEMPLOI FROM EMPLOI WHERE NUM_CLASSE=:num_classe");
                                   q.bindValue(":num_classe", res);
                                   q.exec();
                                    while(q.next())
                                    {
                                        e.supprimer(q.value(0).toInt());
                                    }
                                    query.prepare("DELETE CLASSE WHERE NUM_CLASSE=:num_classe");
                                    query.bindValue(":num_classe",res);
                               }


    }
    return    query.exec();
}

Classe Classe::get_Classe(int num_classe)
{
    Classe *p = new Classe();
   QSqlQuery q;
    q.prepare("SELECT * FROM CLASSE WHERE NUM_CLASSE=:NUM_CLASSE");
    q.bindValue(":NUM_CLASSE",num_classe);
    q.exec();
    while (q.next()) {
            p->set_num_classe(q.value(0).toInt());
            p->set_niveau(q.value(1).toString());
            p->set_Maitresse(q.value(2).toString());
            p->set_num_salle(q.value(3).toInt());
        }
return *p;
}

bool Classe::modifier()
{
    QSqlQuery query;
    QString num_class= QString::number(num_classe);
    QString num_sall= QString:: number(num_salle);
    query.prepare("UPDATE CLASSE SET NIVEAU=:NIVEAU,MAITRESSE=:MAITRESSE,NUM_SALLE=:NUM_SALLE WHERE NUM_CLASSE=:NUM_CLASSE");
    query.bindValue(":NUM_CLASSE", num_class);
    query.bindValue(":NIVEAU", niveau);
    query.bindValue(":MAITRESSE", Maitresse);
    query.bindValue(":NUM_SALLE", num_sall);
    return    query.exec();
}

QSqlQueryModel *Classe::rechercher(const QString &c)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT*FROM CLASSE WHERE (MAITRESSE LIKE '"+c+"%')");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NUM_CLASSE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NIVEAU"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAITRESSE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUM_SALLE"));
    return model;
}
QSqlQueryModel *Classe::Tri()
{
    QSqlQueryModel * model = new QSqlQueryModel;
    QSqlQuery * q= new QSqlQuery;
    q->prepare("SELECT * FROM CLASSE ORDER BY  NUM_SALLE ASC");
    q->exec();
    model->setQuery(*q);
    return model;
}
//Compter les fetes avec prix +200 et retourner leur pourcentage
int Classe ::stat_salle()
{   int plus =0;
    int total =0;
    QSqlQuery query0;
     query0.exec("SELECT * FROM CLASSE ");
     while(query0.next())
                 {
                     total = total + 1;

                 }
    QSqlQuery query;
     query.exec("SELECT * FROM CLASSE WHERE NUM_SALLE=10");
     while(query.next())
                 {
                     plus = plus + 1;

                 }
     return ((plus*100)/total);

}




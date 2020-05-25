#ifndef EMPLOI_H
#define EMPLOI_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTime>
#include <QDate>

class emploi
{
public:
   emploi();
    emploi(int,QTime,QDate,QString,int);

    int get_id_emploi();
    QTime get_heure();
    QDate get_datee();
    QString get_seance();
    int get_num_classe();


    void set_id_emploi(int id_emploi){this->id_emploi=id_emploi;}
    void set_heure(QTime heure){this->heure=heure;}


    void set_datee(QDate datee){this->datee=datee;}
     void set_seance(QString seance){this->seance=seance;}
    void set_num_classe(int num_classe){this->num_classe=num_classe;}


    bool ajouter();
 emploi get_emploi(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *rechercher(const QString &c);
    bool checked(QDate, QTime heure,int num_classe);
private:
    int id_emploi,num_classe;
    QString seance;
    QTime heure;
    QDate datee;

};













#endif // EMPLOI_H

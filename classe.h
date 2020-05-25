#ifndef CLASSE_H
#define CLASSE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include"emploi.h"
class Classe
{
public:
    Classe();
    Classe(int,int,QString,QString);

    int get_num_classe();
    QString get_niveau();
    QString get_Maitresse();
    int get_num_salle();


    void set_num_classe(int num_classe){this->num_classe=num_classe;}
    void set_niveau(QString niveau){this->niveau=niveau;}
    void set_Maitresse(QString Maitresse){this->Maitresse=Maitresse;}
    void set_num_salle(int num_salle){this->num_salle=num_salle;}


    bool ajouter();
    Classe get_Classe(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel *rechercher(const QString &c);
     QSqlQueryModel *Tri();
     int stat_salle();
private:
    int num_salle,num_classe;
    QString Maitresse,niveau;
};

#endif // CLASSE_H

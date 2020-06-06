
#ifndef PROFILS_H
#define PROFILS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>



class Profils
{
public:
    Profils();
    Profils(int,int,QString,QString,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_salaire();
      QString get_etat();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
     bool modifier(int);
    QSqlQueryModel * afficher_tri();
    QSqlQueryModel *rechercher(int);
    int stat_moins();
    int stat_plus();
private:
    QString nom,prenom,etat;
    int id,salaire;
};


#endif // EMPLOYER_H

#ifndef CLUB_H
#define CLUB_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class club
{public:
    club();
    club(QString,int,int,int);
    QString get_nom();
    int get_id();
    int get_prix();
    int get_num_salle();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom;
    int id,prix,num_salle;
};


#endif // CLUB_H

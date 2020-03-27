#ifndef SALLE_H
#define SALLE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class salle
{public:
    salle();
    salle(QString,int,int);
    QString get_nom();
    int get_num();
    int get_max();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom;
    int num,max;
};

#endif // SALLE_H

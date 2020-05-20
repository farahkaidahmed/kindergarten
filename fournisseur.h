#ifndef fournisseur_H
#define fournisseur_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
    int id_fournisseur;
    QString nom;
    int numero_telephone;
    QString email;
    QString adresse;
    QString appreciation;
public:
    int Getid_fournisseur () {return id_fournisseur ;}
    void setid_fournisseur (int val) {id_fournisseur=val ;}
    QString Getnom () {return nom ;}
    void setnom (QString val) {nom=val ;}
    int Getnumero_telephone () {return numero_telephone ;}
    void setnumero_telephone (int val) {numero_telephone=val ;}
    QString Getemail () {return email ;}
    void setemail (QString val) {email=val ;}
    QString Getadresse () {return adresse ;}
    void setadresse (QString val) {adresse=val ;}
    QString Getappreciation () {return appreciation ;}
    void setappreciation (QString val) {appreciation=val ;}
    fournisseur();
    bool ajout_fournisseur(fournisseur &F);
    QSqlQueryModel *afficher();
    bool supprimer_fournisseur(QString nom);
    bool rechercherfournisseur(QString val,fournisseur &F);
    bool modifier_fournisseur(fournisseur &F);
    QSqlQueryModel * rechercher(QString nom);
QSqlQueryModel * rechercherf(QString val);
QSqlQueryModel * rechercherr();

float pourcentage_h();
float pourcentage_e();
float pourcentage_m();
float pourcentage_b();
};
#endif // fournisseur_H

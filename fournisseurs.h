#ifndef fournisseurs_H
#define fournisseurs_H

#include <QDialog>
#include "fournisseur.h"
#include "QMessageBox"
#include <QFileDialog>

#include <QSqlQueryModel>

namespace Ui {

class fournisseurs;
}

class fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseurs(QWidget *parent = 0);
    ~fournisseurs();

private slots:

    void on_ajout_fournisseur_clicked();



    void on_supprimer_2_clicked();

    void on_modifier_clicked();

    void on_recherche_afficher_textChanged(const QString &arg1);

    void on_recherche_afficher_2_textChanged(const QString &arg1);

    void on_ajouter_tabBarClicked(int index);

    void on_pushButton_2_clicked();

    void on_recherche_afficher_3_textChanged(const QString &arg1);

    void on_modifier_2_activated(const QModelIndex &index);

    
    
    void on_supprimer_activated(const QModelIndex &index);

    void on_pushButton_clicked();









private:
    Ui::fournisseurs *ui;
QSqlQueryModel *afficher();
};

#endif // fournisseurs_H


#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"classe.h"
#include"emploi.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include  "notification.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:
    void on_ajout_Classe_clicked();

    void on_pushButton_Supp_Classe_clicked();

    void on_pb_trouver_Classe_clicked();

    void on_pb_modifier_Classe_clicked();

    void on_lineEdit_Recherche_Classe_textChanged(const QString &arg1);

  //  void on_comboBox_classe_currentIndexChanged(const QString &arg1);


 void on_ajout_emploi_clicked();

    void on_pushButton_Supp_emploi_clicked();

   void on_pb_trouver_emploi_clicked();

 void on_pb_modifier_emploi_clicked();

  void on_lineEdit_Recherche_emploi_textChanged(const QString &arg1);
   void on_pb_tri_2_clicked();



private:
    Ui::Dialog *ui;
    Classe tmpClasse;
    emploi tmpemploi;
};

#endif // DIALOG_H

/*#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"classe.h"
#include"emploi.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

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

private:
    Ui::MainWindow *ui;
    Classe tmpClasse;
     emploi tmpemploi;

};

#endif // MAINWINDOW_H
*/

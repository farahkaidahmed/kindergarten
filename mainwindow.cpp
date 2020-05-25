/*#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_Classe_clicked()
{
    int num_classe = ui->lineEdit_classe->text().toInt();
    int num_salle= ui->lineEdit_Salle->text().toInt();
    QString Maitresse=ui->lineEdit_Maitresse->text();
    QString Niveau=ui->lineEdit_Niveau->text();

    ui->comboBox_numclasse->clear();
    QSqlQuery query;
    query.prepare("SELECT NUM_CLASSE FROM CLASSE");
    query.exec();
    while (query.next()) {
            QString num_classe=QString::number(query.value(0).toInt());
            ui->comboBox_numclasse->addItem(num_classe);
            ui->comboBox_numclasse_2->addItem(num_classe);
    }

    Classe c(num_classe,num_salle,Niveau,Maitresse);
    bool test=c.ajouter();
    ui->tabClasse->setModel(tmpClasse.afficher());
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_Maitresse->setText("");
        ui->lineEdit_Niveau->setText("");
        ui->lineEdit_Salle->setText(zero);
        ui->lineEdit_classe->setText(zero);


    }
}

void MainWindow::on_pushButton_Supp_Classe_clicked()
{
    int classe = ui->lineEdit_Supp->text().toInt();
    bool test=tmpClasse.supprimer(classe);
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_Supp->setText(zero);
    }
    ui->comboBox_numclasse->clear();
    QSqlQuery query;
    query.prepare("SELECT NUM_CLASSE FROM CLASSE");
    query.exec();
    while (query.next()) {
            QString num_classe=QString::number(query.value(0).toInt());
            ui->comboBox_numclasse->addItem(num_classe);
            ui->comboBox_numclasse_2->addItem(num_classe);
    }
    ui->tabClasse->setModel(tmpClasse.afficher());
    ui->tabemploi->setModel(tmpemploi.afficher());
}

void MainWindow::on_pb_trouver_Classe_clicked()
{
    int classe = ui->lineEdit_classe_2->text().toInt();
    Classe c=tmpClasse.get_Classe(classe);
    QString salle=QString::number(c.get_num_salle());
    ui->lineEdit_Salle_2->setText(salle);
    ui->lineEdit_Maitresse_2->setText(c.get_Maitresse());
    ui->lineEdit_Niveau_2->setText(c.get_niveau());
}

void MainWindow::on_pb_modifier_Classe_clicked()
{
    int num_classe = ui->lineEdit_classe_2->text().toInt();
    int num_salle= ui->lineEdit_Salle_2->text().toInt();
    QString Maitresse=ui->lineEdit_Maitresse_2->text();
    QString Niveau=ui->lineEdit_Niveau_2->text();

    Classe c(num_classe,num_salle,Niveau,Maitresse);
    bool test=c.modifier();
    ui->tabClasse->setModel(tmpClasse.afficher());
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_Maitresse_2->setText("");
        ui->lineEdit_Niveau_2->setText("");
        ui->lineEdit_Salle_2->setText(zero);
        ui->lineEdit_classe_2->setText(zero);
    }
}

void MainWindow::on_lineEdit_Recherche_Classe_textChanged(const QString &arg1)
{
    ui->tabClasse_r->setModel(tmpClasse.rechercher(ui->lineEdit_Recherche_Classe->text()));
}































void MainWindow::on_ajout_emploi_clicked()
{
    int id_emploi = ui->lineEdit_emploi->text().toInt();
    QTime heure= ui->dateTimeEdit->time();

    QDate Datee=ui->dateTimeEdit->date();

    QString seance=ui->lineEdit_seance->text();
    int num_classe = ui->comboBox_numclasse->currentText().toInt();

  emploi e(id_emploi,heure,Datee,seance,num_classe);
    bool test=e.ajouter();
    ui->tabemploi->setModel(tmpemploi.afficher());
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_seance->setText("");
        ui->lineEdit_emploi->setText(zero);
       // ui->lineEdit_class_3->setText(zero);
    }
}

void MainWindow::on_pushButton_Supp_emploi_clicked()
{
    int emploi = ui->lineEdit_Supp_2->text().toInt();
    bool test=tmpemploi.supprimer(emploi);
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_Supp_2->setText(zero);
    }

    ui->tabemploi->setModel(tmpemploi.afficher());
}








void MainWindow::on_pb_modifier_emploi_clicked()
{
    int id_emploi = ui->lineEdit_emploi_2->text().toInt();
    QTime heure= ui->dateTimeEdit_2->time();

    QDate Datee=ui->dateTimeEdit_2->date();

    QString seance=ui->lineEdit_seance_2->text();
    int num_classe = ui->comboBox_numclasse_2->currentText().toInt();

  emploi e(id_emploi,heure,Datee,seance,num_classe);
    bool test=e.modifier();
    ui->tabemploi->setModel(tmpemploi.afficher());
    if(test){
        QString zero=QString::number(0);
        ui->lineEdit_seance_2->setText("");
        ui->lineEdit_emploi_2->setText(zero);
       // ui->lineEdit_class_3->setText(zero);
    }
    }
void MainWindow::on_lineEdit_Recherche_emploi_textChanged(const QString &arg1)
{
  ui->tabemploi_r->setModel(tmpemploi.rechercher(ui->lineEdit_Recherche_emploi->text()));
}

*/


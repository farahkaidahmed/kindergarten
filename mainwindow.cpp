#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "club.h"
#include "salle.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

//ui->tabclub->setModel(tmpclub.afficher());
//ui_s->tabsalle->setModel(tmpsalle.afficher());

}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    int id = ui->lineEdit_id->text().toInt();
    int prix = ui->lineEdit_prix->text().toInt();
    int num_salle = ui->lineEdit_num_salle->text().toInt();
  club e(nom,id,prix,num_salle);
  bool test=e.ajouter();
  if(test)
{

      ui->tabclub->setModel(tmpclub.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("club ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un club"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}




void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmpclub.supprimer(id);
    if(test)
    {ui->tabclub->setModel(tmpclub.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un club"),
                    QObject::tr("club supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un club"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}

}



void MainWindow::on_pb_ajouter_s_clicked()
{
    QString nom= ui->lineEdit_nom_s->text();
    int num = ui->lineEdit_num_s->text().toInt();
    int max = ui->lineEdit_max_s->text().toInt();
  salle s(nom,num,max);
  bool test=s.ajouter();
  if(test)
{

      ui->tabsalle->setModel(tmpsalle.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("salle ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
  {
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}

void MainWindow::on_pb_supprimer_s_clicked()
{
    int id = ui->lineEdit_num_2->text().toInt();
    bool test=tmpsalle.supprimer(id);
    if(test)
    {ui->tabsalle->setModel(tmpsalle.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("salle supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);}
}

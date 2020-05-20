#include "gestion_menu_ui.h"
#include "ui_gestion_menu_ui.h"
#include "produit.h"
#include "mon_menu.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileInfo>
#include<QFileDialog>
#include <QDate>
#include <QComboBox>
#include <QDebug>
#include "menu_ui.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QChartView>

QT_CHARTS_USE_NAMESPACE
gestion_menu_ui::gestion_menu_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_menu_ui)
{
    ui->setupUi(this);

    produit aff;

mon_menu m;
        QSqlQueryModel *model =aff.recherche();

        ui->comboBox_1->setModel(model);
        ui->comboBox_2->setModel(model);
        ui->comboBox_3->setModel(model);
        ui->affich->setModel(m.affiche_menu()) ;
        QSqlQueryModel *model1 =aff.recherche();
        ui->combo->setModel(model1);
        ui->combo->setCurrentIndex(-1);

}

gestion_menu_ui::~gestion_menu_ui()
{
    delete ui;
}

void gestion_menu_ui::on_ajout_menu_clicked()
{  mon_menu m;
    QString ref = (ui->designation_menu->text());

    QString b(ui->jour_menu->text());

        m.setpreparateur(ui->preparateur_menu->text());
        m.setjour(ui->jour_menu->text());
       m.setdesignation_menu(ui->designation_menu->text());
       QString p1 = ui->comboBox_1->currentText();
       QString p2 = ui->comboBox_2->currentText();
         QString p3 = ui->comboBox_3->currentText();
        m.setref_produit1(p1);
        m.setref_produit2(p2);
        m.setref_produit3(p3);

        if (m.Getpreparateur() =="") ui->ma->setText(("veuillez remplir  le preparateur"));
  else if (m.Getdesignation_menu() =="") ui->ma->setText(("veuillez remplir  designation menu"));

           else if (m.ajout_menu(m)==true)
            {
                QMessageBox::information(0,qApp->tr("ajout"),
                                         qApp->tr("un nouveau menu a ete ajoute")) ;
            }
            else
            {
                //if not we will show the erreur that caused the probleme (not connected to database....)
                QMessageBox::critical(this,tr("operation annulé "),tr("Operation a echoué"));
            }
}




void gestion_menu_ui::on_pushButton_clicked()
{
    menu_ui *I =new menu_ui () ;
    this->hide();
    I->show () ;
}



void gestion_menu_ui::on_recherche_afficher_cursorPositionChanged(int arg1, int arg2)
{

   mon_menu m;;
        QString designation=ui->recherche_afficher->text();

            QSqlQueryModel *model =m.rechercher(designation);
             ui->affich->setModel(model);
}





void gestion_menu_ui::on_recherche_afficher_2_textChanged(const QString &arg1)
{
    mon_menu aff;
        QString nom=ui->recherche_afficher_2->text();

            QSqlQueryModel *model =aff.rechercher(nom);
             ui->supprimermenu->setModel(model);

}

void gestion_menu_ui::on_jour_currentChanged(int index)
{
   mon_menu m;

        ui->supprimermenu->setModel(m.affiche_menu()) ;
        ui->affich->setModel(m.affiche_menu()) ;
ui->modifier_3->setModel(m.affiche_menu()) ;
}



void gestion_menu_ui::on_supprimer_22_clicked()
{
    QString  nom= ui->nom_22->text();

    mon_menu pr;
    qApp->tr("voulez vous vraiment supprimer ce menu?.");


    if (pr.supprimer_menu(nom))
    {
        QMessageBox::information(0, qApp->tr("supprimer"),
                                 qApp->tr("supprimer OK."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(0, qApp->tr("supprimer"),
                              qApp->tr("supprimer not  OK."), QMessageBox::Cancel);

}

void gestion_menu_ui::on_supprimermenu_activated(const QModelIndex &index)
{
    mon_menu m ;
    QString val = ui->supprimermenu->model()->data(index).toString();
    if(m.recherchermon_menu(val,m) == true){
        ui->nom_22->setText(m.Getdesignation_menu());
         ui->nom_22->setDisabled(true);
    }
    else
        QMessageBox::information(this,tr("Error"),"impossible de definir le menu!");

}

void gestion_menu_ui::on_recherche_afficher_6_textChanged(const QString &arg1)
{
    mon_menu aff;
        QString nom=ui->recherche_afficher_6->text();

            QSqlQueryModel *model =aff.rechercher(nom);
             ui->modifier_3->setModel(model);
}

void gestion_menu_ui::on_modifier_3_activated(const QModelIndex &index)
{
    mon_menu F  ;
    QString val = ui->modifier_3->model()->data(index).toString();
    if(F.recherchermon_menu(val,F) == true){
        ui->id_menu->setText(QString::number(F.Getid_menu()));
        ui->designation->setText(F.Getdesignation_menu());
        ui->preparateur->setText(F.Getpreparateur());
        ui->jour_2->setText(F.Getjour());
        ui->p1->setText(F.Getref_produit1());
        ui->p2->setText(F.Getref_produit2());
        ui->p3->setText(F.Getref_produit3());
        ui->id_menu->setDisabled(true);
    }
    else
        QMessageBox::information(this,tr("Error"),"unable to load info!");
}


void gestion_menu_ui::on_modifier_4_clicked()
{
     mon_menu  F;
    F.setid_menu(ui->id_menu->text().toInt());
    F.setdesignation_menu(ui->designation->text());
    F.setpreparateur(ui->preparateur->text());
   F.setjour(ui->jour_2->text());
    F.setref_produit1(ui->p1->text());
    F.setref_produit2(ui->p2->text());
    F.setref_produit3(ui->p3->text());

     int reponse = QMessageBox::question(0, qApp->tr("Modifier"),
          qApp->tr("voulez vous vraiment Modifier ce fournisseur ?."), QMessageBox::Yes|QMessageBox::No);

     if (reponse==QMessageBox::Yes)
     {


        if (F.modifier_menu(F)==true)
        {
            QMessageBox::information(0, qApp->tr("modifier"),
                qApp->tr("modifier OK."), QMessageBox::Ok);


        }
        else
            QMessageBox::critical(0, qApp->tr("modifier"),
                qApp->tr("modifier not  OK."), QMessageBox::Cancel);
}
}

void gestion_menu_ui::on_pushButton_3_clicked()
{
    mon_menu m;

         ui->supprimermenu->setModel(m.affiche_menu()) ;
         ui->affich->setModel(m.affiche_menu()) ;
 ui->modifier_3->setModel(m.affiche_menu()) ;
}


void gestion_menu_ui::on_combo_activated(int index)
{
    mon_menu m;


        QString v = ui->combo->currentText();
    float z=m.pourcentage_produit(v);
    float w=100-z;
    QPieSeries *series1 = new QPieSeries();
       series1->append("produit", z);
       series1->append("total", w);
       QPieSlice *slice = series1->slices().at(1);
          slice->setExploded();
          slice->setLabelVisible();
          slice->setPen(QPen(Qt::darkGreen, 2));
          slice->setBrush(Qt::green);

       QChart *chart2 = new QChart();
       chart2->addSeries(series1);

       QString str = "";
        str = QString::number(z);
        str.append("% c'est le pourcentage de ce produit dans les menus  ");
        chart2->setTitle(str);

       chart2->legend()->hide();

       QChartView *chartView1 = new QChartView(chart2);
       chartView1->setRenderHint(QPainter::Antialiasing);
        //setHidden(chart2);
    //ui->bbb->addWidget(chartView1);
    chartView1->showNormal();
    chartView1->resize(600,600);


}

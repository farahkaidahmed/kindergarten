#include "fournisseurs.h"
#include "ui_fournisseurs.h"
#include "fournisseur.h"
#include <QDebug>
#include <QMessageBox>
#include "menu_ui.h"
#include "ui_menu_ui.h"
#include <QComboBox>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
QT_CHARTS_USE_NAMESPACE
fournisseurs::fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseurs)
{fournisseur f;
    ui->setupUi(this);
    QPixmap back1("C:/Users/djoe/Desktop/picture");  //calling our background
    back1 = back1.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, back1);
    this->setPalette(palette);

    ui->numero_telephone->setValidator(new QIntValidator(0,100000000,this));

    QList<QString> stringsList;
    stringsList.append("Nouveau");
    stringsList.append("Moyen");
    stringsList.append("Bon");
    stringsList.append("Excellent");
ui->comboBox->addItems(stringsList);
ui->moyen->setText(QString::number(f.pourcentage_m())+" %");
ui->excellent->setText(QString::number(f.pourcentage_e())+" %");
ui->bon->setText(QString::number(f.pourcentage_b())+" %");
ui->nouveau->setText(QString::number(f.pourcentage_h())+" %");
QPieSeries *series = new QPieSeries();
   series->append("Nouveau", f.pourcentage_h());
   series->append("Moyen", f.pourcentage_m());
   series->append("Bon", f.pourcentage_b());
   series->append("Excellent", f.pourcentage_e());
   QPieSlice *slice1 = series->slices().at(1);

   slice1->setBrush(Qt::blue);
   QPieSlice *slice2 = series->slices().at(2);
   slice2->setBrush(Qt::red);
   QPieSlice *slice3 = series->slices().at(3);
   slice3->setBrush(Qt::yellow);

   QChart *chart = new QChart();
   chart->addSeries(series);
   chart->setTitle("Nos Appreciations fournisseurs en pourcentages");
   chart->legend()->hide();
//![3]

//![4]
   QChartView *chartView1 = new QChartView(chart);
   chartView1->setRenderHint(QPainter::Antialiasing);
ui->aaa->addWidget(chartView1);
}

fournisseurs::~fournisseurs()
{
    delete ui;
}

void fournisseurs::on_ajout_fournisseur_clicked()
{
    fournisseur F ;
QString val = (ui->nom->text());
QString p1 = ui->comboBox->currentText();
F.setnom(ui->nom->text());
QString b(ui->numero_telephone->text());
    F.setnumero_telephone(ui->numero_telephone->text().toInt());
    F.setemail(ui->email->text());
    F.setadresse(ui->adresse->text());
    F.setappreciation(p1);

      if (F.Getnom() =="") ui->l_controle_saisie->setText(("Emty nom field"));
     else if (b =="") ui->l_controle_saisie->setText(("Empty phone field"));
    else if (F.Getemail() =="") ui->l_controle_saisie->setText(("Empty email field"));
    else if (F.Getadresse()=="") ui->l_controle_saisie->setText(("Empty adress field"));
     else if (F.Getappreciation() =="") ui->l_controle_saisie->setText(("empty appreciation field"));
else if(F.rechercherf(val)->data(F.rechercherf(val)->index(0,0)).toString() !="" )  ui->l_controle_saisie->setText("Identifiant existe deja!");
     else  if (F.ajout_fournisseur(F)==true){

            QMessageBox::information(0,qApp->tr("ajout"),
                                     qApp->tr("A new fournisseur has been added")) ;
        }
        else
        {
            //if not we will show the erreur that caused the probleme (not connected to database....)
            QMessageBox::critical(this,tr("Failed!"),tr("Operation Failed! try again"));
        }
    }


void fournisseurs::on_supprimer_2_clicked()
{
    QString  nom= ui->nom_2->text();

    fournisseur pr;
    qApp->tr("voulez vous vraiment supprimer ce fournisseur?.");


    if (pr.supprimer_fournisseur(nom))
    {
        QMessageBox::information(0, qApp->tr("supprimer"),
                                 qApp->tr("supprimer OK."), QMessageBox::Ok);

    }
    else
        QMessageBox::critical(0, qApp->tr("supprimer"),
                              qApp->tr("supprimer not  OK."), QMessageBox::Cancel);
}




void fournisseurs::on_modifier_2_activated(const QModelIndex &index)
{
fournisseur F  ;
QString val = ui->modifier_2->model()->data(index).toString();
if(F.rechercherfournisseur(val,F) == true){
    ui->lid_fournisseur->setText(QString::number(F.Getid_fournisseur()));
    ui->lineEdit_nom->setText(F.Getnom());
    ui->lineEdit_numero_telephone->setText(QString::number(F.Getnumero_telephone()));
    ui->lineEdit_email->setText(F.Getemail());
    ui->lineEdit_adresse->setText(F.Getadresse());
    ui->lineEdit_appreciation->setText(F.Getappreciation());
    ui->lid_fournisseur->setDisabled(true);
}
else
    QMessageBox::information(this,tr("Error"),"unable to load info!");
}

void fournisseurs::on_modifier_clicked()
{
    fournisseur F;
    F.setid_fournisseur(ui->lid_fournisseur->text().toInt());
    F.setnom(ui->lineEdit_nom->text());
    F.setnumero_telephone(ui->lineEdit_numero_telephone->text().toInt());
   F.setemail(ui->lineEdit_email->text());
    F.setadresse(ui->lineEdit_adresse->text());
    F.setappreciation(ui->lineEdit_appreciation->text());

     int reponse = QMessageBox::question(0, qApp->tr("Modifier"),
          qApp->tr("voulez vous vraiment Modifier ce fournisseur ?."), QMessageBox::Yes|QMessageBox::No);

     if (reponse==QMessageBox::Yes)
     {


        if (F.modifier_fournisseur(F)==true)
        {
            QMessageBox::information(0, qApp->tr("modifier"),
                qApp->tr("modifier OK."), QMessageBox::Ok);


        }
        else
            QMessageBox::critical(0, qApp->tr("modifier"),
                qApp->tr("modifier not  OK."), QMessageBox::Cancel);
}
}

void fournisseurs::on_recherche_afficher_textChanged(const QString &arg1)
{fournisseur aff;
    QString nom=ui->recherche_afficher->text();

        QSqlQueryModel *model =aff.rechercher(nom);
         ui->affiche->setModel(model);

}

void fournisseurs::on_recherche_afficher_2_textChanged(const QString &arg1)
{fournisseur aff;
    QString nom=ui->recherche_afficher_2->text();

        QSqlQueryModel *model =aff.rechercher(nom);
         ui->modifier_2->setModel(model);
}

void fournisseurs::on_ajouter_tabBarClicked(int index)
{
    fournisseur aff;

        ui->supprimer->setModel(aff.afficher()) ;
        ui->affiche->setModel(aff.afficher()) ;
        ui->modifier_2->setModel(aff.afficher()) ;

}

void fournisseurs::on_pushButton_2_clicked()
{
    fournisseur aff ;
    ui->modifier_2->setModel(aff.afficher()) ;
}

void fournisseurs::on_recherche_afficher_3_textChanged(const QString &arg1)
{
    fournisseur aff;
        QString nom=ui->recherche_afficher_3->text();

            QSqlQueryModel *model =aff.rechercher(nom);
             ui->supprimer->setModel(model);
}

void fournisseurs::on_supprimer_activated(const QModelIndex &index)
{
    fournisseur F  ;
    QString val = ui->supprimer->model()->data(index).toString();
    if(F.rechercherfournisseur(val,F) == true){
        ui->nom_2->setText(F.Getnom());
         ui->nom_2->setDisabled(true);
    }
    else
        QMessageBox::information(this,tr("Error"),"impossible de definir le nom du fournisseur!");
}





void fournisseurs::on_pushButton_clicked()
{
    menu_ui *I =new menu_ui () ;
    this->hide();
    I->show () ;
}






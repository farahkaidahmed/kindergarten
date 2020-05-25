#include "dialogclasse.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     QIntValidator *salle=new QIntValidator(1,20);
    QIntValidator *classe=new QIntValidator(1,100);
    ui->lineEdit_classe->setValidator(classe);
      ui->lineEdit_Salle->setValidator(salle);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::on_ajout_Classe_clicked()
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
             ui->comboBox_supp->addItem(num_classe);

    }





    Classe c(num_classe,num_salle,Niveau,Maitresse);
    if (c.get_num_classe() ==0)
    {
        ui->l_controle_saisie->setText(("Emty class field"));
    }
    else if (c.get_niveau() !="ps")
    {
        ui->l_controle_saisie->setText(("Empty ps ou ms"));
    }


    else if (c.get_Maitresse()=="")
    {
        ui->l_controle_saisie->setText(("Empty maitresse field"));
    }
     else if (c.get_num_salle() ==0)
    {
        ui->l_controle_saisie->setText(("empty salle field"));
    }
    bool test=c.ajouter();
    ui->tabClasse->setModel(tmpClasse.afficher());
    if(test){
        //notification n;
       // n.Alerte_Ajout();

        QString zero=QString::number(0);
        ui->lineEdit_Maitresse->setText("");
        ui->lineEdit_Niveau->setText("");
        ui->lineEdit_Salle->setText(zero);
        ui->lineEdit_classe->setText(zero);
    }
}

void Dialog::on_pushButton_Supp_Classe_clicked()
{
    int classe = ui->comboBox_supp->currentText().toInt();
    bool test=tmpClasse.supprimer(classe);
    if(test){
        QString zero=QString::number(0);
        //ui->comboBox_supp->setText(zero);
    }
    ui->comboBox_numclasse->clear();
    QSqlQuery query;
    query.prepare("SELECT NUM_CLASSE FROM CLASSE");
    query.exec();
    while (query.next()) {
            QString num_classe=QString::number(query.value(0).toInt());
            ui->comboBox_numclasse->addItem(num_classe);
            ui->comboBox_numclasse_2->addItem(num_classe);
              ui->comboBox_supp->addItem(num_classe);

    }
    ui->tabClasse->setModel(tmpClasse.afficher());
    ui->tabemploi->setModel(tmpemploi.afficher());
}

void Dialog::on_pb_trouver_Classe_clicked()
{
    int classe = ui->lineEdit_classe_2->text().toInt();
    Classe c=tmpClasse.get_Classe(classe);
    QString salle=QString::number(c.get_num_salle());
    ui->lineEdit_Salle_2->setText(salle);
    ui->lineEdit_Maitresse_2->setText(c.get_Maitresse());
    ui->lineEdit_Niveau_2->setText(c.get_niveau());
}

void Dialog::on_pb_modifier_Classe_clicked()
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

void Dialog::on_lineEdit_Recherche_Classe_textChanged(const QString &arg1)
{
    ui->tabClasse_r->setModel(tmpClasse.rechercher(ui->lineEdit_Recherche_Classe->text()));
}

void Dialog::on_ajout_emploi_clicked()
{
    int id_emploi = ui->lineEdit_emploi->text().toInt();
    QTime heure= ui->dateTimeEdit->time();

    QDate Datee=ui->dateTimeEdit->date();

    QString seance=ui->lineEdit_seance->text();
    int num_classe = ui->comboBox_numclasse->currentText().toInt();


  if (!tmpemploi.checked(Datee,heure,num_classe)){
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
    else
    {
      ui->l_control->setText("tu peux pas ajouter la meme date a la meme classe ");
  }

  ui->comboBox_supp_3->clear();
  QSqlQuery query;
  query.prepare("SELECT IDEMPLOI FROM EMPLOI");
  query.exec();
  while (query.next()) {
          QString id_emploi=QString::number(query.value(0).toInt());

           ui->comboBox_supp_3->addItem(id_emploi);
  }
}




void Dialog::on_pushButton_Supp_emploi_clicked()
{
    int emploi = ui->comboBox_supp_3->currentText().toInt();
    bool test=tmpemploi.supprimer(emploi);
       if(test){
           QString zero=QString::number(0);

       }
       ui->comboBox_supp_3->clear();
       QSqlQuery query;
       query.prepare("SELECT IDEMPLOI FROM EMPLOI");
       query.exec();
       while (query.next()) {
               QString id_emploi=QString::number(query.value(0).toInt());

                ui->comboBox_supp_3->addItem(id_emploi);
       }




       ui->tabClasse->setModel(tmpClasse.afficher());
       ui->tabemploi->setModel(tmpemploi.afficher());
   }




void Dialog::on_pb_trouver_emploi_clicked()
{
    int emplo = ui->lineEdit_emploi_2->text().toInt();
    emploi e=tmpemploi.get_emploi(emplo);
    QString classe=QString::number(e.get_num_classe());
    ui->comboBox_numclasse_2->addItem(classe);
    //ui->lineEdit_seance_2->setText(e.get_seance());
    ui->lineEdit_seance_2->setText(classe);
    ui->dateTimeEdit_2-> setDate(e.get_datee());
    ui->dateTimeEdit_2-> setTime(e.get_heure());

}
















void Dialog::on_pb_modifier_emploi_clicked()
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
void Dialog::on_lineEdit_Recherche_emploi_textChanged(const QString &arg1)
{
  ui->tabemploi_r->setModel(tmpemploi.rechercher(ui->lineEdit_Recherche_emploi->text()));
}


void Dialog::on_pb_tri_2_clicked()
{
    ui->tabClasse->setModel(tmpClasse.Tri());
}

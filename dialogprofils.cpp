#include "dialogprofils.h"
#include "ui_dialogprofils.h"
#include "profils.h"
#include "conge.h"
#include <QDialog>
#include <QMessageBox>
#include <QtSql/QSqlQueryModel>
//#include <QtSql/QSqlQuery>


Dialogprofils::Dialogprofils(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogprofils)
{
    ui->setupUi(this);
    ui->tabprofils->setModel(tmpprofils.afficher());
     ui->tabconge->setModel(tmpconge.afficher());
     ui->tabprofils_modif->setModel(tmpprofils.afficher());
     ui->tabcong_modif->setModel(tmpconge.afficher());
      ui->comboBox_etat->addItem("present(e)");
      ui->comboBox_etat->addItem("congé");
      ui->comboBox_etatm->addItem("present(e)");
      ui->comboBox_etatm->addItem("congé");



     QSqlQueryModel *model = new QSqlQueryModel();
                model->setQuery("select id from Profils");
                    ui->comboBox1->setModel(model);
                    ui->comboBox2->setModel(model);
                    ui->comboBox_suppP->setModel(model);//supp profils
                    ui->comboBox_mP->setModel(model);//modif  profils
                    ui->comboBox_RP->setModel(model);//RECH profils



                    QSqlQueryModel *model1 = new QSqlQueryModel();
                               model1->setQuery("select idC from Conge");
                                ui->comboBox_suppC->setModel(model1);//supp Conge
                                ui->comboBox_mC->setModel(model1);//modif congé

                                ui->comboBox_RC->setModel(model1);//RECH CONGE




}






Dialogprofils::~Dialogprofils()
{
    delete ui;
}






void Dialogprofils::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int salaire = ui->lineEdit_salaire->text().toInt();
    //QString etat= ui->lineEdit_etat->text();
       //QString datef= ui->dateEdit_2->date().toString();

   QString etat= ui->comboBox_etat->currentText();

   // if(ui->comboBox->currentText()=="...")
    //{
    //ui->comboBox->clear();

             //ui->comboBox_etat->addItem("Peugeot");
    QString  idp = ui->lineEdit_id->text();
    QString  salairep = ui->lineEdit_salaire->text();



    QString SS = "0123456789";
    QString numeros = "0123456789";
    QString verifnom= ui->lineEdit_nom->text();

    QString verifprenom= ui->lineEdit_prenom->text();
    bool verifid =false;
    bool verifs =false;


    //verification salaire  numbers only
              for (int c = 0; c < salairep.length(); c++)
                   { verifs= false;
                         for (int d = 0; d < SS.length(); d++)
                         {
                            if (salairep[c] == SS [d] )
                            {verifs = true;}
                         }
                    if (verifs == false )
                    { QMessageBox::information(nullptr, QObject::tr(" ID"),
                                     QObject::tr("salaire  INCORRECT.\n"
                                                 "Verifier salaire."), QMessageBox::Cancel);

                        ;}}


        //verification id numbers only
                  for (int i = 0; i < idp.length(); i++)
                       { verifid= false;
                             for (int j = 0; j < numeros.length(); j++)
                             {
                                if (idp[i] == numeros [j] )
                                {verifid = true;}
                             }
                        if (verifid == false )
                        { QMessageBox::information(nullptr, QObject::tr(" ID"),
                                         QObject::tr("ID INCORRECT.\n"
                                                     "Verifier l'id."), QMessageBox::Cancel);

                            ;}}

  //verification le reste des champs non vides
            bool test1 = verifnom.length() == 0 ;
            bool test2 = verifprenom.length() == 0 ;




             if (test1)
             {QMessageBox::information(nullptr, QObject::tr("NOM"),
                  QObject::tr("CHAMP VIDE.\n"
                                       "Verifier nom."), QMessageBox::Cancel);}
             if (test2)
             {QMessageBox::information(nullptr, QObject::tr("prenom"),
                  QObject::tr("CHAMP VIDE.\n"
                                       "Verifier nom."), QMessageBox::Cancel);}

  if ((verifs == true) &&(verifid == true) && (test1==false) && (test2==false))
  {
  Profils p(id,salaire,nom,prenom,etat);
  bool test=p.ajouter();
  if(test)
{

      ui->tabprofils->setModel(tmpprofils.afficher());//refresh
      QSqlQueryModel *model = new QSqlQueryModel();
                 model->setQuery("select id from Profils");
                     ui->comboBox1->setModel(model);
                     ui->comboBox2->setModel(model);
                     ui->comboBox_suppP->setModel(model);//supp profils
                     ui->comboBox_mP->setModel(model);//modif  profils
                     ui->comboBox_RP->setModel(model);//RECH profils



QMessageBox::information(nullptr, QObject::tr("Ajouter un profil"),
                  QObject::tr("profil ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un profils"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);




}}

void Dialogprofils::on_pb_supprimer_clicked()
{
//int id = ui->lineEdit_id2->text().toInt();
    int  id = ui->comboBox_suppP->currentText().toInt();
bool test=tmpprofils.supprimer(id);
if(test)
{ui->tabprofils->setModel(tmpprofils.afficher());//refresh

                     QSqlQueryModel *model = new QSqlQueryModel();
                               model->setQuery("select id from Profils");
                                    ui->comboBox1->setModel(model);
                                    ui->comboBox2->setModel(model);
                                    ui->comboBox_suppP->setModel(model);//supp profils
                                    ui->comboBox_mP->setModel(model);//modif  profils
                                    ui->comboBox_RP->setModel(model);//RECH profils



    QMessageBox::information(nullptr, QObject::tr("Supprimer un profil"),
                QObject::tr("profil supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
  // ui->comboBox_suppP->setModel(model);//refresh

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un profil"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void Dialogprofils::on_pb_modifier_clicked()
{
    int id= ui->lineEdit_nvid->text().toInt();
    int salaire_nv = ui->lineEdit_nvs->text().toInt();
    QString nom_nv = ui->lineEdit_nvn->text();
    QString prenom_nv = ui->lineEdit_nvp->text();
    QString etat_nv = ui->comboBox_etatm->currentText();



  Profils p1(id,salaire_nv,nom_nv,prenom_nv,etat_nv);
  bool test=p1.modifier(id);
  if(test)
{ui->tabprofils->setModel(tmpprofils.afficher());//refresh
 ui->tabprofils_modif->setModel(tmpprofils.afficher());//refresh

QMessageBox::information(nullptr, QObject::tr("Ajouter un profil"),
                  QObject::tr("profil modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
          {
      QMessageBox::critical(nullptr, QObject::tr("modifier un profil"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);}
}



void Dialogprofils::on_pb_rechm_clicked()
{
      ui->tabprofils_modif->setModel(tmpprofils.rechercher( ui->comboBox_mP->currentText().toInt()));
      if( ui->comboBox_mP->currentText().isEmpty())

               ui->tabprofils_modif->setModel(tmpprofils.afficher());
}




void Dialogprofils::on_pb_rech_clicked()
    {
  ui->tabprofils->setModel(tmpprofils.rechercher(ui->comboBox_RP->currentText().toInt()));
  if(ui->comboBox_RP->currentText().isEmpty())


   ui->tabprofils->setModel(tmpprofils.afficher());
     }


void Dialogprofils::on_pb_trip_clicked()

{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from profils order by SALAIRE ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("salaire"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
  ui->tabprofils->setModel(model);
  ui->tabprofils->show();

}









 void Dialogprofils::on_pb_ajouterc_clicked()
 {
     int idC = ui->lineEdit_idc->text().toInt();
     int  id = ui->comboBox1->currentText().toInt();
     QString dated= ui-> dateEdit_1->date().toString();
     QString datef= ui->dateEdit_2->date().toString();






     QString  idC1 = ui->lineEdit_idc->text();
     QString verifdated= ui->dateEdit_1->date().toString();
     QString verifdatef= ui->dateEdit_2->date().toString();
     QString verifidp= ui->comboBox1->currentText();



     QString numerosc = "0123456789";

     bool verifidc =false;

         //verification id numbers only
                   for (int i = 0; i < idC1.length(); i++)
                        { verifidc= false;
                              for (int j = 0; j < numerosc.length(); j++)
                              {
                                 if (idC1[i] == numerosc [j])
                                 {verifidc = true;}
                              }
                         if (verifidc == false)
                         { QMessageBox::information(nullptr, QObject::tr(" IDC"),
                                          QObject::tr("ID INCORRECT.\n"
                                                      "Verifier l'id."), QMessageBox::Cancel);

                             ;}}


         //verification le reste des champs non vides

            bool test2 = verifdated.length() == 0 ;
            bool test3 = verifdatef.length() == 0 ;
            bool test1 = verifidp.length() == 0 ;




              if (test2)
               {QMessageBox::information(nullptr, QObject::tr("DATED"),
                                              QObject::tr("CHAMP VIDE.\n"
                                              "Verifier date debut."), QMessageBox::Cancel);}
              if (test3)
               {QMessageBox::information(nullptr, QObject::tr("DATEF"),
                                              QObject::tr("CHAMP VIDE.\n"
                                              "Verifier date fin."), QMessageBox::Cancel);}
              if (test1)
               {QMessageBox::information(nullptr, QObject::tr("ID EMPLOYE"),
                                              QObject::tr("CHAMP VIDE.\n"
                                              "verifier id employé ."), QMessageBox::Cancel);}






if ((verifidc == true) && (test1==false) && (test2==false) && (test3==false))

{

  Conge g (idC,id,dated,datef);
   bool test=g.ajouter();
   if(test)
 {

       ui->tabconge->setModel(tmpconge.afficher());//refresh
       QSqlQueryModel *model1 = new QSqlQueryModel();
                  model1->setQuery("select idC from Conge");
                  ui->comboBox_suppC->setModel(model1);//supp Conge
                  ui->comboBox_mC->setModel(model1);//modif congé
                  ui->comboBox_RC->setModel(model1);//RECH CONGE
 QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                   QObject::tr("congé ajouté.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

 }
   else
       QMessageBox::critical(nullptr, QObject::tr("Ajouter un congé"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);


 }
 }




 void Dialogprofils::on_pb_suppc_clicked()
 {
  int  idC = ui->comboBox_suppC->currentText().toInt();
 //int idC = ui->lineEdit_numero->text().toInt();
 bool test=tmpconge.supprimer(idC);
 if(test)
 {ui->tabconge->setModel(tmpconge.afficher());//refresh
     QSqlQueryModel *model1 = new QSqlQueryModel();
                model1->setQuery("select idC from Conge");
                 ui->comboBox_suppC->setModel(model1);//supp Conge
                 ui->comboBox_mC->setModel(model1);//modif congé

                 ui->comboBox_RC->setModel(model1);//RECH CONGE


     QMessageBox::information(nullptr, QObject::tr("Supprimer un conge"),
                 QObject::tr("congé supprimé.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Supprimer un congé"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


 }




 void Dialogprofils::on_pb_modifierc_clicked()
 {
     int idC = ui->lineEdit_rmc_2->text().toInt();
     int  id = ui->comboBox2->currentText().toInt();
     QString dated_nv = ui->dateEdit_nvdd->date().toString();
     QString datef_nv = ui->dateEdit_nvdf->date().toString();

     //QString  idC1 = ui->lineEdit_idc->text();
     //QString verifdated= ui->dateEdit_1->date().toString();
     //QString verifdatef= ui->dateEdit_2->date().toString();
     //QString verifidp= ui->comboBox1->currentText();




   Conge C1 (idC,id,dated_nv,datef_nv);
   bool test=C1.modifier(idC,id,dated_nv,datef_nv);
    // bool test=tmpconge.modifier(idC,id,dated_nv,datef_nv);
   if(test)
 {ui->tabconge->setModel(tmpconge.afficher());//refresh
  ui->tabcong_modif->setModel(tmpconge.afficher());//refresh
  QSqlQueryModel *model = new QSqlQueryModel();
             model->setQuery("select id from Profils");
                 ui->comboBox1->setModel(model);


 QMessageBox::information(nullptr, QObject::tr("Ajouter un conge"),
                   QObject::tr("congé modifié.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
           else
                   {
               QMessageBox::critical(nullptr, QObject::tr("modifier un Congé"),
                           QObject::tr("Erreur !.\n"
                                       "Click Cancel to exit."), QMessageBox::Cancel);}

 }



 void Dialogprofils::on_pb_rechmc_clicked()
 {
       ui->tabcong_modif->setModel(tmpconge.rechercher( ui->comboBox_mC->currentText().toInt()));
       if( ui->comboBox_mC->currentText().isEmpty())


                ui->tabcong_modif->setModel(tmpconge.afficher());
 }





 void Dialogprofils::on_pb_rechc_clicked()
     {
   ui->tabconge->setModel(tmpconge.rechercher( ui->comboBox_RC->currentText().toInt()));
   if( ui->comboBox_RC->currentText().isEmpty())


    ui->tabconge->setModel(tmpconge.afficher());
      }




















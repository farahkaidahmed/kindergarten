#ifndef DIALOGPROFILS_H
#define DIALOGPROFILS_H
#include "profils.h"
#include "conge.h"



#include <QDialog>

namespace Ui {
class Dialogprofils;
}

class Dialogprofils : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogprofils(QWidget *parent = nullptr);
    ~Dialogprofils();
private slots:

    void on_pb_ajouter_clicked();
    void on_pb_supprimer_clicked();
    void on_pb_modifier_clicked();
    void on_pb_rech_clicked();
    void on_pb_rechm_clicked();
    void on_pb_trip_clicked();



     void on_pb_ajouterc_clicked();

     void on_pb_suppc_clicked();
     void on_pb_modifierc_clicked();
     void on_pb_rechc_clicked();
     void on_pb_rechmc_clicked();


private:
    Ui::Dialogprofils *ui;
    Profils tmpprofils;
    Conge tmpconge;
};

#endif // DIALOGPROFILS_H

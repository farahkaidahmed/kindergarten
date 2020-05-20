#ifndef GESTION_MENU_UI_H
#define GESTION_MENU_UI_H

#include <QDialog>

namespace Ui {
class gestion_menu_ui;
}

class gestion_menu_ui : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_menu_ui(QWidget *parent = nullptr);
    ~gestion_menu_ui();

private slots:
    void on_ajout_menu_clicked();





    void on_pushButton_clicked();


    void on_recherche_afficher_cursorPositionChanged(int arg1, int arg2);

    void on_combo_currentIndexChanged(const QString &arg1);



    void on_recherche_afficher_2_textChanged(const QString &arg1);

    void on_jour_currentChanged(int index);


    void on_supprimer_22_clicked();

    void on_supprimermenu_activated(const QModelIndex &index);

    void on_recherche_afficher_6_textChanged(const QString &arg1);

    void on_modifier_3_activated(const QModelIndex &index);

    void on_modifier_4_clicked();

    void on_pushButton_3_clicked();

    void on_combo_editTextChanged(const QString &arg1);

    void on_combo_activated(int index);

private:

    Ui::gestion_menu_ui *ui;
protected:
   // void paintEvent(QPaintEvent *);
};

#endif // GESTION_MENU_UI_H

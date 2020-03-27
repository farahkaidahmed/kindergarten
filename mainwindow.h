#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "club.h"
#include "salle.h"
#include <QMainWindow>

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
    //void on_pushButton_1_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_ajouter_s_clicked();

    void on_pb_supprimer_s_clicked();

private:
    Ui::MainWindow *ui/*,*ui_s*/;
    club tmpclub;
    salle tmpsalle;

};

#endif // MAINWINDOW_H

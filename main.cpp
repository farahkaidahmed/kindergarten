#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connexion.h"
#include "dialogclasse.h"
#include <QtGui>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;

 Dialog Dialog;
    Dialog.show();

    Connexion c;
    //w.show();
    bool test=c.ouvrirConnexion();

    if(test)
    {
        //w.show();
        //ww.setModal(true);

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    return a.exec();
}




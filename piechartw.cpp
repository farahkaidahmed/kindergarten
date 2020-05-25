#include "piechartw.h"
#include <QDebug>
#include "connexion.h"
//#include <QSqlQuery>
#include <QtSql/QSqlQuery>
#include <QPainter>
#include "classe.h"

pieChartw::pieChartw(QWidget *parent) :
QWidget(parent)
{

}

void pieChartw::paintEvent(QPaintEvent *)
{


        Classe tmpClasse;
        QPainter painter (this);
        QRectF size = QRectF(5,5, this->width()-10,this->width()-10);

        int plus = tmpClasse.stat_salle();
        //moins= ((moins * 360) / 100);
        painter.setBrush(Qt::green);
        painter.drawPie(/*size, 0, (moins*16)*/  size, 0,((plus*36)/10)*16 );

       }

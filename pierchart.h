#include "piechartw.h"
#include <QDebug>
#include "connexion.h"
//#include <QSqlQuery>
#include <QtSql/QSqlQuery>
#include <QPainter>
#include "club.h"

pieChartw::pieChartw(QWidget *parent) :
QWidget(parent)
{

}

void pieChartw::paintEvent(QPaintEvent *)
{


      classe tmpcClasse;
        QPainter painter (this);
        QRectF size = QRectF(5,5, this->width()-10,this->width()-10);

        int moins = tmpclub.stat_moins();
        //moins= ((moins * 360) / 100);
        painter.setBrush(Qt::green);
        painter.drawPie(/*size, 0, (moins*16)*/  size, 0,((moins*36)/10)*16 );

        //int plus = tmpclub.stat_plus();
        //plus= ((plus * 360) / 100);
        painter.setBrush(Qt::yellow);
        painter.drawPie(/*size, ((360-plus)*16),(plus*16)*/ size,((moins*36)/10)*16,(360-((moins*36)/10))*16  );







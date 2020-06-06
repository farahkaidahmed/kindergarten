#include "piechart1.h"

#include "profils.h"
#include "dialogprofils.h"
#include <QPainter>

piechart1::piechart1(QWidget *parent):
     QWidget(parent)
{

}

void piechart1::paintEvent(QPaintEvent *)
{   Profils tmpprofils;
    QPainter painter (this);
    QRectF size = QRectF(5,5, this->width()-10,this->width()-10);

   int moins = tmpprofils.stat_moins();
    painter.setBrush(Qt::green);
    painter.drawPie(size, 0, ((moins*36)/10)*16);


    painter.setBrush(Qt::yellow);
    painter.drawPie(size, ((moins*36)/10)*16,(360-((moins*36)/10))*16);

}

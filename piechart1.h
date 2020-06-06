#ifndef PIECHART1_H
#define PIECHART1_H

#include <QWidget>

class piechart1: public QWidget
{ Q_OBJECT
public:
    explicit piechart1(QWidget *parent = 0);
     void paintEvent(QPaintEvent *);
signals:

public slots:
};

#endif // PIECHART1_H



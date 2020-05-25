#ifndef PIECHARTW_H
#define PIECHARTW_H

#include <QWidget>

class pieChartw : public QWidget
{
    Q_OBJECT
public:
    explicit pieChartw(QWidget *parent = 0);
protected:
    void paintEvent(QPaintEvent *);
signals :

public slots :

};

#endif // PIECHARTW_H

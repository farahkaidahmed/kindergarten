#ifndef GESTION_MENU_H
#define GESTION_MENU_H

#include <QDialog>

namespace Ui {
class gestion_menu;
}

class gestion_menu : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_menu(QWidget *parent = nullptr);
    ~gestion_menu();

private:
    Ui::gestion_menu *ui;
};

#endif // GESTION_MENU_H

#include "gestion_menu.h"
#include "ui_gestion_menu.h"

gestion_menu::gestion_menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_menu)
{
    ui->setupUi(this);
}

gestion_menu::~gestion_menu()
{
    delete ui;
}

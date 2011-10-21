#include "ft_widget.h"
#include "ui_ft_widget.h"

ft_widget::ft_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ft_widget)
{
    ui->setupUi(this);
}

ft_widget::~ft_widget()
{
    delete ui;
}

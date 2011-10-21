#ifndef FT_WIDGET_H
#define FT_WIDGET_H

#include <QWidget>
#include "ui_ft_widget.h"

class ft_widget : public QWidget, public Ui::ft_widget
{
    Q_OBJECT

public:
    explicit ft_widget(QWidget *parent = 0);
    ~ft_widget();

    void setPourcentage(int pourcentage) { progression_transfert->setValue(pourcentage);}
    void setVitesse(int vitesse) { vitesse_dl->display(vitesse);}
private slots:
    void on_pause_b_clicked() { emit pause(); }
    void on_annuler_b_clicked() { emit annulation(); }
signals:
    void pause();
    void annulation();
};

#endif // FT_WIDGET_H

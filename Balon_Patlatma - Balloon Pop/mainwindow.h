#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "baluunbatlatma.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:


    void ButonCagirma(int satir);
    void saklagards();
    void balonindir();
    void donusurek();


private:
    Ui::MainWindow *ui;


    QList <baluunbatlatma*> grkltus;
    QList<baluunbatlatma*> yuvo;

};
#endif // MAINWINDOW_H

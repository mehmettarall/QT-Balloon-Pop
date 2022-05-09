#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QPushButton>
#include <QRandomGenerator>


int surearttirma = 0;
int blnsure = 2;
int ulekacir = 0;
int bumbe = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->showMaximized();

    QString m = QString::number(surearttirma);
    ui->gerisayim->setText(m);

    QTimer *timerartici = new QTimer(this);
    connect(timerartici, SIGNAL(timeout()), this, SLOT(donusurek()));
    timerartici->start(1000);

    QTimer *timerdelayli = new QTimer;
    connect(timerdelayli, SIGNAL(timeout()), this, SLOT(saklagards()));
    timerdelayli->start(2000);

}

void MainWindow::ButonCagirma(int satir)
{
    baluunbatlatma *kdm_tus = new baluunbatlatma(this);
    kdm_tus->setGeometry(satir,115,62,62);
    grkltus.push_back(kdm_tus);

    int p =  QRandomGenerator::global()->bounded(0,7);

    switch(p)
    {
        case 0:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/0.jpg);");
        break;

        case 1:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/1.jpg);");
        break;

        case 2:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/2.jpg);");
        break;

        case 3:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/3.jpg);");
        break;

        case 4:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/4.jpg);");
        break;

        case 5:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/5.jpg);");
        break;

        case 6:
        kdm_tus->setStyleSheet("border-image:url(:/dosyalar/images/6.jpg);");
        break;

    }

    kdm_tus->show();

}

void MainWindow::donusurek()
{
    surearttirma +=1;
    blnsure +=1;
    balonindir();
    if(blnsure % 3 == 0)
    {
        int p =  QRandomGenerator::global()->bounded(10,1000);
        ButonCagirma(p);
    }
    QString p = QString::number(surearttirma);
    ui->gerisayim->setText(p);

}


void MainWindow::balonindir()
{
    int sayisi = grkltus.size();
    for (int i = 0; i < sayisi; ++i)
    {
        if(grkltus[i])
        {

            grkltus[i]->setGeometry(grkltus[i]->x(),grkltus[i]->y()+30,grkltus[i]->width(),grkltus[i]->height());

            if(grkltus[i]->dgdm)
            {
                grkltus[i]->setStyleSheet("border-image:url(:/dosyalar/images/patlama.jpg);");
                bumbe +=1;
                QString d = QString::number(bumbe);
                ui->olenbalon->setText(d);
                grkltus[i]->dgdm = false;
                yuvo.push_back(grkltus[i]);
            }

            if(grkltus[i]->y() > 925)
            {
                if(grkltus[i]->deletemrq == 0)
                {
                    ulekacir+=1;
                    QString b = QString::number(ulekacir);
                    ui->yasayanbalon->setText(b);
                    grkltus[i]->hide();
                    grkltus[i]->deletemrq = 1;

                }
            }
        }
    }
}


void MainWindow::saklagards()
{
    int sayisi = yuvo.size();
    for (int i = 0; i < sayisi; ++i)
    {
        if(yuvo[i]->kontrol == 1)
            {
                yuvo[i]->hide();
                yuvo[i]->kontrol = 0;
            }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}





#include "baluunbatlatma.h"

baluunbatlatma::baluunbatlatma(QWidget *parent) :
    QPushButton(parent)
{
    dgdm = false;
    kontrol = 1;
    deletemrq = 0;
    connect(this,SIGNAL(clicked()),this,SLOT(dokunus()));
}

void baluunbatlatma::dlte()
{
    deletemrq = 0;
}

void baluunbatlatma::bumbum()
{
    kontrol = 0;
}

void baluunbatlatma::dokunus()
{
    dgdm = !dgdm;
}

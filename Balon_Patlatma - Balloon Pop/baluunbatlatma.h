#ifndef BALUUNBATLATMA_H
#define BALUUNBATLATMA_H

#include <QPushButton>
#include <QObject>
#include <QWidget>

class baluunbatlatma : public QPushButton
{
    Q_OBJECT

public:
    baluunbatlatma();
    int deletemrq;
    int kontrol;
    explicit baluunbatlatma(QWidget *parent = 0);
    bool dgdm;

signals:


public slots:

    void dlte();
    void bumbum();
    void dokunus();

};

#endif // BALONOLUSTURMA_H






#include "widget.h"
#include"drawwidget.h"
#include <QGroupBox>
#include <QPushButton>
#include <QDebug>
#include <QLayout>
#include <QPainter>
#include <QPixmap>
#include <QIcon>


//void widget::paintEvent(QPaintEvent *event)
//{
 //QPainter painter(this);
 //painter.drawPixmap(0,0,400,700,QPixmap(":/user"));
//}

widget::widget(QWidget *parent) : QWidget(parent)
{
    dra=new DrawWidget;
    group = new QGroupBox(this);
    group->setTitle(tr("选则图片"));
    setWindowTitle(tr("picture"));
    QPixmap pixmap(20, 20);
    first=new QPushButton(group);
    pixmap.fill(BACKGROUND_COLOR);
    QPainter painter(&pixmap);
    QImage image1(":/user");
    QRect targetRect1(0,0,20,20);
    QRect sourceRect1 =image1.rect();
    painter.drawImage(targetRect1,image1,sourceRect1);
    first->setIcon(QIcon(pixmap));
    first->setToolTip(tr("选择图片"));
    //connect(first,&QPushButton::clicked,dra,&DrawWidget::setPicture());

    sec=new QPushButton(group);
    pixmap.fill(BACKGROUND_COLOR);
    QImage image2(":/res/png/t0115e58067ce5e097b.jpg");
    QRect targetRect2(0,0,20,20);
    QRect sourceRect2 =image2.rect();
    painter.drawImage(targetRect2,image2,sourceRect2);
    sec->setIcon(QIcon(pixmap));
    sec->setToolTip(tr("选择图片"));

    thir=new QPushButton(group);
    pixmap.fill(BACKGROUND_COLOR);
    //QPainter painter(&pixmap);
    QImage image3(":/res/png/t01510744f32a73a702.jpg");
    QRect targetRect3(0,0,20,20);
    QRect sourceRect3 =image3.rect();
    painter.drawImage(targetRect3,image3,sourceRect3);
    thir->setIcon(QIcon(pixmap));
    thir->setToolTip(tr("选择图片"));

    four= new QPushButton(group);
    pixmap.fill(BACKGROUND_COLOR);
    //QPainter painter(&pixmap);
    QImage image4(":/res/png/t016a2ffcd60da5308e.jpg");
    QRect targetRect4(0,0,20,20);
    QRect sourceRect4 =image4.rect();
    painter.drawImage(targetRect4,image4,sourceRect4);
    four->setIcon(QIcon(pixmap));
    four->setToolTip(tr("选择图片"));
    QGridLayout *gridLayout = new QGridLayout();
     gridLayout->addWidget(first,0,0);
     gridLayout->addWidget(sec,0,1);
     gridLayout->addWidget(thir,1,0);
     gridLayout->addWidget(four,1,1);

    gridLayout->setMargin(3);
    gridLayout->setSpacing(3);
    group->setLayout(gridLayout);

}

widget::~widget()
{}

void widget::showEvent()
{
    a=new widget;

    a->show();

}

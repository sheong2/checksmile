#include "videodialog.h"
#include "playingdialog.h"
#include "ui_videodialog.h"
#include <qdir.h>
#include <QImage>              //QImage를 사용하기 위한 라이브러리
#include <QPixmap>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QSize>
#include <stdio.h>
#define lb(j) label_##j
#define btn(j) pushButton_##j
int PG;//현재페이지 (1,7,13 등등)
int a;//서버에서 보낼 영상 개수
int N;

VideoDialog::VideoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoDialog)
{

    ui->setupUi(this);
    QDir directory("/mnt/nfs/videothum");
    count= directory.count();

    a=13;
    N=a;
    PG=1;

    showlist();

}
void VideoDialog::showlist()
{
    char i='0';
    char title[]="/mnt/nfs/videothum/tn0.png";

    if (PG+6<=N) ui->rightbutton->setVisible(true);
    else ui->rightbutton->setVisible(false);
    if (PG-6>0) ui->leftbutton->setVisible(true);
    else ui->leftbutton->setVisible(false);

    vtitle="running man";

    ui->lb(1)->setText(vtitle);
    ui->lb(2)->setText(vtitle);
    ui->lb(3)->setText(vtitle);
    ui->lb(4)->setText(vtitle);
    ui->lb(5)->setText(vtitle);


    if (a-->0)
       {title[21]=i++;
       ui->btn(1)->setIcon(QIcon(title));
       ui->btn(1)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(1)->setVisible(false);
        ui->lb(1)->setVisible(false);

    }
    if (a-->0)
       {title[21]=i++;
       ui->btn(2)->setIcon(QIcon(title));
       ui->btn(2)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(2)->setVisible(false);
        ui->lb(2)->setVisible(false);

    }
    if (a-->0)
       {title[21]=i++;
       ui->btn(3)->setIcon(QIcon(title));
       ui->btn(3)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(3)->setVisible(false);
        ui->lb(3)->setVisible(false);

    }
    if (a-->0)
       {title[21]=i++;
       ui->btn(4)->setIcon(QIcon(title));
       ui->btn(4)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(4)->setVisible(false);
        ui->lb(4)->setVisible(false);

    }
    if (a-->0)
       {title[21]=i++;
       ui->btn(5)->setIcon(QIcon(title));
       ui->btn(5)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(5)->setVisible(false);
        ui->lb(5)->setVisible(false);

    }
    if (a-->0)
       {title[21]=i++;
       ui->btn(6)->setIcon(QIcon(title));
       ui->btn(6)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(6)->setVisible(false);
        ui->lb(6)->setVisible(false);

    }
    ui->lb(6)->setText(vtitle);

}

VideoDialog::~VideoDialog()
{
    delete ui;
}

void VideoDialog::on_rightbutton_clicked()
{
    PG+=6;
    showlist();
}

void VideoDialog::on_leftbutton_clicked()
{
    PG-=6;
    showlist();
}

void VideoDialog::on_pushButton_1_clicked()
{
    PlayingDialog dlg(0);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

void VideoDialog::on_pushButton_2_clicked()
{
    PlayingDialog dlg(1);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

void VideoDialog::on_pushButton_3_clicked()
{
    PlayingDialog dlg(21);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

void VideoDialog::on_pushButton_4_clicked()
{
    PlayingDialog dlg(3);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

void VideoDialog::on_pushButton_5_clicked()
{
    PlayingDialog dlg(4);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

void VideoDialog::on_pushButton_6_clicked()
{
    PlayingDialog dlg(5);
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
}

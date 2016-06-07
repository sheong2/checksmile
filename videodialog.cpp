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
    ui->verticalScrollBar->setMinimum(1);

    a=13;
    N=a;
    PG=1;

    on_WatchingTab_clicked();
}

void VideoDialog::showlist()
{
    char i='0';
    char title[]="/mnt/nfs/test_contents/tn000.png";

    ui->lb(1)->setText(name1);
    ui->lb(2)->setText(name2);
    ui->lb(3)->setText(name3);
    ui->lb(4)->setText(name4);
    ui->lb(5)->setText(name5);
    ui->lb(6)->setText(name6);

    if (id1[0])
    {
       title[25]=id1[0];
       title[26]=id1[1];
       title[27]=id1[2];
       ui->btn(1)->setIcon(QIcon(title));
       ui->btn(1)->setIconSize( QSize(213,160) );
    }
    else
    {
        ui->btn(1)->setVisible(false);
        ui->lb(1)->setVisible(false);

    }
    if (id2[0])
    {
        title[25]=id2[0];
        title[26]=id2[1];
        title[27]=id2[2];
        ui->btn(2)->setIcon(QIcon(title));
        ui->btn(2)->setIconSize( QSize(213,160) );
    }
    else
    {
        ui->btn(2)->setVisible(false);
        ui->lb(2)->setVisible(false);

    }
    if (id3[0])
    {
        title[25]=id3[0];
        title[26]=id3[1];
        title[27]=id3[2];
       ui->btn(3)->setIcon(QIcon(title));
       ui->btn(3)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(3)->setVisible(false);
        ui->lb(3)->setVisible(false);

    }
    if (id4[0])
    {
        title[25]=id4[0];
        title[26]=id4[1];
        title[27]=id4[2];
       ui->btn(4)->setIcon(QIcon(title));
       ui->btn(4)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(4)->setVisible(false);
        ui->lb(4)->setVisible(false);

    }
    if (id5[0])
    {
        title[25]=id5[0];
        title[26]=id5[1];
        title[27]=id5[2];
       ui->btn(5)->setIcon(QIcon(title));
       ui->btn(5)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(5)->setVisible(false);
        ui->lb(5)->setVisible(false);

    }
    if (id6[0])
   {
        title[25]=id6[0];
        title[26]=id6[1];
        title[27]=id6[2];
       ui->btn(6)->setIcon(QIcon(title));
       ui->btn(6)->setIconSize( QSize(213,160) );}
    else
    {
        ui->btn(6)->setVisible(false);
        ui->lb(6)->setVisible(false);

    }
}

VideoDialog::~VideoDialog()
{
    delete ui;
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
    PlayingDialog dlg(2);
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

void VideoDialog::on_WatchingTab_clicked()
{
    ui->WatchingTab->setChecked(true);
    ui->HistoryTab->setChecked(false);
    ui->SuggestTab->setChecked(false);

    //udp 통신으로 "WR001" 보내기
    //udp 통신으로 전체 페이지 갯수, 6개 ID, 제목 6개 받아오기

    maxpage = 5;//char 배열 바꾸기
    readydata();

    ui->verticalScrollBar->setMaximum(maxpage);
    ui->verticalScrollBar->setSliderPosition(1);

    PG=1;
    showlist();
}

void VideoDialog::on_verticalScrollBar_sliderReleased()
{
    PG = ui->verticalScrollBar->sliderPosition();
    //영상 id 요청 영상 id 6개 받아서 썸네일 출력
    readydata();
    showlist();
}

void VideoDialog::readydata()
{
    id1[0] = id2[0] = id3[0] = id4[0] = id5[0] = id6[0] = '0';
    id1[1] = id2[1] = id3[1] = id4[1] = id5[1] = id6[1] = '0';
    id1[2] = '1';
    id2[2] = '2';
    id3[2] = '3';
    id4[2] = '4';
    id5[2] = '5';
    id6[2] = '6';
    name1 = "happyTogether";
    name2 = "runningman";
    name3 = "joseho";
    name4 = "1bak2il";
    name5 = "happyTogether2";
    name6 = "Comedy";
}

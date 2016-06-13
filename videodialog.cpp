#include "videodialog.h"
#include "playingdialog.h"
#include "ui_videodialog.h"
#include "mainwindow.h"
#include <qdir.h>
#include <QImage>              //QImage를 사용하기 위한 라이브러리
#include <QPixmap>
#include <QStackedWidget>
#include <QStackedLayout>
#include <QSize>
#include <stdio.h>
#include "mylineedit.h"
#include <QMouseEvent>
#include "rcvthread.h"
#define lb(j) label_##j
#define btn(j) pushButton_##j
int PG;//현재페이지 (1,7,13 등등)
int a;//서버에서 보낼 영상 개수
int N;

VideoDialog::VideoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoDialog)
{
    printf("came Vddlg\n");
    ui->setupUi(this);
    vidkeyboard = ui->keyboard;
    ui->verticalScrollBar->setMinimum(1);
    ui->dockWidget->hide();


    connect(ui->SearchLine, SIGNAL(pressed()), this, SLOT(got_sig_from_searchline()));
}

void VideoDialog::got_sig_from_searchline()
{
    if(ui->dockWidget->isHidden()) ui->dockWidget->show();
    vidkeyboard->setinputbox(ui->SearchLine, ui->SearchLine->cursorPosition());
}

void VideoDialog::init(QString id)
{
    printf("init viddlg\n");
    tab = "W";
    subtab = "R";
    page = "001";
    ui->UserID->setText(id);
    send_data("w");
}

void VideoDialog::showlist()
{
    char title[]="/mnt/nfs/test_contents/tn000.png";

    ui->lb(1)->setText(name1);
    ui->lb(2)->setText(name2);
    ui->lb(3)->setText(name3);
    ui->lb(4)->setText(name4);
    ui->lb(5)->setText(name5);
    ui->lb(6)->setText(name6);

    ui->LabelTime1->setText(time1);
    ui->LabelTime2->setText(time2);
    ui->LabelTime3->setText(time3);
    ui->LabelTime4->setText(time4);
    ui->LabelTime5->setText(time5);
    ui->LabelTime6->setText(time6);

    if (id1[0])
    {
       title[25]=id1[0];
       title[26]=id1[1];
       title[27]=id1[2];
       ui->btn(1)->setIcon(QIcon(title));
       ui->btn(1)->setIconSize( QSize(213,160) );
       ui->btn(1)->show();
       ui->lb(1)->show();
    }
    else
    {
        ui->btn(1)->hide();
        ui->LabelTime1->setText(NULL);
        ui->lb(1)->setText(NULL);

    }
    if (id2[0])
    {
        title[25]=id2[0];
        title[26]=id2[1];
        title[27]=id2[2];
        ui->btn(2)->setIcon(QIcon(title));
        ui->btn(2)->setIconSize( QSize(213,160) );
        ui->btn(2)->show();
        ui->lb(2)->show();
    }
    else
    {
        ui->btn(2)->hide();
        ui->LabelTime2->setText(NULL);
        ui->lb(2)->setText(NULL);

    }
    if (id3[0])
    {
        title[25]=id3[0];
        title[26]=id3[1];
        title[27]=id3[2];
       ui->btn(3)->setIcon(QIcon(title));
       ui->btn(3)->setIconSize( QSize(213,160) );
       ui->btn(3)->show();
       ui->lb(3)->show();
    }
    else
    {
        ui->btn(3)->hide();
        ui->LabelTime3->setText(NULL);
        ui->lb(3)->setText(NULL);

    }
    if (id4[0])
    {
        title[25]=id4[0];
        title[26]=id4[1];
        title[27]=id4[2];
       ui->btn(4)->setIcon(QIcon(title));
       ui->btn(4)->setIconSize( QSize(213,160) );
       ui->btn(4)->show();
       ui->lb(4)->show();
    }
    else
    {
        ui->btn(4)->hide();
        ui->LabelTime4->setText(NULL);
        ui->lb(4)->setText(NULL);

    }
    if (id5[0])
    {
        title[25]=id5[0];
        title[26]=id5[1];
        title[27]=id5[2];
       ui->btn(5)->setIcon(QIcon(title));
       ui->btn(5)->setIconSize( QSize(213,160) );
       ui->btn(5)->show();
       ui->lb(5)->show();
    }
    else
    {
        ui->btn(5)->hide();
        ui->LabelTime5->setText(NULL);
        ui->lb(5)->setText(NULL);
    }
    if (id6[0])
   {
        title[25]=id6[0];
        title[26]=id6[1];
        title[27]=id6[2];
       ui->btn(6)->setIcon(QIcon(title));
       ui->btn(6)->setIconSize( QSize(213,160) );
       ui->btn(6)->show();
       ui->lb(6)->show();
    }
    else
    {
        ui->btn(6)->hide();
        ui->LabelTime6->setText(NULL);
        ui->lb(6)->setText(NULL);
    }
}

VideoDialog::~VideoDialog()
{
    printf("bye viddlg\n");
    delete ui;
}

void VideoDialog::on_pushButton_1_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id1);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id1.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::on_pushButton_2_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id2);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id2.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::on_pushButton_3_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id3);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id3.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::on_pushButton_4_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id4);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id4.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::on_pushButton_5_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id5);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id5.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::on_pushButton_6_clicked()
{
    cam = new CaptureThread;
    cam->start();

    QByteArray datagram;
    datagram.append("P").append(id6);
    printf("%s\n", datagram.data());
    send_data(datagram);

    PlayingDialog dlg(id6.data());
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    send_data("fend");
}

void VideoDialog::set_tab(int maxpage)
{
    ui->verticalScrollBar->setMaximum(maxpage);
    ui->verticalScrollBar->setSliderPosition(1);

    on_verticalScrollBar_sliderReleased();
}

void VideoDialog::on_subtab1_clicked()
{
    if(ui->WatchingTab->isChecked()) on_recentTab_clicked();
    else if(ui->HistoryTab->isChecked()) on_HistoryTab_clicked();
}

void VideoDialog::on_subtab2_clicked()
{
    if(ui->WatchingTab->isChecked()) on_bookmarkTab_clicked();
    else if(ui->HistoryTab->isChecked()) on_AlreadyTab_clicked();
}

void VideoDialog::on_subtab3_clicked()
{
    on_viewTab_clicked();
}

void VideoDialog::on_recentTab_clicked()
{
    ui->subtab1->setChecked(true);
    ui->subtab2->setChecked(false);
    ui->subtab3->setChecked(false);
    ui->verticalScrollBar->setSliderPosition(1);
    subtab = "R";

    on_verticalScrollBar_sliderReleased();
}

void VideoDialog::on_bookmarkTab_clicked()
{
    ui->subtab1->setChecked(false);
    ui->subtab2->setChecked(true);
    ui->subtab3->setChecked(false);
    ui->verticalScrollBar->setSliderPosition(1);
    subtab = "B";

    on_verticalScrollBar_sliderReleased();
}

void VideoDialog::on_viewTab_clicked()
{
    ui->subtab1->setChecked(false);
    ui->subtab2->setChecked(false);
    ui->subtab3->setChecked(true);
    ui->verticalScrollBar->setSliderPosition(1);
    subtab = "V";

    on_verticalScrollBar_sliderReleased();
}

void VideoDialog::on_WatchingTab_clicked()
{
    printf("watching tab\n");
    ui->HistoryTab->setChecked(false);
    ui->SuggestTab->setChecked(false);
    ui->WatchingTab->setChecked(true);

    ui->subtab1->show();
    ui->subtab2->show();
    ui->subtab3->show();

    ui->subtab1->setChecked(true);
    ui->subtab2->setChecked(false);
    ui->subtab3->setChecked(false);

    ui->subtab1->setText("recent");
    ui->subtab2->setText("bookmark");
    ui->subtab3->setText("view");

    tab = "W";
    subtab = "R";

    send_data("w");
}

void VideoDialog::on_HistoryTab_clicked()
{
    ui->WatchingTab->setChecked(false);
    ui->SuggestTab->setChecked(false);
    ui->HistoryTab->setChecked(true);

    ui->subtab1->show();
    ui->subtab2->show();
    ui->subtab3->hide();

    ui->subtab1->setChecked(true);
    ui->subtab2->setChecked(false);

    ui->subtab1->setText("bookmark");
    ui->subtab2->setText("video");

    tab = "H";
    subtab.clear();

    send_data("h");
}

void VideoDialog::on_AlreadyTab_clicked()
{
    ui->WatchingTab->setChecked(false);
    ui->SuggestTab->setChecked(false);
    ui->HistoryTab->setChecked(true);

    ui->subtab1->show();
    ui->subtab2->show();
    ui->subtab3->hide();

    ui->subtab1->setChecked(false);
    ui->subtab2->setChecked(true);

    ui->subtab1->setText("bookmark");
    ui->subtab2->setText("video");

    tab = "A";
    subtab.clear();

    send_data("a");
}

void VideoDialog::on_SuggestTab_clicked()
{
    ui->WatchingTab->setChecked(false);
    ui->HistoryTab->setChecked(false);
    ui->SuggestTab->setChecked(true);

    ui->subtab1->hide();
    ui->subtab2->hide();
    ui->subtab3->hide();

    tab = "S";
    subtab.clear();

    send_data("s");
}

void VideoDialog::on_verticalScrollBar_sliderReleased()
{
    QByteArray datagram;

   page = QByteArray::number(ui->verticalScrollBar->sliderPosition());
   page.prepend("000");
   page = page.right(3);

    datagram.append(tab).append(subtab).append(page);

    send_data(datagram);
    //udp : 현재탭, 기준, 페이지 전송
}

void VideoDialog::readydata(QByteArray datagram)
{
    int find;
    int cnt = datagram.count('@');
    printf("cnt : %d\n", cnt);

    id1 = id2 = id3 = id4 = id5 = id6 = NULL;

    if(cnt>=1) id1 = datagram.mid(1, 3);
    if(cnt>=2) id2 = datagram.mid(4, 3);
    if(cnt>=3) id3 = datagram.mid(7, 3);
    if(cnt>=4) id4 = datagram.mid(10, 3);
    if(cnt>=5) id5 = datagram.mid(13, 3);
    if(cnt>=6) id6 = datagram.mid(16, 3);

    if(cnt>=1) time1 = datagram.mid(19, 4).insert(2, ':');
    if(cnt>=2) time2 = datagram.mid(23, 4).insert(2, ':');
    if(cnt>=3) time3 = datagram.mid(27, 4).insert(2, ':');
    if(cnt>=4) time4 = datagram.mid(31, 4).insert(2, ':');
    if(cnt>=5) time5 = datagram.mid(35, 4).insert(2, ':');
    if(cnt>=6) time6 = datagram.mid(39, 4).insert(2, ':');

    datagram = datagram.mid(43);
    if(cnt>=1)
    {
        find = datagram.indexOf('@', 0);
        name1 = datagram.left(find);
        datagram = datagram.mid(find+1);
    }
    if(cnt>=2)
    {
        find = datagram.indexOf('@', 0);
        name2 =  datagram.left(find);
        datagram = datagram.mid(find+1);
    }
    if(cnt>=3)
    {
        find = datagram.indexOf('@', 0);
        name3 =  datagram.left(find);
        datagram = datagram.mid(find+1);
    }
    if(cnt>=4)
    {
        find = datagram.indexOf('@', 0);
        name4 =  datagram.left(find);
        datagram = datagram.mid(find+1);
    }
    if(cnt>=5)
    {
        find = datagram.indexOf('@', 0);
        name5 =  datagram.left(find);
        datagram = datagram.mid(find+1);
    }
    if(cnt>=6)
    {
        find = datagram.indexOf('@', 0);
        name6 =  datagram.left(find);
        datagram = datagram.mid(find+1);
    }

    showlist();
}

void VideoDialog::mousePressEvent(QMouseEvent *e)
{
    ui->dockWidget->hide();
}

void VideoDialog::on_logoutButton_clicked()
{
    close();
}

void VideoDialog::on_SearchButton_clicked()
{
    QByteArray datagram;
    datagram.append('Q').append(tab).append(page).append(ui->SearchLine->text());
    send_data(datagram);

    ui->SearchLine->setText(NULL);
}

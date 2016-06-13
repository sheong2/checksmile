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
#include "mylineedit.h"
#include <QMouseEvent>
#include "capturethread.h"
#define lb(j) label_##j
#define btn(j) pushButton_##j
int PG;//현재페이지 (1,7,13 등등)
int a;//서버에서 보낼 영상 개수
int N;

extern QString userid;

VideoDialog::VideoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VideoDialog)
{
    ui->setupUi(this);
    ui->verticalScrollBar->setMinimum(1);
    ui->dockWidget->hide();
    ui->UserID->setText(userid);
    connect(ui->SearchLine, SIGNAL(pressed()), this, SLOT(got_sig_from_searchline()));
    on_WatchingTab_clicked();
}

void VideoDialog::got_sig_from_searchline()
{
    ui->dockWidget->show();
    cursor=ui->SearchLine->cursorPosition();
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
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id1);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
    //cam->terminate();
}

void VideoDialog::on_pushButton_2_clicked()
{
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id2);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
}

void VideoDialog::on_pushButton_3_clicked()
{
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id3);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
}

void VideoDialog::on_pushButton_4_clicked()
{
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id4);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
}

void VideoDialog::on_pushButton_5_clicked()
{
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id5);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
}

void VideoDialog::on_pushButton_6_clicked()
{
    cam = new CaptureThread;
    cam->start();
    PlayingDialog dlg(id6);
    connect(&dlg,SIGNAL(stopclicked()),cam,SLOT(stopcapture()));
    connect(&dlg,SIGNAL(pauseclicked()),cam,SLOT(pausecapture()));
    connect(&dlg,SIGNAL(playclicked()),cam,SLOT(resumecapture()));
    connect(&dlg,SIGNAL(ffclicked()),cam,SLOT(ffpressed()));
    connect(&dlg,SIGNAL(rwclicked()),cam,SLOT(rwpressed()));
    dlg.setWindowFlags(Qt::FramelessWindowHint);
    dlg.exec();
    cam->quit();
}

void VideoDialog::on_WatchingTab_clicked()
{
    //udp 통신으로 "WR001" 보내기
    //udp 통신으로 전체 페이지 갯수, 6개 ID, 제목 6개 받아오기

    maxpage = 5;//char 배열 바꾸기
    readydata();

    ui->verticalScrollBar->setMaximum(maxpage);
    ui->verticalScrollBar->setSliderPosition(1);

    PG=1;
    showlist();

    ui->HistoryTab->setChecked(false);
    ui->SuggestTab->setChecked(false);
    ui->WatchingTab->setChecked(true);
}

void VideoDialog::on_HistoryTab_clicked()
{
    ui->WatchingTab->setChecked(false);
    ui->SuggestTab->setChecked(false);
    ui->HistoryTab->setChecked(true);
}

void VideoDialog::on_SuggestTab_clicked()
{
    ui->WatchingTab->setChecked(false);
    ui->HistoryTab->setChecked(false);
    ui->SuggestTab->setChecked(true);
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

void VideoDialog::mousePressEvent(QMouseEvent *e)
{
    ui->dockWidget->hide();
}

void VideoDialog::on_Button_HIDE_clicked()
{
    ui->dockWidget->hide();
}

void VideoDialog::on_Button_Q_clicked()
{
    char q[2] = {'q', 'Q'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
     cursor++;
}

void VideoDialog::on_Button_W_clicked()
{
    char q[2] = {'w', 'W'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_RESET_clicked()
{
    ui->SearchLine->text().clear();
    ui->SearchLine->setText(NULL);
    cursor=0;
}

void VideoDialog::on_Button_E_clicked()
{
    char q[2] = {'e', 'E'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
    cursor++;
}

void VideoDialog::on_Button_R_clicked()
{
    char q[2] = {'r', 'R'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
    cursor++;
}

void VideoDialog::on_Button_T_clicked()
{
    char q[2] = {'t', 'T'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
    cursor++;
}

void VideoDialog::on_Button_Y_clicked()
{
    char q[2] = {'y', 'Y'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_U_clicked()
{
    char q[2] = {'u', 'U'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_I_clicked()
{
    char q[2] = {'i', 'i'};
 ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_O_clicked()
{
    char q[2] = {'o', 'O'};
ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_P_clicked()
{
    char q[2] = {'p', 'P'};
 ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_Z_clicked()
{
    char q[2] = {'z', 'Z'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_X_clicked()
{
    char q[2] = {'x', 'X'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_C_clicked()
{
    char q[2] = {'c', 'C'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_V_clicked()
{
    char q[2] = {'v', 'V'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_B_clicked()
{
    char q[2] = {'b', 'B'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_N_clicked()
{
    char q[2] = {'n', 'N'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_M_clicked()
{
    char q[2] = {'m', 'M'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_DOT_clicked()
{
    char q[2] = {'.', ','};

   ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_question_clicked()
{
    char q[2] = {'?', '!'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}


void VideoDialog::on_Button_spacebar_clicked()
{
     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,' '));
        cursor++;
}

void VideoDialog::on_Button_enter_clicked()
{
    ui->dockWidget->hide();
}

void VideoDialog::on_Button_del_clicked()
{
     ui->SearchLine->setText(ui->SearchLine->text().remove(--cursor, 1));
}

void VideoDialog::on_Button_A_clicked()
{
    char q[2] = {'q', 'Q'};
    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_S_clicked()
{
    char q[2] = {'s', 'S'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_D_clicked()
{
    char q[2] = {'d', 'D'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_F_clicked()
{
    char q[2] = {'f', 'F'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_G_clicked()
{
    char q[2] = {'g', 'G'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_H_clicked()
{
    char q[2] = {'h', 'H'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_J_clicked()
{
    char q[2] = {'j', 'J'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_K_clicked()
{
    char q[2] = {'k', 'K'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_L_clicked()
{
    char q[2] = {'l', 'L'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_1_clicked()
{
    char q[2] = {'1', '1'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_2_clicked()
{
    char q[2] = {'2', '2'};

   ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_3_clicked()
{
    char q[2] = {'3', '3'};

   ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_4_clicked()
{
    char q[2] = {'4', '4'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_5_clicked()
{
    char q[2] = {'5', '5'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;
}

void VideoDialog::on_Button_6_clicked()
{
    char q[2] = {'6', '6'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_7_clicked()
{
    char q[2] = {'7', '7'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_8_clicked()
{
    char q[2] = {'8', '8'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_9_clicked()
{
    char q[2] = {'9', '9'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_0_clicked()
{
    char q[2] = {'0', '0'};

    ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_Button_bar_clicked()
{
    char q[2] = {'-', '_'};

     ui->SearchLine->setText(ui->SearchLine->text().insert(cursor,q[ui->Button_shift->isChecked()]));
        cursor++;

}

void VideoDialog::on_logoutButton_clicked()
{
    close();
}

#include "playingdialog.h"
#include "mainwindow.h"
#include "ui_playingdialog.h"
#include "capturethread.h"
#include <QFileDialog>
#include <QString>
#include <stdio.h>
#include <string.h>
#include <signal.h>
volatile int play_flag;
volatile int pause_flag;
volatile int end_flag;
void sigChldHandler(int signal);
void Display_Play_Menu(void);
char cmd[256];
//제목 넣는 것 바꾸기
char title[]="/mnt/nfs/test_contents/vid000.avi";


pid_t pid_temp;
PlayingDialog::PlayingDialog(char * id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayingDialog)
{
    ui->setupUi(this);
    if(pipe(fd_pipe)==-1)close();
    pause_flag=0;
    Display_Play_Menu();

    if(play_flag)return;
    play_flag=1;
    pid_temp=fork();
    if(pid_temp==-1)exit(-1);
    else if (pid_temp==0){
        ::close(0);
        dup(fd_pipe[0]);
        ::close(fd_pipe[0]);
        ::close(fd_pipe[1]);
        title[26]=id[0];
        title[27]=id[1];
        title[28]=id[2];

        execlp("/mnt/nfs/mplayer","mplayer","-vo", "fbdev2","-ss", "00:30", "-volume","1","-srate","44100", "-geometry", "50%:50%",title,NULL);
    }else{
        sighandler_t sig_ret;
        sig_ret=signal(SIGCHLD,sigChldHandler);
        if(sig_ret==SIG_ERR)exit(-1);
    }

}

void PlayingDialog::Display_Play_Menu(void){
    ui->BTN_Play->setIcon(QIcon(":/images/images/pause.png"));ui->BTN_Play->setIconSize(QSize(55,55));
    ui->BTN_RW->setIcon(QIcon(":/images/images/rw.png"));ui->BTN_RW->setIconSize(QSize(55,55));
    ui->BTN_FF->setIcon(QIcon(":/images/images/ff.png"));ui->BTN_FF->setIconSize(QSize(55,55));
    ui->BTN_Down->setIcon(QIcon(":/images/images/down.png"));ui->BTN_Down->setIconSize(QSize(55,55));
    ui->BTN_UP->setIcon(QIcon(":/images/images/up.png"));ui->BTN_UP->setIconSize(QSize(55,55));
    ui->BTN_Stop->setIcon(QIcon(":/images/images/stop.png"));ui->BTN_Stop->setIconSize(QSize(55,55));
}

void sigChldHandler(int signal)
{
    play_flag=0;
    printf("got signal %d\n", signal);
    end_flag=1;
}


PlayingDialog::~PlayingDialog()
{
    delete ui;
}

void PlayingDialog::on_BTN_Play_clicked()
{
    if(!play_flag){
        play_flag=1;
        pid_temp=fork();
        if(pid_temp==-1)exit(-1);
        else if (pid_temp==0){
            ::close(0);
            dup(fd_pipe[0]);
            ::close(fd_pipe[0]);
            ::close(fd_pipe[1]);
            execlp("/mnt/nfs/mplayer","mplayer","-vo", "fbdev2","-ss", "00:00:30", "-volume","1","-srate","44100", "-geometry", "50%:50%",title,NULL);
        }else{
            sighandler_t sig_ret;
            sig_ret=signal(SIGCHLD,sigChldHandler);
            if(sig_ret==SIG_ERR)exit(-1);
        }
    }
    else {
        write(fd_pipe[1],"p",1);
        if(pause_flag^=1){emit pauseclicked();ui->BTN_Play->setIcon(QIcon(":/images/images/play.png"));ui->BTN_Play->setIconSize(QSize(55,55));}
        else {emit playclicked();ui->BTN_Play->setIcon(QIcon(":/images/images/pause.png"));ui->BTN_Play->setIconSize(QSize(45,45));}
    }
}

void PlayingDialog::on_BTN_Stop_clicked()
{
    play_flag=0;
    emit stopclicked();
    write(fd_pipe[1], "q", 1);
    sleep(1);
    repaint();
    close();
}

void PlayingDialog::on_BTN_UP_clicked()
{
    write(fd_pipe[1], "o", 1);
}

void PlayingDialog::on_BTN_Down_clicked()
{
    write(fd_pipe[1], "9", 1);
}

void PlayingDialog::on_BTN_FF_clicked()
{
    write(fd_pipe[1], "+", 1);
    if(pause_flag){
        ui->BTN_Play->setIcon(QIcon(":/images/images/pause.png"));ui->BTN_Play->setIconSize(QSize(55,55));
        pause_flag^=1;
    }

}

void PlayingDialog::on_BTN_RW_clicked()
{
    write(fd_pipe[1], "-", 1);
    if(pause_flag){
        ui->BTN_Play->setIcon(QIcon(":/images/images/pause.png"));ui->BTN_Play->setIconSize(QSize(55,55));
        pause_flag^=1;
    }
}

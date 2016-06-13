#include "mainwindow.h"
#include "qlineedit.h"
#include "ui_mainwindow.h"
#include "mylineedit.h"
#include <QEvent>
#include <QMouseEvent>
#include <stdio.h>
#include "signupdialog.h"
#include "videodialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    printf("start mainwindow\n");
    ui->setupUi(this);
    printf("setupUI\n");
    Keyboard = ui->Keyboard;
    printf("setup Keyboard\n");
    Keyboard->setinputbox(ui->inputID, 0);
    printf("setup inputbox\n");
    ui->keyboarddock->hide();
    ui->warning->hide();

    printf("before connect\n");
    connect(ui->inputID, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_id(void)));
    connect(ui->inputPassword, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_pw(void)));

    connect(this, SIGNAL(init_viddlg(QString)), &viddlg, SLOT(init(QString)));

    init_udp();
    printf("done init\n");
    codec = QTextCodec::codecForName("UTF8");

    printf("setup mainwindow\n");
}

MainWindow::~MainWindow()
{
    rcvthread->exit();
    delete ui;
}

void MainWindow::init_udp()
{
    rcvthread = new rcvThread(this);

    connect(rcvthread, SIGNAL(login_result(bool)), this, SLOT(login_result(bool)));
    connect(rcvthread, SIGNAL(dup_id_result(bool)), &signdlg, SLOT(dup_id_result(bool)));
    connect(rcvthread, SIGNAL(readydata(QByteArray)), &viddlg, SLOT(readydata(QByteArray)));
    connect(rcvthread, SIGNAL(set_tab(int)), &viddlg, SLOT(set_tab(int)));
    connect(this, SIGNAL(send_data(QByteArray)), rcvthread, SLOT(send_data(QByteArray)));
    connect(&signdlg, SIGNAL(send_data(QByteArray)), rcvthread, SLOT(send_data(QByteArray)));
    connect(&viddlg, SIGNAL(send_data(QByteArray)), rcvthread, SLOT(send_data(QByteArray)));

    rcvthread->start();
}

void MainWindow::login_result(bool accept)
{

    if(!this->isActiveWindow()) return;
    if (accept)
    {
        ui->warning->hide();
        ui->keyboarddock->hide();
        userid = ui->inputID->text();
        printf("useridmain: %s\n", userid.toStdString().c_str());
        ui->inputID->setText(NULL);
        ui->inputPassword->setText(NULL);

        viddlg.setWindowFlags(Qt::FramelessWindowHint);
        emit init_viddlg(userid);
        viddlg.show();
    }
    else
    {
        ui->warning->show();
    }

}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    ui->keyboarddock->hide();
}

void MainWindow::got_focus_sig_from_id(void)
{
   if(ui->keyboarddock->isHidden()) ui->keyboarddock->show();
   Keyboard->setinputbox(ui->inputID, ui->inputID->cursorPosition());
}

void MainWindow::got_focus_sig_from_pw(void)
{
  //printf("password input\n");
  if(ui->keyboarddock->isHidden()) ui->keyboarddock->show();
  Keyboard->setinputbox(ui->inputPassword, ui->inputPassword->cursorPosition());
}

void MainWindow::on_SignupButton_clicked()
{
    ui->keyboarddock->hide();
    ui->warning->hide();
    signdlg.show();
}

void MainWindow::on_LoginButton_clicked()
{
    QByteArray datagram;
    datagram.append('L').append(ui->inputID->text()).append('@').append(ui->inputPassword->text());
    printf("%s\n", datagram.data());
    send_data(datagram);
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <mylineedit.h>
#include <qtextcodec.h>
#include <rcvthread.h>
#include <signupdialog.h>
#include <videodialog.h>
#include <wkeyboard.h>


namespace Ui {
class MainWindow;
}

class MyLineEdit;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

public slots:

signals:
    void init_viddlg(QString id);
    void send_data(QByteArray datagram);
    void changeinputbox();

private slots:
    //초기화
    void init_udp();

    //로그인 화면
    void mousePressEvent(QMouseEvent *e);
    void on_SignupButton_clicked();
    void on_LoginButton_clicked();
    void login_result(bool);

    void got_focus_sig_from_id();
    void got_focus_sig_from_pw();

private:
    QTextCodec *codec;
    Ui::MainWindow *ui;
    rcvThread *rcvthread;
    SignupDialog signdlg;
    VideoDialog viddlg;

    WKeyboard * Keyboard;

    QString userid;
};

#endif // MAINWINDOW_H

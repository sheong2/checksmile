#ifndef VIDEODIALOG_H
#define VIDEODIALOG_H

#include <QDialog>
#include <QByteArray>
#include <QTextCodec>
#include <wkeyboard.h>
#include <capturethread.h>
#include <playingdialog.h>

namespace Ui {
class VideoDialog;
}

class VideoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VideoDialog(QWidget *parent = 0);
    ~VideoDialog();
    CaptureThread* getcamthread(){return cam;}

public slots:
    void got_sig_from_searchline();

signals:
    void send_data(QByteArray datagram);
    void connect_cam_rcv();

private slots:

    void init(QString id);
    void showlist();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

    void on_WatchingTab_clicked();
    void on_HistoryTab_clicked();
    void on_AlreadyTab_clicked();
    void on_SuggestTab_clicked();

    void on_recentTab_clicked();
    void on_bookmarkTab_clicked();
    void on_viewTab_clicked();

    void on_verticalScrollBar_sliderReleased();
    void readydata(QByteArray datagram);
    void set_tab(int maxpage);

    void mousePressEvent(QMouseEvent *e);

    void on_logoutButton_clicked();
    void on_SearchButton_clicked();
    void on_subtab1_clicked();

    void on_subtab2_clicked();

    void on_subtab3_clicked();

private:
    Ui::VideoDialog *ui;
    WKeyboard * vidkeyboard;

    QString tab;
    QString subtab;
    QByteArray page;

    QByteArray id1;
    QByteArray id2;
    QByteArray id3;
    QByteArray id4;
    QByteArray id5;
    QByteArray id6;

    QByteArray time1;
    QByteArray time2;
    QByteArray time3;
    QByteArray time4;
    QByteArray time5;
    QByteArray time6;

    QByteArray name1;
    QByteArray name2;
    QByteArray name3;
    QByteArray name4;
    QByteArray name5;
    QByteArray name6;

    CaptureThread * cam;

    bool connected;
};

#endif // VIDEODIALOG_H

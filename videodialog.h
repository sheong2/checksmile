#ifndef VIDEODIALOG_H
#define VIDEODIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class VideoDialog;
}

class VideoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit VideoDialog(QWidget *parent = 0);
    ~VideoDialog();
    
private slots:

    void showlist();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_WatchingTab_clicked();

    void on_verticalScrollBar_sliderReleased();

    void readydata();

private:
    Ui::VideoDialog *ui;
    QByteArray datagram;
    char data[640];
    int maxpage;
    char id1[4];
    char id2[4];
    char id3[4];
    char id4[4];
    char id5[4];
    char id6[4];
    QString name1;
    QString name2;
    QString name3;
    QString name4;
    QString name5;
    QString name6;
};

#endif // VIDEODIALOG_H

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

public slots:
    void got_sig_from_searchline();


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

    void mousePressEvent(QMouseEvent *e);

    void on_Button_HIDE_clicked();

    void on_Button_Q_clicked();

    void on_Button_W_clicked();

    void on_Button_RESET_clicked();

    void on_Button_E_clicked();

    void on_Button_R_clicked();

    void on_Button_T_clicked();

    void on_Button_Y_clicked();

    void on_Button_U_clicked();

    void on_Button_I_clicked();

    void on_Button_O_clicked();

    void on_Button_P_clicked();

    void on_Button_Z_clicked();

    void on_Button_X_clicked();

    void on_Button_C_clicked();

    void on_Button_V_clicked();

    void on_Button_B_clicked();

    void on_Button_N_clicked();

    void on_Button_M_clicked();

    void on_Button_DOT_clicked();

    void on_Button_question_clicked();

    void on_Button_spacebar_clicked();

    void on_Button_enter_clicked();

    void on_Button_del_clicked();

    void on_Button_A_clicked();

    void on_Button_S_clicked();

    void on_Button_D_clicked();

    void on_Button_F_clicked();

    void on_Button_G_clicked();

    void on_Button_H_clicked();

    void on_Button_J_clicked();

    void on_Button_K_clicked();

    void on_Button_L_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();

    void on_Button_0_clicked();

    void on_Button_bar_clicked();

    void on_logoutButton_clicked();

    void on_HistoryTab_clicked();

    void on_SuggestTab_clicked();

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

    int cursor;
};

#endif // VIDEODIALOG_H

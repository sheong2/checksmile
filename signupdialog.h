#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <qtextcodec.h>
#include <QDialog>

namespace Ui {
class SignupDialog;
}

class SignupDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SignupDialog(QWidget *parent = 0);
    ~SignupDialog();
    
public slots:
    void got_focus_sig_from_id();
    void got_focus_sig_from_pw();

private slots:
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

    void on_CheckAgree_clicked(bool checked);

    void on_SignupButton_clicked();

    void on_pushButton_clicked();

    void on_inputID_textChanged(const QString &arg1);

private:
    Ui::SignupDialog *ui;
    QTextCodec *codec;
    bool able;
};

#endif // SIGNUPDIALOG_H

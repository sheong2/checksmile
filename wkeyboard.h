#ifndef WKEYBOARD_H
#define WKEYBOARD_H

#include <QWidget>
#include <mylineedit.h>

namespace Ui {
class WKeyboard;
}

class WKeyboard : public QWidget
{
    Q_OBJECT
    
public:
    explicit WKeyboard(QWidget *parent = 0);
    void setinputbox (MyLineEdit *box, int cursorpos);
    MyLineEdit *inputbox;
    int cursor;
    ~WKeyboard();

signals:
    void hide();

public slots:
    
private slots:
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

private:
    Ui::WKeyboard *ui;

};

#endif // WKEYBOARD_H

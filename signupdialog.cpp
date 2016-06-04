#include "signupdialog.h"
#include "ui_signupdialog.h"
#include "mylineedit.h"
#include "mainwindow.h"
#include <QMouseEvent>

extern int cursorpos;
extern int cursorpos2;

extern int focus;
extern int shift;

SignupDialog::SignupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignupDialog)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    ui->KeyboardDock->hide();
    ui->SignupButton->setEnabled(false);
    ui->warninglabel->hide();
    connect(ui->inputID, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_id(void)));
    connect(ui->inputPassword, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_pw(void)));
    cursorpos=0;
    cursorpos2=0;

    codec = QTextCodec::codecForName("UTF8");
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::mousePressEvent(QMouseEvent *e)
{
    ui->KeyboardDock->hide();
}

void SignupDialog::got_focus_sig_from_id(void)
{
    ui->KeyboardDock->show();
    focus=1;
    cursorpos = ui->inputID->cursorPosition();
}

void SignupDialog::got_focus_sig_from_pw(void)
{
    ui->KeyboardDock->show();
    focus=2;
    cursorpos2 = ui->inputPassword->cursorPosition();
}


void SignupDialog::on_Button_HIDE_clicked()
{
    ui->KeyboardDock->hide();
}

void SignupDialog::on_Button_Q_clicked()
{
    char q[2] = {'q', 'Q'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_W_clicked()
{
    char q[2] = {'w', 'W'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_RESET_clicked()
{
    if(focus==1)
    {
        ui->inputID->text().clear();
        ui->inputID->setText(NULL);
        cursorpos=0;
    }
    else if(focus==2)
    {
        ui->inputPassword->text().clear();
        ui->inputPassword->setText(NULL);
        cursorpos2=0;
    }
}

void SignupDialog::on_Button_E_clicked()
{
    char q[2] = {'e', 'E'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_R_clicked()
{
    char q[2] = {'r', 'R'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_T_clicked()
{
    char q[2] = {'t', 'T'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_Y_clicked()
{
    char q[2] = {'y', 'Y'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_U_clicked()
{
    char q[2] = {'u', 'U'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_I_clicked()
{
    char q[2] = {'i', 'i'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_O_clicked()
{
    char q[2] = {'o', 'O'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_P_clicked()
{
    char q[2] = {'p', 'P'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_Z_clicked()
{
    char q[2] = {'z', 'Z'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_X_clicked()
{
    char q[2] = {'x', 'X'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_C_clicked()
{
    char q[2] = {'c', 'C'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_V_clicked()
{
    char q[2] = {'v', 'V'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_B_clicked()
{
    char q[2] = {'b', 'B'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_N_clicked()
{
    char q[2] = {'n', 'N'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_M_clicked()
{
    char q[2] = {'m', 'M'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_DOT_clicked()
{
    char q[2] = {'.', ','};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_question_clicked()
{
    char q[2] = {'?', '!'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}


void SignupDialog::on_Button_spacebar_clicked()
{
    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,' '));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, ' '));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_enter_clicked()
{
    if(focus==1)
    {
        focus=2;
        cursorpos2 = ui->inputPassword->text().length();
    }
    else if(focus==2)
    {
        ui->KeyboardDock->hide();
    }
}

void SignupDialog::on_Button_del_clicked()
{
    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().remove(--cursorpos, 1));
    }
    else if(focus==2)
    {
       ui->inputPassword->setText(ui->inputPassword->text().remove(--cursorpos2, 1));
    }
}

void SignupDialog::on_Button_A_clicked()
{
    char q[2] = {'a', 'A'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_S_clicked()
{
    char q[2] = {'s', 'S'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_D_clicked()
{
    char q[2] = {'d', 'D'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_F_clicked()
{
    char q[2] = {'f', 'F'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_G_clicked()
{
    char q[2] = {'g', 'G'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_H_clicked()
{
    char q[2] = {'h', 'H'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_J_clicked()
{
    char q[2] = {'j', 'J'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_K_clicked()
{
    char q[2] = {'k', 'K'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_L_clicked()
{
    char q[2] = {'l', 'L'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_1_clicked()
{
    char q[2] = {'1', '1'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_2_clicked()
{
    char q[2] = {'2', '2'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_3_clicked()
{
    char q[2] = {'3', '3'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }

}

void SignupDialog::on_Button_4_clicked()
{
    char q[2] = {'4', '4'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_5_clicked()
{
    char q[2] = {'5', '5'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_6_clicked()
{
    char q[2] = {'6', '6'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_7_clicked()
{
    char q[2] = {'7', '7'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_8_clicked()
{
    char q[2] = {'8', '8'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_9_clicked()
{
    char q[2] = {'9', '9'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_0_clicked()
{
    char q[2] = {'0', '0'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}

void SignupDialog::on_Button_bar_clicked()
{
    char q[2] = {'-', '_'};

    if(focus==1)
    {
        ui->inputID->setText(ui->inputID->text().insert(cursorpos,q[ui->Button_shift->isChecked()]));
        cursorpos++;
    }
    else if(focus==2)
    {
        ui->inputPassword->setText(ui->inputPassword->text().insert(cursorpos2, q[ui->Button_shift->isChecked()]));
        cursorpos2++;
    }
}


void SignupDialog::on_CheckAgree_clicked(bool checked)
{
    if(checked) ui->SignupButton->setEnabled(true);
    else ui->SignupButton->setEnabled(false);
}

void SignupDialog::on_SignupButton_clicked()
{
    /*DB에서 정보 확인 후 가입여부 결정*/
    int disable=0;

    /*불가능한 경우*/
    if(disable) ui->warninglabel->show();
    //가능한 경우
    else close();
}

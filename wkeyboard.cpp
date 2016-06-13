#include "wkeyboard.h"
#include "ui_wkeyboard.h"
#include <QMouseEvent>

#include <stdio.h>



WKeyboard::WKeyboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WKeyboard)
{
    ui->setupUi(this);
    printf("setup Keyboard ui\n");
}

WKeyboard::~WKeyboard()
{
    printf("bye Keyboard\n");
    delete ui;
}

void WKeyboard::setinputbox(MyLineEdit *box, int cursorpos)
{
    inputbox = box;
    cursor = cursorpos;
}

void WKeyboard::on_Button_Q_clicked()
{
    char key[2] = {'q', 'Q'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_W_clicked()
{
    char key[2] = {'w', 'W'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_E_clicked()
{
    char key[2] = {'e', 'E'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_R_clicked()
{
    char key[2] = {'r', 'R'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_T_clicked()
{
    char key[2] = {'t', 'T'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_Y_clicked()
{
    char key[2] = {'y', 'Y'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_U_clicked()
{
    char key[2] = {'u', 'U'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_I_clicked()
{
    char key[2] = {'i', 'I'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_O_clicked()
{
    char key[2] = {'o', 'O'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_P_clicked()
{
    char key[2] = {'p', 'P'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_A_clicked()
{
    char key[2] = {'a', 'A'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_S_clicked()
{
    char key[2] = {'s', 'S'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_D_clicked()
{
    char key[2] = {'d', 'D'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_F_clicked()
{
    char key[2] = {'f', 'F'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_G_clicked()
{
    char key[2] = {'g', 'G'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_H_clicked()
{
    char key[2] = {'h', 'H'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;

}

void WKeyboard::on_Button_J_clicked()
{
    char key[2] = {'j', 'J'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_K_clicked()
{
    char key[2] = {'k', 'K'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_L_clicked()
{
    char key[2] = {'l', 'L'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_Z_clicked()
{
    char key[2] = {'z', 'Z'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_X_clicked()
{
    char key[2] = {'x', 'X'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_C_clicked()
{
    char key[2] = {'c', 'C'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_V_clicked()
{
    char key[2] = {'v', 'V'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_B_clicked()
{
    char key[2] = {'b', 'B'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_N_clicked()
{
    char key[2] = {'n', 'N'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_M_clicked()
{
    char key[2] = {'m', 'M'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_DOT_clicked()
{
    char key[2] = {'.', ','};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_question_clicked()
{
    char key[2] = {'?', '!'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_bar_clicked()
{
    char key[2] = {'-', '_'};

    inputbox->setText(inputbox->text().insert(cursor, key[ui->Button_shift->isChecked()]));
    cursor++;
}

void WKeyboard::on_Button_1_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '1'));
    cursor++;
}

void WKeyboard::on_Button_2_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '2'));
    cursor++;
}

void WKeyboard::on_Button_3_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '3'));
    cursor++;
}

void WKeyboard::on_Button_4_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '4'));
    cursor++;
}

void WKeyboard::on_Button_5_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '5'));
    cursor++;
}

void WKeyboard::on_Button_6_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '6'));
    cursor++;
}

void WKeyboard::on_Button_7_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '7'));
    cursor++;
}

void WKeyboard::on_Button_8_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '8'));
    cursor++;
}

void WKeyboard::on_Button_9_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '9'));
    cursor++;
}

void WKeyboard::on_Button_0_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, '0'));
    cursor++;
}

void WKeyboard::on_Button_del_clicked()
{
    inputbox->setText(inputbox->text().remove(--cursor, 1));
}

void WKeyboard::on_Button_RESET_clicked()
{
    inputbox->setText(NULL);
}

void WKeyboard::on_Button_spacebar_clicked()
{
    inputbox->setText(inputbox->text().insert(cursor, ' '));
    cursor++;
}


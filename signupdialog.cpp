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
    signkeyboard = ui->Keyboard;
    ui->KeyboardDock->hide();
    ui->SignupButton->setEnabled(false);
    connect(ui->inputID, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_id(void)));
    connect(ui->inputPassword, SIGNAL(pressed()), this, SLOT(got_focus_sig_from_pw(void)));
    able = false;

    codec = QTextCodec::codecForName("UTF8");
}

SignupDialog::~SignupDialog()
{
    delete ui;
}

void SignupDialog::dup_id_result(bool accept)
{
    if(accept)
    {
        able = true;
        ui->pushButton->setEnabled(false);
        ui->warninglabel->setText(codec->toUnicode("사용 가능한 아이디입니다  "));
        if(ui->CheckAgree->isChecked()) ui->SignupButton->setEnabled(true);
    }

    else
    {
        ui->warninglabel->setText(codec->toUnicode("사용할 수 없는 아이디입니다  "));
    }
}

void SignupDialog::on_CheckAgree_clicked(bool checked)
{
    if(checked && able==true) ui->SignupButton->setEnabled(true);
    else ui->SignupButton->setEnabled(false);
}

void SignupDialog::on_SignupButton_clicked()
{
    QByteArray datagram;
    datagram.append('J').append(ui->inputID->text()).append('@').append(ui->inputPassword->text());
    printf("%s\n", datagram.data());
    send_data(datagram);

    on_CancelButton_clicked();
}

void SignupDialog::on_pushButton_clicked()
{
    QByteArray datagram;
    datagram.append('D').append(ui->inputID->text());
    send_data(datagram);
}

void SignupDialog::on_inputID_textChanged(const QString &arg1)
{
    able = false;
    ui->warninglabel->setText(codec->toUnicode("중복확인버튼을 눌러주세요  "));
}

void SignupDialog::mousePressEvent(QMouseEvent *e)
{
    ui->KeyboardDock->hide();
}

void SignupDialog::got_focus_sig_from_id(void)
{
    if(ui->KeyboardDock->isHidden()) ui->KeyboardDock->show();
    signkeyboard->setinputbox(ui->inputID, ui->inputID->cursorPosition());
}

void SignupDialog::got_focus_sig_from_pw(void)
{
    if(ui->KeyboardDock->isHidden()) ui->KeyboardDock->show();
    signkeyboard->setinputbox(ui->inputPassword, ui->inputPassword->cursorPosition());
}


void SignupDialog::on_CancelButton_clicked()
{
    ui->warninglabel->setText(codec->toUnicode("중복 확인 버튼을 눌러주세요  "));
    ui->CheckAgree->setChecked(false);
    ui->pushButton->setEnabled(true);
    ui->inputID->setText(NULL);
    ui->inputPassword->setText(NULL);
    close();
}

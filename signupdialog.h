#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <qtextcodec.h>
#include <QDialog>
#include <wkeyboard.h>

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

signals:
    void send_data(QByteArray datagram);

private slots:

    void on_CheckAgree_clicked(bool checked);
    void on_SignupButton_clicked();
    void on_pushButton_clicked();
    void on_inputID_textChanged(const QString &arg1);
    void mousePressEvent(QMouseEvent *e);
    void dup_id_result(bool);

    void on_CancelButton_clicked();

private:
    Ui::SignupDialog *ui;
    QTextCodec *codec;
    bool able;
    WKeyboard * signkeyboard;
};

#endif // SIGNUPDIALOG_H

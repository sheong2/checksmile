#ifndef PLAYINGDIALOG_H
#define PLAYINGDIALOG_H

#include <QDialog>

namespace Ui {
class PlayingDialog;
}

class PlayingDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PlayingDialog(int idx, QWidget *parent = 0);
    ~PlayingDialog();
private slots:

    void on_BTN_Play_clicked();

    void on_BTN_RW_clicked();

    void on_BTN_Stop_clicked();

    void on_BTN_UP_clicked();

    void on_BTN_Down_clicked();

    void on_BTN_FF_clicked();
    void Display_Play_Menu(void);



private:
    Ui::PlayingDialog *ui;
    int fd_pipe[2];
};

#endif // PLAYINGDIALOG_H

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
    void on_rightbutton_clicked();
    void showlist();


    void on_leftbutton_clicked();

private:
    Ui::VideoDialog *ui;
    int count;
    QString vtitle;
};

#endif // VIDEODIALOG_H

#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>

class MyLineEdit : public QLineEdit
{
  Q_OBJECT

public:
    MyLineEdit(QWidget *parent = 0);
    ~MyLineEdit();

signals:
  void pressed(void);

protected:
  virtual void mousePressEvent(QMouseEvent *e);
};

#endif // MYLINEEDIT_H

#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QLineEdit>
#include <QMouseEvent>

class MyLineEdit : public QLineEdit
{
  Q_OBJECT

public:
    MyLineEdit(QWidget *parent = 0);
    ~MyLineEdit();

signals:
  void pressed();

protected:
  virtual void mousePressEvent(QMouseEvent *e);
};

#endif // MYLINEEDIT_H

#include "mylineedit.h"

MyLineEdit::MyLineEdit(QWidget *parent)
 : QLineEdit(parent)
{
}

MyLineEdit::~MyLineEdit()
{}

void MyLineEdit::mousePressEvent(QMouseEvent *e)
{
    QLineEdit::mousePressEvent(e);
    emit(pressed());
}

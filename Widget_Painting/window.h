#ifndef window_h
#define window_h

#include <QPushButton>
#include <QVBoxLayout>
#include <QTextCodec>

#include <QWidget>
#include "area.h"
class Window : public QWidget
{
protected:
    QTextCodec *codec;
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
    Window();
};
#endif

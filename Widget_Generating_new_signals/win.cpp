#include "win.h"

Win::Win(QWidget *parent):QWidget(parent)
{
codec = QTextCodec::codecForName("Windows-1251");

this->setWindowTitle(tr("Счетчик"));

label1 = new QLabel(tr("Cчет по 1"),this);
label2 = new QLabel(tr("Cчет по 5"),this);

edit1 = new Counter("0",this);
edit2 = new Counter("0",this);

calcbutton=new QPushButton("+1",this);
exitbutton=new QPushButton(tr("Выход"),this);

QHBoxLayout *layout1 = new QHBoxLayout();
layout1->addWidget(label1);
layout1->addWidget(label2);

QHBoxLayout *layout2 = new QHBoxLayout();
layout2->addWidget(edit1);
layout2->addWidget(edit2);

QHBoxLayout *layout3 = new QHBoxLayout();
layout3->addWidget(calcbutton);
layout3->addWidget(exitbutton);

QVBoxLayout *layout4 = new QVBoxLayout(this);
layout4->addLayout(layout1);
layout4->addLayout(layout2);
layout4->addLayout(layout3);

// связь сигнала нажатия кнопки и слота закрытия окна
connect(calcbutton,&QPushButton::clicked, edit1, &Counter::add_one);
connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);
connect(exitbutton,&QPushButton::clicked,this,&Win::close);
}

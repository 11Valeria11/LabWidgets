#include "window.h"
Window::Window()
{
codec = QTextCodec::codecForName("Windows-1251");

this->setWindowTitle(tr("Обработка событий"));
area = new Area( this );
btn = new QPushButton(tr("Завершить"),this );
QVBoxLayout *layout = new QVBoxLayout(this);
layout->addWidget(area);
layout->addWidget(btn);

connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

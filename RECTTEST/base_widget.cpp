#include "base_widget.h"

Base_Widget::Base_Widget(QWidget *parent) :
    QWidget(parent)
{
    resize(1024, 613);
    setAutoFillBackground(true);
    setAttribute(Qt::WA_DeleteOnClose);

    i_base_image_flag = 0;
}
Base_Widget::~Base_Widget()
{
    if(0 < i_base_timer_id)
    {
        killTimer(i_base_timer_id);
        i_base_timer_id = 0;
    }
}
void Base_Widget::timerEvent_Start(int value)
{
    if(value <= 0) return;
    if(0 < i_base_timer_id) return;

    i_base_timer_id = startTimer(value);
}

void Base_Widget::timerEvent_Stop()
{
    if(0 < i_base_timer_id)
    {
        killTimer(i_base_timer_id);
        i_base_timer_id = 0;
    }
}

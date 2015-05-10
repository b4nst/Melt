#include "clickablewidget.h"

ClickableWidget::ClickableWidget(QWidget *parent) : QWidget(parent)
{

}

void ClickableWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked();
    }
}

#ifndef CLICKABLEWIDGET_H
#define CLICKABLEWIDGET_H

#include <QWidget>
#include <QMouseEvent>

class ClickableWidget : public QWidget
{
  Q_OBJECT
public:
  explicit ClickableWidget(QWidget *parent = 0);

protected:
   void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

signals:
  void clicked();

public slots:
};

#endif // CLICKABLEWIDGET_H

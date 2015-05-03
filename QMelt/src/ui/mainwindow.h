#pragma once


// QT
#include <QMainWindow>


namespace ui
{


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
};


} // namespace ui

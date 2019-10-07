#ifndef RECT_H
#define RECT_H

#include <QMainWindow>

namespace Ui {
class Rect;
}

class Rect : public QMainWindow
{
    Q_OBJECT

public:
    explicit Rect(QWidget *parent = 0);
    ~Rect();

    void on_Dreawing_button_clicked();

private:
    Ui::Rect *ui;

public:
     int X=0;
     int Y=0;
     int Right=0;
     int Bottom = 0;

};

#endif // RECT_H

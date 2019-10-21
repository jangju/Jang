#ifndef RULE_H
#define RULE_H

#include <QWidget>

namespace Ui {
class rule;
}

class rule : public QWidget
{
    Q_OBJECT

public:
    explicit rule(QWidget *parent = 0);
    ~rule();

private:
    Ui::rule *ui;
};

#endif // RULE_H

#include "rule.h"
#include "ui_rule.h"

#define RULE "/home/lubuntu/baseball/Image/rule_img.png"
rule::rule(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rule)
{
    ui->setupUi(this);

    QPalette pal = palette();
    pal.setBrush(QPalette::Background, QBrush(QPixmap(RULE)));
    setPalette(pal);
}

rule::~rule()
{
    delete ui;
}

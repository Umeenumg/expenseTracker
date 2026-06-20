#ifndef BARCHARTWIDGET_H
#define BARCHARTWIDGET_H

#include <QWidget>

class BarChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BarChartWidget(QWidget *parent = nullptr);

    void setData(double income, double expense);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    double m_income  = 0;
    double m_expense = 0;
};

#endif

#ifndef LINECHARTWIDGET_H
#define LINECHARTWIDGET_H

#include <QWidget>
#include <QMap>

class LineChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LineChartWidget(QWidget *parent = nullptr);

    // key = day number (1-31), value = cumulative expense
    void setData(const QMap<int, double> &dailyExpenses);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<int, double> m_data;
};

#endif

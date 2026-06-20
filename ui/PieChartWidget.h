#ifndef PIECHARTWIDGET_H
#define PIECHARTWIDGET_H

#include <QWidget>
#include <QMap>

class PieChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PieChartWidget(QWidget *parent = nullptr);

    void setData(const QMap<QString, double> &categoryTotals);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QMap<QString, double> m_data;

    QList<QColor> m_colors = {
        QColor("#a78bfa"),
        QColor("#60a5fa"),
        QColor("#4ade80"),
        QColor("#f87171"),
        QColor("#fbbf24"),
        QColor("#f472b6"),
        QColor("#34d399"),
        QColor("#fb923c")
    };
};

#endif

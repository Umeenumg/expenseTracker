#include "LineChartWidget.h"

#include <QPainter>
#include <QPainterPath>

LineChartWidget::LineChartWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(180);
}

void LineChartWidget::setData(const QMap<int, double> &dailyExpenses)
{
    m_data = dailyExpenses;
    update();
}

void LineChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int W = width();
    int H = height();
    int padL = 55, padR = 20, padT = 30, padB = 35;
    int chartW = W - padL - padR;
    int chartH = H - padT - padB;

    p.fillRect(rect(), QColor("#0d0d14"));

    // title
    p.setPen(QColor("#6b7280"));
    p.setFont(QFont("Segoe UI", 10, QFont::Medium));
    p.drawText(padL, 20, "Daily Spending — This Month");

    if (m_data.isEmpty()) {
        p.setPen(QColor("#374151"));
        p.setFont(QFont("Segoe UI", 9));
        p.drawText(rect(), Qt::AlignCenter, "No expense data this month");
        return;
    }

    // find max and real day range
    double maxVal  = 1.0;
    int    minDay  = m_data.firstKey();
    int    maxDay  = m_data.lastKey();

    // if only 1 data point, spread it nicely
    if (minDay == maxDay) {
        minDay = qMax(1, minDay - 2);
        maxDay = qMin(31, maxDay + 2);
    }

    int dayRange = qMax(maxDay - minDay, 1);

    for (double v : m_data) maxVal = qMax(maxVal, v);

    // grid lines
    p.setPen(QPen(QColor("#111120"), 1, Qt::DashLine));
    for (int i = 0; i <= 4; i++) {
        int y = padT + (chartH * i / 4);
        p.drawLine(padL, y, W - padR, y);

        double val = maxVal * (4 - i) / 4;
        p.setPen(QColor("#374151"));
        p.setFont(QFont("Segoe UI", 8));
        p.drawText(0, y - 8, padL - 4, 16,
                   Qt::AlignRight | Qt::AlignVCenter,
                   QString::number(val, 'f', 0));
        p.setPen(QPen(QColor("#111120"), 1, Qt::DashLine));
    }

    auto toPoint = [&](int day, double val) -> QPointF {
        double x = padL + ((double)(day - minDay) / dayRange) * chartW;
        double y = padT + chartH - (val / maxVal) * chartH;
        return {x, y};
    };

    // filled area
    QPainterPath areaPath;
    bool    first   = true;
    QPointF firstPt, lastPt;

    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        QPointF pt = toPoint(it.key(), it.value());
        if (first) { areaPath.moveTo(pt); firstPt = pt; first = false; }
        else          areaPath.lineTo(pt);
        lastPt = pt;
    }

    QPainterPath closedArea = areaPath;
    closedArea.lineTo(lastPt.x(),  padT + chartH);
    closedArea.lineTo(firstPt.x(), padT + chartH);
    closedArea.closeSubpath();

    QColor areaColor("#7c3aed");
    areaColor.setAlpha(25);
    p.fillPath(closedArea, areaColor);

    // line
    p.setPen(QPen(QColor("#a78bfa"), 2));
    p.setBrush(Qt::NoBrush);
    p.drawPath(areaPath);

    // dots
    p.setBrush(QColor("#a78bfa"));
    p.setPen(QPen(QColor("#0d0d14"), 2));
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        QPointF pt = toPoint(it.key(), it.value());
        p.drawEllipse(pt, 5, 5);

        // value tooltip above dot
        p.setPen(QColor("#a78bfa"));
        p.setFont(QFont("Segoe UI", 8, QFont::Medium));
        p.drawText((int)pt.x() - 20, (int)pt.y() - 16,
                   40, 14, Qt::AlignCenter,
                   QString::number(it.value(), 'f', 0));
        p.setPen(QPen(QColor("#0d0d14"), 2));
    }

    // x axis day labels
    p.setPen(QColor("#374151"));
    p.setFont(QFont("Segoe UI", 8));
    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        QPointF pt = toPoint(it.key(), 0);
        p.drawText((int)pt.x() - 12, padT + chartH + 8,
                   24, 16, Qt::AlignCenter,
                   QString::number(it.key()));
    }

    // baseline
    p.setPen(QPen(QColor("#1a1a28"), 1));
    p.drawLine(padL, padT + chartH, W - padR, padT + chartH);
}

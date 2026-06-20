#include "PieChartWidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QtMath>

PieChartWidget::PieChartWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(200);
}

void PieChartWidget::setData(const QMap<QString, double> &categoryTotals)
{
    m_data = categoryTotals;
    update();
}

void PieChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int W = width();
    int H = height();

    p.fillRect(rect(), QColor("#13131a"));

    // title
    p.setPen(QColor("#9ca3af"));
    p.setFont(QFont("Segoe UI", 10, QFont::Medium));
    p.drawText(10, 20, "Expenses by Category");

    if (m_data.isEmpty()) {
        p.setPen(QColor("#4b5563"));
        p.setFont(QFont("Segoe UI", 9));
        p.drawText(rect(), Qt::AlignCenter, "No data");
        return;
    }

    double total = 0;
    for (double v : m_data) total += v;
    if (total <= 0) return;

    int diameter = qMin(W / 2, H - 50);
    diameter = qMax(diameter, 80);
    int cx = diameter / 2 + 20;
    int cy = H / 2 + 10;
    QRectF pieRect(cx - diameter/2, cy - diameter/2,
                   diameter, diameter);

    int colorIdx = 0;
    double startAngle = 0;

    // legend x start
    int legendX = cx + diameter / 2 + 20;
    int legendY = 40;

    for (auto it = m_data.begin(); it != m_data.end(); ++it) {
        double ratio      = it.value() / total;
        double spanAngle  = ratio * 360.0;
        QColor color      = m_colors[colorIdx % m_colors.size()];

        // slice
        p.setBrush(color);
        p.setPen(QPen(QColor("#13131a"), 2));
        p.drawPie(pieRect,
                  (int)(startAngle * 16),
                  (int)(spanAngle  * 16));

        // legend item
        p.fillRect(legendX, legendY, 10, 10, color);
        p.setPen(QColor("#9ca3af"));
        p.setFont(QFont("Segoe UI", 8));
        p.drawText(legendX + 14, legendY, 120, 12,
                   Qt::AlignLeft | Qt::AlignVCenter,
                   QString("%1 (%2%)")
                       .arg(it.key())
                       .arg(QString::number(ratio * 100, 'f', 1)));

        legendY    += 18;
        startAngle += spanAngle;
        colorIdx++;
    }
}

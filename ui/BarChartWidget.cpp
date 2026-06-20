#include "BarChartWidget.h"

#include <QPainter>
#include <QPainterPath>
#include <QFontMetrics>

BarChartWidget::BarChartWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(200);
}

void BarChartWidget::setData(double income, double expense)
{
    m_income  = income;
    m_expense = expense;
    update();
}

void BarChartWidget::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);

    int W = width();
    int H = height();
    int padL = 50, padR = 20, padT = 50, padB = 40;
    int chartH = H - padT - padB;
    int chartW = W - padL - padR;

    // background
    p.fillRect(rect(), QColor("#13131a"));

    // title
    p.setPen(QColor("#9ca3af"));
    p.setFont(QFont("Segoe UI", 10, QFont::Medium));
    p.drawText(padL, 20, "Income vs Expense");

    double maxVal = qMax(m_income, qMax(m_expense, 1.0));
    int barW = qMin(60, chartW / 3);
    int gap  = (chartW - barW * 2) / 3;

    auto drawBar = [&](int x, double val, QColor color, QString label) {
        int barH = (int)((val / maxVal) * chartH);
        barH = qMin(barH, chartH);
        int y    = padT + chartH - barH;

        // bar
        QPainterPath path;
        path.addRoundedRect(x, y, barW, barH, 4, 4);
        p.fillPath(path, color);

        // value label — now has room because padT=50
        p.setPen(color);
        p.setFont(QFont("Segoe UI", 9, QFont::Medium));
        p.drawText(x, y - 22, barW, 20,  // ← y-22 instead of y-6
                   Qt::AlignCenter,
                   QString::number(val, 'f', 0));

        // label below
        p.setPen(QColor("#6b7280"));
        p.setFont(QFont("Segoe UI", 9));
        p.drawText(x, padT + chartH + 8, barW, 20,
                   Qt::AlignCenter, label);
    };

    drawBar(padL + gap,           m_income,  QColor("#4ade80"), "Income");
    drawBar(padL + gap*2 + barW,  m_expense, QColor("#f87171"), "Expense");

    // baseline
    p.setPen(QPen(QColor("#1e1e2e"), 1));
    p.drawLine(padL, padT + chartH, W - padR, padT + chartH);
}

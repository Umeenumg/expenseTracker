#ifndef CURRENCY_H
#define CURRENCY_H

#include <QString>
#include <QList>

struct Currency
{
    QString code;    // USD, EUR, MAD...
    QString symbol;  // $, €, MAD...
    QString name;    // US Dollar, Euro...
    double  rate;    // rate relative to USD

    Currency() : rate(1.0) {}
    Currency(const QString &code, const QString &symbol,
             const QString &name, double rate)
        : code(code), symbol(symbol), name(name), rate(rate) {}
};

class CurrencyManager
{
public:
    // returns all supported currencies
    static QList<Currency> allCurrencies();

    // find by code
    static Currency findByCode(const QString &code);

    // convert amount from one currency to another
    static double convert(double amount,
                          const QString &fromCode,
                          const QString &toCode);

    // format amount with symbol
    static QString format(double amount, const QString &code);
};

#endif

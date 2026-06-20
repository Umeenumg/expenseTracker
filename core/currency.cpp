#include "core/Currency.h"

QList<Currency> CurrencyManager::allCurrencies()
{
    return {
        Currency("USD", "$",    "US Dollar",         1.000),
        Currency("EUR", "€",    "Euro",               0.920),
        Currency("GBP", "£",    "British Pound",      0.790),
        Currency("MAD", "MAD",  "Moroccan Dirham",   10.060),
        Currency("SAR", "SAR",  "Saudi Riyal",        3.750),
        Currency("AED", "AED",  "UAE Dirham",         3.670),
        Currency("EGP", "EGP",  "Egyptian Pound",    30.900),
        Currency("TRY", "₺",    "Turkish Lira",      32.500),
        Currency("JPY", "¥",    "Japanese Yen",     149.500),
        Currency("CNY", "¥",    "Chinese Yuan",       7.240),
        Currency("CAD", "CA$",  "Canadian Dollar",    1.360),
        Currency("AUD", "A$",   "Australian Dollar",  1.530),
        Currency("CHF", "CHF",  "Swiss Franc",        0.900),
        Currency("INR", "₹",    "Indian Rupee",      83.100),
        Currency("BRL", "R$",   "Brazilian Real",     4.970),
    };
}

Currency CurrencyManager::findByCode(const QString &code)
{
    for (const Currency &c : allCurrencies()) {
        if (c.code == code) return c;
    }
    return Currency("USD", "$", "US Dollar", 1.0);
}

double CurrencyManager::convert(double amount,
                                const QString &fromCode,
                                const QString &toCode)
{
    if (fromCode == toCode) return amount;

    Currency from = findByCode(fromCode);
    Currency to   = findByCode(toCode);

    // convert to USD first, then to target
    double inUSD = amount / from.rate;
    return inUSD * to.rate;
}

QString CurrencyManager::format(double amount, const QString &code)
{
    Currency c = findByCode(code);
    return c.symbol + " " + QString::number(amount, 'f', 2);
}

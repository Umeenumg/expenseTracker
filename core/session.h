#ifndef SESSION_H
#define SESSION_H

#include <QString>

class Session
{
public:
    static int userId;
    static QString username;
    static QString currencyCode;
    static QString currencySymbol;
    static void clear();
};

#endif

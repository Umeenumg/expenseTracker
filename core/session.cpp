#include "Session.h"

int     Session::userId         = -1;
QString Session::username       = "";
QString Session::currencyCode   = "USD";
QString Session::currencySymbol = "$";

void Session::clear()
{
    userId         = -1;
    username       = "";
    currencyCode   = "USD";
    currencySymbol = "$";
}

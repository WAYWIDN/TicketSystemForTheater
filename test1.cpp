#include <iostream>
#include <string>
#include "Class_Theater.cpp"
using namespace std;

int main()
{
    Theater theater;

    // Purchase tickets
    theater.PurchaseTicket("Alice");

    // Purchase VIP ticket
    theater.PurchaseVIPTicket("Charlie", 12);

    // Reserve ticket
    theater.ReserveTicket("Dave", 7);

    // Cancel ticket
    theater.CancelTicket(1);
    theater.CancelTicket(7);

    // Customer entry
    theater.CustomerEntry();

    // Purchase ticket after entry
    theater.PurchaseTicketAfterEntry("Grace");

    return 0;
}

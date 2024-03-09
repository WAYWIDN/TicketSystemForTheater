#include <iostream>
#include <string>
#include "Class_Theater.cpp"
using namespace std;

int main()
{
    Theater theater;

    int choice;
    string name;
    int seatNumber;
    int amount;

    do
    {
        cout << "\nx-----x-----x-----x-----x-----x-----x-----x-----x----\n";
        cout << "\n1. Purchase Ticket(Price 150)";
        cout << "\n2. Purchase VIP Ticket(Price 777)";
        cout << "\n3. Reserve Ticket(Price 250)";
        cout << "\n4. Cancel Ticket";
        cout << "\n5. Customer Entry";
        cout << "\n6. Purchase Ticket After Entry(Prize 350)";
        cout << "\n7. Exit\n";
        cout << "\n-----------------------------------------------------\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\n-----------------------------------------------------\n";
            cout << "\nEnter Amount : ";
            cin >> amount;
            if (amount == 150)
            {
                cout << "Enter customer name: ";
                cin >> name;
                theater.PurchaseTicket(name);
                break;
            }
            else
            {
                cout << "\nInsufficient Amount to purchase Ticket ";
                break;
            }

        case 2:

            cout << "\n-----------------------------------------------------\n";
            cout << "\nEnter Amount : ";
            cin >> amount;
            if (amount == 777)
            {
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter seat number: ";
                cin >> seatNumber;
                theater.PurchaseVIPTicket(name, seatNumber);
                break;
            }
            else
            {
                cout << "\n-----------------------------------------------------\n";
                cout << "\nInsufficient Amount to purchase Ticket ";
                break;
            }

        case 3:

            cout << "\n-----------------------------------------------------\n";
            cout << "\nEnter Amount : ";
            cin >> amount;
            if (amount == 250)
            {
                cout << "Enter customer name: ";
                cin >> name;
                cout << "Enter seat number: ";
                cin >> seatNumber;
                theater.ReserveTicket(name, seatNumber);
                break;
            }
            else
            {
                cout << "\n-----------------------------------------------------\n";
                cout << "\nInsufficient Amount to purchase Ticket ";
                break;
            }

        case 4:

            cout << "\n-----------------------------------------------------\n";
            cout << "\nEnter seat number to cancel ticket: ";
            cin >> seatNumber;
            theater.CancelTicket(seatNumber);
            break;

        case 5:

            cout << "\n-----------------------------------------------------\n";
            theater.CustomerEntry();
            break;

        case 6:

            cout << "\n-----------------------------------------------------\n";
            cout << "\nEnter Amount : ";
            cin >> amount;
            if (amount == 350)
            {
                cout << "Enter customer name: ";
                cin >> name;
                theater.PurchaseTicket(name);
                break;
            }
            else
            {
                cout << "\nInsufficient Amount to purchase Ticket ";
                break;
            }

        case 7:

            cout << "\nThank You :) ";
            cout << "\nExiting program...";
            break;

        default:

            cout << "Invalid choice! Please enter a valid option.";
        }

    } while (choice != 7);

    return 0;
}

#include <iostream>
#include <string>

using namespace std;

//_____________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________

//------------------------------------Theater Seat Matrix------------------------------------------------------->

#define Size 20 // Assuming Size of theater is 20
const int rows = 4;
const int cols = 5;
int arr[rows][cols] = {0}; // Array to store seat status, 0 means empty, 1 means filled , 2 means entered

//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________

//-------------------------------Varibles to keep Track on Tickets and Entries ---------------------------------->

int TicketCount = 0;
int EntryCount = 0;

//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________

//-------------------------------Class For Customer-------------------------------------------------------------->

class Customer
{
public:
    string name;
    int seatNumber;
    Customer *next;

    Customer(string name, int seatNumber) : name(name), seatNumber(seatNumber), next(NULL) {}
};

//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________
//_______________________________________________________________________________________________________________________________

//--------------------------------Class For Theater-------------------------------------------------------------->

class Theater
{
private:
    // For Customers who have Reserved ticket or Purchased Ticket

    Customer *Head;
    Customer *Tail;

    // For Vip Customers

    Customer *HeadVIP;
    Customer *TailVIP;

public:
    Theater()
    {
        Head = NULL;
        Tail = NULL;
        HeadVIP = NULL;
        TailVIP = NULL;
    }

    //------------------------------Function to check if a seat is available------------------------------------------------->

    bool CheckSeatAvailability(int seatNumber)
    {
        if (seatNumber >= 0 && seatNumber < Size)
        {
            int row = seatNumber / cols;
            int col = seatNumber % cols;
            return arr[row][col] == 0;
        }
        else
        {
            cout << "\nInvalid seat Number ";
            return false;
        }
    }

    //------------------------------------------------Function to Purchase VIP Ticket---------------------------------------->

    void PurchaseVIPTicket(string name, int seatNumber)
    {
        if (TicketCount < Size)
        {
            if (CheckSeatAvailability(seatNumber))
            {
                int row = seatNumber / cols;
                int col = seatNumber % cols;
                arr[row][col] = 1; // Mark the seat as Filled

                TicketCount++; // Increment in Ticket Counter

                cout << "\n# VIP Ticket : ";
                cout << "\nName : " << name;
                cout << "\nSeat Number : " << seatNumber;
                cout << "\n-----------------------------------------------------\n";

                // Add it to the queue

                Customer *newNode = new Customer(name, seatNumber);
                if (HeadVIP == NULL)
                {
                    HeadVIP = newNode;
                    TailVIP = newNode;
                }
                else
                {
                    TailVIP->next = newNode;
                    TailVIP = newNode;
                }
                return;
            }
            else
            {
                cout << "\nSeat " << seatNumber << " is already reserved, Please choose another seat ";
                cout << "\n-----------------------------------------------------\n";
                return;
            }
        }
        else
        {
            cout << "\nAll tickets have been Sold Out ";
            cout << "\n-----------------------------------------------------\n";
            return;
        }
    }

    //-------------------------------------------------- Function to reserve ticket------------------------------------------>

    void ReserveTicket(string name, int seatNumber)
    {
        if (TicketCount < Size)
        {
            if (CheckSeatAvailability(seatNumber))
            {
                int row = seatNumber / cols;
                int col = seatNumber % cols;
                arr[row][col] = 1; // Marking as Filled

                TicketCount++; // Increment in Ticket Counter

                cout << "\n# Reserved Ticket : ";
                cout << "\nName : " << name;
                cout << "\nSeat Number : " << seatNumber;
                cout << "\n-----------------------------------------------------\n";

                Customer *newNode = new Customer(name, seatNumber);

                // Add it to the Queue

                if (Head == NULL)
                {
                    Head = newNode;
                    Tail = newNode;
                }
                else
                {
                    Tail->next = newNode;
                    Tail = newNode;
                }
                return;
            }
            else
            {
                cout << "\nSeat " << seatNumber << " is already reserved, Please choose another seat ";
                cout << "\n-----------------------------------------------------\n";
                return;
            }
        }
        else
        {
            cout << "\nAll tickets have been Sold Out ";
            cout << "\n-----------------------------------------------------\n";
            return;
        }
    }

    //-------------------------------------------- Function to purchase ticket---------------------------------------------->

    void PurchaseTicket(string name)
    {
        if (TicketCount < Size)
        {
            // Find Empty Seat and allot it

            bool SeatIsEmpty = false;

            for (int i = 0; i < rows && !SeatIsEmpty; i++)
            {
                for (int j = 0; j < cols && !SeatIsEmpty; j++)
                {
                    if (arr[i][j] == 0)
                    {
                        SeatIsEmpty = true; // Empty Seat Founded

                        int seatNumber = i * cols + j;
                        arr[i][j] = 1; // Marking as Filled

                        TicketCount++; // Increment in Ticket Counter

                        cout << "\n# Normal Ticket : ";
                        cout << "\nName : " << name;
                        cout << "\nSeat Number : " << seatNumber;
                        cout << "\n-----------------------------------------------------\n";

                        // Add it to the queue

                        Customer *newNode = new Customer(name, seatNumber);
                        if (Head == NULL)
                        {
                            Head = newNode;
                            Tail = newNode;
                        }
                        else
                        {
                            Tail->next = newNode;
                            Tail = newNode;
                        }
                    }
                }
            }

            if (!SeatIsEmpty)
            {
                cout << "\nAll seats have been reserved ";
                cout << "\n-----------------------------------------------------\n";
            }
        }
        else
        {
            cout << "\nAll tickets have been sold ";
            cout << "\n-----------------------------------------------------\n";
        }
    }

    //--------------------------------------- Function to handle Customer Entry-------------------------------------->

    void CustomerEntry()
    {
        cout << "\nEntry Started ---------> \n";

        if (Head != NULL || HeadVIP != NULL)
        {
            // Give Priority to VIP customer

            while (HeadVIP != NULL)
            {
                Customer *NodeToDelete = HeadVIP;
                cout << endl
                     << HeadVIP->name << " entered the theater , Seat Number: " << HeadVIP->seatNumber;

                EntryCount++; // Increment in Entry Counter

                arr[HeadVIP->seatNumber / cols][HeadVIP->seatNumber % cols] = 2; // Marking as Entered

                HeadVIP = HeadVIP->next;
                delete NodeToDelete; // Remove From the Queue
            }

            while (Head != NULL)
            {
                Customer *NodeToDelete = Head;
                cout << endl
                     << Head->name << " entered the theater , Seat Number: " << Head->seatNumber;

                EntryCount++; // Increment in Entry Counter

                arr[Head->seatNumber / cols][Head->seatNumber % cols] = 2;

                Head = Head->next;
                delete NodeToDelete; // Remove From the Queue
            }
            cout << "\n\n<-----------Entry Closed\n";
            cout << "\n-----------------------------------------------------\n";
        }
        else
        {
            cout << "\nNot even Tickets have been sold yet\n";
            cout << "\n-----------------------------------------------------\n";
        }
    }

    //-------------------------------------------- Function to Cancle ticket---------------------------------------------->

    void CancelTicket(int seatNumber)
    {
        bool ticketCanceled = false;

        // Finding Ticket in Queue of VIP customers

        if (HeadVIP != NULL)
        {
            // Ticket Found at Head

            if (HeadVIP->seatNumber == seatNumber)
            {
                Customer *NodeToDelete = HeadVIP;
                cout << "\n# Ticket : ";
                cout << "\nName : " << HeadVIP->name;
                cout << "\nSeat Number : " << HeadVIP->seatNumber;
                cout << "\nSuccessfully Canceled ";
                cout << "\n-----------------------------------------------------\n";

                arr[HeadVIP->seatNumber / cols][HeadVIP->seatNumber % cols] = 0; // Marking Seat as Empty

                HeadVIP = HeadVIP->next;

                delete NodeToDelete; // Remove from the Queue

                TicketCount--; // Decrement in Ticket Counter

                ticketCanceled = true;
            }

            // Ticket Found at other than Head

            else
            {
                Customer *Prev = HeadVIP;
                Customer *Current = HeadVIP->next;

                while (Current != NULL && !ticketCanceled)
                {
                    if (Current->seatNumber == seatNumber)
                    {
                        Prev->next = Current->next;
                        cout << "\n# Ticket : ";
                        cout << "\nName : " << Current->name;
                        cout << "\nSeat Number : " << Current->seatNumber;
                        cout << "\nSuccessfully Canceled ";
                        cout << "\n-----------------------------------------------------\n";

                        arr[Current->seatNumber / cols][Current->seatNumber % cols] = 0; // Marking as Empty

                        delete Current; // Remove From the Queue

                        TicketCount--; // Decrement in Ticket Counter

                        ticketCanceled = true;
                    }
                    else
                    {
                        Prev = Current;
                        Current = Current->next;
                    }
                }
            }
        }

        // Finding Ticket in the Queue of Other Customers

        if (!ticketCanceled && Head != NULL)
        {
            // Ticket Found at Head

            if (Head->seatNumber == seatNumber)
            {
                Customer *NodeToDelete = Head;
                cout << "\n# Ticket : ";
                cout << "\nName : " << Head->name;
                cout << "\nSeat Number : " << Head->seatNumber;
                cout << "\nSuccessfully Canceled ";
                cout << "\n-----------------------------------------------------\n";

                arr[Head->seatNumber / cols][Head->seatNumber % cols] = 0; // Marking as Empty

                Head = Head->next;

                delete NodeToDelete; // Remove From the Queue

                TicketCount--; // Decrement in Ticket Counter

                ticketCanceled = true;
            }

            // Ticket Found at other than Head

            else
            {
                Customer *Prev = Head;
                Customer *Current = Head->next;

                while (Current != NULL && !ticketCanceled)
                {
                    if (Current->seatNumber == seatNumber)
                    {
                        Prev->next = Current->next;
                        cout << "\n# Ticket : ";
                        cout << "\nName : " << Current->name;
                        cout << "\nSeat Number : " << Current->seatNumber;
                        cout << "\nSuccessfully Canceled ";
                        cout << "\n-----------------------------------------------------\n";

                        arr[Current->seatNumber / cols][Current->seatNumber % cols] = 0; // Marking as Empty

                        delete Current; // Remove From the Queue

                        TicketCount--; // Decrement in Ticket Counter

                        ticketCanceled = true;
                    }
                    else
                    {
                        Prev = Current;
                        Current = Current->next;
                    }
                }
            }
        }

        if (!ticketCanceled)
        {
            cout << "\nTicket with seat number " << seatNumber << " not found or already entered in the Theater";
            cout << "\n-----------------------------------------------------\n";
        }
    }

    //-------------------------------------------- Function to Purchase ticket after Entry ---------------------------------------------->

    void PurchaseTicketAfterEntry(string name)
    {
        if (EntryCount < Size)
        {
            // Finding Empty Seat

            bool SeatIsEmpty = false;

            for (int i = 0; i < rows && !SeatIsEmpty; i++) // Update condition to include SeatIsEmpty
            {
                for (int j = 0; j < cols && !SeatIsEmpty; j++) // Update condition to include SeatIsEmpty
                {
                    if (arr[i][j] == 0)
                    {
                        SeatIsEmpty = true; // Empty Seat Founded

                        int seatNumber = i * cols + j;

                        arr[i][j] = 1; // Marking as Filled

                        TicketCount++; // Increment in Ticket Counter

                        cout << "\n# Normal Ticket : ";
                        cout << "\nName : " << name;
                        cout << "\nSeat Number : " << seatNumber;
                        cout << "\n-----------------------------------------------------\n";

                        // Add it to the Queue

                        Customer *newNode = new Customer(name, seatNumber);
                        if (Head == NULL)
                        {
                            Head = newNode;
                            Tail = newNode;
                        }
                        else
                        {
                            Tail->next = newNode;
                            Tail = newNode;
                        }
                    }
                }
            }

            if (!SeatIsEmpty)
            {
                cout << "\nTheater is FULL";
                cout << "\n-----------------------------------------------------\n";
            }
        }
        else
        {
            cout << "\nTheater is FULL";
            cout << "\n-----------------------------------------------------\n";
        }
    }
};

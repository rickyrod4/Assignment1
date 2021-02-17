#include <iostream>
#include <fstream>
#include <string>


using namespace std;

struct Flight{
    string departure;
    string arrival;
    string type;
    float price;
};
    Flight flight[100];

//CS 2308 Assignment 1
int readTickets(){
    // 1) “readTickets”. Given the file input stream, and empty array of 
    //flights, read the ticket file and return a size of an array.

    //Opening tickets file in order to read the data
    ifstream fin;
    fin.open("tickets.txt");
    if (!fin){
        cout << "error opening file"<< endl;
        return(0);
    }
        for(int i=0;i <sizeof(flight); i++){
        getline(fin, flight[i].departure,'\n');
        getline(fin, flight[i].arrival, '\n');
        getline(fin, flight[i].type, '\n');
        fin >> flight[i].price;
        fin >> ws;
    }

    return sizeof(flight);
};

void printTickets(){
    readTickets();
    // 2) “printTickets”. Given the array of tickets and its size it prints those tickets in a human readable format.
    cout.setf(ios::left);
    cout.width(25);
    cout << "From";
    cout.width(25); 
    cout << "To";
    cout.width(25);
    cout << "Type";
    cout.width(25);
    cout << "Price" << endl;
    for(int j = 0; j < 8; j++){
        cout.width(25);
        cout << flight[j].departure;
        cout.width(25); 
        cout << flight[j].arrival;
        cout.width(25); 
        cout << flight[j].type; 
        cout.width(25); 
        cout << fixed << setprecision(2) << flight[j].price << endl;

    }
    cout.unsetf(ios::left);

}
void printTicketsFromTo(){
    readTickets();
    // 3) “pringTicketsFromTo”. Given the array of tickets, its size and a city 
    //name it prints flights from the given city.
    string dummy;
    getline(cin, dummy);
    string departureCity, arrivalCity;
    cout << "Enter departure city: ";
    getline(cin, departureCity);
    cout << endl << "Enter arrival city: ";
    getline(cin, arrivalCity);

    cout.setf(ios::left); cout.width(25); 
    cout << "From"; cout.width(25); 
    cout << "To"; cout.width(25);
    cout << "Type"; cout.width(25);
    cout << "Price" << endl;
    for (int i = 0; i < sizeof(flight); i++){
        if(departureCity == flight[i].departure){
            if (arrivalCity == flight[i].arrival){
                        cout.width(25);
                        cout << flight[i].departure;
                        cout.width(25); 
                        cout << flight[i].arrival;
                        cout.width(25); 
                        cout << flight[i].type; 
                        cout.width(25); 
                        cout << fixed << setprecision(2) << flight[i].price << endl;
             }
        }
    }
    cout.unsetf(ios::left);

}

int findCheapestTicket(){
    readTickets();
    float cheapestTicket = flight[0].price;
    int flightIndex;

    for(int i = 0; i < 8; i++){
        if(flight[i].price < cheapestTicket){
            cheapestTicket = flight[i].price;
            flightIndex = i;
        }
    }

    return flightIndex;

}
int main(){
    readTickets();
    int choice;
    while(choice !=4){
        cout << "Select the actions:" << endl;
        cout << "1) Display all flights" << endl;
        cout << "2) Show the flights that depart from a given city" << endl;
        cout << "3) Find a flight with the best distance to price ratio" << endl;
        cout << "4) Exit the program" << endl;
        cin >> choice;

        if(choice == 1){
            printTickets();
            cout << "\n\n";
        } else if(choice == 2){
            printTicketsFromTo();
        } else if (choice == 3){
            int flightIndex = findCheapestTicket();
            cout << "The cheapest ticket cost is $" << fixed << setprecision(2) << flight[flightIndex].price << endl;
            cout << "From" << setw(25) << "To" << setw(25) << "Type" << setw(25) << "Price" << endl;
            cout << flight[flightIndex].departure << setw(25) << flight[flightIndex].arrival << setw(25) << flight[flightIndex].type 
            << setw(25) << fixed << setprecision(2) << flight[flightIndex].price << endl;;

            cout << "\n\n";
        } else if (choice == 4){
            return 0;
        }
        else {
            cout << "You did not enter one of the available options. Please Try Again" << endl;
        }
        
    }


    return 0;
}

//Finished



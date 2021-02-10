#include <iostream>
#include <fstream>

using namespace std;

//CS 2308 Assignment 1

int main(){

    //Opening tickets file in order to read the data
    ifstream fin;
    fin.open("tickets.txt");
    if (!fin){
        cout << "error opening file"<< endl;
        return(0);
    }
    
    int choice;
    cout << "Select the actions:" << endl;
    cout << "1) Display all flights" << endl;
    cout << "2) Show the flights that depart from a given city" << endl;
    cout << "3) Find a flight with the best distance to price ratio" << endl;
    cout << "4) Exit the program" << endl
}

//int readTickets(){
    // 1) “readTickets”. Given the file input stream, and empty array of 
    //flights, read the ticket file and return a size of an array.
}

//int printTickets(){
    // 2) “printTickets”. Given the array of tickets and its size it prints those tickets in a human readable format.

}

//int printTicketsFromTo(){
    // 3) “pringTicketsFromTo”. Given the array of tickets, its size and a city 
    //name it prints flights from the given city.
}


//int findCheapestTicket(){
    // 4) “findCheapestTicket”. Given the array of tickets, its size and “flightIndex” 
    //integer passed by reference it finds the highest dis- tance to price ratio, 
    //puts the index of the respective flight into “flightIndex” variable and returns the price. 
    //IMPORTANT: It should not print anything.
}

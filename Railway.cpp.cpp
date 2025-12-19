#include <iostream>
#include <string>
using namespace std;

class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    string trainTime;
    static int trainCount;

public:
    Train() : trainNumber(0) {
        trainName = "";
        source = "";
        destination = "";
        trainTime = "";
        trainCount++;
    }

    Train(int num, const string& name, const string& src, const string& dest, const string& time) 
        : trainNumber(num), trainName(name), source(src), destination(dest), trainTime(time) {
        trainCount++;
    }

    ~Train() {
        trainCount--;
    }

    void inputTrainDetails() {
        cout << "Enter Train Number: ";
        cin >> trainNumber;
        cin.ignore(); // Clear newline for getline
        
        cout << "Enter Train Name: ";
        getline(cin, trainName);
        
        cout << "Enter Source: ";
        getline(cin, source);
        
        cout << "Enter Destination: ";
        getline(cin, destination);
        
        cout << "Enter Train Time: ";
        getline(cin, trainTime);
    }

    void displayTrainDetails() const {
        cout << "Train Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Train Time: " << trainTime << endl;
        cout << endl;
    }

    int getTrainNumber() const {
        return trainNumber;
    }
    
    static int getTrainCount() {
        return trainCount;
    }
};

int Train::trainCount = 0;

class RailwaySystem {
private:
    Train trains[100];
    int totalTrains;

public:
    RailwaySystem() : totalTrains(0) {}

    void addTrain() {
        if (totalTrains < 100) {
            cout << "Adding Train " << totalTrains + 1 << ":" << endl;
            trains[totalTrains].inputTrainDetails();
            totalTrains++;
        } else {
            cout << "Train limit reached!" << endl;
        }
    }

    void displayAllTrains() const {
        if (totalTrains == 0) {
            cout << "No train records available." << endl;
        }
        for (int i = 0; i < totalTrains; i++) {
            cout << "Train " << i + 1 << " details:" << endl;
            trains[i].displayTrainDetails();
        }
    }

    void searchTrainByNumber(int number) const {
        bool found = false;
        for (int i = 0; i < totalTrains; i++) {
            if (trains[i].getTrainNumber() == number) {
                trains[i].displayTrainDetails();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Train with number " << number << " not found!" << endl;
        }
    }
};

int main() {
    RailwaySystem system;

    // Initial input: Enter at least three train records
    cout << "Enter initial train records (minimum 3): " << endl;
    for (int i = 0; i < 3; i++) {
        system.addTrain();
    }

    int choice;
    do {
        cout << "\n--- Railway Reservation System Menu ---\n";
        cout << "1. Add New Train Record\n";
        cout << "2. Display All Train Records\n";
        cout << "3. Search Train by Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system.addTrain();
            break;
        case 2:
            system.displayAllTrains();
            break;
        case 3: {
            int searchNumber;
            cout << "Enter Train Number to search: ";
            cin >> searchNumber;
            system.searchTrainByNumber(searchNumber);
            break;
        }
        case 4:
            cout << "Exiting the system. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

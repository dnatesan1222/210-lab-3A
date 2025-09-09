// COMSC-210 | Lab 3A | Diksha Tara Natesan
// IDE used: VIM/Terminal


#include <iostream>
#include <string>
using namespace std;

struct Restaurant {
    int maxTotal;       // maximum number of people the restaurant can serve
    string name;        // restaurant name
    string cuisine;     // restaurant's type of cuisine
    double rating;      // restaurant's rating out of 5.0
    string owner;       // owner's name
};


//createRestaurant() takes user input to create a Restaurant object
Restaurant createRestaurant() {
    
    Restaurant temp;

    cout << "Restaurant name: ";
    getline(cin, temp.name);

    cout << "Cuisine type: ";
    getline(cin, temp.cuisine);

    cout << "Owner's name: ";
    getline(cin, temp.owner);

    int max;
    cout << "Max customer occupancy: ";
    while (!(cin >> max)){
        cout << "Please enter a positive integer.\nMax customer occupancy: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    temp.maxTotal = max; //what if the user input is a negative number

    double rating;
    cout << "Restaurant rating (1.0-5.0 star scale): ";
    cin >> rating;
    while ((rating < 1.0) || (rating > 5.0)){
        cout << "Error: Please enter a value in the range 1.0-5.0\nRestaurant rating (1.0-5.0 star scale): ";
        cin >> rating;
    } 
    temp.rating = rating;
    cout << endl;

    // returns: a Restaurant struct based upon the user's input
    return temp;
}


// displayRestaurant() outputs a Restaurant object's data
// arguments: takes in a restaurant object to use to output its information
void displayRestaurant(Restaurant r) {
    cout << "Restaurant Name: " << r.name << endl;
    cout << "Cuisine Served: " << r.cuisine << endl;
    cout << "Owner: " << r.owner << endl;
    cout << "Max Occupancy: " << r.maxTotal << endl;
    cout << "Rating: " << r.rating << " / 5.0\n" << endl;
}

int main(){
    Restaurant olive = {100, "Olive Garden", "Italian", 2.5, "Maria Zimmer"};
    Restaurant imperial = {80, "Imperial Delight", "Chinese", 4.8, "Zoe Woon"};
    Restaurant taco = {50, "Taco Bell", "Mexican", 3.1, "Sam Martin"};

    // restaurant from user input
    cout << "Create a new restaurant entry:\n";
    Restaurant userInput = createRestaurant();

    // display all restaurants
    displayRestaurant(olive);
    displayRestaurant(imperial);
    displayRestaurant(taco);
    displayRestaurant(userInput);

}

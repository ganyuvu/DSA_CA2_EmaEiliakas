#include <iostream>
#include <string>
#include "TreeMap.h"
#include "BinaryTree.h"
#include "ReadFile.h"

using namespace std;

void displayMenu();

int main() {

    TreeMap<char, BinaryTree<string>> letterTreeMap;

    string fileName = "testTextFile.txt"; //setting file path to a variable

    //calls readWords() from readFile, gives it the filename and populates letterTreeMap
    ReadWords(fileName, letterTreeMap);

    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (choice == 1) {

            cout << "\nLetters in the TreeMap:" << endl;
            //calls keySet method in treeMap and returns the keySet to the tree keys
            BinaryTree<char> keys = letterTreeMap.keySet();

            keys.printInOrder(); //calls printInOrder from BinaryTree 
        }

        else if (choice == 2) {
            char letter;

            cout << "\nEnter a letter: ";
            cin >> letter;
            letter = tolower(letter);

            if (letterTreeMap.contains(letter)) {

                //getting the tree reference with its values based on the key (letter)
                BinaryTree<string>& words = letterTreeMap.get(letter);

                cout << "\nWords starting with '" << letter << "': " << endl;
                words.printInOrder(); //calls printInOrder from BinaryTree 
            }
           
            else {
                cout << "\nThere are no words for the letter '" << letter << "'" << endl;
            }
        }
        
        else if (choice == 3) {
            cout << "\nGoodbyeeee" << endl;
        }

        //if user types anything but 1, 2 or 3 it will send this message
        else {
            cout << "\nError, please try again" << endl;
        }
    } 
    
    while (choice != 3);

    return 0;
}

void displayMenu() {
    cout << "\n=====Menu=====" << endl;
    cout << "1. Display letters" << endl;
    cout << "2. Display words starting with a letter" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice of number: ";
}
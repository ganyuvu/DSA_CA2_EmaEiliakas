#include <iostream>
#include <string>
#include "TreeMap.h"
#include "BinaryTree.h"
#include "ReadTextFile.h"
#include "CatData.h"

using namespace std;

void displayMenu();
void openTextFile();
void openCSVFile();

int main() {

    int fileChoice;

    cout << "Choose file you would like to open:" << endl;
    cout << "1. Text file" << endl;
    cout << "2. CSV file" << endl;
    cout << "Enter choice: ";

    cin >> fileChoice;

    if (fileChoice == 1) {

        openTextFile();
        
    }

    else if (fileChoice == 2) {
        openCSVFile();
    }

    else {
        cout << "\nError, please try again" << endl;
    }


}

void openTextFile() {
    TreeMap<char, BinaryTree<string>> letterTreeMap;

    string fileName = "testTextFile.txt"; //setting file path to a variable
    ReadWords(fileName, letterTreeMap);  //calls readWords() from readFile, gives it the filename and populates letterTreeMap

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

    return;
}

void openCSVFile() {

    TreeMap<int, CatData> dataMap;

    string fileName = "CatCSVData.csv"; // setting file path to a variable

    dataMap = readCSVFile(fileName); // calls readCSVFile() in CatData to parse CSV


    int choice;

    do {

        cout << "\n=== CSV Options ===" << endl;
        cout << "1. View data" << endl;
        cout << "2. Index data by field" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nCAT DATA (1-100):\n" << endl;

            dataMap.printInOrder();  
        }
        else if (choice == 2) {

            string field;
            cout << "\nFields you can index: (cat_name, breed, age, weight, vaccination_status): ";
            cin >> field;

            //creating a treemap to store the key and the count
            TreeMap<string, int> index;

            // tryna get the root node here
            BSTNode<MapPair<int, CatData>>* root = dataMap.getRoot();  

            // calling the indexdata from catData
            indexData(root, index, field);  

            cout << "\nIndexed data for field: " << field << endl;
            index.printInOrder();  

        } 
        
        else if (choice == 3) {
            cout << "\nGoodbyeeee" << endl;
        } 
        
        else {
            cout << "\nError, please try again" << endl;
        }
    } while (choice != 3);

}

void displayMenu() {
    cout << "\n=====Menu=====" << endl;
    cout << "1. Display letters" << endl;
    cout << "2. Display words starting with a letter" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter choice of number: ";
}


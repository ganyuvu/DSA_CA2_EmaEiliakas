#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <iomanip>
#include "BinaryTree.h"
#include "TreeMap.h"

using namespace std;

struct CatData {
    int cat_id;
    string cat_name;
    string breed;
    int age;
    float weight;
    bool vaccination_status;

    // Default constructor
    CatData();

    // Parameterized constructor
    CatData(int cat_id, string cat_name, string breed, int age, float weight, bool vaccination_status);

    // Less than operator (compares by cat_id)
    bool operator<(CatData& other) {
        return cat_id < other.cat_id;
    }

    // Greater than operator (compares by cat_id)
    bool operator>(CatData& other) {
        return cat_id > other.cat_id;
    }

    // Equals operator (compares by cat_id)
    bool operator==(CatData& other) {
        return cat_id == other.cat_id;
    }
};

// Overloading << operator to print CatData
ostream& operator<<(ostream& os, const CatData& cat);

// Function to read data from a CSV file and return a BinaryTree of CatData
TreeMap<int, BinaryTree<CatData>> readCSVFile(const string& fileName);


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

    CatData();

    CatData(int cat_id, string cat_name, string breed, int age, float weight, bool vaccination_status);

   friend ostream& operator<<(ostream& out, const CatData& cat) {
        out << " Name: " << cat.cat_name << ", Breed: " << cat.breed
            << ", Age: " << cat.age << ", Weight: " << cat.weight << "kg, Vaccination Status: "
            << (cat.vaccination_status ? "Vaccinated" : "Not vaccinated");
        return out;
    }

};

TreeMap<int, CatData> readCSVFile(const string& fileName);



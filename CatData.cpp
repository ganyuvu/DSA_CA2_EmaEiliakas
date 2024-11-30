#include "CatData.h"

using namespace std;

CatData::CatData(){}

CatData::CatData(int cat_id, string cat_name, string breed, int age, float weight, bool vaccination_status) {
    this->cat_id = cat_id;
    this->cat_name = cat_name;
    this->breed = breed;
    this->age = age;
    this->weight = weight;
    this->vaccination_status = vaccination_status;
}

// method to read data from a CSV file 
//learnt about parsing more here, like using ss.ignore: https://labex.io/tutorials/cpp-how-to-use-stringstream-in-c-425236
TreeMap<int, BinaryTree<CatData>> readCSVFile(const string& fileName) {

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Unable to open file: " << fileName << endl;
        return {};
    }

    string line;

    TreeMap<int, BinaryTree<CatData>> dataMap;

    // skipping the header line
    getline(file, line);

    while (getline(file, line)) {

        stringstream ss(line);

        int cat_id;
        string cat_name;
        string breed;
        string vaccination_status;
        int age;
        float weight;
        bool status;

        // parsing CSV line
        ss >> cat_id;
        ss.ignore();  // this ingores the comma after cat_id
        getline(ss, cat_name, ',');
        getline(ss, breed, ',');
        ss >> age;
        ss.ignore();
        ss >> weight;
        ss.ignore();
        getline(ss, vaccination_status, ','); //getting vacination status as string first

        // we then convert the vacination status to bool
        status = (vaccination_status == "true");

        CatData row(cat_id, cat_name, breed, age, weight, status);

        // Add to TreeMap with cat_id as the key
        if (dataMap.contains(cat_id)) {
            dataMap.get(cat_id).add(row);
        }
        else {
            BinaryTree<CatData> newTree;
            newTree.add(row);
            dataMap.put(cat_id, newTree);
        }
    }

    file.close();
    return dataMap;
}
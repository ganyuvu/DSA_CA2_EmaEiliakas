#include "CatData.h"

using namespace std;

CatData::CatData() 
    : cat_id(0), cat_name(""), breed(""), age(0), weight(0.0f), vaccination_status(false) {}

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
TreeMap<int, CatData> readCSVFile(const string& fileName) {

    TreeMap<int, CatData> dataMap;

    ifstream file(fileName);

    if (!file.is_open()) {
        cout << "Unable to open file: " << fileName << endl;
        return dataMap;
    }

    string line;


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

        CatData catRow(cat_id, cat_name, breed, age, weight, status);

        // ddd the CatData object to the TreeMap
        dataMap.put(cat_id, catRow);
    }

    file.close();
    return dataMap;
}

// method that will index data based on the given field by the user
void indexData(BSTNode<MapPair<int, CatData>>* root, TreeMap<string, int>& index, string field) {

    if (root == nullptr) {
        return; //stops the recursion if the node is null
    }

    string keyValues; // will store the values under the key that's been selected

    // gets the CatData values from the MapPair stored in the node
    const CatData& cat = root->getItem().value;

    // checking if the field inputted by the user matches the one in the tree
    if (field == "cat_name") {
        keyValues = cat.cat_name;
    }
    else if (field == "breed") {
        keyValues = cat.breed;
    }
    else if (field == "age") {
        keyValues = to_string(cat.age);
    }
    else if (field == "weight") {
        keyValues = to_string(cat.weight);
    }
    else if (field == "vaccination_status") {
        keyValues = cat.vaccination_status ? "Vaccinated" : "Not Vaccinated";
    }
    else {
        // error message
        cout << "Not a valid field name, please try again!" << endl;
        return;
    }

    // if a key containts the same key values 
    if (index.contains(keyValues)) {

        // should increment by 1 but it wont work for some reason

        int currentCount = index.get(keyValues);
        index.put(keyValues, currentCount + 1); //if the key values already in the tree it will increment by 1
    }
    else {
        //if the key values dont exist in the tree yet we leave it at 1
        index.put(keyValues, 1);
    }

    //recursively goes through the entire tree, node by node, starting on the left first
    indexData(root->getLeft(), index, field);
    indexData(root->getRight(), index, field);
}
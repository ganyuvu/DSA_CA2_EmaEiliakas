#include "readTextFile.h"
#include <fstream>

using namespace std;

//used code from previous bugs Life project to help write this section: https://github.com/ganyuvu/CA2_BugsLife_Ema_Eiliakas_D00255056/blob/master/Board.cpp
void ReadWords(const string& fileName, TreeMap<char, BinaryTree<string>>& letterTreeMap) {

    ifstream file(fileName); //opens file

    //checks if file was opened
    if (!file.is_open()) {

        cout << "Unable to open file: " << fileName << endl;
        return;
    }

    string word;

    while (file >> word) {

        //making sure word has characters, if not it will skip any blank space
        if (!word.empty()) {

            // converting the whole word to lowercase, to prevent case sensetivity 
            for (size_t i = 0; i < word.size(); ++i) {
                word[i] = tolower(word[i]); //goes through each char of the word and changed it to lowercase
            }

            char firstLetter = word[0];

            //checking if the first letter already has a tree
            if (!letterTreeMap.contains(firstLetter)) {
                //if the letter doesnt have a tree we make a new binary tree for it
                BinaryTree<string> newWordTree;

                // puts the new tree into the map, the first letter is used as the key
                // the new tree will store words starting with that letter
                letterTreeMap.put(firstLetter, newWordTree);
            }

            // we find the reference of the tree based on the key (first letter of the word we want to add)
            BinaryTree<string>& wordTree = letterTreeMap.get(firstLetter);

            wordTree.add(word); // then we add it to the tree

        }

    }

    file.close(); //closing the txt file

}

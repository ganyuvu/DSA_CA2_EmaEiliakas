#pragma once
#include "BSTNode.h"
#include "BinaryTree.h"
#include "MapPair.h"
#include <iostream>
#include <stdexcept>

//using template class as the code given also uses it and it will be easy to work with any type
template <class K, class V>
class TreeMap
{
private:
    //making an instance of a binary tree that stores the key and value pair
    BinaryTree<MapPair<K, V>> tree;

public:
    TreeMap(); //constructor 

    //tree map methods that we will implement 
    void clear();
    bool contains(K key);
    V& get(K key);
    BinaryTree<K> keySet();
    void put(K key, V value);
    int size();
    bool removeKey(K key);
    V operator[](K key);

    ~TreeMap(); //destructor

};

//defualt contructor 
template <class K, class V>
TreeMap<K, V>::TreeMap() {}

//method to clear all entries from map
//clear() is called from BinaryTree
template <class K, class V>
void TreeMap<K, V>::clear() {
    tree.clear();
}

// checks if a mapPair is in the treeMap by looking up the key
template <class K, class V>
bool TreeMap<K, V>::contains(K key) {
    MapPair<K, V> searchPair(key, V()); // creating a mapPair with the key we want to search and a default value for V
    try {
        tree.get(searchPair); ////tries to get the mapPair by the key 
    }
    catch (logic_error) {
        return false; // will return false if the key doesnt match any pair
    }
    return true;
}

template<class K, class V>
inline V& TreeMap<K, V>::get(K key)
{
    MapPair<K, V> searchPair(key, V()); // creating a mapPair with the key we want to search and a default value for V

    try {
        // calling get() from binary tree
        MapPair<K, V>& searchResult = tree.get(searchPair);

        // only returning the value from the searchResult
        return searchResult.value;
    }
    catch (logic_error) {
        //returns null if key isnt found
        return nullptr;
    }

}

template<class K, class V>
inline BinaryTree<K> TreeMap<K, V>::keySet()
{
    return BinaryTree<K>();
}

// removes the mapPair that has the given key
//calling the remove() method in BinaryTree
template <class K, class V>
bool TreeMap<K, V>::removeKey(K key) {

    MapPair<K, V> removePair(key, V());

    return tree.remove(removePair); // similarly to contains method, removes mapPair by the key
}

template<class K, class V>
inline V TreeMap<K, V>::operator[](K key)
{
    return get(key);
}

//adds new mapPair to binary tree
template <class K, class V>
void TreeMap<K, V>::put(K key, V value) {

    MapPair<K, V> addPair(key, value);

    tree.add(addPair); // adds a mapPair to the binary tree
}

template<class K, class V>
inline int TreeMap<K, V>::size()
{
    return tree.count();
}

//destructor, will clean up nodes when treeMap is removed
template <class K, class V>
TreeMap<K, V>::~TreeMap() {
}

  



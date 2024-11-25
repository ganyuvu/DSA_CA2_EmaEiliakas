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
    TreeMap();

    //tree map methods that we will implement 
    void clear();
    bool contains(K key);
    V& get(K key);
    BinaryTree<K> keySet();
    void put(K key, V value);
    int size();
    bool removeKey(K key);
    V operator[](K key);

    ~TreeMap();

};



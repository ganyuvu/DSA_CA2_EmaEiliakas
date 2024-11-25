#pragma once

//using template class as the code given also uses it and it will be easy to work with any type
template <typename K, typename V>
class MapPair {
public:
    K key;
    V value;

    // default constructor
    MapPair() {

    }

    // constructor
    MapPair(K key, V value) {
        this->key = key;
        this->value = value;
    }


    // less than operator
    bool operator<(MapPair<K, V>& other) {
        return key < other.key;
    }

    // greater than operator 
    bool operator>(MapPair<K, V>& other) {
        return key > other.key;
    }

    // equals operator
    bool operator==(MapPair<K, V>& other) {
        return key == other.key;
    }

    void setValue(V v) {
        value = v;
    }

    K getKey() {
        return key;
    }

    V getValue() {
        return value;
    }
};
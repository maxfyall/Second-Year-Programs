/*
    Name: Max Fyall
    Matriculation Number: 180011724
    Module Code: AC21008
*/

#ifndef MY_HASH_NODE
#define MY_HASH_NODE

using namespace std;

template <class KeyType, class ValueType>
class HashNode {
  KeyType key;     // The hash node's key
  ValueType value; // The key's associated data
  bool occupied = false; // boolean to determine if space is occupied
  /* extend if necessary */

public:

  HashNode();  // constructor

  KeyType getKey() { return key; }
  ValueType getValue() { return value; }
  bool getOccupied() { return occupied; }
  void assign(KeyType key, ValueType value);
  void setOccupied(bool);

  // extend if necessary
};

// constructor
template<class KeyType,class ValueType>
HashNode<KeyType,ValueType>::HashNode(){
  occupied = false; // set occupied to false
}

// assign values to parameters passed in
template <class KeyType, class ValueType>
void HashNode<KeyType,ValueType>::assign(KeyType inputKey, ValueType inputValue){

  key = inputKey; // set key to parameter
  value = inputValue; // set value to parameter
  occupied = true; // set occupied to true, assuming we are adding a node to the table
  
}

// set occupied to a set value
template <class KeyType, class ValueType>
void HashNode<KeyType,ValueType>::setOccupied(bool newState){
  occupied = newState; // set occupied to parameter, most likly to false as we will be erasing a node
}

/* 
   Implement the constructor, the assign method 
   and any methods that you may additionally need for the HashTable to work.
*/

#endif

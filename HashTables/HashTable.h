/*
    Name: Max Fyall
    Matriculation Number: 180011724
    Module Code: AC21008
*/

#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

template <class KeyType, class ValueType>
class HashTable {
  typedef vector <HashNode<KeyType,ValueType> > Table;
  Table *table; // size of table (# of buckets) is stored in the Table data structure
  int num;   // number of entries stored in the HashTable;

public:
  HashTable();        // constructor, initializes table of size 11;
  HashTable(int);  // constructor, requires size of table as arg
  ~HashTable();       // deconstructor
  vector <HashNode<KeyType,ValueType>>* getTable(); // return the table pointer

  int size();      // returns size of the hash table (number of buckets)
  int hash_function(KeyType);  // the table's hash function
  ValueType getValue(KeyType);    // find and return data associated with key

  void insert(KeyType,ValueType); // insert data associated with key into table
  void erase(KeyType);            // remove key and associated data from table

  void rehash(int); // sets a new size for the hash table, rehashes the hash table 
  // extend if necessary
};

// constructor, to initialise table
template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable(){

  table = new Table(); // create a new table
  table->reserve(11); // reserve storage for elements in table
  table->resize(11); // set the size of the table

}

// constructor to create the table of size length
template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::HashTable(int length){

  if (length < 1) // check if the size is less than one
  {
    table = new Table(); // create a new table
    table->reserve(11); // reserve storage for elements in table
    table->resize(11); // set the size of the table
  }
  else // if the size is no less than 1
  {
    table = new Table(); // create new table
    table->reserve(length); // reserve storage for elements in table
    table->resize(length); // set the size of the table to parameter length
  }

}

// deconstructor
template <class KeyType, class ValueType>
HashTable<KeyType,ValueType>::~HashTable(){

  table->clear(); // clear the table of all elements
  delete(table); // delete the table

}

// returns the size of the hash table
template <class KeyType, class ValueType>
int HashTable<KeyType,ValueType>::size() {
  return table->size(); // return the size of the table
}

// returns the table pointer
template <class KeyType, class ValueType>
vector <HashNode<KeyType,ValueType>>*
HashTable<KeyType,ValueType>::getTable(){
  return table; // return a pointer to the table
}

// hash function for the table
template <class KeyType, class ValueType>
int HashTable<KeyType,ValueType>::hash_function(KeyType inputKey){

  hash<KeyType> hashVal; // use hash class to generate hash value for key
  int index = (hashVal(inputKey) % size()); // generate our index in the table by taking the modulus of our hash value and the size of the table

  return index; // return the index
}

// find and return data associsted with key
template <class KeyType, class ValueType>
ValueType HashTable<KeyType,ValueType>::getValue(KeyType inputKey){

  int location = hash_function(inputKey); // get the location of the key in the table
  bool found = false; // create boolean variable

  // loop through all the elements in the table
  for (int i = 0; i < size(); ++i)
  {
    if (table->at(i).getKey() == inputKey) // check if the key at that location is the same as the key provided
    {
      found = true; //  if so then set found to true
      location = i; // update our position
      break; // get out of the loop
    }
  }

  if (found) // check if we found the key in the table
  {

      ValueType valueToFind = table->at(location).getValue(); // create new ValueType variable and set it to the ValueType of the current node in the table
      return valueToFind; // return the value

  }
  else // or if we couldn't find the key
  {
    cout << "Key was not found" << endl; // print message
    throw KEY_NOT_FOUND; // throw error
  }


}

// insert data associated with key into table
template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::insert(KeyType inputKey,ValueType inputValue){

  int index = hash_function(inputKey); // get the location to store our new node

  HashNode<KeyType,ValueType> newNode; // create a new node

  newNode.assign(inputKey, inputValue); // assign data to the new node

  if (table->at(index).getOccupied() == true) // check if the slot the node has been allocated is occupied
  {
    while(table->at(index).getOccupied() == true) // loop unitl we find an empty space
    {
        if (index == size()-1) // check if we have reached the end of the table
        {
          index = 0; // go back to the start of the table
        }
        if (num+1>size()*0.75) // if we reach a point where the table is filling up
        {
          rehash(2*size()); // rehash the table
        }

        index++; // add one to the index to move up the table
    }
  }

  table->at(index) = newNode; // insert the new node at the given space in the table

  num++; // add one to variable num to indicate a node has been added
}

// remove key and data from the table
template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::erase(KeyType inputKey){

  int location = hash_function(inputKey); // get the location of our node

  if (table->at(location).getKey() != inputKey) // check if the location has the node we want to delete
  {
    location = 0; // set location to 0, so we can search through the table

    while(table->at(location).getKey() != inputKey) // loop until we find the node we are looking for
    {
      if (location == size()-1) // check if we have reached the end of the table
      {
        cout << "Key was not found" << endl; // print error message
        throw KEY_NOT_FOUND; // throw error
        break; // break out of loop
      }
      else // otherwise
      {
        location++; // add one to location
      }
        
    }

  }
  // create empty variables to store in the node we wish to delete
  KeyType emptyKey{};
  ValueType emptyValue{};

  table->at(location).assign(emptyKey, emptyValue); // assign the node we wish to delete empty variables
  table->at(location).setOccupied(false); // set node's boolean value to false to indicate it is empty

}

// set new size for the table and rehash the table
template <class KeyType, class ValueType>
void HashTable<KeyType,ValueType>::rehash(int newLength){

  int prevLength = size(); // store the length of the original table

  table->resize(newLength); // resize the table to the new length provided

  int i = 0; // create index variable

  while(i>prevLength) // loop until we have rehashed our old nodes into our new table
  {
    if (table->at(i).getOccupied()) // check if the node is occupied i.e. does it have data in it
    {
      KeyType key; // create a new key

      key = table->at(i).getKey(); // store the key of the current table slot inside

      int newHash = hash_function(key); // hash the key to gain a new/similar index

      if (i != newHash) // check if the locations are different
      {
          table->at(newHash) = table->at(i); // place the node at the new index

          erase(table->at(newHash).getKey()); // erase the node in the old index
      }
    }

    i++; // add one to counter variable
  }

}

/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/
#endif

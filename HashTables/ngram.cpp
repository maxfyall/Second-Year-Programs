/*
	Name: Max Fyall
	Matriculation Number: 180011724
	Module Code: AC21008
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include "HashTable.h"
using namespace std;

class Ngram{

public:

	string readInputFile();
	vector<string> trigramCalc();

};

// read in the data from file given from user if the file exist
string readInputFile()
{
	string line; // create string to store data from file
	string statement; // create string to store the data as one string
	

	// create read file object to read from the file inputfile.txt
	ifstream fp("inputfile.txt");

	if (!fp) // check if the file failed to open
	{
		// print error message
		cout<< "Error Opening File, Please try again"<<endl;
		exit(0); // End the program
	}

	// loop until there is no data left in the file
	while(getline(fp, line))
	{
		statement = statement + line; // store the data inside string variable
	}

	fp.close(); // close the file stream

	for (int i = 0; i < statement.size(); ++i) // loop for the length of the string
	{
		if (statement[i] == ' ') // if we reach a blank space
		{
			statement[i] = '_';
			// convert it to an underscore so it will be easier to read
			// and easier for our ngram algorithm
		}
	}

	return statement; // return our string
}

// convert string read in from inputfile.txt into trigrams
vector<string> trigramCalc()
{
	string toConvert = readInputFile(); // stores data from inputfile.txt in string

	vector <string> trigrams; // create string vector to store trigrams
	trigrams.assign(toConvert.size()-2, ""); // assign


	// loop until we have reach the final trigram
	for (int i = 0; i < trigrams.size(); ++i)
	{
		// create a new trigram
		trigrams[i] = (trigrams[i]+toConvert[i])+(trigrams[i]+toConvert[i+1])+(trigrams[i]+toConvert[i+2]);
	}

	return trigrams; // return all the trigrams

}


int main()
{
	// create new vector to store all the trigrams
	vector<string> ngram = trigramCalc();

	// create a new hash table
	HashTable<string,int> FreqTable(ngram.size()*2);

	bool found = false; // create boolean variable

	/* CALCULATING FREQUENCY WITH HASH TABLE */

	// loop for the length of the ngram vector
	for (int i = 0; i < ngram.size(); ++i)
	{
		// loop through all elements in the table to check for duplicates
		for (int j = 0; j < FreqTable.size(); ++j)
		{
			// check if we have a duplicate key
			if (FreqTable.getTable()->at(j).getKey() == ngram[i])
			{
				// if so set found to true, so we don't add the duplicate
				found = true;
				// increment the existing node's frequency by 1
				FreqTable.getTable()->at(j).assign(FreqTable.getTable()->at(j).getKey(), FreqTable.getTable()->at(j).getValue()+1);
				break; // break out of the loop
			}
			else // if we dont have a match
			{
				found = false; // then set found to false
			}
		}
		// check if we had any duplicates
		if (!found)
		{
			FreqTable.insert(ngram[i], 1); // if not then add te ngram to the table
		}
	}

	/* SORTING */

	// create 2 empty vectors, one for storing the frequency and one to store the matching keys
	vector<int> Freq;
	vector<string> keys;

	// initialise the vectors, the vectors know look like Freq {0} and keys {""}
	Freq.resize(1);
	keys.resize(1);

	// loop for the length of the hash table
	for (int j = 0; j < FreqTable.size(); ++j)
	{
		// check if the node has data inside
		if (FreqTable.getTable()->at(j).getOccupied())
		{
			// check if the value inside is bigger than the first item in the frequency vector
			if (FreqTable.getTable()->at(j).getValue() >= Freq.front())
			{
				// check if the frequency vector is not empty i.e. we have already put stuff inside
				if (Freq.front() != 0)
				{
					// insert the key and value at the beginning of their respective vectors 
					Freq.insert(Freq.begin(), FreqTable.getTable()->at(j).getValue());
					keys.insert(keys.begin(), FreqTable.getTable()->at(j).getKey());
				}
				else // or if the vector is empty i.e. the only value inside is 0
				{
					// insert the key and value into their respective vectors
					Freq[0] = FreqTable.getTable()->at(j).getValue();
					keys[0] = FreqTable.getTable()->at(j).getKey();
				}
			}
			else // or if the value inside the node is less than the value at the front of the vector
			{
				// insert the key and value at the end of their respective vectors
				Freq.insert(Freq.end(), FreqTable.getTable()->at(j).getValue());
				keys.insert(keys.end(), FreqTable.getTable()->at(j).getKey());
			}
		}
	}


	/* GET THE TOTAL FREQUENCY OF THE ELEMENTS IN HASHTABLE */

	int totalNum = 0; // create total number variable

	for (int i = 0; i < FreqTable.size(); ++i) // loop for the length of the table
	{
		if (FreqTable.getTable()->at(i).getOccupied()) // check if the node has data inside
		{
			totalNum = totalNum + FreqTable.getTable()->at(i).getValue(); // add the frequency value to the total value
		}
	}

	/* PRINTING FREQUENCIES */

	double percentage; // create percentage variable

	// loop 10 times to get the 10 most frequent items
	for (int i = 0; i < 10; ++i)
	{
		// calculate the frequency as a percentage
		percentage = static_cast<double>(Freq[i])/totalNum*100;
		// print the percentage and the trigram in the required format
		cout << fixed << setprecision(2) << percentage << ":" << keys[i] << endl;
	}

	return 0;
}


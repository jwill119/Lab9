// main.cpp
// COSC 2030 lab 9
// Jacob Williams
// Created: 12/3/2018
// Last modified: 12/3/2018

// The map sorter main file.

#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// The functions

// Reads the functions into a map, counting the number of times they appear.
map<string,int> readIn(string filename) {
    ifstream theFile;
    theFile.open(filename);
    string word;
    word.clear();

    map<string,int> theCount;

    while (theFile >> word) {
        ++theCount[word];
    }

    theFile.close();

    return theCount;
}

// Writes a tally-map to a text file.
void writeOut(map<string,int> theCount) {
    ofstream outFile("output.txt");

    map<string,int>::iterator in;
    for (in = theCount.begin(); in != theCount.end(); in++) {
        for (int i = 0; i < in->second; i++) {
            outFile << in->first << " ";
        }
    }

    outFile.close();
    return;
}

int main() {

    cout << "Reading color words from 'example.txt'." << endl << endl;
    map<string,int> counts = readIn("example.txt");
    writeOut(counts);

    return 0;
}

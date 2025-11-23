/* 
   Spellcheck.cpp
   CSC242 - Spell Checking Program
   This program loads a dictionary file (wordlist.txt)
   and reports any words in the input file that are not found
   in the dictionary.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

//Alex C., Danielle A., & Rene N.

// Helper function: turn a word into lowercase and remove punctuation
string normalize(const string& word) {
    string result;

    for (char c : word) {
        if (isalpha(static_cast<unsigned char>(c))) {
            result.push_back(static_cast<char>(tolower(static_cast<unsigned char>(c))));
        }
    }

    return result;
}

// Check if a word is in the dictionary vector
bool inDictionary(const vector<string>& words, const string& target) {
    for (const string& w : words) {
        if (w == target) {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    // We expect: Spellcheck <file-to-check>
    if (argc < 2) {
        cerr << "Usage: Spellcheck <file-to-check>\n";
        return 1;
    }

    // Dictionary filename
    string dictFilename = "wordlist.txt";   
    string inputFilename = argv[1];         

    // 1) Open the dictionary file
    ifstream dictFile(dictFilename);
    if (!dictFile) {
        cerr << "Error: Could not open dictionary file: " << dictFilename << endl;
        return 1;
    }

    // 2) Define a vector of strings called words
    vector<string> words;

    // 3) For each word in the dictionary file, append it to the words vector
    string dictWord;
    while (dictFile >> dictWord) {
        string norm = normalize(dictWord);
        if (!norm.empty()) {
            words.push_back(norm);
        }
    }

    dictFile.close();

    // 4) Open the file to be checked
    ifstream inputFile(inputFilename);
    if (!inputFile) {
        cerr << "Error: Could not open input file: " << inputFilename << endl;
        return 1;
    }

    cout << "Misspelled or unknown words in \"" << inputFilename << "\":" << endl;

    // 5) For each word in that file
    string fileWord;
    while (inputFile >> fileWord) {
        string norm = normalize(fileWord);
        if (norm.empty()) {
            continue;
        }

        // If the word is not contained in the words vector, print it
        if (!inDictionary(words, norm)) {
            cout << norm << endl;
        }
    }

    inputFile.close();

    return 0;
}

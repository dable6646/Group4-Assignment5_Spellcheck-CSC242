## Assignment 5 Group 4 Project - CSC242 - Q. 8.2
## Group 4 Members: Alex Carris, Rene Navarro, & Danielle Able

## Purpose:
- This program checks the spelling of words in a text file by comparing each word to a dictionary list stored in `wordlist.txt`.
- Any word **not found** in the dictionary is reported as a possible misspelling.
- This assignment follows the instructions for Problem 8.2 from the CSC242 textbook.

## How the Spell Checker Works

1. The program opens the dictionary file: `wordlist.txt`.
2. All words in the dictionary file are read, normalized (lowercased, letters only), and loaded into a vector.
3. The program then opens the file to be checked (ex: `sample_input.txt`).
4. Each word from the input file is normalized the same way.
5. If a word is **not found** in the dictionary vector, it is printed to the console as an unknown/misspelled word.

Normalization includes:
- Converting letters to lowercase  
- Removing punctuation  
- Ignoring numeric and symbol characters  

## Files Included in This Program
- **Spellcheck.cpp**: source code for the spell checker  
- **wordlist.txt**: dictionary word list used for verification  
- **sample_input.txt**: sample text file used for testing  
- **wordlist_updated.txt** *(optional)*: expanded dictionary list  

## Building / Compiling

Testing from inside the project folder:

- You must download and install **g++ (MinGW-w64 / WinLibs)** to compile this program.  
  > To install this, visit: https://winlibs.com/  
  > Download the latest *win64* GCC release if using Windows.  
  > Extract it and add the `bin` folder to your system PATH.

## Compile Program:

```bash
g++ -std=c++11 -o Spellcheck Spellcheck.cpp

## Testing Program:
>> After compiling the program you should see the 'Spellcheck.exe' program file
>> Now Run the following: .\Spellcheck sample_input.txt

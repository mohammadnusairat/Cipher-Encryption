#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // 26 letters in the English Language

// Function prototypes at the top of the file for function decomposition

/**
 * Print instructions for using the program.
 */
void printMenu();
/**
 * Returns the 0-based index in the English alphabet where `c` appears,
 * or -1 if `c` is not an uppercase letter in the alphabet.
 *
 * For example:
 *  - `findIndexInAlphabet('A')` returns 0
 *  - `findIndexInAlphabet('D')` returns 3
 *  - `findIndexInAlphabet('+')` returns -1
 *  - `findIndexInAlphabet('a')` returns -1
 */
int findIndexInAlphabet(char c);
/**
 * Returns `c` rotated by `amount` many characters forward. If we run out
 * of letters in the alphabet, wrap around back to 'A'. This method
 * assumes that `c` is an uppercase letter.
 * For example:
 *  - `rot('A', 0)` returns 'A'
 *  - `rot('A', 1)` returns 'B'
 *  - `rot('Z', 1)` returns 'A'
 *  - `rot('A', 10)` returns 'K'
 *  - `rot('J', 25)` returns 'I'
 */
char rot(char c, int amount);
/**
 * Returns a new string in which every character has been rotated by `amount`
 * letters. Lowercase letters are converted to uppercase and rotated.
 * Non-alphabetic characters are left alone.
 * For example:
 *  `rot("A", 0)` returns "A"
 *  `rot("AA", 3)` returns "DD"
 *  `rot("HELLO", 0)` returns "HELLO"
 *  `rot("HELLO", 1)` returns "IFMMP"
 *  `rot("oh HEL-LO!", 1)` returns "PI IFM-MP!"
 */
string rot(string line, int amount);
/**
 * Returns a new string in which every character that is not a letter is removed.
 * All lowercase letters are uppercased.  
 * For example:
 *  `cleanUpKey("ABC34")` returns "ABC"
 *  `cleanUpKey("Aa")` returns "AA"
 *  `cleanUpKey("H--E--L--L--O")` returns "HELLO"
 *  `cleanUpKey("12HeY21")` returns "HEY"
 *  `cleanUpKey("OHHpHH")` returns "OHHPHH"
 */
string cleanUpKey(string line);
/**
 * Updates an int array of the string values in the key with their corresponding indexes in 
 * the ALPHABET string.
 * Parameter assumed to be all uppercase  
 * For example:
 *  `keyToNumberArray("ABC")` returns array of 1 2 3 
 *  `keyToNumberArray("ACD")` returns array of 0 2 3
 *  `keyToNumberArray("XYZ")` returns array of 24 25 26
 *  `keyToNumberArray("ZAC")` returns array of 26 0 2
 *  `keyToNumberArray("Z")` returns array of 26
 */
void keyToNumberArray(string capitalLetters, int arrayKey[], int num_elements);
/**
 * Returns the number of words in a string.
 * Parameter is assumed to be string of words seperated by spaces.
 * For example:
 *  `findNumWordsInString("hello my name")` returns 3 
 *  `findNumWordsInString("hey")` returns 1
 *  `findNumWordsInString(" bro")` returns array of 1
 *  `findNumWordsInString(" man this is hard ")` returns 4
 *  `findNumWordsInString("Z")` returns 1
 */
int findNumWordsInString(string line);
/**
 * This function removes non-letters, uppercases every letter, and saves
 * all words into a string vector ("hello" " " "my" " " "name" ...).
 * Parameter are uncleaned text, vector for storing cleaned text, and the\
 * number of elements of the vector. 
 * For example:
 *  `breakUpTextIntoWords("hello my name")` saves array of the words capitalized and seperated by spaces
 *  `breakUpTextIntoWords("he66y66 ho1w ar2e y22o3u")` saves array of the words capitalized and seperated by spaces
 *  `breakUpTextIntoWords("bro33 come222 on111")` saves array of the words capitalized and seperated by spaces
 *  `breakUpTextIntoWords("m2an thi2s i3s hard")` saves array of the words capitalized and seperated by spaces
 *  `breakUpTextIntoWords("ab")` saves array of the words capitalized and seperated by spaces
 */
void breakUpTextIntoWords(string text, string vectorOfWords[], int num_elements);
/**
 * This function removes extra spaces between words in a string, and 
 * returns the cleaned string.
 * Parameter is a string.
 * For example:
 *  `removeExtraSpacesInString("hello my name")` returns string "hello my name"
 *  `removeExtraSpacesInString("h  y  u")` returns string "h y u" 
 *  `removeExtraSpacesInString("bro come       on")` returns string "bro come on"
 *  `removeExtraSpacesInString("manthis is   hard")` returns string "manthis is hard"
 *  `removeExtraSpacesInString("ab")` returns string "ab"
 */
string removeExtraSpacesInString(string line);

int main() {

    // input the file
    string dictTextFile = "dictionary.txt";
    ifstream inputFile(dictTextFile);

    // make sure file opened correctly
    if (!inputFile.is_open()) {
        cout << "ERROR OPENING FILE." << endl;
        return 0;
    }

    string command;

    cout << "Welcome to Ciphers!" << endl;
    cout << "-------------------" << endl;
    cout << endl;

    do {
        printMenu();
        cout << endl
             << "Enter a command (case does not matter): ";

        // Use getline for all user input to avoid needing to handle
        // input buffer issues relating to using both >> and getline
        getline(cin, command);
        cout << endl;

        // TODO_STUDENT: Execute non-exit commands
        if (command == "C" || command == "c") {
            // Encrypt with Caesar Cipher
            string text;
            string numChar;
            int numCharInt;
            cout << "Enter the text to encrypt:";
            getline(cin, text);
            cout << endl;
            cout << "Enter the number of characters to rotate by:" << endl;
            getline(cin, numChar);
            cout << endl;
            numCharInt = stoi(numChar);
            cout << rot(text, numCharInt) << endl;
        } else if (command == "D" || command == "d") {
            // Decrypt Caesar Cipher
            string encryptedtext; // WILL THIS CAUSE SIMILAR NAME ERRORS????? IDK LETS FIND OUT!!!!!!!!!!!
            cout << "Enter the text to Caesar-cipher decrypt: ";
            getline(cin, encryptedtext);
            cout << endl;
            encryptedtext = removeExtraSpacesInString(encryptedtext);
            // find number of words in user text
            int num_words = findNumWordsInString(encryptedtext); // num words COUOLD CAUSE AN ERROR IN LONGER TEST CASE BC NUMWORDS CHECKED BEFORE CLEANING (ie. hello my 333 name is 666 mohammad)
            int num_elements_in_string_vect = (2 * num_words) - 1; // one space per word, minus one at the end
            string vectorOfWords[num_elements_in_string_vect];
            // break text into a vector of words seperated by spaces (convert lowercase to uppercase & remove non-letters)
            breakUpTextIntoWords(encryptedtext, vectorOfWords, num_elements_in_string_vect);
            // brute force solution- rotate text every possible number and output solutions with >1/2 words in dictionary
            string word;
            string rotatedWord;
            int numInDict = 0;
            bool linesOutputted = false;
            for (int k = 0; k < 26; k++) {
                // count number of rotated words in the dictionary
                for (int i = 0; i < num_elements_in_string_vect; i++) {    
                    word = vectorOfWords[i];
                    // if word is a space skip to next element
                    if (word == " ") {
                        continue;
                    }
                    // rotate word by k amount (max 26)
                    rotatedWord = rot(word, k);
                    // check if word in dictionary
                    string dictWord;
                    // loop through file line by line
                    while (getline(inputFile, dictWord)) {
                        if (rotatedWord == dictWord) {
                            numInDict++; // increment number in dictionary if word found
                        }
                    }
                    // Reset file stream to the beginning of the file
                    inputFile.clear();  // Clear any error flags
                    inputFile.seekg(0); // Move the read pointer to the beginning
                }
                // output those words if number of words in dictionary is > 1/2 
                if (numInDict > (num_words / 2)) {
                    for (int j = 0; j < num_elements_in_string_vect; j++) {
                        word = vectorOfWords[j];
                        // if word is a space output then skip to next element
                        if (word == " ") {
                            cout << word;
                            continue;
                        }
                        // rotate word by k amount (the k that had > 1/2 words of user text in dictionary)
                        rotatedWord = rot(word, k);
                        cout << rotatedWord;
                    }
                    cout << endl;
                    linesOutputted = true;
                }
                numInDict = 0;
            }
            if (!linesOutputted) { // no good decryptions found
                cout << "No good decryptions found" << endl;
            }
        } else if (command == "V" || command == "v") {
            // Encrypt with Vigenère
            string text;
            string key;
            int num_elements_in_key;
            cout << "Enter text to encrypt: ";
            getline(cin, text);
            cout << endl;
            cout << "Enter the Vigenère key: ";
            getline(cin, key);
            cout << endl;
            key = cleanUpKey(key); // remove non-letters and uppercase
            num_elements_in_key = key.size(); // get the number of times key wants to rotate by
            int arrayOfIntKeys[num_elements_in_key]; // initialize array of int keys
            // convert key to numerical values corresponding to their postions in the ALPHABET and save to int array
            keyToNumberArray(key, arrayOfIntKeys, num_elements_in_key);
            // rotate each character from the text according the current key value
            char c;
            string encryptedText;
            int keyIndex = 0;
            for (int i = 0; i < text.size(); i++) { // loop through all text
                c = text.at(i); // set first character of text equal to c
                if (isalpha(c)) { // check if c is a letter
                    c = toupper(c); // uppercase c
                    c = rot(c, arrayOfIntKeys[keyIndex]); // rotate c
                    keyIndex++; // increment key index
                    if (keyIndex == num_elements_in_key) {
                        keyIndex = 0; // reset key index before it goes out of bounds
                    }
                }
                encryptedText += c; // append c to new string
            }
            // output encrypted text to screen
            cout << encryptedText << endl;
        } else if (!(command == "X" || command == "x")){
            cout << "ERROR." << endl; 
            cout << "Please input a character that is on the menu." << endl;
        }

        cout << endl;

    } while (!(command == "x" || command == "X"));

    inputFile.close();

    return 0;
}

void printMenu() {
    cout << "Ciphers Menu" << endl;
    cout << "------------" << endl;
    // Caesar Ciphers
    cout << "C - Encrypt with Caesar Cipher" << endl;
    cout << "D - Decrypt Caesar Cipher" << endl;
    // Vigenere
    cout << "V - Encrypt with Vigenère" << endl;
    // Utility
    cout << "X - Exit Program" << endl;
}

int findIndexInAlphabet(char c) {
    int index;
    if (isalpha(c)) { // make sure character is a letter
        if (isupper(c)) { // make sure character is uppercase
            index = ALPHABET.find(c); // find index of uppercase letter in ALPHABET string
            return index;
        } else {
            return -1; // character not an uppercase letter
        }
    } else {
        return -1; // character not a letter
    }
}

char rot(char c, int amount) {
    // make sure character is uppercase letter, otherwise return error character
    if (!isupper(c)) {
        return c = '@';
    }
    
    // find the index of the uppercase letter in the ALPHABET string
    int index;
    index = ALPHABET.find(c);
    index = index + amount;
    // loop index back around the ALPHABET string when the amount is greater than the number of letters
    while (index >= 26) {
        index = index - 26;
    }
    // update character value
    c = ALPHABET.at(index);

    return c;
}

string rot(string line, int amount) {
    char c;
    for (int i = 0; i < line.size(); i++) {
        c = line.at(i);
        if (isalpha(c)) { // c is a letter
            if (isupper(c)) { // c is uppercase letter
                c = rot(c, amount); // rotate c
                line.at(i) = c; // update string with rotated character
            } else {
                c = toupper(c); // convert lowercase letter c to uppercase
                c = rot(c, amount); 
                line.at(i) = c;
            }
        } else {
            // c is not a letter
        }
    }
    return line;
}

string cleanUpKey(string line) {
    // remove all non-letters from the string
    char c;
    string cleanedLine;
    for (int i = 0; i < line.size(); i++) {
        c = line.at(i); 
        if (isalpha(c)) { // when character is a letter
            c = toupper(c); // uppercase the letter
            cleanedLine += c; // append to new string
        }
    }
    
    return cleanedLine;
}

void keyToNumberArray(string capitalLetters, int arrayKey[], int num_elements) {
    char c;
    int index;
    for (int i = 0; i < num_elements; i++) {
        c = capitalLetters.at(i);
        index = findIndexInAlphabet(c);
        arrayKey[i] = index;
    }
}

int findNumWordsInString(string line) {
    // count number of spaces
    int ctNumSpaces = 1; // minimum 1 word
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            ctNumSpaces++;
        }
    }

    // edge case: user entered space at end of sentence
    int indexOfLastChar = line.size() - 1;
    if (line[indexOfLastChar] == ' ') {
        ctNumSpaces--;
    }

    // edge case: user entered space at beginning of sentence
    int indexOfFirstChar = 0;
    if (line[indexOfFirstChar] == ' ') {
        ctNumSpaces--;
    }

    return ctNumSpaces;
}

void breakUpTextIntoWords(string text, string vectorOfWords[], int num_elements) {
    // remove non-letters, uppercase every letter, and save all words into vector ("hello" " " "my" " " "name" ...)
    char c;
    string cleanedWord;
    int ctVect = 0;
    // for every word before a space
    for (int i = 0; i < text.size(); i++) {
        c = text.at(i);
        if (isalpha(c)) { // if c is a letter
            c = toupper(c); // uppercase c
            cleanedWord += c; // add to new string
        } else if (c == ' ') { // if c is a space
            vectorOfWords[ctVect] = cleanedWord; // add string gathered so far to vector
            ctVect++; // incerement element
            vectorOfWords[ctVect] = " "; // add space
            ctVect++; // increment element
            cleanedWord = ""; // reset the temporary string
        }
    }

    // at end no space occurs in text so need to add last word.
    vectorOfWords[ctVect] = cleanedWord;
}

string removeExtraSpacesInString(string line) {
    string cleanedLine;
    char c;
    int ct = 0;
    for (int i = 0; i < line.size(); i++) { // loop through whole string
        c = line.at(i);
        if (c == ' ') {
            if (ct == 0) {
                cleanedLine += c; // append space only when ct is zero
            }
            ct++; // increment ct
        } else {
            cleanedLine += c; // append letter
            ct = 0; // did not append space so reset ct
        }
    }

    return cleanedLine;
}
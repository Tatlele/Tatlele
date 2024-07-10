#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Morse code dictionary
unordered_map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},
    {'E', "."}, {'F', "..-."}, {'G', "--."}, {'H', "...."},
    {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."},
    {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}, {' ', "/"}, {'1', ".----"},
    {'2', "..---"}, {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."}, {'9', "----."},
    {'0', "-----"}, {'.', "\x46"}, {'-', "\x45"} // ASCII values for dot and dash
};


string encodeToMorse(const string& message) {
    string morse;
    for (char c : message) {
        if (isalpha(c)) {
            morse += morseCode[toupper(c)] + " ";
        } else if (c == ' ') {
            morse += morseCode[c] + " ";
        }
        // Skip digits (numbers)
    }
    return morse;
}

int main() {
    string message;
    cout << "Enter a short message in English: ";
    getline(cin, message);

    string morse = encodeToMorse(message);

    // Output each individual alphanumeric character and its Morse code
    cout << "Individual characters and Morse code:\n";
    for (char c : message) {
        if (isalpha(c) || c == ' ') { // Check if alphanumeric or space
            cout << c << ": " << morseCode[toupper(c)] << endl;
        }
    }

    // Output the full Morse code message with letters separated by three spaces
    cout << "Morse code: " << morse << endl;

    return 0;
}

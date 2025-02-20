#include <iostream>
#include <fstream>
#include <cctype>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <regex>

using namespace std;

// Define keywords
unordered_set<string> keywords = {"int","struct", "char", "return", "if", "else", "while", "for","printf","scanf","void","long"};

// Define operators and punctuations
unordered_set<char> operators = {'+', '-', '*', '/', '=', '>', '<', '!', '&', '|','%'};
unordered_set<char> punctuations = {'(', ')', '{', '}', ';', ',','"','\'','n','\\'};

vector<string> symbol_table;
vector<string> lexical_errors;

// Function to check if a string is a valid identifier
bool isValidIdentifier(const string& str) {
    return regex_match(str, regex("[a-zA-Z_][a-zA-Z0-9_]*"));
}

void tokenize(string code) {
    string token;
    int i = 0;
    while (i < code.size()) {
        char ch = code[i];
        
        // Ignore white spaces
        if (isspace(ch)) {
            i++;
            continue;
        }

        // Handle comments
        if (ch == '/' && i + 1 < code.size()) {
            if (code[i + 1] == '/') {
                while (i < code.size() && code[i] != '\n') i++; // Skip single-line comment
                continue;
            } else if (code[i + 1] == '*') {
                i += 2;
                while (i + 1 < code.size() && !(code[i] == '*' && code[i + 1] == '/')) i++;
                i += 2; // Skip closing */
                continue;
            }
        }

        // Handle numbers
        if (isdigit(ch)) {
            string number;
            while (i < code.size() && isalnum(code[i])) {
                number += code[i++];
            }
            if (!regex_match(number, regex("[0-9]+"))) {
                lexical_errors.push_back("Invalid lexeme: " + number);
            } else {
                cout << "Constant: " << number << endl;
            }
            continue;
        }

        // Handle identifiers and keywords
        if (isalpha(ch) || ch == '_') {
            string identifier;
            while (i < code.size() && (isalnum(code[i]) || code[i] == '_')) {
                identifier += code[i++];
            }
            if (keywords.find(identifier) != keywords.end()) {
                cout << "Keyword: " << identifier << endl;
            } else {
                cout << "Identifier: " << identifier << endl;
                symbol_table.push_back(identifier);
            }
            continue;
        }
        
        // Handle operators
        if (operators.find(ch) != operators.end()) {
            cout << "Operator: " << ch << endl;
            i++;
            continue;
        }
        
        // Handle punctuations
        if (punctuations.find(ch) != punctuations.end()) {
            cout << "Punctuation: " << ch << endl;
            i++;
            continue;
        }

        // Unknown character (lexical error)
        lexical_errors.push_back("Unknown token: " + string(1, ch));
        i++;
    }
}

int main() {
    ifstream file("sample.c");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string code((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
    file.close();
    
    tokenize(code);
    
    // Print symbol table
    cout << "\nSYMBOL TABLE:\n";
    for (const auto& id : symbol_table) {
        cout << id << endl;
    }
    
    // Print lexical errors
    if (!lexical_errors.empty()) {
        cout << "\nLEXICAL ERRORS:\n";
        for (const auto& err : lexical_errors) {
            cout << err << endl;
        }
    }
    
    return 0;
}
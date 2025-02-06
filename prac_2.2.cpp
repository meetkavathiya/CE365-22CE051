#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   
    vector<char> sym = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 
                        'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 
                        'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', 
                        '4', '5', '6', '7', '8', '9'};

    int no_sym = sym.size();


    vector<vector<int>> transitions(3, vector<int>(no_sym, 2));

   
    for (int i = 0; i < 26; i++) { // 'a' to 'z'
        transitions[0][i] = 1;
    }

    
    for (int i = 0; i < no_sym; i++) {
        transitions[1][i] = 1;
    }

   
    int i_state = 0;
    int accepting_state = 1;

    while (true) {
        cout << "\nEnter 'exit' to quit or input a string to validate: ";
        string input;
        cin >> input;

        if (input == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        // Validate the input string
        int current_state = i_state;
        bool is_valid = true;

        for (char ch : input) {
            // Find the symbol index
            int sym_index = -1;
            for (int j = 0; j < no_sym; j++) {
                if (sym[j] == ch) {
                    sym_index = j;
                    break;
                }
            }

            if (sym_index == -1) {
                cout << "Invalid String: Unrecognized symbol\n";
                is_valid = false;
                break;
            }

            // Transition to the next state
            current_state = transitions[current_state][sym_index];
            if (current_state == 2) {
                cout << "Invalid String: Transition to invalid state\n";
                is_valid = false;
                break;
            }
        }

        if (is_valid && current_state == accepting_state) {
            cout << "Valid String\n";
        } else {
            cout << "Invalid String\n";
        }
    }

    cout << "22CE051\n";
    return 0;
}
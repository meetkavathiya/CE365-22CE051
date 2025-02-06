#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int no_sym;
    cout << "Number of input symbols: ";
    cin >> no_sym;

    cout << "Input symbols: ";
    vector<char> sym(no_sym);
    for (int i = 0; i < no_sym; i++) {
        cin >> sym[i];
    }

    // Number of states
    cout << "Enter number of states: ";
    int no_state;
    cin >> no_state;

    // Initial state
    cout << "Initial state: ";
    int i_state;
    cin >> i_state;

    // Accepting states
    cout << "Number of accepting states: ";
    int a_state;
    cin >> a_state;

    cout << "Accepting states: ";
    vector<int> accepting_states(a_state);
    for (int i = 0; i < a_state; i++) {
        cin >> accepting_states[i];
    }

    // Transition table
    vector<vector<int>> transitions(no_state + 1, vector<int>(no_sym, -1));
    cout << "Transition table:\n";
    for (int i = 1; i <= no_state; i++) {
        for (int j = 0; j < no_sym; j++) {
            cout << i << " to " << sym[j] << " -> ";
            cin >> transitions[i][j];
        }
    }

    while (true) {
        cout << "\nEnter 'exit' to quit or input a string to validate: ";
        string input;
        cin >> input;

        if (input == "exit") {
            cout << "Exiting program.\n";
            break;
        }

        // Validate string
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

            // Transition to next state
            current_state = transitions[current_state][sym_index];
            if (current_state == -1) {
                cout << "Invalid String: No transition defined\n";
                is_valid = false;
                break;
            }
        }

        if (is_valid) {
            // Check if the final state is an accepting state
            is_valid = false;
            for (int acc_state : accepting_states) {
                if (current_state == acc_state) {
                    is_valid = true;
                    break;
                }
            }

            if (is_valid) {
                cout << "Valid String\n";
            } else {
                cout << "Invalid String\n";
            }
        }
    }

    cout << "22CE051\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <ctime>
#include <limits> // For numeric_limits
#include <cstdlib>

// Custom headers
#include "Shared.h"
#include "Generators.h"
#include "Student.h"
#include "Teacher.h"
#include "Parent.h"

using namespace std; // Allowed in main.cpp for convenience

// Helper to clear screen (Works on Mac/Linux/Windows)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Helper to pause execution
void pause() {
    cout << "\n(Press Enter to continue...)";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    cin.get(); // Wait for enter
}

int main() {
    // Seed the random number generator once at startup
    srand(static_cast<unsigned int>(time(0)));

    MathGenerator mathGen;
    LetterGenerator letterGen;
    NumberGenerator numGen;

    vector<Exercise> customExercises; // Stores exercises created by Teacher

    int menu = 0;

    while (menu != 4) {
        clearScreen();
        cout << "=============================" << endl;
        cout << "    LEARN BY GAME SYSTEM     " << endl;
        cout << "=============================" << endl;
        cout << "1. Login as TEACHER" << endl;
        cout << "2. Login as STUDENT" << endl;
        cout << "3. Login as PARENT" << endl;
        cout << "4. Exit" << endl;
        cout << "-----------------------------" << endl;
        cout << "Select Option: ";
        cin >> menu;

        // Input validation: Check if user entered a number
        if (cin.fail()) {
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard bad input
            menu = 0; 
            continue;
        }

        // --- TEACHER MENU ---
        if (menu == 1) {
            Teacher t;
            cout << "\n>> Enter Teacher Name: ";
            cin >> t.name;

            int tChoice = 0;
            while (tChoice != 3) {
                clearScreen();
                cout << "Welcome, Teacher " << t.name << "!\n";
                cout << "1. Create New Exercise\n";
                cout << "2. View Student Reports\n";
                cout << "3. Logout\n";
                cout << "> Choice: ";
                cin >> tChoice;

                if (tChoice == 1) {
                    Exercise ex = t.createNewExercise();
                    customExercises.push_back(ex);
                    pause();
                }
                else if (tChoice == 2) {
                    t.viewStudentReports();
                    pause();
                }
            }
        }
        // --- STUDENT MENU ---
        else if (menu == 2) {
            Student s;
            cout << "\n>> Enter Student Name: ";
            cin >> s.name;

            int sChoice = 0;
            while (sChoice != 5) {
                clearScreen();
                cout << "Student: " << s.name << " | Score: " << s.score << "\n";
                cout << "------------------------------------------\n";
                cout << "1. Practice Letters\n";
                cout << "2. Practice Numbers\n";
                cout << "3. Practice Math (+/-)\n";
                cout << "4. Solve Teacher's Exercises\n";
                cout << "5. Save & Logout\n";
                cout << "> Choice: ";
                cin >> sChoice;

                if (sChoice == 1) {
                    s.practice(letterGen.getQuestion());
                }
                else if (sChoice == 2) {
                    s.practice(numGen.getQuestion());
                }
                else if (sChoice == 3) {
                    cout << "\n   1. Addition (+)\n   2. Subtraction (-)\n   > ";
                    int type;
                    cin >> type;
                    if (type == 1) s.practice(mathGen.getPlusQuestion());
                    else s.practice(mathGen.getMinusQuestion());
                }
                else if (sChoice == 4) {
                    if (customExercises.empty()) {
                        cout << "\n>> [Info]: No exercises assigned by teacher yet!\n";
                    } else {
                        // Take the last exercise added
                        s.practice(customExercises.back());
                    }
                }

                if (sChoice != 5) pause();
            }
            
            s.saveMyScore();
            pause();
        }
        // --- PARENT MENU ---
        else if (menu == 3) {
            Parent p;
            clearScreen();
            p.checkMyChild();
            pause();
        }
    }

    cout << "\nGoodbye! See you next time.\n";
    return 0;
}

#ifndef TEACHER_H
#define TEACHER_H

#include "Shared.h"

class Teacher {
public:
    std::string name;

    Exercise createNewExercise() {
        Exercise e;
        std::cout << "\n--- Create New Exercise ---\n";
        std::cout << "Enter Subject (e.g., Math/History): ";
        std::cin >> e.type;
        
        std::cout << "Enter Question: ";
        std::cin.ignore(); // Clear buffer before getline
        std::getline(std::cin, e.question);
        
        std::cout << "Enter Correct Answer: ";
        std::cin >> e.answer;
        
        std::cout << ">> [System]: Exercise Created Successfully.\n";
        return e;
    }

    void viewStudentReports() {
        std::cout << "\n--- Student Report Card ---\n";
        std::ifstream f("school_data.txt");
        
        if (!f.is_open()) {
            std::cout << ">> [Info]: No records found (File does not exist).\n";
            return;
        }
        
        std::string sName;
        int sScore;
        bool found = false;

        // Print table header
        std::cout << "Name\t\tScore\n";
        std::cout << "----\t\t-----\n";

        while (f >> sName >> sScore) {
            std::cout << sName << "\t\t" << sScore << "\n";
            found = true;
        }
        f.close();

        if (!found) {
            std::cout << ">> [Info]: The file is empty.\n";
        }
    }
};

#endif

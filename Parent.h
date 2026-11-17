#ifndef PARENT_H
#define PARENT_H

#include "Shared.h"

class Parent {
public:
    void checkMyChild() {
        std::string childName;
        std::cout << "\n>> Enter your child's name to search: ";
        std::cin >> childName;

        std::ifstream f("school_data.txt");
        if (!f.is_open()) {
            std::cout << ">> [Error]: No school records found.\n";
            return;
        }
        
        std::string n;
        int s;
        bool found = false;

        while (f >> n >> s) {
            if (n == childName) {
                std::cout << "\n----------------------------\n";
                std::cout << "🎓 REPORT CARD FOUND\n";
                std::cout << "Student: " << n << "\n";
                std::cout << "Score:   " << s << "\n";
                std::cout << "----------------------------\n";
                found = true;
            }
        }
        f.close();

        if (!found) {
            std::cout << ">> [Info]: Student '" << childName << "' not found.\n";
        }
    }
};

#endif

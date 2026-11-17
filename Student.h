#ifndef STUDENT_H
#define STUDENT_H

#include "Shared.h"

class Student {
public:
    std::string name;
    int score = 0;

    // Append score to the file without deleting old data
    void saveMyScore() {
        std::ofstream f;
        f.open("school_data.txt", std::ios::app);
        
        if (f.is_open()) {
            f << name << " " << score << "\n";
            f.close();
            std::cout << ">> System: Score saved.\n";
        } else {
            std::cerr << ">> Error: Cannot save file.\n";
        }
    }

    void practice(const Exercise& e) {
        std::cout << "\n--- QUIZ: " << e.type << " ---\n";
        std::cout << "Question: " << e.question << "\n";
        std::cout << "Answer: ";
        
        std::string myAns;
        std::cin >> myAns;

        if (e.checkAnswer(myAns)) {
            std::cout << "Correct! (+10)\n";
            score += 10;
        } else {
            std::cout << "Wrong! Answer is: " << e.answer << "\n";
        }
    }
};

#endif

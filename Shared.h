#ifndef SHARED_H
#define SHARED_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

// Structure to hold question details
struct Exercise {
    std::string type;     
    std::string question; 
    std::string answer;   

    // Helper to compare user input with the correct answer
    bool checkAnswer(const std::string& input) const {
        return input == answer;
    }
};

#endif

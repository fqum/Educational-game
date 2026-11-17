//
//  Generators.h
//  LerenByGameSimulator
//
//  Created by furas on 2026-01-19.
//

#ifndef GENERATORS_H
#define GENERATORS_H

#include "Shared.h"
#include <cstdlib>
#include <ctime>

using namespace std;

class MathGenerator {
public:
    Exercise getPlusQuestion() {
        Exercise e;
        e.type = "Math (+) ";
        
        int n1 = rand() % 20 + 1;
        int n2 = rand() % 20 + 1;
        
        e.question = to_string(n1) + " + " + to_string(n2) + " = ?";
        
        e.answer = to_string(n1 + n2);
        
        return e;
    }

    Exercise getMinusQuestion() {
        Exercise e;
        e.type = "Math (-) ";
        
        int n1 = rand() % 20 + 10;
        int n2 = rand() % 9 + 1;
        
        e.question = to_string(n1) + " - " + to_string(n2) + " = ?";
        e.answer = to_string(n1 - n2);
        
        return e;
    }
};

class LetterGenerator {
public:
    Exercise getQuestion() {
        Exercise e;
        e.type = "Letters";
        
        char randomChar = 'A' + (rand() % 25);
        
        string s(1, randomChar);
        e.question = "What comes after the letter " + s + "?";
        
        char nextChar = randomChar + 1;
        e.answer = string(1, nextChar);
        
        return e;
    }
};

class NumberGenerator {
public:
    string numberNames[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    
    Exercise getQuestion() {
        Exercise e;
        e.type = "Numbers";
        
        int num = rand() % 10;
        
        e.question = "Write the number digit for: " + numberNames[num];
        e.answer = to_string(num);
        
        return e;
    }
};

#endif

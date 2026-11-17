# Learn By Game 

**Learn By Game** is a C++ educational console application designed to make learning fun and interactive for first-grade students.

The application provides simple educational exercises in English letters, numbers, and basic mathematics through randomly generated questions and interactive quizzes.

## Features

###  Student Interface
- Practice English letters through interactive questions.
- Learn numbers from 0 to 9.
- Solve basic addition and subtraction exercises.
- Complete custom exercises created by teachers.
- Earn 10 points for each correct answer.
- Save student scores for future review.

### Teacher Interface
- Create custom educational exercises.
- Define exercise subjects, questions, and correct answers.
- View student score reports.

### Parent Interface
- Search for a child by name.
- View the child's saved score.

## Educational Activities

| Subject | Description |
|---|---|
| Letters | Identify the next letter in the English alphabet. |
| Numbers | Convert written number names into digits (0–9). |
| Mathematics | Practice basic addition and subtraction. |
| Custom Exercises | Solve questions created by teachers. |

## 🛠️ Technologies Used

- **Programming Language:** C++
- **Core Concepts:** Object-Oriented Programming (OOP)
- **Data Structures:** Classes, Structs, and Vectors
- **File Handling:** Reading and writing student scores using text files.
- **Randomization:** Generating random educational questions.
- **Standard Libraries:** iostream, string, vector, fstream, cstdlib, and ctime.

##  Project Structure

```text
Learn-By-Game/
│
├── main.cpp
├── Shared.h
├── Generators.h
├── Student.h
├── Teacher.h
├── Parent.h
├── README.md
├── LICENSE
└── .gitignore
```

## 🚀 Getting Started

### Requirements
- A C++ compiler (GCC or G++).
- C++11 support or later.

### Compile

```bash
g++ -std=c++11 main.cpp -o learn-by-game
```

### Run

**Linux / macOS:**
```bash
./learn-by-game
```

**Windows:**
```bash
learn-by-game.exe
```

## 💾 Data Storage

Student scores are saved in a local text file named `school_data.txt`.

The application uses this file to allow teachers and parents to review saved student scores.

Note:

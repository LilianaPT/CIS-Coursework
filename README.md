# 💻 CIS Coursework — C++

C++ programs I wrote for my Computer Information Systems courses at **Elgin Community College**, from first programs with input and output to classes, templates, the STL, exception handling and file encryption.

**Author:** Liliana Pantoja · [Portfolio](https://lilianapt.github.io) · [LinkedIn](https://www.linkedin.com/in/liliana-pantoja)

| Course | Folder | Focus |
|---|---|---|
| **CIS-121** · Spring 2026 | [`CIS-121-200/`](CIS-121-200) | Fundamentals: decisions, loops, functions, arrays, files, strings, first classes |
| **CIS-223** · Fall 2026 | [`CIS-223-400/`](CIS-223-400) | Advanced C++: classes, operator overloading, inheritance, templates, STL containers, exceptions |

---

## ⭐ Highlights

| Program | What it does | Concepts |
|---|---|---|
| [Arcade Multi-Game Suite](CIS-121-200/Final_Project) | CIS-121 final project: Car Racing, Snake and Tic Tac Toe in one menu ([full repo](https://github.com/LilianaPT/Arcade-MultiGame-Suite)) | Classes, multi-file project, real-time input, flicker-free rendering |
| [File Encryption](CIS-223-400/Encryption) | Encrypts a text file with a substitution code and decrypts it back | `map<char,char>`, file I/O |
| [Word Index](CIS-223-400/WordIndex) | Builds an index of every word in a text file and the lines where it appears | `map<string, set<int>>`, file I/O |
| [Sortable Vector](CIS-223-400/SortableVectorDriver) | A vector class template that can sort itself, tested with several data types | Class templates |
| [Performance Benchmark](CIS-121-200/ModuleIn12/Performance_Benchmark) | Times Linear Search, Bubble Sort and Selection Sort on 100,000 integers | Algorithms, performance measurement |
| [Coffee Shop Simulator](CIS-121-200/Assn1/CoffeeShop_Simulator) | Order system with drink menu, membership discount, tax and receipt | Functions, input validation, formatted output |
| [Multi-Student Exam Grader](CIS-121-200/Assn3/Multi-Student_ExamGrader) | Automates grading of exams for several students | Arrays, loops, functions |

---

## 📘 CIS-121 — Fundamentals

| Folder | Topic | Programs |
|---|---|---|
| `Lab1`, `kilometers`, `CIS121SP26`, `Module2-Practice` | First programs, input/output, math | Favorite movie, km → miles, kinetic energy |
| `GroceryBillCalculator` (Lab 2) | Arithmetic and formatting | Grocery receipt, coin counter, temperature converter |
| `Module3_Lab3` | Formulas and output formatting | Stock commission, cylinder volume |
| `Module4In` | Decisions (`if`, `switch`) and loops | Water bill, prime numbers |
| `Module5In`, `Module5More Examples` | Loops and random numbers | Finding π, sum/largest/smallest of random numbers |
| `Module6In` | Menus and nested loops | Geometry calculator, multiplication table |
| `Module7In` | Functions | Rock, Paper, Scissors |
| `Module8In` | Functions with parameters and return values | Quadratic formula, future time calculator |
| `ModuleIn9` | Reading files | Processing integers from a file |
| `ModuleIn10` | File I/O | Vowel/consonant counter, file comparison |
| `ModuleIn11` | Arrays | Lottery game, reversing characters, array processing |
| `ModuleIn12` | 2D arrays, searching and sorting | 2D array processing, search/sort benchmark |
| `ModuleIn13` | Strings and characters | CamelCase word separator, letter counter |
| `ModuleIn14` | Classes and objects | Movie, Circle, Employee and Payroll classes |
| `Module15In` | Classes and validation | Password validator, quadratic equation class |
| `Assn1`, `Assn2`, `Assn3` | Assignments | Coffee shop, office supply calculator, fitness tracker, exam grader |
| `MidTerm`, `Final_Programming_Test` | Exams | Number series analyzer, linear search, random numbers |
| `ExerciseA`, `ObjectDrop` | Practice | Falling object distance and more |
| `Final_Project` | Final project | Arcade Multi-Game Suite |

## 📗 CIS-223 — Advanced C++

| Folder | Topic | Programs |
|---|---|---|
| `Class1`, `Class-9.1.26` | Pointers, structures | Movie statistics, soccer scores, monthly budget |
| `Chapter12-Advc-Files` | Advanced file operations | Inventory program, word search in a file |
| `Chapter13-Classes`, `PayrollClass`, `PatientCharge`, `CashRegister` | Classes and object composition | Car, payroll, hospital charges, cash register with inventory |
| `CarpetCalculator`, `NumDays`, `Ch15-TimeFormat` | Operator overloading, aggregation, inheritance | Carpet cost, work hours ↔ days, military time |
| `CorporateSalesmain` | Static members | Division sales totals |
| `MidTerm` | Midterm project | KossCo membership system |
| `ExceptionChapter`, `ArithmeticExceptions`, `InClassEX` | Exception handling | Custom exception classes, input validation |
| `Min-MaxCh16`, `RotateLeft`, `SortableVectorDriver` | Function and class templates | Generic min/max, vector rotation, sortable vector |
| `CapitalQuiz`, `WordIndex`, `Encryption` | STL containers (`map`, `set`, `vector`) | State capitals quiz, word index, file encryption |

---

## ▶️ How to run

Each folder is a Visual Studio project. Open the `.slnx` file in **Visual Studio 2022+** and press **F5**.
Or compile any program from the terminal:

```bash
g++ -std=c++17 path/to/Program.cpp -o program
./program
```

#  Electronic School System  
### C++ Console Application

---

##  Description

This project represents a console-based application developed in C++, simulating the core functionality of an electronic school system. The application allows users to access learning materials, complete exercises, and take an automatically generated test with evaluation and performance statistics.

The system is designed for educational purposes and demonstrates the implementation of fundamental programming concepts in a structured and interactive way.

---

##  Project Objectives

- To reinforce fundamental C++ programming concepts  
- To develop a structured console-based application  
- To implement testing and grading logic  
- To create an interactive user experience  
- To demonstrate clean and organized code design  

---

##  Core Functionalities

###  1. Learning Materials
The system provides access to theoretical topics, including:
- Variables and data types  
- Conditional statements (`if`, `switch`)  
- Loops (`for`, `while`)  
- Arrays  

---

###  2. Exercises
The application includes practice tasks such as:
- Calculating the sum of two numbers  
- Checking whether a number is even  
- Finding the largest of three numbers  

---

###  3. Automated Test
- Multiple-choice questions (A, B, C)  
- Randomized question selection  
- User input for answers  
- Automatic answer validation  

---

###  4. Grading and Statistics
After completing the test, the system:
- Calculates the total number of correct answers  
- Determines the success percentage  
- Assigns a final grade based on a six-point grading scale  

| Success Rate | Grade |
|--------------|--------|
| ≥ 90%        | Excellent (6) |
| 75% – 89%    | Very Good (5) |
| 60% – 74%    | Good (4) |
| 50% – 59%    | Satisfactory (3) |
| < 50%        | Fail (2) |

---

##  Application Architecture

###  `Question` Structure
Represents a test question and includes:
- Question text  
- Three possible answers  
- Correct answer  

---

###  Main Functions

#### `showMaterials()`
Displays the available learning materials.

#### `showExercises()`
Displays the list of exercises.

#### `runTest()`
- Manages the test execution  
- Processes user answers  
- Calculates the score  

#### `showStatistics()`
- Computes the success percentage  
- Determines the final grade  
- Displays the results  

---

###  `main()` Function
- Implements the main menu  
- Handles user input  
- Ensures continuous program execution until exit  

---

##  How to Run

### 1. Requirements
- C++ compiler (e.g., `g++`)  
- Terminal or command prompt  

---

### 2. Compilation
```bash

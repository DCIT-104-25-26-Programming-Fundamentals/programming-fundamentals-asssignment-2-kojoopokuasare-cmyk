// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
// - name   : the student's full name (string)
// - id     : a unique student ID number (int, e.g. 20240001)
// - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
// 1. Add a Student
//    - Ask the user to enter the student's name and ID.
//    - Ask how many scores to enter, then collect each score one by one.
//    - Save the student record and confirm it was added.
//
// 2. Display All Students
//    - Print a formatted table showing every student's:
//      Name, ID, individual scores, and their average score.
//    - If no students have been added yet, print a message saying so.
//
// 3. Calculate Average Score for a Specific Student
//    - Ask the user to enter a student ID.
//    - Find the student and print their average score.
//    - If the ID is not found, print an error message.
//
// 4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
// ================================
// STUDENT RECORD SYSTEM MENU
// ================================
// 1. Add student
// 2. Display all students
// 3. Calculate average score
// 4. Quit
// Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
// Enter your choice (1-4): 1
// Student name: Alice Mensah
// Student ID: 20240001
// How many scores? 3
// Enter score 1: 78
// Enter score 2: 85
// Enter score 3: 90
// Student "Alice Mensah" added successfully.
//
// Enter your choice (1-4): 3
// Enter student ID: 20240001
// Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//
// =============================================================================
// YOUR CODE BELOW
// =============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Definition of the Student struct
struct Student {
    string name;
    int id;
    vector<double> scores;
};

// Helper function to calculate a student's average score
double getStudentAverage(const Student& s) {
    if (s.scores.empty()) {
        return 0.0;
    }
    double total = 0;
    for (double score : s.scores) {
        total += score;
    }
    return total / s.scores.size();
}

// 1. Function to add a student record
void addStudent(vector<Student>& database) {
    Student newStudent;
    
    cin.ignore(); // Clear the input buffer stream
    cout << "Student name: ";
    getline(cin, newStudent.name);
    
    cout << "Student ID: ";
    cin >> newStudent.id;
    
    int scoreCount;
    cout << "How many scores? ";
    cin >> scoreCount;
    
    for (int i = 0; i < scoreCount; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        newStudent.scores.push_back(score);
    }
    
    database.push_back(newStudent);
    cout << "Student \"" << newStudent.name << "\" added successfully." << endl;
}

// 2. Function to print all student records
void displayAllStudents(const vector<Student>& database) {
    if (database.empty()) {
        cout << "No student records found in the database." << endl;
        return;
    }
    
    cout << "\n------------------------------------------------------------" << endl;
    cout << left << setw(20) << "Name" << setw(12) << "ID" << setw(18) << "Scores" << "Average" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    // Set global float format rules for the calculation tables
    cout << fixed << setprecision(2);
    
    for (const Student& s : database) {
        cout << left << setw(20) << s.name << setw(12) << s.id;
        
        // Print individual values inside the scores vector cleanly inline
        string scoresStr = "";
        for (size_t i = 0; i < s.scores.size(); i++) {
            scoresStr += to_string(static_cast<int>(s.scores[i]));
            if (i < s.scores.size() - 1) {
                scoresStr += ", ";
            }
        }
        cout << left << setw(18) << scoresStr;
        cout << getStudentAverage(s) << endl;
    }
    cout << "------------------------------------------------------------" << endl;
}

// 3. Function to find and print the average for a specific student ID
void calculateSpecificAverage(const vector<Student>& database) {
    if (database.empty()) {
        cout << "The database is empty." << endl;
        return;
    }
    
    int searchId;
    cout << "Enter student ID: ";
    cin >> searchId;
    
    // Search loops checking for matching ID variables
    for (const Student& s : database) {
        if (s.id == searchId) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << getStudentAverage(s) << endl;
            return; // Exit function immediately upon finding the target item
        }
    }
    
    cout << "Error: Student ID " << searchId << " not found." << endl;
}

// Main operational layout controller
int main() {
    vector<Student> studentDatabase;
    int choice = 0;
    
    while (true) {
        cout << "\n================================" << endl;
        cout << "STUDENT RECORD SYSTEM MENU" << endl;
        cout << "================================" << endl;
        cout << "1. Add student" << endl;
        cout << "2. Display all students" << endl;
        cout << "3. Calculate average score" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (cin.fail()) {
            cin.clear();
            string junk;
            cin >> junk;
            cout << "Invalid entry. Please choose a choice selection from 1 to 4." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudent(studentDatabase);
                break;
            case 2:
                displayAllStudents(studentDatabase);
                break;
            case 3:
                calculateSpecificAverage(studentDatabase);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Error: Selection choice must be exactly 1, 2, 3, or 4." << endl;
                break;
        }
    }
    
    return 0;
}

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
// 1. Add a Task
//    - Prompt the user to type a task description.
//    - Add it to the list and confirm it was added.
//
// 2. View All Tasks
//    - Display all tasks currently in the list, numbered from 1.
//    - If the list is empty, print a friendly message saying so.
//
// 3. Delete a Task
//    - Show the list of tasks with their numbers.
//    - Ask the user which task number they want to remove.
//    - Remove the task and confirm the deletion.
//    - If the task number is invalid, print an error message.
//
// 4. Quit
//    - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
// ============================
// TO-DO LIST MENU
// ============================
// 1. Add task
// 2. View tasks
// 3. Delete task
// 4. Quit
// Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
// Enter your choice (1-4): 1
// Enter task: Buy groceries
// Task added: "Buy groceries"
//
// Enter your choice (1-4): 2
// Your Tasks:
// 1. Buy groceries
// 2. Study for exams
//
// Enter your choice (1-4): 3
// Enter task number to delete: 1
// Task "Buy groceries" has been removed.
//
// Enter your choice (1-4): 4
// Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//
// =============================================================================
// YOUR CODE BELOW
// =============================================================================
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Function to add a task to the vector
void addTask(vector<string>& tasks) {
    cin.ignore(); // Clear the input buffer before reading a sentence string
    cout << "Enter task: ";
    string newTask;
    getline(cin, newTask); // Captures spaces between words
    
    tasks.push_back(newTask);
    cout << "Task added: \"" << newTask << "\"" << endl;
}

// 2. Function to view all tasks in the list
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your to-do list is empty!" << endl;
        return;
    }
    
    cout << "Your Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i] << endl;
    }
}

// 3. Function to delete a task by index position
void deleteTask(vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available to delete." << endl;
        return;
    }
    
    // Display list first so user can choose a number accurately
    viewTasks(tasks);
    
    cout << "Enter task number to delete: ";
    int choiceNumber;
    cin >> choiceNumber;
    
    // Map human input (1-based index) to C++ container elements (0-based index)
    if (choiceNumber < 1 || choiceNumber > static_cast<int>(tasks.size())) {
        cout << "Error: Invalid task number selection." << endl;
    } else {
        int internalIndex = choiceNumber - 1;
        string removedTask = tasks[internalIndex];
        
        // Remove structural item using vector iterator notation
        tasks.erase(tasks.begin() + internalIndex);
        cout << "Task \"" << removedTask << "\" has been removed." << endl;
    }
}

// Main interactive engine loop
int main() {
    vector<string> myTodoList;
    int choice = 0;
    
    while (true) {
        cout << "\n============================" << endl;
        cout << "TO-DO LIST MENU" << endl;
        cout << "============================" << endl;
        cout << "1. Add task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete task" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        // Input validation case if stream breaks (e.g. typing characters instead of digits)
        if (cin.fail()) {
            cin.clear();
            string discard;
            cin >> discard;
            cout << "Invalid input. Please enter a digit choice between 1 and 4." << endl;
            continue;
        }
        
        switch (choice) {
            case 1:
                addTask(myTodoList);
                break;
            case 2:
                viewTasks(myTodoList);
                break;
            case 3:
                deleteTask(myTodoList);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0; // Graceful termination exit point
            default:
                cout << "Error: Selection choice must be exactly 1, 2, 3, or 4." << endl;
                break;
        }
    }
    
    return 0;
}

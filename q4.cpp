#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to add a task to the list
void addTask(vector<Task>& tasks, const string& description) {
    Task newTask = {description, false};
    tasks.push_back(newTask);
}

// Function to display tasks
void displayTasks(const vector<Task>& tasks) {
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks, size_t index) {
    if (index >= 1 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    vector<Task> tasks;

    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cin.ignore(); // Clear the input buffer
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                break;
            }
            case '2':
                displayTasks(tasks);
                break;
            case '3': {
                size_t taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markTaskCompleted(tasks, taskIndex);
                break;
            }
            case '4': {
                size_t taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex);
                break;
            }
            case '5':
                cout << "Quitting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}

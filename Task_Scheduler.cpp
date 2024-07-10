#include <iostream>
#include <queue>

using namespace std;

// Function to add task to scheduler 
void addTask(priority_queue<pair<int, int>>& tasks, int id, int priority) {
    tasks.push({priority, id});
}

// Function to execute task with highest priority
void executeTask(priority_queue<pair<int, int>>& tasks) {
    if (!tasks.empty()) {
        pair<int, int> nextTask = tasks.top();
        tasks.pop();
        cout << "Executing Task: " << nextTask.second << endl;
    } else {
        cout << "No tasks to execute!" << endl;
    }
}

int main() {
    priority_queue<pair<int, int>> tasks;
    int taskId, taskPriority;

    char choice;
    do {
        // Prompt user to add a task
        cout << "Enter Task ID: ";
        cin >> taskId;
        cout << "Enter Task Priority: ";
        cin >> taskPriority;

        // Add task to scheduler
        addTask(tasks, taskId, taskPriority);

        // Ask user if they want to add more tasks
        cout << "Do you want to add another task? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Execute tasks
    cout << "\nExecuting Tasks:" << endl;
    while (!tasks.empty()) {
        executeTask(tasks);
    }

    return 0;
}
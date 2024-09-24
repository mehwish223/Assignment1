#include <iostream>
#include <string>

using namespace std;

// Structure to represent each task in the linked list
struct Task {
    int id;                 // Unique ID for each task
    string description;      // Description of the task
    int priority;            // Priority level of the task (higher value means higher priority)
    Task* next;              // Pointer to the next task in the list
};

// Pointer to the head (start) of the task list
Task* head = NULL;  // NULL is used to indicate that the list is initially empty

// Function to add a new task in the list based on priority (higher priority comes first)
void addTask(int id, string description, int priority) {
    // Create a new task
    Task* newTask = new Task();     // Allocate memory for a new task node
    newTask->id = id;               // Set the task ID
    newTask->description = description; // Set the task description
    newTask->priority = priority;       // Set the task priority
    newTask->next = NULL;           // Initially, the new task doesn't point to any other task

    // If the list is empty, or the new task has the highest priority, insert it at the start
    if (head == NULL || head->priority < priority) {
        newTask->next = head;       // Point the new task to the current head
        head = newTask;             // Make the new task the head of the list
    } else {
        // Traverse the list to find the correct position for the new task
        Task* current = head;
        while (current->next != NULL && current->next->priority >= priority) {
            current = current->next;  // Move to the next task in the list
        }
        // Insert the new task at the correct position
        newTask->next = current->next;
        current->next = newTask;
    }

    cout << "Task added successfully!\n";
}

// Function to remove the task with the highest priority (first task in the list)
void removeHighestPriorityTask() {
    if (head == NULL) {
        // If the list is empty, display a message
        cout << "Task list is empty.\n";
        return;
    }

    // Remove the head (highest priority task) and update the head pointer
    Task* temp = head;
    head = head->next;   // Move the head to the next task
    cout << "Removed task with ID: " << temp->id << endl;
    delete temp;         // Free the memory of the removed task
}

// Function to remove a task by its ID
void removeTaskById(int id) {
    if (head == NULL) {
        // If the list is empty, display a message
        cout << "Task list is empty.\n";
        return;
    }

    // If the task to remove is the first task (head)
    if (head->id == id) {
        Task* temp = head;
        head = head->next;  // Move the head to the next task
        cout << "Removed task with ID: " << id << endl;
        delete temp;        // Free the memory of the removed task
        return;
    }

    // Traverse the list to find the task with the given ID
    Task* current = head;
    while (current->next != NULL && current->next->id != id) {
        current = current->next;  // Move to the next task
    }

    // If the task with the given ID is found
    if (current->next != NULL) {
        Task* temp = current->next;
        current->next = current->next->next;  // Bypass the task to remove it
        cout << "Removed task with ID: " << id << endl;
        delete temp;       // Free the memory of the removed task
    } else {
        // If the task with the given ID was not found
        cout << "Task with ID " << id << " not found.\n";
    }
}

// Function to display all the tasks in the list
void viewTasks() {
    if (head == NULL) {
        // If the list is empty, display a message
        cout << "Task list is empty.\n";
        return;
    }

    // Traverse and display each task
    Task* current = head;
    cout << "Task List:\n";
    while (current != NULL) {
        // Print task details
        cout << "ID: " << current->id << ", Description: " << current->description << ", Priority: " << current->priority << endl;
        current = current->next;  // Move to the next task
    }
}

// Main function: Console-based menu for user interaction
int main() {
    int choice, id, priority;
    string description;

    // Infinite loop for menu-based interaction
    while (true) {
        // Display the menu options
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add a new task\n";
        cout << "2. View all tasks\n";
        cout << "3. Remove the highest priority task\n";
        cout << "4. Remove a task by ID\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Perform actions based on user choice
        switch (choice) {
            case 1:
                // Add a new task
                cout << "Enter Task ID: ";
                cin >> id;
                cin.ignore();  // Ignore the newline character after the previous input
                cout << "Enter Task Description: ";
                getline(cin, description);  // Read the full line as task description
                cout << "Enter Task Priority: ";
                cin >> priority;
                addTask(id, description, priority);  // Add the task
                break;

            case 2:
                // View all tasks in the list
                viewTasks();
                break;

            case 3:
                // Remove the task with the highest priority
                removeHighestPriorityTask();
                break;

            case 4:
                // Remove a task by its ID
                cout << "Enter Task ID to remove: ";
                cin >> id;
                removeTaskById(id);
                break;

            case 5:
                // Exit the program
                cout << "Exiting Task Manager.\n";
                return 0;

            default:
                // Handle invalid menu options
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }
}


#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int id;
    string task;
    int priority;
    bool completed;
    Node* next;
};

// Head pointer
Node* head = NULL;


// Function to add a task
void addTask()
{
    Node* newNode = new Node;

    cout << "\nEnter Task ID: ";
    cin >> newNode->id;

    cin.ignore();

    cout << "Enter Task Name: ";
    getline(cin, newNode->task);

    cout << "Enter Priority (1 = High, 2 = Medium, 3 = Low): ";
    cin >> newNode->priority;

    newNode->completed = false;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "\nTask added successfully!\n";
}


// Function to display all tasks
void displayTasks()
{
    if (head == NULL)
    {
        cout << "\nTo-Do List is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\n========== TO-DO LIST ==========\n";

    while (temp != NULL)
    {
        cout << "\nTask ID      : " << temp->id;
        cout << "\nTask Name    : " << temp->task;

        cout << "\nPriority     : ";

        if (temp->priority == 1)
            cout << "High";
        else if (temp->priority == 2)
            cout << "Medium";
        else
            cout << "Low";

        cout << "\nStatus       : ";

        if (temp->completed)
            cout << "Completed";
        else
            cout << "Pending";

        cout << "\n-------------------------------";

        temp = temp->next;
    }

    cout << endl;
}


// Function to complete/delete a task
void completeTask()
{
    if (head == NULL)
    {
        cout << "\nTo-Do List is empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Task ID to complete/delete: ";
    cin >> id;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->id != id)
    {
        prev = temp;
        temp = temp->next;
    }

    // Task not found
    if (temp == NULL)
    {
        cout << "\nTask not found!\n";
        return;
    }

    // Mark task as completed
    temp->completed = true;

    cout << "\nTask completed successfully!\n";

    // Ask whether user wants to delete it
    char choice;

    cout << "Do you want to delete this task? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        // If first node is deleted
        if (temp == head)
        {
            head = head->next;
        }
        else
        {
            prev->next = temp->next;
        }

        delete temp;

        cout << "Task deleted successfully!\n";
    }
}


// Function to search task by ID
void searchByID()
{
    if (head == NULL)
    {
        cout << "\nTo-Do List is empty!\n";
        return;
    }

    int id;

    cout << "\nEnter Task ID: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            cout << "\nTask Found!";
            cout << "\nTask ID   : " << temp->id;
            cout << "\nTask Name : " << temp->task;

            cout << "\nPriority  : ";

            if (temp->priority == 1)
                cout << "High";
            else if (temp->priority == 2)
                cout << "Medium";
            else
                cout << "Low";

            cout << "\nStatus    : ";

            if (temp->completed)
                cout << "Completed";
            else
                cout << "Pending";

            cout << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nTask not found!\n";
}


// Function to search task by name
void searchByName()
{
    if (head == NULL)
    {
        cout << "\nTo-Do List is empty!\n";
        return;
    }

    string name;

    cin.ignore();

    cout << "\nEnter Task Name: ";
    getline(cin, name);

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->task == name)
        {
            cout << "\nTask Found!";
            cout << "\nTask ID   : " << temp->id;
            cout << "\nTask Name : " << temp->task;

            cout << "\nPriority  : ";

            if (temp->priority == 1)
                cout << "High";
            else if (temp->priority == 2)
                cout << "Medium";
            else
                cout << "Low";

            cout << "\nStatus    : ";

            if (temp->completed)
                cout << "Completed";
            else
                cout << "Pending";

            cout << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nTask not found!\n";
}


// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n\n================================";
        cout << "\n       TO-DO LIST SYSTEM";
        cout << "\n================================";

        cout << "\n1. Add Task";
        cout << "\n2. Display / Traverse Tasks";
        cout << "\n3. Complete / Delete Task";
        cout << "\n4. Search Task by ID";
        cout << "\n5. Search Task by Name";
        cout << "\n6. Exit";

        cout << "\n================================";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                completeTask();
                break;

            case 4:
                searchByID();
                break;

            case 5:
                searchByName();
                break;

            case 6:
                cout << "\nProgram terminated successfully!\n";
                break;

            default:
                cout << "\nInvalid input! Please enter 1-6.\n";
        }

    } while (choice != 6);

    return 0;
}
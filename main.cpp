#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<string, bool>> tasks;

void addTask() {
    string task;
    cout << "Enter task: ";
    cin.ignore();
    getline(cin, task);
    tasks.push_back(make_pair(task, false));
    cout << "Task added successfully!\n";
}

void viewTasks() {
     if(tasks.empty())
    {
        cout<<"Nothing to display"<<endl;
    }
    cout << "\nTasks:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ": " << tasks[i].first << " ["
             << (tasks[i].second ? "Completed" : "Pending") << "]\n";
    }
}

void deleteTask() {

    int taskNumber;

     if(tasks.empty())
    {
        cout<<"Nothing to delete"<<endl;
    }
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

void markTaskAsCompleted() {
    int taskNumber;

    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;


    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].second = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Delete Task\n4. Mark Task as Completed\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: deleteTask(); break;
            case 4: markTaskAsCompleted(); break;
            case 5: break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;

}

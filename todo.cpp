#include <iostream>
#include <windows.h>
using namespace std;

void print_tasks(string tasks[], bool completed[], int task_count)
{
    cout << "\nTASKS TO DO:" << endl;
    cout << "------------------------" << endl;
    for (int i = 0; i < task_count; i++)
    {
        cout << "TASK " << i << ": " << tasks[i];
        if (completed[i])
            cout << " [✅ Completed]";
        else
            cout << " [⏳ Pending]";
        cout << endl;
    }
    cout << "------------------------" << endl;
}

int main()
{
    string tasks[10] = {""};
    bool completed[10] = {false};
    int task_count = 0;
    int option = -1;

    while (option != 0)
    {
        cout << "\n--- TO DO LIST ---" << endl;
        cout << "1 - ADD NEW TASK" << endl;
        cout << "2 - VIEW TASKS" << endl;
        cout << "3 - DELETE A TASK" << endl;
        cout << "4 - MARK TASK AS COMPLETED" << endl;
        cout << "0 - EXIT PROGRAM" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option)
        {
        case 1: // Add Task
        {
            if (task_count > 9)
            {
                cout << "'''TASK LIST IS FULL'''" << endl;
            }
            else
            {
                cout << "Enter a new task: ";
                cin.ignore();
                getline(cin, tasks[task_count]);
                completed[task_count] = false;
                task_count++;
                cout << "✅ Task added successfully!\n";
            }
            break;
        }

        case 2: // View Tasks
        {
            if (task_count == 0)
                cout << "No tasks to show!\n";
            else
                print_tasks(tasks, completed, task_count);
            break;
        }

        case 3: // Delete Task
        {
            if (task_count == 0)
            {
                cout << "No tasks to delete!\n";
                break;
            }

            int del_task = 0;
            cout << "Enter the task number to delete: ";
            cin >> del_task;

            if (del_task < 0 || del_task >= task_count)
            {
                cout << "⚠ Invalid task number.\n";
                break;
            }

            for (int i = del_task; i < task_count - 1; i++)
            {
                tasks[i] = tasks[i + 1];
                completed[i] = completed[i + 1];
            }
            task_count--;
            cout << "🗑 Task deleted successfully!\n";
            break;
        }

        case 4: // Mark Task as Completed
        {
            if (task_count == 0)
            {
                cout << "No tasks to mark!\n";
                break;
            }

            int task_num;
            cout << "Enter task number to mark as completed: ";
            cin >> task_num;

            if (task_num < 0 || task_num >= task_count)
            {
                cout << "⚠ Invalid task number.\n";
                break;
            }

            completed[task_num] = true;
            cout << "✅ Task marked as completed!\n";
            break;
        }

        case 0:
        {
            cout << "👋 Program terminated. Have a nice day!\n";
            break;
        }

        default:
        {
            cout << "⚠ Invalid option, please try again.\n";
            break;
        }
        } // end of switch
    }     // end of while

    return 0;
}
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

#define CAMERON 'C'
#define JAIME 'J'

struct task
{
    int originalIndex;
    int start;
    int finish;
};

bool compare(task a, task b);
string makeSchedule(task tasks[], int n);

int main()
{
    int n = 0;
    cin >> n;

    task tasks[n];

    for (int i = 0; i < n; i++)
    {
        cin >> tasks[i].start;
        cin >> tasks[i].finish;
        tasks[i].originalIndex = i;
    }

    cout << makeSchedule(tasks, n) << endl;

    return 0;
}

bool compare(task a, task b)
{
    if (a.start < b.start)
    {
        return true;
    }
    else if (a.start > b.start)
    {
        return false;
    }
    else
    {
        return a.originalIndex < b.originalIndex;
    }
}

string makeSchedule(task tasks[], int n)
{
    sort(tasks, tasks + n, compare);

    stack<task> J;
    stack<task> C;

    char result[n];

    result[tasks[0].originalIndex] = CAMERON;
    C.push(tasks[0]);

    bool overlapingTasks = false;

    for (int i = 1; i < n; i++)
    {
        task lastC = C.top();

        if (tasks[i].start < lastC.finish)
        {
            if (J.empty())
            {
                J.push(tasks[i]);
                result[tasks[i].originalIndex] = JAIME;
            }
            else
            {
                task lastJ = J.top();

                if (tasks[i].start < lastJ.finish)
                {
                    overlapingTasks = true;
                    break;
                }
                else
                {
                    J.push(tasks[i]);
                    result[tasks[i].originalIndex] = JAIME;
                }
            }
        }
        else
        {
            C.push(tasks[i]);
            result[tasks[i].originalIndex] = CAMERON;
        }
    }

    if (overlapingTasks)
    {
        return "Impossible schedule";
    }
    else
    {
        string schedule = "";

        for (int i = 0; i < n; i++)
        {
            schedule += string(1, result[i]);
        }

        return schedule;
    }
}

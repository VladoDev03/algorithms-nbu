#include <iostream>
#include <algorithm>

using namespace std;

struct myItem
{
    int itemNumber;
    int profit;
    int weight;
    float ppw;
};

bool compare(myItem a, myItem b);
float fractionalKnapsack(int capacity, myItem items[], int n);

int main()
{
    int capacity = 25;

    myItem items[] = {
        {1, 30, 10, 0},
        {2, 20, 5, 0},
        {3, 40, 15, 0},
        {4, 36, 8, 0}
    };

    cout << fractionalKnapsack(capacity, items, 4) << endl;

    return 0;
}

bool compare(myItem a, myItem b)
{
    return a.ppw > b.ppw;
}

float fractionalKnapsack(int capacity, myItem items[], int n)
{
    for (int i = 0; i < n; i++)
    {
        items[i].ppw = ((float)items[i].profit / items[i].weight);
    }

    sort(items, items + n, compare);

    float maxVal = 0.0;
    int i = 0;

    while (capacity > 0 && i <= n - 1)
    {
        if (capacity >= items[i].weight)
        {
            maxVal = maxVal + (float)items[i].profit;
            capacity = capacity - items[i].weight;
        }
        else
        {
            maxVal += (capacity * items[i].ppw);
            capacity = 0;
        }

        i++;
    }

    return maxVal;
}

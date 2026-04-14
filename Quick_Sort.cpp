#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int s, int e)
{
    int pivot = arr[s];
    int count = 0;


    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int p_index = s + count;
    swap(arr[s], arr[p_index]);

    int i = s, j = e;
    while (i < p_index && j > p_index)
    {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < p_index && j > p_index)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return p_index;
}

void quicksort(int arr[], int s, int e)
{
    if (s >= e) return;

    int p = partition(arr, s, e);

    quicksort(arr, s, p - 1);
    quicksort(arr, p + 1, e);
}

int main()
{
    int n;
    cout<<"size of array:";
    cin >> n;
    int arr[n];
    cout<<"Enter array:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);


    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}


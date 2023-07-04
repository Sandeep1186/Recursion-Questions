#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& arr, int s, int e) {
    int size = e - s + 1;
    int *out = new int[size];
    int k = 0;
    int mid = (s + e) / 2;
    int i = s, j = mid + 1;

    while (i <= mid && j <= e) {
        if (arr[i] < arr[j]) {
            out[k] = arr[i];
            k++;
            i++;
        }
        else {
            out[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= mid) {
        out[k] = arr[i];
        k++;
        i++;
    }

    while (j <= e) {
        out[k] = arr[j];
        j++;
        k++;
    }

    int m = 0;
    for (int i = s; i <= e; i++) {
        arr[i] = out[m];
        m++;
    }

    delete[] out;
}

void mergeSortHelper(vector<int>& arr, int s, int e) {
    if (s >= e)
        return;

    int mid = (s + e) / 2;
    mergeSortHelper(arr, s, mid);
    mergeSortHelper(arr, mid + 1, e);
    merge(arr, s, e);
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();
    mergeSortHelper(arr, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;


}

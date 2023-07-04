#include <iostream>
#include <vector>

using namespace std;

int findKthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int m = arr1.size();
    int n = arr2.size();
    int i = 0;
    int j = 0;
    int count = 0;
    int kthElement;

    while (i < m && j < n) {
        if (arr1[i] < arr2[j]) {
            count++;
            if (count == k) {
                kthElement = arr1[i];
                break;
            }
            i++;
        } else {
            count++;
            if (count == k) {
                kthElement = arr2[j];
                break;
            }
            j++;
        }
    }

    while (i < m) {
        count++;
        if (count == k) {
            kthElement = arr1[i];
            break;
        }
        i++;
    }

    while (j < n) {
        count++;
        if (count == k) {
            kthElement = arr2[j];
            break;
        }
        j++;
    }

    return kthElement;
}

int main() {
    int n1, n2, k;
    cout << "Enter the number of elements in array 1: ";
    cin >> n1;
    cout << "Enter the elements of array 1 in sorted order: ";
    vector<int> arr1(n1);
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in array 2: ";
    cin >> n2;
    cout << "Enter the elements of array 2 in sorted order: ";
    vector<int> arr2(n2);
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int kthElement = findKthElement(arr1, arr2, k);

    cout << "The kth element is: " << kthElement << endl;
}

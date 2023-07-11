#include <bits/stdc++.h> 
int findKthElementRecursive(vector<int>& arr1, vector<int>& arr2, int start1, int start2, int k) {
    // Base cases
    if (start1 >= arr1.size()) {
        return arr2[start2 + k - 1];
    }
    if (start2 >= arr2.size()) {
        return arr1[start1 + k - 1];
    }
    if (k == 1) {
        return min(arr1[start1], arr2[start2]);
    }

    // Recursive cases
    int mid1 = start1 + k / 2 - 1;
    int mid2 = start2 + k / 2 - 1;
    int val1 = mid1 < arr1.size() ? arr1[mid1] : INT_MAX;
    int val2 = mid2 < arr2.size() ? arr2[mid2] : INT_MAX;

    if (val1 <= val2) {
        return findKthElementRecursive(arr1, arr2, mid1 + 1, start2, k - k / 2);
    } else {
        return findKthElementRecursive(arr1, arr2, start1, mid2 + 1, k - k / 2);
    }
}
int findKthElement(vector<int>& arr1, vector<int>& arr2, int k) {
    int m = arr1.size();
    int n = arr2.size();
    return findKthElementRecursive(arr1, arr2, 0, 0, k);
}



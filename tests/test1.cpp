// Syllabus: sorting




// Test:
// 1. Perform bubble sort done
// 2. Perform selection sort done
// 3. Perform insertion sort done
// 4. Perform merge sort done
// 5. Perform quick sort done
// 6. sorting analysis done

//score: 60/60

#include <bits/stdc++.h>
using namespace std;

void print_array(vector<int> arr) {
    for(int i : arr) cout<<i<<" ";
}

void bubbleSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0;i<n;i++) {
        for(int j = 1;j<n-i;j++) {
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}


void selectionSort(vector<int> &arr) {
    int n = arr.size();
    for(int i = 0;i<n-1;i++) {
        int mini = i;
        for(int j = i+1;j<n;j++) {
            if(arr[j] < arr[mini]) mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}

void insertionSort(vector<int> &arr) {
    const auto n = arr.size();
    for(int i = 1;i<n;i++) {
        int j = i;
        while(j>0 && arr[j]<arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}


void merge(vector<int> &arr, int s, int e) {
    int m = s + (e - s)/2;
    vector<int> arr1, arr2, arr3;

    for(int i = s;i<=m;i++) arr1.push_back(arr[i]);
    for(int i = m+1;i<=e;i++) arr2.push_back(arr[i]);

    int i = 0, j = 0, k = 0;
    while(i<arr1.size() && j<arr2.size()) {
        if(arr1[i] <= arr2[j]) arr3.push_back(arr1[i++]);
        else arr3.push_back(arr2[j++]);
    }

    while(i<arr1.size()) arr3.push_back(arr1[i++]);
    while(j<arr2.size()) arr3.push_back(arr2[j++]);

    for(int i = s;i<=e;i++) {
        arr[i] = arr3[k++];
    }
}

void mergeSort(vector<int> &arr, int s, int e) {
    if(s>=e) return;
    int m = s + (e - s)/2;
    mergeSort(arr, s, m);
    mergeSort(arr, m+1, e);
    merge(arr, s, e);
}

int findPivot(vector<int> &arr, int s, int e) {
    int i = s, j = e;
    int x = 0;
    while(i<=j) {
        // cout<<arr[i]<<" "<<arr[j]<<endl;
        while(arr[i] <= arr[s]) i++;
        while(arr[j] > arr[s]) j--;
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[s],arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int s, int e) {
    if(s<e) {
        int pivot = findPivot(arr, s, e);
        quickSort(arr, s, pivot-1);
        quickSort(arr, pivot+1, e);
    }
}

// . sorting analysis
// . name       best    average     worst       space       online      stable      inplace
// . bubble     O(n)    O(n2)       O(n2)       O(1)        no          yes         yes
// . selection  O(n2)   O(n2)       O(n2)       O(1)        no          no          yes
// . insertion  O(n)    O(n2)       O(n2)       O(1)        yes         yes         yes
// . merge      O(nlogn)O(nlogn)    O(nlogn)    O(n)        no          yes         no
// . quick      O(nlogn)O(nlogn)    O(n2)       O(1)        no          no          yes
// . heap       O(nlogn)O(nlogn)    O(nlogn)    O(1)        no          no          yes
// .
// .
// .


int main() {
    vector<int> arr = {9,4,5,3,1,2,4,7,8};
    quickSort(arr, 0, 8);
    // cout<<findPivot(arr, 0, 8)<<endl;
    print_array(arr);
}
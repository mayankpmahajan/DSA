//
// Created by mayank on 13-08-2024.
//

#include <bits/stdc++.h>
using namespace std;

// int partition(vector<int> &arr, int low, int high) {
//     int pivotIndex = low;
//
//     for(int i = low;i<=high;i++) {
//         if(arr[i] > arr[pivotIndex]) {
//             swap(arr[i-1], arr[pivotIndex]);
//             return i-1;
//         }
//     }
//
//     return 0;
// }

// Why this wont work?
//     because
//         *arr is not already sorted
//         *you have to place all the smaller elements before the pivot and larger after the pivot

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }
        if (i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort(vector<int> &arr, int low, int high) {
    if(low < high) {
        int part = partition(arr, low, high);
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

int partition1(vector<int> &arr, int low, int high) {
    int i = low , j = high;
    while(i < j) {
        while(arr[i] <= arr[low] && i <= high - 1) i++;
        while(arr[j] > arr[low] && j >= low + 1 ) j--;
        if(i>=j) break;
        swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}


void quickSort1(vector<int> &arr, int low, int high) {
    if(low < high) {
        int p = partition1(arr, low, high);
        quickSort1(arr, low, p);
        quickSort1(arr, p+1, high);
    }
}

int partition2(vector<int> &arr, int low, int high) {
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= arr[low] && i<=high) i++;
        while(arr[j] > arr[low] && j>=low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[j], arr[low]);
    return j;
}

void quickSort2(vector<int> &arr, int low, int high) {
    if(low < high) {
        int part = partition2(arr, low, high);
        quickSort2(arr, low, part-1);
        quickSort2(arr, part+1, high);
    }
}

int partition3(vector<int> &arr, int low, int high) {
    int i = low, j = high;
    while(i < j) {
        while(arr[i] <= arr[low] && i<=high) i++;
        while(arr[j] > arr[low] && j>=low) j--;
        if(i < j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}




void quickSort3(vector<int> &arr, int low, int high) {
    if(low < high) {
        int part = partition3(arr, low, high);
        quickSort3(arr, low, part-1);
        quickSort3(arr, part+1, high);
    }
}



int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    quickSort3(arr, 0, arr.size()-1);
    for(int i : arr) cout<<i<<" ";
}


















































//
// Created by mayank on 13-08-2024.
//
#include <bits/stdc++.h>
using namespace std;

//worst and average case TC: O(n2)
//best case TC: O(n)
//SC: O(n)

void brokenBubble(vector<int> &arr, int j) {
    if(j == 0 || arr[j] > arr[j-1]) return;

    swap(arr[j], arr[j-1]);
    brokenBubble(arr, j -1);
}

void insertionSort(vector<int> &arr, int i) {
    if(i == arr.size()) return;
    brokenBubble(arr, i);
    insertionSort(arr, i+1);
}

int main() {
    vector<int> arr = {4,5,87,7,54,4,1,2,3,6,78,4,6,9,7,45,5,6,4,1,2,3,6,7,98,7,4};
    insertionSort(arr, 1);
    for(int i : arr) cout<<i<<" ";

    return 0;
}
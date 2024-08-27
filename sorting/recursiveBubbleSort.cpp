//
// Created by mayank on 13-08-2024.
//

//TC: O(n2)
//SC: O(n)


#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr, int i, int j) {
    if(i == arr.size() - 1) return;

    if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);

    if(j == arr.size() - 1) bubbleSort(arr, i+1, 1);
    else bubbleSort(arr, i , j+1);
}

int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    bubbleSort(arr, 0, 1);
    for(auto i : arr) cout<<i<<" ";

    return 0;
}
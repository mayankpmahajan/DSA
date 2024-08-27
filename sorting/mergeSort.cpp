#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int s, int e) {
    int m = s + (e - s)/2;
    vector<int> arr1;
    vector<int> arr2;
    vector<int> arr3;

    for(int i = s;i<=m;i++) arr1.push_back(arr[i]);
    for(int i = m+1;i<=e;i++) arr2.push_back(arr[i]);

    int a = 0, b = 0;
    while(a < arr1.size() && b < arr2.size()) {
        if(arr1[a]  <= arr2[b]) arr3.push_back(arr1[a++]);
        else arr3.push_back(arr2[b++]);
    }

    while(a<arr1.size()) arr3.push_back(arr1[a++]);
    while(b<arr2.size()) arr3.push_back(arr2[b++]);

    int c = 0;
    for(int i = s;i<=e;i++) {
        arr[i] = arr3[c++];
    }
}



void mergeSort(vector<int> &arr, int s, int e) {
    if(s >= e) return;
    int m = s + (e - s)/2;

    mergeSort(arr, s, m );
    mergeSort(arr, m+1, e);
    merge(arr, s, e);
}


int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    mergeSort(arr, 0, arr.size()-1);
    for(int a : arr) cout<<a<<" ";

    return 0;
}

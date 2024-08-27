#include <bits/stdc++.h>
using namespace std;

// in each round, select the minimum and put it in starting of array
// from next round dont include the positions placed

// TC: O(n2)
// SC: O(1)


void selectionSort(vector<int> &arr) {
    for(int i = 0;i<arr.size();i++) {
        int mimimumIndex = i;
        for(int j = i;j<arr.size();j++) {
            if(arr[j] < arr[mimimumIndex]) mimimumIndex = j;
        }
        swap(arr[i], arr[mimimumIndex]);
    }
}


int main() {
    vector<int> arr = {9,8,7,6,5,4,1,2,3,5,4,1,2,3,6,7,8,9,6,5,4,1,2,3};
    selectionSort((arr));
    for(auto i : arr) cout<<i<<" ";
    return 0;
}

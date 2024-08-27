#include <bits/stdc++.h>
using namespace std;


//pair wise compare the eleements from start to the partial unsorted array's end if the comparison is not according to the order you want then swap
//do it for n -1 rounds

// TC: O(n2)
//Best case: O(n)f
// SC: O(1)

void bubbleSort(vector<int> &arr) {
    for(int i = 0;i<arr.size()-1;i++) {
        for(int j = 1;j<arr.size()-i;j++) {
            if(arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
        }
    }
}

void bubbleSort1(vector<int> &arr) {
    for(int i = 0;i<arr.size()-1;i++) {
        for(int j = 1;j<arr.size()-i;j++) {
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

void bubbleSort2(vector<int> &arr){
    for(int i = 0;i<arr.size()-1;i++) {
        for(int j = 1;j<arr.size()-i;j++) {
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}

void bubbleSort3(vector<int> &arr) {
    for(int i = 0;i<arr.size()-1;i++) {
        for(int j = 1;j<arr.size()-i;j++) {
            if(arr[j] < arr[j-1]) swap(arr[j], arr[j-1]);
        }
    }
}



int main() {
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    bubbleSort3(arr);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}















































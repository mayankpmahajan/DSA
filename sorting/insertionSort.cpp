//takes and element and places it in it's correct order


// TC: o(n2)
// Best case:o(n)
//SC: O(1)

#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr){
    for(int i = 1;i<arr.size();i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }

}

void insertionSort1(vector<int> &arr) {
    for(int i = 1;i<arr.size();i++) {
        int j = i;
        while(j>0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

void insertionSort2(vector<int> &arr) {
    for(int i = 1;i<arr.size();i++) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}


void insertionSort3(vector<int> &arr) {
    for(int i = 1;i<arr.size();i++) {
        int j = i;
        while(j>0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}


int main(){
    vector<int> arr = {9,8,7,6,5,4,3,2,1};
    insertionSort3(arr);
    for(auto i : arr) cout<<i<<" ";
    return 0;
}


































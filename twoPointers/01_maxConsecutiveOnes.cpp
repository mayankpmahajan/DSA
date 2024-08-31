#include <bits/stdc++.h>
using namespace std;

int longestOnes1(vector<int>& nums, int k) {
    int n = nums.size();

    int start = 0, maxi = 0, zeroCount = 0;


    for(int i = 0;i<nums.size();i++){
        if(nums[i] == 0){
            zeroCount++;
        }
        while(zeroCount > k){
            if(nums[start] == 0){
                zeroCount--;
            }
            start++;
        }
        maxi = max(maxi, i - start + 1);
    }
    return maxi;
}
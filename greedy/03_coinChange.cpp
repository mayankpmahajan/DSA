//
// Created by mayank on 17-08-2024.
//
#include <bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

public:
    int minCoins(vector<int> &coins, int sum) {
        // table[i] will be storing the minimum number of coins
        // required for i value.  So table[V] will have result
        int M = coins.size();
        int table[sum + 1];

        // Base case (If given value V is 0)
        table[0] = 0;

        // Initialize all table values as Infinite
        for (int i = 1; i <= sum; i++)
            table[i] = INT_MAX;

        // Compute minimum coins required for all
        // values from 1 to V
        for (int i = 1; i <= sum; i++) {
            // Go through all coins smaller than i
            for (int j = 0; j < M; j++) {
                if (coins[j] <= i) {
                    int sub_res = table[i - coins[j]];
                    if (sub_res != INT_MAX && sub_res + 1 < table[i])
                        table[i] = sub_res + 1;
                }
            }
        }

        if (table[sum] == INT_MAX)
            return -1;

        return table[sum];
    }
};

int minCoins(vector<int> &coins, int sum) {
    int n = coins.size();
    int table[sum+1];

    for(auto i : table) i = INT_MAX;

    table[0] = 0;

    for(int i = 1;i<=sum;i++) {

        for(int j = 0;j<n;j++) {
            if(coins[j]<=i) {
                int sub_res = table[i - coins[j]];
                if(sub_res != INT_MAX && sub_res + 1 < table[i]) table[i] = sub_res + 1;
            }
        }
    }

    return table[sum] == INT_MAX ? -1 : table[sum];
}

int minCoins2(vector<int> &coins, int sum) {

    int arr[sum+1];
    for(int i = 0;i<sum;i++) arr[i] = INT_MAX;

    arr[0] = 0;

    for(int i = 1;i<=sum;i++) {

        for(int j = 0;j<coins.size();j++) {
            if(coins[j] <= i) {
                int sub_res = arr[i - coins[j]];
                if(sub_res != INT_MAX && sub_res + 1 < arr[i]) {
                    arr[i] = sub_res + 1;
                }
            }
        }
    }

    return arr[sum] == INT_MAX ? -1 : arr[sum];
}


int minCoins3(vector<int> &coins, int sum) {

    vector<int> table(sum+1, INT_MAX);
    table[0] = 0;

    for(int i = 1;i<table.size();i++) {

        for(int j = 0;j<coins.size();j++) {
            if(coins[j] <= i) {
                int sub_res = table[i-coins[j]];
                if(sub_res !=INT_MAX && sub_res + 1 < table[i]) table[i] = sub_res + 1;
            }
        }
    }

    return table[sum] == INT_MAX ? -1 : table[sum];

}



//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for (int i = 0; i < m; i++)
            cin >> coins[i];

        Solution ob;
        cout << ob.minCoins(coins, v) << "\n";
    }
    return 0;
}

// } Driver Code Ends


























//there can be more combinations to distributions. It is not important for bigger denomination to have bigger number of coins or have as much as it can have
//in certain combinations they'll have to let go even if there is space for one more big coins or more
// int minCoins(vector<int> &coins, int sum) {
//     sort(coins.begin(), coins.end());
//     int mini = INT_MAX;
//     for(int i = coins.size()-1;i>=0;i--) {
//
//         int coin = 0, tempSum = sum;
//         for(int j = i;j>=0;j--) {
//             while(coins[j]<= tempSum) {
//                 coin++;
//                 tempSum -= coins[j];
//             }
//             if(tempSum == 0) break;
//         }
//         if(tempSum == 0) mini = min(mini, coin);
//     }
//     return mini == INT_MAX ? -1 : mini;
// }


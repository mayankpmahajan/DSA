#include<bits/stdc++.h>

using namespace std;
// A structure to represent a job
struct Job {
    int id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
class Solution {
public:
    bool static comparison(Job a, Job b) {
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done
    pair < int, int > JobScheduling(Job arr[], int n) {

        sort(arr, arr + n, comparison);
        int maxi = arr[0].dead;
        for (int i = 1; i < n; i++) {
            maxi = max(maxi, arr[i].dead);
        }

        int slot[maxi + 1];

        for (int i = 0; i <= maxi; i++)
            slot[i] = -1;

        int countJobs = 0, jobProfit = 0;

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].dead; j > 0; j--) {
                if (slot[j] == -1) {
                    slot[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(countJobs, jobProfit);
    }
};


bool cmp1(Job a, Job b) {
    if(a.profit > b.profit) return true;
    else if(a.profit < b.profit) return false;
    else if(a.dead < b.dead) return true;
    return false;
}

vector<int> JobScheduling1(Job arr[], int n) {
    int maxi = INT_MIN;

    for(auto i : arr) {
        maxi = max(maxi, i.dead);
    }

    vector<int> ans(2, 0);

    sort(arr, arr+n, cmp1);

    for(int i = 0;i<n;i++) {
        int x = arr[i].dead;
        while(x>0) {
            if(time[x] == -1) {
                time[x] = 1;
                ans[0]++;
                ans[1] += arr[i].profit;
                break;
            }
            x--;
        }
    }

    return ans;
}

bool cmp2(Job a, Job b) {
    if(a.profit > b.profit) return true;
    else if(a.profit < b.profit) return true;
    else if(a.dead < b.dead) return true;
    return false;
}

vector<int> JobScheduling2(Job arr[], int n)
{
    sort(arr, arr+n, cmp2);
    int jobCount = 0, profit = 0;
    int maxi = arr[0].dead;
    for(int i = 1;i<n;i++) {
        maxi = max(maxi, arr[i].dead)
    }

    vector<int> time(maxi + 1, -1);

    for(int i = 0;i<n;i++) {
        int x = arr[i].dead;
        while(x>0 && time[x] != -1) {
            x--;
        }

        if(x!=0) {
            time[x] = 1;
            jobCount++;
            profit += arr[i].profit;
        }
    }

    vector<int> ans;
    ans.push_back(jobCount);
    ans.push_back(profit);

}







int main() {
    int n = 4;
    Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};

    Solution ob;
    //function call
    pair < int, int > ans = ob.JobScheduling(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}




























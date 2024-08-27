//
// Created by mayank on 17-08-2024.
//

#include <bits/stdc++.h>

using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:

    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;
    }

    // function to return fractionalweights
    double fractionalKnapsack(int W, Item arr[], int n) {

        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalvalue = 0.0;

        for (int i = 0; i < n; i++) {

            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;
            }
        }

        return finalvalue;

    }
};

bool cmp(Item a, Item b) {
    double valueA = (double)a.value / (double)a.weight;
    double valueB = (double)b.value / (double)b.weight;

    return valueA > valueB;
}

double fractionalKnapsack1(int w, Item arr[], int n) {
    sort(arr, arr+n, cmp);
    double finalValue = 0;
    int i = 0;
    while(i < n && w!=0) {
        if(arr[i].weight <= w ) {
            w-= arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            double unitValue = (double)arr[i].value / (double)arr[i].weight;
            finalValue += unitValue * (double)w;
            w = 0;
        }
        i++;
    }
    return finalValue;
}

class Solution2 {
public:

    bool cmp(Item a, Item b) {
        double x = double(a.value) / double(a.weight);
        double y = double(b.value) / double(b.weight);

        return x > y;
    }

    double fractionalKnapsack(int w, Item arr[], int n) {
        sort(arr, arr+n, cmp);
        double finalValue = 0;
        for(int i = 0;i<n;i++) {
            if(arr[i].weight <= w) {
                w-=arr[i].weight;
                finalValue+= arr[i].value;
            }
            else {
                double unitWeight = (double)arr[i].value / (double)arr[i].weight;
                finalValue += unitWeight * w;
                w = 0;
                break;
            }
        }
        return finalValue;
    }
};

bool comp(Item a, Item b) {
    double x = double(a.value) / double(a.weight);
    double y = double(b.value) / double(b.weight);
    return x>y;
}


double fractionalKnapsack3(int w, Item arr[], int n) {
    sort(arr, arr+n, comp);

    double finalValue = 0;

    for(int i = 0;i<n;i++) {
        if(arr[i].weight <= w) {
            finalValue += arr[i].value;
            w-= arr[i].weight;
        }
        else {
            double unitvalue = double(arr[i].value) / double(arr[i].weight);
            finalValue += unitvalue * w;
            w = 0;
            break;
        }
    }

    return finalValue;
}



int main() {
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    return 0;
}






































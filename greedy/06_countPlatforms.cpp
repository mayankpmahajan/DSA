#include<bits/stdc++.h>
using namespace std;

int countPlatforms(int n,int arr[],int dep[])
{
    int ans=1; //final value

    for(int i=0;i<=n-1;i++)
    {
        int count=1; // count of overlapping interval of only this   iteration
        for(int j=i+1;j<=n-1;j++)
        {
            if((arr[i]>=arr[j] && arr[i]<=dep[j]) ||
           (arr[j]>=arr[i] && arr[j]<=dep[i]))
            {
                count++;
            }
        }
        ans=max(ans,count); //updating the value
    }
    return ans;
}

int main()
{
    int arr[]={900,945,955,1100,1500,1800};
    int dep[]={920,1200,1130,1150,1900,2000};
    int n=sizeof(dep)/sizeof(dep[0]);
    cout<<"Minimum number of Platforms required "<<countPlatforms(n,arr,dep)<<endl;
}

int countPlatforms1(int n,int arr[],int dep[]){
	int ans = 1;
    int maxi = INT_MIN;
	for(int i = 0;i<n;i++) {

	    for(int j = i + 1;j<n;j++) {
	        if(arr[i]<= arr[j] && arr[j] <= dep[i] || arr[j] <= arr[i] && arr[i] <= dep[j]) ans++;
	    }
	    maxi = max(maxi, ans);

	}
    return maxi;
}




int findPlatform(int arr[], int dep[], int n)
{
    int mini = 1;
    for(int i = 0;i<n;i++) {
        int count = 0;
        for(int j = i+1;j<n;j++) {
            if(arr[i]>= arr[j] && arr[i] <= dep[j] || arr[i]<=arr[j] && arr[j] <= dep[i]) {
                count++;
            }
        }
        mini = max(count, mini);
    }

    return mini;
}





































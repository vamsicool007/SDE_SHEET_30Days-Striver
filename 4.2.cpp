//4 Sum problem asked in Google and Amazon interviews in this problem we have to find max unique quadruplets
#include<bits/stdc++.h>
using namespace std;

void fun()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

int main()
{
    fun();
    //Method1: Using hashmap and 2 pointer method time complexity O(n^3)
    int n;
    cin>>n;
    int x;
    cin>>x;  //target sum of 4 numbers
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<vector<int>>ans;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum1=a[i]+a[j];
            int left=j+1;
            int right=n-1;
            while(left<right)
            {
                int sum2=a[left]+a[right];
                if((x-sum1)<sum2)
                    right--;
                else if((x-sum1)>sum2)
                    left++;
                else
                {
                    vector<int>v;
                    v.push_back(a[i]);
                    v.push_back(a[j]);
                    v.push_back(a[left]);
                    v.push_back(a[right]);
                    ans.push_back(v);
                    while(left<right && v[2]==a[left])      //prevents from duplicate
                        left++;
                    while(left<right && v[3]==a[right])     //prevents from duplicate
                        right--;
                }
            }
            int y=a[j];                                     //prevents from duplicate
            while(j<n && y==a[j])
                j++;
            j--;
        }
        int z=a[i];                                         //prevents from duplicate
        while(i<n && z==a[i])
            i++;
        i--;
    }
    for(auto i:ans)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
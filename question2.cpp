#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int>arr, int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        // itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}
int main(){
    int n,k,cust_money;
    bool f=0;
    cin>>n>>k>>cust_money;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
  for (int i = 0; i <= n - k; i++)
    {
        for (int j = 1; j < k; j++)
        {
            if (binarySearch(v,i,i+k,cust_money))
            {
                f=1;
                cout<<"right";
                break;
            }
               
        }
        if(f==1)
        break;
        
    }
    if(f==0)
    cout<<"false";



return 0;

}

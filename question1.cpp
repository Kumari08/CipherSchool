#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> res;
      if(n==0) res.push_back(0);
        if(n%2 != 0) res.push_back(0);
        for(int i=1;i<=floor(n/2);i++){
            res.push_back(i);
            res.push_back(-i);
        }
        for(auto x:res)
            cout<<x<<" "<<endl;
        cout<<endl;

return 0;

}

		

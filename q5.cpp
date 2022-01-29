#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define l long
#define sz size()
#define vt vector<int>
#define FOR(n) for (int i = 0; i < n; i++)
#define FORV(n) for (int v = 0; v < n; v++)
#define FORJ(n) for (int j = 0; j < n; j++)
#define RFOR(n) for (int i = n - 1; i >= 0; i--)
void Print(vt data){
    FOR(data.sz) cout<<data[i]<<' ';
    cout<<endl;
}
int main(){
     int t; cin>>t;
     FOR(t){
        vt data;
        string s;cin>>s;
        s.pop_back();
        s.erase(0,1);
      //  cout<<s<<endl;
        while(s.find(',')!=string::npos){
            data.pb(stoi(s.substr(0,s.find(','))));
            s.erase(0,s.find(',')+1);
        }
        data.pb(stoi(s));
        int x,cost=0;
        while(data.sz!=1){
            if(data[0]>data[data.sz-1]) x=0;
            else x=data.sz-1;
            cost+=data[0]+data[data.sz-1];
            data.erase(data.begin()+x);
           // Print(data);
           // cout<<x<<endl;
        }
        cout<<cost<<endl;
    }
}
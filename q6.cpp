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
// use bfs for q2
int lis(vt data){
    vt lis(data.sz);
    lis[0] = 1;
    for (int i = 1; i < data.sz; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (data[j]<data[i]&&lis[j]+1>lis[i])
                lis[i] = lis[j] + 1;
    }
    int max=INT_MIN;
    FOR(lis.sz) if(max<lis[i]) max=lis[i];
    return max;
}
int main(){
    int t;
    cin>>t;
    string s;
    FOR(t){
        vt data;
        cin>>s;
        while(s.find(',')!=string::npos){
            data.pb(stoi(s.substr(0,s.find(','))));
            s.erase(0,s.find(',')+1);
        }
        data.pb(stoi(s));
       // FOR(data.sz) cout<<data[i]<<' ';
        int max=1,n=data.sz;
        cout<<lis(data)<<endl;
    }
}
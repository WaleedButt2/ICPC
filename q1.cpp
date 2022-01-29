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
vt Sol(string &s,vt &data,int next){
    stack <int>stk;
    FOR(s.length()){
        if(s[i]=='(') stk.push(i);
        else if(stk.empty()&&s[i]==')')  data[i]=-1;
        else if(s[i]==')') {
            stk.pop();
            data[i]=1;
        } 
    }
    while(!stk.empty()){
        data[stk.top()]=-1;
        stk.pop();
    }
    return data;
}
vt jojo_it(vt data){
    vt jojo;int ans=0;
    FOR(data.sz){
        if(data[i]>=0)ans+=data[i];
        else {
            jojo.pb(ans*2);ans=0;
        }
    }
    if(ans!=0) jojo.pb(ans*2);
    int dio=INT_MIN;ans=0;
    FOR(jojo.sz) dio=max(jojo[i],dio);
    FOR(jojo.sz) if(dio==jojo[i]) ans++;
    jojo.clear();jojo.pb(dio);jojo.pb(ans);
    return jojo;
}
void Print(vt data){
    FOR(data.sz) cout<<data[i]<<' ';
    cout<<endl;
}
int main(){
    int op;string s;
    cin>>op;
    FOR(op){
        cin>>s;
        int ans=0;
        vt data(s.length(),0);
        data=jojo_it(Sol(s,data,0));
        Print(data);
    }
}
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
int main(){
    int t;
    cin>>t;
    FOR(t){
        int n,e;
        cin>>n>>e;
        int Matrix[n][n];

        int u,v,w;
        int start, dest,val;
        FOR(e){
            //exit(0);
            cin>>u>>v>>w;
            Matrix[u-1][v-1]=w;
            Matrix[v-1][u-1]=w;
        }
        cin>>start>>dest>>val;
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++)
                for(int j=0; j<n; j++)
                Matrix[j][i]=Matrix[i][j]=max(Matrix[i][j],min(Matrix[i][k],Matrix[k][j]));

       int trip=ceil((float)val/(Matrix[start-1][dest-1]-1));
       cout<<trip<<" trips"<<endl;
    }
}
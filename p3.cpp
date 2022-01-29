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
void Print(vector<int> v){
    FOR(v.sz) cout<<v[i]<<' '; 
    cout<<endl;
}
void Print(vector<vt> v){
    cout<<"  ";
    FOR(v.sz) cout<<i<<"  ";
    cout<<endl;
    FOR(v.sz) {
        cout<<i<<' ';
    FORJ(v[i].sz){ 
        cout<<v[i][j];
        if(v[i][j]>=10) cout<<" ";
        else if(v[i][j]>=0) cout<<"  ";
        else cout<<" ";
    } 
    cout<<endl;
    }
    cout<<endl;
}
class Hold{
public:
    int edge;
    int src;
    int dest;
Hold(){

}
Hold(int e,int s,int d){
    edge=e;src=s;dest=d;
}
};
void Print(vector<Hold> h){
    cout<<"Weight\tsource\tdest \n";
    FOR(h.sz){
        cout<<h[i].edge<<"\t"<<h[i].src<<"\t"<<h[i].dest<<endl;
    }
}
bool check(Hold x, Hold y){
    return x.edge<y.edge;
}
int Make_Cycle(vector<Hold> holder, int x){
    Hold p=holder[x];
    int src=p.src;
    bool flag=true;
    int weight=0;
    bool cycle=true;
    while((flag||src!=p.src)&&cycle){
        flag=false;
        weight+=p.edge;
        FOR(holder.sz){
            if(holder[i].src==p.dest){
                p=holder[i];
                break;
            }
            else if(i==holder.sz-1) cycle=false;
        } 
    }
    if(cycle==false) return 1;
    else return weight;
}
int main(){
    int t,n,e;
    cin>>t;int u,v,w;
    for(int op=0;op<t;op++){
        cin>>n>>e;
        vector<vt> graph(n,vt(n,0)); 
        vector<Hold> holder;
        FOR(e){
            cin>>u>>v>>w;
            u--;v--;
            graph[u][v]=w;
            //cout<<w<<' ';
            holder.pb(Hold(w,u,v));
        }
        //exit(0);
       // Print(graph);
        sort(holder.begin(),holder.end(),check);
        //Print(holder);
        int ans=0;
         bool found=false;
        FOR(n){ 
        if(holder[i].edge<=0)  ans=Make_Cycle(holder,i); 
        else break;
        if(ans<0) {found=true;break;}
        }
        if(found) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
/*
1
8
11
1 2 3
2 3 4
3 4 10
4 5 15
2 6 15
3 6 3
6 7 -5
7 8 15
7 4 2
5 3 -3
4 2 -5
*/
/*
1
4
5
1 2 4
2 3 3
2 4 -5
4 3 11
3 2 -2
*/
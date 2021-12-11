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
    FOR(v.sz) {
    FORJ(v[i].sz) cout<<v[i][j]<<' '; 
    cout<<endl;
    }
    cout<<endl;
}

class Holder{
public:
    int Edge;
    int src;
    int dest;
Holder(){

}
Holder(int e,int s,int d){
    Edge=e;src=s;dest=d;
}
};
void Print(vector<Holder> h){
    cout<<"Weight\tsource\tdest \n";
    FOR(h.sz){
        cout<<h[i].Edge<<"\t"<<h[i].src<<"\t"<<h[i].dest<<endl;
    }
}
bool check(Holder h1,Holder h2){
    return h1.Edge<h2.Edge;
}
void Fill(vector<Holder> &hold,vector<vt> &graph){
    vector<vector<bool>> visited(graph.sz,vector<bool>(graph.sz,false));
    FOR(graph.sz){
        FORJ(graph[i].sz){
            if(graph[i][j]!=0&&!visited[i][j]){
                hold.pb(Holder(graph[i][j],i,j));
                visited[i][j]=true;visited[j][i]=true;
            }
        }
    }
}
class point{
    public:
    int i;
    int prev;
point(){

}
point (int i,int j){
    this->i=i;this->prev=j;
}
};
bool check_cycle(Holder h,vector <vt> graph)
{
    vector<bool> visited(graph.sz,false);
    graph[h.src][h.dest]=h.Edge;
    graph[h.dest][h.src]=h.Edge;
    bool flag=false;
    stack <point> s;
    s.push(point(h.src,-1));
    point p;
    // src=4 dest =5 edge =34 
   // cout<<endl;
    while(!s.empty()){
        p=s.top();s.pop();
        if(flag&&p.i==h.src){
            flag=false;break;
        }
        flag=true;
        for(int j=0;j<graph[p.i].sz;j++) if(graph[p.i][j]!=0&&j!=p.prev) s.push(point(j,p.i));
    }
    return !flag;
}
int MPS (vector <vt> graph,vector<Holder> &hold,bool run){
    vector<bool> visited(graph.sz,false);
    vector<Holder> new_graph;
    vector<vt> g(graph.sz,vt(graph.sz,0));
    int x=0;
    FOR(hold.sz){
        if(new_graph.empty()) {
            new_graph.pb(hold[i]);
            g[hold[i].src][hold[i].dest]=hold[i].Edge;
            g[hold[i].dest][hold[i].src]=hold[i].Edge;
        }
        else{
            if(!check_cycle(hold[i],g)){
                x=i;
            new_graph.pb(hold[i]);
            g[hold[i].src][hold[i].dest]=hold[i].Edge;
            g[hold[i].dest][hold[i].src]=hold[i].Edge;
            }
        }
    }
   // cout<<endl;
   // Print(g);
    //Print(new_graph);
    if(run){
    int sum=0;
    FOR(new_graph.sz) sum+=new_graph[i].Edge;
    cout<<sum<<endl;
    }return x;
}
int main(){
    int t,n,i,j;
    cin>>t>>n;
    for(int op=0;op<t;op++){
        vector<Holder> hold;

        vector<vt> graph(n,vt(n,0));        
        FOR(n){
            FORJ(n){
                cin>>graph[i][j];
                if(graph[i][j]>1000) graph[i][j]=0;
            }
        }
        Fill(hold,graph);
      //  cout<<endl;
        sort(hold.begin(),hold.end(),check);
       // Print(hold);
        int a=MPS(graph,hold,false);
        hold.erase(hold.begin()+a);
        //Print(hold);
        MPS(graph,hold,true);
        //cout<<BFS_Twisted(graph,n)<<endl;
    }
}
/*
1
3
0 990 692
990 0 179
692 179 0
*/
/*
1
6
0 13 0 0 39 27
13 0 7 0 0 28
0 7 0 7 0 2
0 0 7 0 36 14
39 0 0 36 0 34
27 28 2 14 34 0
*/
/*
1
5
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/
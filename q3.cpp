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
    int t,n,c;
    cin>>t;
    FOR(t){
        cin>>n>>c;
        n=n*c;
        cout<<n<<' '<<(n*n/2.0)+(n/2.0)<<endl;
    }
}
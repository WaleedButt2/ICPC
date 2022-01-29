#include <bits/stdc++.h>
using namespace std;

int E[1000001], S[1000001], F[1000001];

void solve(string st)
{
    int mx = 0;
    stack<int> stk;

    for (int i = 0; i < st.size(); i++)
    {
        char ch = st[i];

        if (ch == '(')
        {
            stk.push(i);
        }
        else
        {
            if (stk.empty())
            {
                S[i] = E[i] = -1;
            }
            else
            {
                int idx = stk.top();
                stk.pop();

                S[i] = E[i] = idx;

                if (idx > 0 && st[idx - 1] == ')' && S[idx - 1] >= 0)
                    E[i] = E[idx - 1];

                int l = i - E[i] + 1;
                F[l]++;
                mx = max(mx, l);
            }
        }
    }

    F[0] = 1;

    cout << mx << ' ' << F[mx] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    string st = "";

    // cin >> t;
    for (int a = 1; a <= t; a++)
    {
        memset(E, 0, sizeof(E));
        memset(S, 0, sizeof(S));
        memset(F, 0, sizeof(F));
        // cin >> st;
        string st = "(()(())()((()()())))(((((()()())())())())()())((()(()()()(()())))()()";
        solve(st);
    }

    return 0;
}

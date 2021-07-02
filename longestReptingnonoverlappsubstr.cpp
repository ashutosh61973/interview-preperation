#include "bits/stdc++.h"

using namespace std;

vector<vector<int>> dp(1005, vector<int>(1005, -1));
int f(int i, int j, int e, string &s, int n)
{
    if (j >= n or i >= e)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (s[i] != s[j])
    {
        return dp[i][j] = 0;
    }
    return dp[i][j] = 1 + f(i + 1, j + 1, e, s, n);
}
int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int maxi = 0;
    int ansi = -1, ansj = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int len = f(i, j, j, s, n);
            if (len > maxi)
            {
                maxi = len;
                ansi = i;
                ansj = j;
            }
        }
    }
    if (ansi == -1 or ansj == -1)
    {
        cout << " " << endl;
    }
    for (int i = ansi; i < ansi + maxi; i++)
    {
        cout << s[i];
    }
    cout << endl;
}

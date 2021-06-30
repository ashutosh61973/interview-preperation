#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    string s;
    cin >> s;
    vector<vector<int>> idx(26);
    for (int i = 0; i < s.length(); i++)
    {
        idx[s[i] - 'a'].push_back(i);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int len = v[i].length();
        int curr = -1;
        bool is_subs = true;
        for (int j = 0; j < len; j++)
        {
            auto x = upper_bound(idx[v[i][j] - 'a'].begin(), idx[v[i][j] - 'a'].end(), curr);
            if (x == idx[v[i][j] - 'a'].end())
            {
                is_subs = false;
                break;
            }
            curr = *x;
        }
        if (is_subs)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
}

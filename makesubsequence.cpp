#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/

///////////////////////////////////////////////////////////////////////
const int N = (int)1e3 + 10;
vector<vector<int>> dp(N, vector<int>(N, -1));

int f(int i, int j, int n, int m, vector<int> &a, vector<int> &b)
{
    if (i >= n or j >= m)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (a[i] != b[j])
    {
        return max(f(i + 1, j, n, m, a, b), f(i, j + 1, n, m, a, b));
    }
    return dp[i][j] = 1 + f(i + 1, j + 1, n, m, a, b);
    //time complexity  o(n*m)
    //space complexity o(n*m)
}

void solve(vector<int> &a, vector<int> &b, int n, int m)
{
    int commmon_length;
    //  int commmon_length= f(0, 0, n, m, a, b);
    int curr_row;
    vector<vector<int>> lcs(2, vector<int>(m + 10));
    for (int i = 0; i <= n; i++)
    {
        curr_row = i & 1;
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 or j == 0)
            {
                lcs[curr_row][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                lcs[curr_row][j] = 1 + lcs[1 - curr_row][j - 1];
            }
            else
            {
                lcs[curr_row][j] = max(lcs[1 - curr_row][j], lcs[curr_row][j - 1]);
            }
        }
        commmon_length = lcs[curr_row][m];
    }
    // cout << commmon_length << endl;
    int ans = n - commmon_length;
    cout << ans << endl;
    // space o(2*m)
    // time o(n*m)
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // maximum common subsequence
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    solve(a, b, n, m);
}

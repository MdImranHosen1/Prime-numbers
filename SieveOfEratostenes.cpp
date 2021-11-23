#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef pair<long long, long long> pl;
#define F first
#define S second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mod 1000000007
#define FOR(i, a, b) for (i = a; i <= b; i++)
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

const int Inf = (int)2e9 + 5;
const ll Lnf = (ll)2e18 + 5;
const int N = 5e5 + 5;
const int NN = 1e6 + 5;

int Shive()
{
    ll i, j, n;
    cin >> n;
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (i = 2; i <= n; i++)
    {
        if (is_prime[i] && i * i <= n)
        {
            for (j = i * i; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    for(i=0;i<=n;i++)
    {
        cout<<i<<"::-"<<is_prime[i]<<endl;
    }

}

int main()
{
    int test = 1;
    //cin>>test;
    while (test--)
        Shive();
    return 0;
}

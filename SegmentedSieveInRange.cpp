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

void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit + 1];
    memset(mark, false, sizeof(mark));

    for (int i = 2; i * i <= limit; i++)
    {
        if (mark[i] == false)
        {
            prime.push_back(i);
            for (int j = i; j <= limit; j+=i)
            {
                mark[j] = true;
            }
        }
    }
}
void primeInRange(int low, int high)
{
    int limit = floor(sqrt(high))+1;
    vector<int> prime;
    simpleSieve(limit, prime);

    int n = high - low + 1;

    bool mark[n + 1];
    memset(mark, false, sizeof(mark));

    for (int i = 0; i < prime.size(); i++)
    {
        int lowlimit = floor(low / prime[i]) * prime[i];
        if (lowlimit < low)
            lowlimit += prime[i];
            
        if (lowlimit == prime[i])
            lowlimit += prime[i];

        for (int j = lowlimit; j <= high; j += prime[i])
        {
            if (j != prime[i])
            {
                mark[j - low] = true;
            }
        }
    }
    for (int i = low; i <= high; i++)
    {
        if (!mark[i - low])
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int low, high;
    cin >> low >> high;
    primeInRange(low, high);
}

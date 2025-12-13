#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vec;
typedef vector<vec> vec2;
typedef pair<ll, ll> pll;
typedef vector<pll> vecp;
typedef pair<ll, ll> pll;

vec presum(vec &nums)
{
    vec prefix(nums);
    for (ll i = 1; i < nums.size(); ++i)
        prefix[i] += prefix[i - 1];
    return prefix;
}

void print(vec v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

string toBinary(ll n)
{
    if (n == 0)
        return "0";

    string s = "";
    while (n > 0)
    {
        s += char('0' + (n % 2));
        n /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

void sort_vec(vec &v)
{
    sort(v.begin(), v.end());
}

void sort_reverse(vec &v)
{
    sort(v.begin(), v.end(), greater<ll>());
}

ll sum_total(vec v)
{
    return accumulate(v.begin(), v.end(), 0LL);
}

ll max_in_array(vec v)
{
    return *max_element(v.begin(), v.end());
}

ll min_in_array(vec v)
{
    return *min_element(v.begin(), v.end());
}

ll leftmost_bit_pos(ll x)
{
    return 31 - __builtin_clz(x);
}

vec spf_vector(ll n)
{
    vec spf(n + 1);
    for (ll i = 2; i <= n; i++)
        spf[i] = i;
    for (ll i = 2; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= n; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
    return spf;
}

map<ll, ll> prime_factorisation(ll n)
{
    map<ll, ll> factors;
    vec spf = spf_vector(n);
    while (n != 1)
    {
        factors[spf[n]]++;
        n /= spf[n];
    }
    return factors;
}

ll bit_count(ll x)
{
    return __builtin_popcount(x);
}

ll binaryexpo(ll a, ll b, ll m)
{

    ll ans = 1;
    a %= m;

    while (b > 0)
    {
        if (b & 1)
        {
            ans = (ans * a) % m;
        }
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

class disjointset
{
    vec rank, parent, size;

public:
    disjointset(ll n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (ll i = 0; i <= n; i++)
            parent[i] = i;
    }

    ll findultimateparent(ll node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findultimateparent(parent[node]);
    }

    void unionbyrank(ll u, ll v)
    {
        ll ultimateparentofu = findultimateparent(u);
        ll ultimateparentofv = findultimateparent(v);
        if (ultimateparentofu == ultimateparentofv)
            return;
        if (rank[ultimateparentofu] < rank[ultimateparentofv])
        {
            parent[ultimateparentofu] = ultimateparentofv;
        }
        else if (rank[ultimateparentofu] > rank[ultimateparentofv])
        {
            parent[ultimateparentofv] = ultimateparentofu;
        }
        else
        {
            parent[ultimateparentofv] = ultimateparentofu;
            rank[ultimateparentofu]++;
        }
    }

    void unionbysize(ll u, ll v)
    {
        ll ultimateparentofu = findultimateparent(u);
        ll ultimateparentofv = findultimateparent(v);
        if (ultimateparentofu == ultimateparentofv)
            return;
        if (size[ultimateparentofu] < size[ultimateparentofv])
        {
            parent[ultimateparentofu] = ultimateparentofv;
            size[ultimateparentofv] += size[ultimateparentofu];
        }
        else
        {
            parent[ultimateparentofv] = ultimateparentofu;
            size[ultimateparentofu] += size[ultimateparentofv];
        }
    }

    ll componentsize(ll idx)
    {
        return size[idx];
    }
};

void dfs(vec2 &adj, vector<ll> &vis, ll node, ll &cnt)
{
    vis[node] = 1;
    cnt++;

    for (int next : adj[node])
    {
        if (!vis[next])
        {
            dfs(adj, vis, next, cnt);
        }
    }
}

ll mod = 1000000007;
ll modinv = 500000004;
ll sum(ll st, ll last) {
    ll cnt = (last - st + 1) % mod;
    ll s = (st + last) % mod;
    return (cnt * s % mod) * modinv % mod; 
}

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;
    ll i=1;
    while(i<=n){
        ll cnt = n/i;
        ll last = n/cnt;
        ans = (ans + sum(i,last)*cnt)%mod;
        i = last+1;
    }
    cout<<ans<<endl;
}   
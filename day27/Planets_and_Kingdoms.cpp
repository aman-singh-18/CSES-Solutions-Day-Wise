#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vec;
typedef vector<vec> vec2;
typedef pair<ll, ll> pll;
typedef vector<pll> vecp;

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

bool power_of_2(ll n) { return n > 0 && !(n & (n - 1)); }

ll power_of_2_count(ll n) { return n ? __builtin_ctz(n) : -1; }

bool is_prime(ll n)
{
    if (n < 2)
        return false;
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

bool is_even(ll n)
{
    return !(n & 1);
}

void sort_vec(vec &v)
{
    sort(v.begin(), v.end());
}

void sort_reverse(vec &v)
{
    sort(v.begin(), v.end(), greater<ll>());
}

ll gcd(ll v, ll k) { return k ? gcd(k, v % k) : v; }

ll lcm(ll v, ll k) { return v / gcd(v, k) * k; }

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

bool is_present(const std::vector<ll> &v, ll target)
{
    return std::find(v.begin(), v.end(), target) != v.end();
}

ll count_ccurrences(const vector<ll> &vec, ll target)
{
    ll count = 0;
    for (ll n : vec)
    {
        if (n == target)
        {
            count++;
        }
    }
    return count;
}

ll leftmost_bit_pos(ll x)
{
    return 31 - __builtin_clz(x);
}

ll smallestPrimeDivisor(ll n)
{
    if (n % 2 == 0)
        return 2;
    for (ll i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return i;
    return n;
}

ll modpow(ll a, ll b)
{
    ll mod = 1000000000 + 7;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
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

ll sqrt_binary_search(ll n)
{
    if (n < 2)
        return n;

    ll left = 1, right = n, ans = 0;
    while (left <= right)
    {
        ll mid = left + (right - left) / 2;
        if (mid <= n / mid)
        {
            ans = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}

map<ll, ll> pf(ll n)
{
    map<ll, ll> mp;

    for (ll i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            mp[i]++;
            n /= i;
        }
    }

    if (n > 1)
    {
        mp[n]++;
    }

    return mp;
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

ll countdigits(long long n)
{
    if (n == 0)
        return 1;
    ll count = 0;
    n = abs(n);
    while (n > 0)
    {
        n /= 10;
        count++;
    }
    return count;
}
stack<ll> s;
void dfs(vec &visited, vec2 &adj, ll val,vec & ans)
{
    visited[val] = 1;
    ans.push_back(val);
    for (auto now : adj[val])
    {
        if (!visited[now])
        {
            dfs(visited, adj, now,ans);
        }
    }
    s.push(val);
}

class SGTree
{
    vector<long long> seg, lazy;
    int n;

public:
    SGTree(int n)
    {
        this->n = n;
        seg.resize(4 * n, 0);
    }

    void build(int idx, int low, int high, vector<long long> &a)
    {
        if (low == high)
        {
            seg[idx] = a[low];
            return;
        }

        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, a);
        build(2 * idx + 2, mid + 1, high, a);

        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }

    long long query(int idx, int low, int high, int l, int r)
    {
        if (r < low || high < l)
            return 0;

        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;
        return (query(2 * idx + 1, low, mid, l, r) + query(2 * idx + 2, mid + 1, high, l, r));
    }

    void update(int idx, int low, int high, int pos, long long val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;
        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos, val);
        else
            update(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = (seg[2 * idx + 1] + seg[2 * idx + 2]);
    }
};

struct Fenwick
{
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void update(int i, ll v)
    {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    ll query(int i)
    {
        ll s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

ll solve(ll n)
{
    if ((n & (n - 1)) == 0)
        return log2(n);
    else if (n == 3)
        return 1;
    else if (n == 6)
        return 2;
    else if (n == 12)
        return 3;
    else
    {
        string s = toBinary(n);
        if (s[s.size() - 1] == '0' && s[s.size() - 2] == '0' && s[s.size() - 3] == '0')
            return 1 + solve(n / 2);
        else
        {
            return 1 + solve(((n ^ 3) + 1));
        }
    }
}

ll dig(ll n)
{
    ll cnt = 0;
    while (n != 0)
    {
        cnt++;
        n /= 10;
    }
    return cnt;
}

bool isvalid(ll h1, ll h2, ll m1, ll m2)
{
    if (h1 == -1 || h2 == -1 || m1 == -1 || m2 == -1)
        return false;
    if ((h1 * 10 + h2) <= 23 && (m1 * 10 + m2) <= 59)
        return true;
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vec2 adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vec visited(n + 1, 0);
    vec fal;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
            dfs(visited, adj, i,fal);
    }

    {

     
        vec2 newadj(n + 1);
        for (int i = 1; i <= n; i++)
        {
            for (auto val : adj[i])
            {
                newadj[val].push_back(i);
            }
        }
        vec vis(n+1,0);
        vec2 ans;
        while(!s.empty()){
            vec now;
            ll node = s.top();
            s.pop();
            if(!vis[node]){
                dfs(vis,newadj,node,now);
                ans.push_back(now);
            }
        }

        vec fi(n+1,0);
        fi[0] = 0;
        for(int i=0;i<ans.size();i++){
            for(auto val:ans[i]){
                fi[val] = i+1;
            }
        }
        cout<<max_in_array(fi)<<endl;
        for(int i=1;i<=n;i++) cout<<fi[i]<<" ";
        cout<<endl;
        
    }
}

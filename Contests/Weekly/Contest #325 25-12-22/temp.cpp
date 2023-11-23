#include <bits/stdc++.h>
#include <iomanip>
#define ll long long int
using namespace std;
ll mod = (ll)(1e9 + 7);

void solve()
{

    string s;
    ll k;
    cin >> s >> k;

    ll n = s.size();
    vector<vector<ll>> t(3, vector<ll>(n));
    ll c1 = 0;
    ll c2 = 0;
    ll c3 = 0;
    t[0][0] = n;
    t[1][0] = n;
    t[2][0] = n;
    for (ll j = n - 1; j >= 0; j--)
    {
        if (s[j] == 'a')
        {
            c1++;
            t[0][c1] = j;
        }
        else if (s[j] == 'b')
        {
            c2++;
            t[1][c2] = j;
        }
        else
        {
            c3++;
            t[2][c3] = j;
        }
    }

    if (min(c3, min(c1, c2)) < k)
    {
        cout << -1 << endl;
        return;
    }

    ll ans = n;
    c1 = 0;
    c2 = 0;
    c3 = 0;
    for (ll i = 0; i <= n; i++)
    {

        ll r = min(t[0][max(0ll, k - c1)], t[1][max(0ll, k - c2)]);
        r = min(r, t[2][max(0ll, k - c3)]);
        ans = min(ans, i + n - r);
        if (i == n)
        {
            continue;
        }
        if (s[i] == 'a')
        {
            c1++;
        }
        else if (s[i] == 'b')
        {
            c2++;
        }
        else
        {
            c3++;
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t = 1;
    while (t--)
    {
        solve();
    }
    // solve();
    return 0;
}
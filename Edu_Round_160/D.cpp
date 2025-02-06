//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <stack>
#include <limits>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MA(ll a, ll b) { return (a + b) % PM; }
ll MS(ll a, ll b) { return (a - b + PM) % PM; }
ll MM(ll a, ll b) { return (a * b) % PM; }
ll MP(ll a, ll b) {
    ll res{1};
    do {
        if (b & 1) res = MM(res, a);
    } while (a = MM(a, a), b >>= 1);
    return res;
}
ll MI(ll a) { return MP(a, PM - 2); }
ll MD(ll a, ll b) { return MM(a, MI(b)); }

void solve() {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i{1}; i <= n; ++i) cin >> v[i];

	vector<int> ls(n + 1); {
		stack<pair<int, int>> s{};
		s.emplace(numeric_limits<int>::min(), 0);
		for (int i{1}; i <= n; ++i) {
			while (s.top().fi >= v[i]) s.pop();
			ls[i] = s.top().se;
			s.emplace(v[i], i);
		}
	}

	vector<ll> dp(n + 1), ps(n + 1), ch(n + 1);
	for (int i{1}; i <= n; ++i) {
		if (ls[i]) dp[i] = MA(MS(ps[i - 1], ps[ls[i]]), ch[ls[i]]);
		else dp[i] = MA(ps[i - 1], 1);
		ps[i] = MA(ps[i - 1], dp[i]);
		ch[i] = MA(ch[ls[i]], dp[i]);
	}

	ll ans{};
	for (int i{n}, mn{numeric_limits<int>::max()}; i >= 1; --i) {
		if (v[i] < mn) mn = v[i], ans = MA(ans, dp[i]);
	}

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

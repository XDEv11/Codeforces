//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;
const ll PM{998244353};
ll MC(ll a) { return (a % PM + PM) % PM; }
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

namespace {
	vector<vector<int>> tl{}, tr{};
	vector<int> t{};
	void dfs(int u) {
		for (auto& v : tl[u]) dfs(v);
		t.push_back(u);
		for (auto& v : tr[u]) dfs(v);
	}
	static bool solve() {
		int n, m;
		cin >> n >> m;
		vector<int> a(m), b(m);
		for (auto& x : a) cin >> x, --x;
		for (auto& x : b) cin >> x, --x;
		if (!cin) return false;

		tl.assign(n, {}), tr.assign(n, {});
		vector<bool> c(n);
		for (int i{0}; i < m; ++i) {
			if (a[i] > b[i]) tr[a[i]].push_back(b[i]);
			else tl[b[i]].push_back(a[i]);
			c[a[i]] = c[b[i]] = true;
		}
		for (auto& x : tr) reverse(x.begin(), x.end());
		t.clear(), dfs(n - 1);

		ll ans{1};
		vector<int> v(n);
		for (int i{-1}; i < int(t.size()); ++i) {
			int x{i >= 0 ? t[i] : -1}, y{i + 1 < int(t.size()) ? t[i + 1] : -1};
			v[max(x, y)] += 1;
		}
		for (int i{n - 2}; i >= 0; --i) v[i] += v[i + 1];
		for (int i{n - 1}, d{}; i >= 0; --i) {
			if (c[i]) continue;
			ans = MM(ans, v[i] + d), ++d;
		}

		cout << ans << '\n';
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

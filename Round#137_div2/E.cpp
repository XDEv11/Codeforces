//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

using ll = long long;
const ll PM{1000000007};
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
	auto id{[](char x) {
		if (clamp(x, 'a', 'z') == x) return x - 'a';
		else return 26 + x - 'A';
	}};
	auto mm{[](const vector<vector<ll>>& m1, const vector<vector<ll>>& m2) {
		int s1{m1.size()}, s2{m2.size()}, s3{m2[0].size()};
		vector<vector<ll>> m3(s1, vector<ll>(s3));
		for (int i{0}; i < s1; ++i)
			for (int j{0}; j < s3; ++j)
				for (int k{0}; k < s2; ++k)
					m3[i][j] = MA(m3[i][j], MM(m1[i][k], m2[k][j]));
		return m3;
	}};

	ll n;
	int m, c;
	cin >> n >> m >> c;
	vector<array<char, 2>> f(c);
	for (auto& [x, y] : f) cin >> x >> y;

	vector<vector<ll>> t(m, vector<ll>(m, 1));
	for (auto& [x, y] : f) t[id(x)][id(y)] = 0;

	vector<vector<ll>> r(m, vector<ll>(m));
	for (int i{0}; i < m; ++i) r[i][i] = 1;
	n -= 1;
	while (n) {
		if (n & 1) r = mm(r, t);
		t = mm(t, t), n /= 2;
	}

	ll ans{};
	for (auto& v : mm(vector<vector<ll>>(1, vector<ll>(m, 1)), r))
		for (auto& x : v) ans = MA(ans, x);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();
}

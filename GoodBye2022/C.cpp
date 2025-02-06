//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

using ll = long long;

const vector<ll> sp{[](){
	const ll maxn{100 * 99 / 2};
	vector<ll> p{};
	vector<bool> ck(maxn + 1, true);
	for (ll i{2}; i <= maxn; ++i) {
		if (!ck[i]) continue;
		p.push_back(i);
		for (ll j{i * i}; j <= maxn; j += i) ck[j] = false;
	}
	return p;
}()};

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	sort(v.begin(), v.end());

	vector<vector<ll>> c(sp.size());
	for (int i{0}; i < n; ++i)
		for (int j{i + 1}; j < n; ++j) {
			if (v[j] == v[i]) return cout << "NO\n", []{}();
			for (int k{0}; k < sp.size(); ++k) {
				if ((v[j] - v[i]) % sp[k]) continue;
				c[k].push_back(v[i] % sp[k]);
			}
		}

	for (int k{0}; k < sp.size(); ++k) {
		sort(c[k].begin(), c[k].end());
		if (distance(c[k].begin(), unique(c[k].begin(), c[k].end())) == sp[k]) return cout << "NO\n", []{}();
	}
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t{1};
	cin >> t;
	while (t--) solve();
}

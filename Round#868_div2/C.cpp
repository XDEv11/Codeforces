//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	map<ll, int> mp;
	for (auto& x : v) {
		for (ll f{2}; f * f <= x; ++f) {
			while (x % f == 0) x /= f, ++mp[f];
		}
		if (x != 1) ++mp[x];
	}

	vector<ll> ans{}, tmp{};
	for (auto& [k, v] : mp) {
		for (int i{0}; i + 1 < v; i += 2) ans.push_back(k * k);
		if (v & 1) tmp.push_back(k);
	}
	for (int i{0}; i < tmp.size(); i += 3) {
		if (i + 2 < tmp.size()) ans.push_back(tmp[i] * tmp[i + 1] * tmp[i + 2]);
		else {
			if (ans.empty()) return cout << "0\n", []{}();
			ans.back() *= tmp[i] * (i + 1 < tmp.size() ? tmp[i + 1] : 1);
		}
	}

	cout << ans.size() << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

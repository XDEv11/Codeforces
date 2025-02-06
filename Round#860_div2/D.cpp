//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void solve() {
	using ll = long long;

	int n;
	cin >> n;
	vector<ll> v(n);
	for (auto& x : v) cin >> x;

	vector<ll> pos{}, neg{};
	for (auto& x : v) {
		if (x >= 0) pos.push_back(x);
		else neg.push_back(x);
	}
	sort(pos.rbegin(), pos.rend());
	sort(neg.begin(), neg.end());

	vector<ll> ans(n);
	ll s{0}, d{(pos.empty() ? 0 : pos[0]) - (neg.empty() ? 0 : neg[0])};
	for (int i{0}; i < n; ++i) {
		if (neg.empty() || (!pos.empty() && abs(s + pos.back()) <= abs(s + neg.back())))
			s += (ans[i] = pos.back()), pos.pop_back();
		else s += (ans[i] = neg.back()), neg.pop_back();
		if (abs(s) >= d) return cout << "No\n", []{}();
	}
	cout << "Yes\n";
	for (auto& x : ans) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

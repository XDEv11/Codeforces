//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

void solve() {
	using ll = long long;

	int n; ll c;
	cin >> n >> c;
	vector<ll> a(n);
	for (auto& x : a) cin >> x;

	vector<pair<ll, ll>> t{};
	for (int i{1}; i < n; ++i) t.emplace_back((i + 1) * c - a[i], a[i]);
	sort(t.begin(), t.end());

	ll s{a[0]};
	for (int i{0}; i < n - 1; ++i) {
		if (s >= t[i].fi) s += t[i].se;
		else return cout << "No\n", []{}();
	}
	cout << "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

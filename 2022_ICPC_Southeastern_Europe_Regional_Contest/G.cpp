//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

bool solve() {
	using ll = long long;

	int n;
	if (!(cin >> n)) return false;
	vector<ll> v(n), r(n);
	for (auto& x : v) cin >> x;
	for (auto& x : r) cin >> x;

	sort(r.begin(), r.end());
	vector<ll> a(n);
	for (int i{1}; i < n; ++i) a[i] = v[i] - v[i - 1] - a[i - 1];

	vector<ll> ans(n);

	ll mn{numeric_limits<ll>::max()}, mni;
	for (int i{1}; i < n; i += 2) {
		if (a[i] < mn) mn = a[i], mni = i;
	}
	ll x{a[mni] - r[0]}; // a[mni] - x = r[0]
	for (int i{0}; i < n; i += 2) ans[i] = x + a[i];
	for (int i{1}; i < n; i += 2) ans[i] = a[i] - x;
	auto tmp{ans};
	sort(tmp.begin(), tmp.end());
	if (tmp == r) {
		for (auto& e : ans) cout << e << ' ';
		cout << '\n';
		return true;
	}

	mn = numeric_limits<ll>::max();
	for (int i{0}; i < n; i += 2) {
		if (a[i] < mn) mn = a[i], mni = i;
	}
	x = r[0] - a[mni]; // x + a[mni] = r[0]
	for (int i{0}; i < n; i += 2) ans[i] = x + a[i];
	for (int i{1}; i < n; i += 2) ans[i] = a[i] - x;
	for (auto& e : ans) cout << e << ' ';
	cout << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while (solve()) ;
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

void solve() {
	array<int, 3> c; array<int, 5> a;
	for (auto& x : c) cin >> x;
	for (auto& x : a) cin >> x;

	if (a[0] <= c[0]) {
		auto t{min(a[3], c[0] - a[0])};
		a[0] += t, a[3] -= t;
	} else return cout << "NO\n", []{}();
	if (a[1] <= c[1]) {
		auto t{min(a[4], c[1] - a[1])};
		a[1] += t, a[4] -= t;
	} else return cout << "NO\n", []{}();
	a[2] += a[3] + a[4];

	cout << (a[0] <= c[0] && a[1] <= c[1] && a[2] <= c[2] ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

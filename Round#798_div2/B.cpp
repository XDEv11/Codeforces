//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n == 1) return cout << "-1\n", []{}();

	vector<int> p(n); iota(p.begin(), p.end(), 1);
	for (int i{0}; i + 1 < n; ++i)
		if (p[i] == v[i]) swap(p[i], p[i + 1]);
	if (p[n - 1] == v[n - 1]) swap(p[n - 1], p[n - 2]);

	for (auto& x : p) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

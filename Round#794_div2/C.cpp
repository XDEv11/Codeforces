//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	if (n & 1) return cout << "NO\n", []{}();

	vector<int> c(n);
	sort(v.begin(), v.end());
	for (int i{0}; i < n / 2; ++i) c[2 * i] = v[i];
	for (int i{n / 2}; i < n; ++i) c[2 * (i - n / 2) + 1] = v[i];

	for (int i{0}; i < n; ++i) {
		int ip{(i - 1 + n) % n}, in{(i + 1) % n};
		if (i & 1) {
			if (!(c[i] > c[ip] && c[i] > c[in])) return cout << "NO\n", []{}();
		} else {
			if (!(c[i] < c[ip] && c[i] < c[in])) return cout << "NO\n", []{}();
		}
	}

	cout << "YES\n";
	for (auto& x : c) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

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

	for (int i{0}; i < n; ++i) {
		int j{(i + 1) % n};
		if (v[i] + 1 < v[j]) return cout << "NO\n", []{}();
	}
	sort(v.begin(), v.end());
	if (v[0] != 1) return cout << "NO\n", []{}();
	if (n >= 2 && v[1] == 1) return cout << "NO\n", []{}();
	for (int i{0}; i + 1 < n; ++i)
		if (v[i] + 1 < v[i + 1]) return cout << "NO\n", []{}();

	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> v(2 * n);
	for (auto& e : v) cin >> e;

	sort(v.begin(), v.end());
	for (int i{0}; i < n; ++i)
		if (v[i] + x > v[n + i]) return cout << "NO\n", []{}();
	cout << "YES\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	sort(v.rbegin(), v.rend());
	for (int i{0}; i < n; ++i) {
		if (i - 1 >= 0 && v[i - 1] <= i) continue;
		if (v[i] > i) continue;
		return cout << i << '\n', []{}();
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

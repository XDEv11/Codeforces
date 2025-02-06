#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
	int n, l, r, k;
	cin >> n >> l >> r >> k;
	vector<int> v{};
	for (int i{0}; i < n; ++i) {
		int x;
		cin >> x;
		if (l <= x && x <= r) v.push_back(x);
	}
	sort(v.begin(), v.end());

	int i{0};
	while (i < v.size() && k >= v[i]) k -= v[i++];

	cout << i << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

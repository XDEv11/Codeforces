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

	vector<int> b{};
	for (int i{0}; i + 1 < n; ++i) {
		if (v[i] < v[i + 1]) continue;
		b.push_back(i);
	}

	vector<int> dp(b.size());
	for (auto& x : b) cout << x << ' ';
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

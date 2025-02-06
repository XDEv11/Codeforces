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

	int l{0}, r{1000000000};
	for (int i{1}; i < n; ++i) {
		if (v[i - 1] < v[i]) {
			r = min(r, v[i - 1] + (v[i] - v[i - 1]) / 2);
		} else if (v[i - 1] > v[i]) {
			l = max(l, v[i - 1] - (v[i - 1] - v[i]) / 2);
		}
	}

	cout << (l > r ? -1 : l) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

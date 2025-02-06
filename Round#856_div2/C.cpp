//#pragma GCC optimize ("O3")

#include <ios>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	for (int i{0}; i < n; ++i) {
		int l{-1}, r{i + 1};
		while (r - l > 1) {
			int m{(l + r) / 2};
			if (v[m] >= i + 1 - m) r = m;
			else l = m;
		}
		cout << (i + 1 - r) << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

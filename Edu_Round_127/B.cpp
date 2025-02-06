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

	for (int k{-1}; k <= 1; ++k) {
		bool f{true};
		for (int i{1}; i < n; ++i) {
			auto exp{v[0] + k + i};
			if (!(v[i] - 1 == exp || v[i] == exp || v[i] + 1 == exp)) {
				f = false;
				break;
			}
		}
		if (f) return cout << "YES\n", []{}();
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

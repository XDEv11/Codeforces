//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n), a(n - 1);
		for (auto& x : v) cin >> x;
		for (auto& x : a) cin >> x;

		int c{count(v.begin(), v.end(), '0')};
		for (int i{0}; i < n - 1; ++i) {
			if (c == 0 || c == n - i) return cout << "NO\n", []{}();
			c -= 1;
			c += (a[i] == '0');
		}
		cout << "YES\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

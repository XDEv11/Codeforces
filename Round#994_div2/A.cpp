//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int i{0}, j{n - 1};
		while (i < n && v[i] == 0) ++i;
		while (j >= 0 && v[j] == 0) --j;


		if (i > j) cout << "0\n";
		else {
			int c{count(v.begin() + i, v.begin() + j + 1, 0)};
			if (c == 0) cout << "1\n";
			else cout << "2\n";
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

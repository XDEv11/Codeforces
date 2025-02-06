//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace {
	void solve() {
		int n, x, y;
		cin >> n >> x >> y;
		vector<char> v(n);
		for (auto& e : v) cin >> e;

		x = abs(x), y = abs(y);
		for (auto& e : v) {
			if (e == '4') {
				if (x > y) --x;
				else if (y) --y;
			} else {
				if (x) --x;
				if (y) --y;
			}
		}

		cout << (x || y ? "NO\n" : "YES\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

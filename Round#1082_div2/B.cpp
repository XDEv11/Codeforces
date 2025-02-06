//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int s{n & 1}; // 0: a..b, 1: a..a, 2: b..b, 3: (1 | 2)
		for (auto& x : v) {
			if (x == 'a') {
				switch (s) {
					break; case 0: s = 2;
					break; case 1: s = 0;
					break; case 2: return void(cout <<"NO\n");
					break; case 3: s = 0;
				}
			} else if (x == 'b') {
				switch (s) {
					break; case 0: s = 1;
					break; case 1: return void(cout <<"NO\n");
					break; case 2: s = 0;
					break; case 3: s = 0;
				}
			} else {
				switch (s) {
					case 0: s = 3; break;
					case 1:
					case 2:
					case 3: s = 0; break;
				}
			}
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

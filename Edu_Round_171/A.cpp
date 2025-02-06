//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int x, y, k;
		cin >> x >> y >> k;

		int t{min(x, y)};

		cout << "0 0 " << t << ' ' << t << '\n';
		cout << t <<  " 0 0 " << t << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

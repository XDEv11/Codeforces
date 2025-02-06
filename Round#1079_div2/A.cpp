//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	int d(int x) {
		int r{};
		while (x) r += x % 10, x /= 10;
		return r;
	}
	void solve() {
		int n;
		cin >> n;

		int ans{};
		for (int i{n}; ; ++i) {
			int t{i - d(i)};
			if (t == n) ++ans;
			else if (t > n) break;
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

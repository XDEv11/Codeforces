//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		array<int, 26> cnt{};
		for (auto& x : v) ++cnt[x - 'a'];

		int mx{max_element(cnt.begin(), cnt.end()) - cnt.begin()};
		cnt[mx] = n + 1;
		for (auto& x : cnt) {
			if (x == 0) x = n + 1;
		}
		int mn{min_element(cnt.begin(), cnt.end()) - cnt.begin()};

		for (auto& x : v) {
			if (x == 'a' + mn) {
				x = 'a' + mx;
				break;
			}
		}

		for (auto& x : v) cout << x;
		cout << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int ca{count(v.begin(), v.end(), 'A')};

		while (m--) {
			int x;
			cin >> x;
			if (ca == v.size()) {
				cout << x << '\n';
				continue;
			}

			int ans{};
			for (int i{0}; x; i = (i + 1) % n) {
				x = (v[i] == 'A' ? x - 1 : (x / 2));
				++ans;
			}
			cout << ans << '\n';
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

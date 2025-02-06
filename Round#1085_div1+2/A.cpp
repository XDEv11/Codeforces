//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int mx{};
		for (int i{0}; i < n; ++i) {
			if (i && v[i - 1] == '1' && i + 1 < n && v[i + 1] == '1') v[i] = '1', ++mx;
			else if (v[i] == '1') ++mx;
		}

		int mn{};
		for (int i{0}; i < n; ++i) {
			if (i && v[i - 1] == '1' && i + 1 < n && v[i + 1] == '1') v[i] = '0';
			else if (v[i] == '1') ++mn;
		}

		cout << mn << ' ' << mx << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

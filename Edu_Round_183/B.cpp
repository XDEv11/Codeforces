//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<char> v(m);
		for (auto& x : v) cin >> x;

		array<int, 3> c{};
		for (auto& x : v) ++c[x - '0'];

		for (int i{0}; i < n; ++i) {
			if (m == n || i + 1 <= c[0] || n - i <= c[1]) cout << '-';
			else if (i + 1 <= c[0] + c[2] || n - i <= c[1] + c[2]) cout << '?';
			else cout << '+';
		}
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

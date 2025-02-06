//#pragma GCC optimize ("O3")

#include <iostream>
#include <array>

using namespace std;

namespace {
	void solve() {
		array<int, 3> a;
		for (auto& x : a) cin >> x;

		for (int k{0}; k < 30; ++k) {
			int c{};
			for (int i{0}; i < 3; ++i) c += (a[i] >> k) & 1;
			if (c == 2) return cout << "NO\n", []{}();
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

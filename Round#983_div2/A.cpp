//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(2 * n);
		for (auto& x : v) cin >> x;

		int c{};
		for (auto& x : v) c += x;

		cout << (c & 1) << ' ' << (c <= n ? c : (2 * n - c)) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

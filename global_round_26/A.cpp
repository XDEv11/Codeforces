//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;
		if (v[0] == v[n - 1]) return cout << "NO\n", []{}();

		cout << "YES\n";
		cout << "BR";
		for (int i{2}; i < n; ++i) cout << "B";
		cout << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<char> s(n), t(n);
		for (auto& x : s) cin >> x;
		for (auto& x : t) cin >> x;

		for (int i{0}; i < n; ++i) {
			if (s[i] == '1') break;
			if (t[i] == '1') return cout << "NO\n", []{}();
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

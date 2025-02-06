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

		vector<int> cnt(n + 1);
		for (auto& x : v) ++cnt[x];

		for (int i{n}; i >= 1; --i) {
			if (cnt[i] & 1) return cout << "YES\n", []{}();
		}
		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

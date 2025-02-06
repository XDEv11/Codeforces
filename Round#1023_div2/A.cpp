//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		auto it{max_element(v.begin(), v.end())};
		if (count(v.begin(), v.end(), *it) != n) {
			cout << "Yes\n";
			for (int i{0}; i < n; ++i) cout << (i == distance(v.begin(), it) ? "2 " : "1 ");
			cout << '\n';
		} else cout << "No\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

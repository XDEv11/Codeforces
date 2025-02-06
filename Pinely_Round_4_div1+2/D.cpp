//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		if (n < 6) {
			vector<int> ans{};
			ans.push_back(1), --n;
			if (n) ans.push_back(2), --n;
			if (n) ans.push_back(2), --n;
			if (n) ans.push_back(3), --n;
			if (n) ans.push_back(3), --n;

			cout << *max_element(ans.begin(), ans.end()) << '\n';
			for (auto& x : ans) cout << x << ' ';
			cout << '\n';
		} else {
			cout << "4\n";
			for (int i{1}; i <= n; ++i) cout << (i % 4) + 1 << " \n"[i == n];
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

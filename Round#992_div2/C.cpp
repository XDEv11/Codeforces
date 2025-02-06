//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n; ll k;
		cin >> n >> k, --k;

		int i{n - 1}; ll t{1};
		while (i > 0 && !(k < t)) --i, t *= 2;
		if (!(k < t)) return cout << "-1\n", []{}();

		vector<int> ans1{}, ans2{};
		for (int j{0}; j < i; ++j) ans1.push_back(j);
		for (; i < n; ++i) {
			if (k < t / 2) ans1.push_back(i);
			else k -= t / 2, ans2.push_back(i);
			t /= 2;
		}
		reverse(ans2.begin(), ans2.end());

		for (auto& x : ans1) cout << (x + 1) << ' ';
		for (auto& x : ans2) cout << (x + 1) << ' ';
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

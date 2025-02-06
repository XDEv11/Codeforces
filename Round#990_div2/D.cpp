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

		vector<int> ans1{}, ans2{};
		for (int i{0}; i < n; ++i) {
			while (!ans1.empty() && v[i] < ans1.back()) ans2.push_back(ans1.back() + 1), ans1.pop_back();
			ans1.push_back(v[i]);
		}
		if (!ans2.empty()) {
			int mn{*min_element(ans2.begin(), ans2.end())};
			while (!ans1.empty() && mn < ans1.back()) ans2.push_back(ans1.back() + 1), ans1.pop_back();
			sort(ans2.begin(), ans2.end());
		}

		for (auto& x : ans1) cout << x << ' ';
		for (auto& x : ans2) cout << x << ' ';
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

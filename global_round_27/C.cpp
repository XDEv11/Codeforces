//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

namespace {
	int pw2(int x) {
		for (int b{30}; b >= 0; --b) {
			if (x & (1 << b)) return (1 << b);
		}
		return 0;
	}
	void solve() {
		int n;
		cin >> n;
		if (n == 5) return cout << "5\n2 1 3 4 5\n", []{}();

		vector<int> ans{};
		int t{n};
		if (t & 1) ans.push_back(t);
		t = pw2(t);
		while (t >= 8) {
			ans.push_back(t);
			ans.push_back(t - 1);
			t /= 2;
		}
		ans.push_back(6), ans.push_back(5), ans.push_back(4), ans.push_back(3), ans.push_back(1), ans.push_back(2);

		set<int> st{};
		for (auto& x : ans) st.insert(x);
		for (int i{1}; i <= n; ++i) {
			if (!st.count(i)) ans.push_back(i);
		}

		reverse(ans.begin(), ans.end());

		cout << (n & 1 ? n : (2 * pw2(n) - 1)) << '\n';
		for (auto& x : ans) cout << x << ' ';
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

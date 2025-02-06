//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>

using namespace std;

namespace {
	void solve() {
		int n, m;
		cin >> n >> m;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		multiset<int> st{};
		for (auto& x : v) st.insert(x);

		int ans{};
		for (int i{0}; i < n; ++i) {
			while (!st.empty() && *st.rbegin() > m) st.erase(prev(st.end()));
			if (!st.empty()) st.erase(prev(st.end())), ++ans;
			m /= 2;
		}

		cout << (n - ans) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <limits>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int ans{};
		bool f{false}; int k;
		for (int i{n - 1}; i >= 0; --i) {
			if (v[i]) ++ans;
			else f = true, k = i;
		}

		if (f) {
			vector<int> mn(n + 1, numeric_limits<int>::max());
			for (int i{0}; i < n; ++i) mn[i + 1] = (v[i] ? min(mn[i], v[i]) : mn[i]);

			set<int> st{};
			for (int i{n - 1}, x{0}; i >= 0; --i) {
				if (v[i]) {
					if (mn[i + 1] < x) f = false;
					st.insert(v[i]);
				} else if (i == k) st.insert(0);
				while (st.count(x)) ++x;
			}
		}

		cout << (ans + f) << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

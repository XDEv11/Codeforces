//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <set>
#include <iterator>
#include <array>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<array<int, 3>> v(n);
		for (int i{0}; i < n; ++i) cin >> v[i][0] >> v[i][1], v[i][2] = i;

		vector<int> ans(n);
		sort(v.begin(), v.end(),
			[](array<int, 3> a, array<int, 3> b) {
				if (a[0] != b[0]) return a[0] < b[0];
				else return a[1] > b[1];
			}
		);
		set<int> st{};
		for (int i{0}; i < n; ++i) {
			auto it{st.lower_bound(v[i][1])};
			if (!(i + 1 < n && v[i][0] == v[i + 1][0] && v[i][1] == v[i + 1][1]) &&
				it != st.end()) ans[v[i][2]] += *it - v[i][1];
			st.insert(v[i][1]);
		}

		vector<int> ans1(n);
		sort(v.begin(), v.end(),
			[](array<int, 3> a, array<int, 3> b) {
				if (a[1] != b[1]) return a[1] > b[1];
				else return a[0] < b[0];
			}
		);
		st = set<int>{};
		for (int i{0}; i < n; ++i) {
			auto it{st.upper_bound(v[i][0])};
			if (!(i + 1 < n && v[i][0] == v[i + 1][0] && v[i][1] == v[i + 1][1]) &&
				it != st.begin()) ans[v[i][2]] += v[i][0] - *prev(it);
			st.insert(v[i][0]);
		}

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

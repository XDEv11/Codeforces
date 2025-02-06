//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> c(n);
		vector<int> t{};
		for (int i{n - 1}; i >= 0; --i) {
			if (t.empty() || v[i] > t.back()) t.push_back(v[i]);
			else *lower_bound(t.begin(), t.end(), v[i]) = v[i];
			c[i] = t.size();
		}

		long long ans{}, s{accumulate(c.begin(), c.end(), 0ll)};
		for (int i{n - 1}; i >= 0; --i) {
			ans += s;
			if (i) {
				s -= 1;
				if (v[i - 1] > v[i]) s -= i;
			}
		}

		cout << ans << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

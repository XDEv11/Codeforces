//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <deque>
#include <ranges>

using namespace std;

namespace {
	const int PM{998244353};
	// longest prefix which is also suffix
	template<ranges::range T>
	vector<int> prefix_func(const T& v) {
		vector<int> len(v.size());
		for (int i{1}; i < v.size(); ++i) {
			int j{len[i - 1]};
			while (j > 0 && v[i] != v[j]) j = len[j - 1];
			len[i] = j + (v[i] == v[j]);
		}
		return len;
	}
	void solve() {
		int n;
		cin >> n;
		deque<int> v(n);
		for (auto& x : v) cin >> x;

		vector<int> dp(n + 1);
		dp[0] = 1;
		auto MAA{[](int& a, int b) {
			a += b;
			if (a >= PM) a -= PM;
			return a;
		}};
		for (int i{0}; i < n; ++i) {
			MAA(dp[i + 1], dp[i]);
			auto p{prefix_func(v)};
			for (int j{i + 1}; j < n; ++j) {
				if (p[j - i]) continue;
				MAA(dp[j + 1], dp[i]);
			}
			v.pop_front();
		}

		cout << dp[n] << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

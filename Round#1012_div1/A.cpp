//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	const int maxn{100000};
	vector<int> pt{[] {
		vector<int> v(maxn + 1);
		for (ll i{2}; i <= maxn; ++i) {
			if (v[i]) continue;
			for (ll j{i * i}; j <= maxn; j += i) v[j] = 1;
		}
		return v;
	}()};
	void solve() {
		int n;
		cin >> n;

		if (n == 2) return cout << "2 1\n", []{}();

		int p{(n + 1) / 2};
		while (pt[p]) --p;

		vector<int> ans{};
		ans.push_back(p);
		for (int i{1}; p - i >= 1; ++i) ans.push_back(p - i), ans.push_back(p + i);
		for (int i{2 * p}; i <= n; ++i) ans.push_back(i);

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

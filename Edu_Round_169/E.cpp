//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

namespace {
	using ll = long long;
	const int maxn{10000000};
	vector<int> nim{[] {
		vector<int> t(maxn + 1, 0);
		for (ll i{3}; i <= maxn; i += 2) {
			if (t[i]) continue;
			for (ll j{i * i}; j <= maxn; j += 2 * i) {
				if (t[j]) continue;
				t[j] = i;
			}
		}
		vector<int> v(maxn + 1);
		v[1] = 1;
		for (int i{3}, c{1}; i <= maxn; i += 2) v[i] = (t[i] ? v[t[i]] : ++c);
		return v;
	}()};
	void solve() {
		int n;
		cin >> n;
		vector<int> v(n);
		for (auto& x : v) cin >> x;

		int y{};
		for (auto& x : v) y ^= nim[x];

		cout << (y ? "Alice\n" : "Bob\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

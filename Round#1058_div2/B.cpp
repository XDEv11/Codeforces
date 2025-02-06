//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>

using namespace std;

namespace {
	using ll = long long;
	void solve() {
		int n;
		cin >> n;
		vector<ll> b(n);
		for (auto& x : b) cin >> x;

		vector<int> a(n);
		int t{1};
		a[0] = t++;
		for (int i{1}; i < n; ++i) {
			auto d{b[i] - b[i - 1]};
			if (d == i + 1) a[i] = t++;
			else a[i] = a[i - d];
		}

		for (auto& x : a) cout << x << ' ';
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

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (auto& x : a) cin >> x;
		for (auto& x : b) cin >> x;

		int ra{}, rb{}, cp{}, cn{};
		for (int i{0}; i < n; ++i) {
			if (a[i] == 1 && b[i] == 1) ++cp;
			else if (a[i] == -1 && b[i] == -1) ++cn;
			else if (a[i] == 1) ++ra;
			else if (b[i] == 1) ++rb;
		}

		if (ra < rb) swap(ra, rb);
		int t{min(ra - rb, cp)};
		rb += t, cp -= t;
		t = min(ra - rb, cn);
		ra -= t, cn -= t;
		if (cp >= cn) rb += (cp - cn) / 2;
		else rb -= (cn - cp + 1) / 2;

		cout << rb << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

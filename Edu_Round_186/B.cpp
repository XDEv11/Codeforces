//#pragma GCC optimize ("O3")

#include <iostream>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);

		int k{0}, c0{}, c1{};
		do {
			(k & 1 ? c0 : c1) += 1 << k;
			++k;
		} while (max(c0, c1) <= a && min(c0, c1) <= b);

		cout << k - 1 << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

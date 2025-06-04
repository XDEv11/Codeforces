//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		for (int i{1}; i <= n; ++i) cout << i << " \n"[i == n];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

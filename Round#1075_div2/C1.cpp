//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		cout << (n - (n & 1)) << ' ';
		for (int i{2}; i <= n - 1; ++i) cout << (i ^ 1) << ' ';
		cout << "1\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		cout << "1 1 2 ";
		for (int i{5}; i < n; ++i) cout << i << ' ';
		cout << "1 2\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

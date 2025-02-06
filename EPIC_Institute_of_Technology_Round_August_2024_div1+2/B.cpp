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

		if (a[0] == b[n - 1]) reverse(b.begin(), b.end());

		cout << (a == b ? "Bob\n" : "Alice\n");
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

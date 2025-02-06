//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

static void solve() {
	auto ask{[](int l, int x) {
		cout << "? " << l << " " << x << endl;
		int r;
		cin >> r;
		return r;
	}};
	auto ans{[](int m) {
		cout << "! " << m << endl;
		int r;
		cin >> r;
		assert(r == 1);
	}};

	int n, k;
	cin >> n >> k;


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

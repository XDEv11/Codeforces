//#pragma GCC optimize ("O3")

#include <iostream>

using namespace std;

namespace {
	void solve() {
		int n, w, d;
		cin >> n >> w >> d;

		int t{1 + d / w}, a{(n + t - 1) / t};

		cout << a << '\n';
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

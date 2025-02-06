//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <array>
#include <utility>
#define fi first
#define se second
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n;
		cin >> n;

		if (n == 1 || n == 3) return cout << "-1\n", []{}();

		if (n & 1) {
			for (int i{0}; i < n - 5; i += 2) cout << "33";
			cout << "36366\n";
		} else {
			for (int i{0}; i < n - 2; i += 2) cout << "33";
			cout << "66\n";
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

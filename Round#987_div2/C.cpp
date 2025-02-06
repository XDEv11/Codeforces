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

		if (n & 1) {
			if (n >= 27) {
				int c{3};
				cout << "1 ";
				for (int i{0}; i < 8; i += 2) cout << c << ' ' << c << ' ', ++c;
				cout << "1 2 ";
				for (int i{0}; i < 14; i += 2) cout << c << ' ' << c << ' ', ++c;
				cout << "1 2 ";
				for (int i{0}; i < n - 27; i += 2) cout << c << ' ' << c << ' ', ++c;
				cout << '\n';
			} else cout << "-1\n";
		} else {
			int c{1};
			for (int i{0}; i < n; i += 2) cout << c << ' ' << c << ' ', ++c;
			cout << '\n';
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

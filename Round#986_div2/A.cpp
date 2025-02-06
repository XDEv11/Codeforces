//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace {
	void solve() {
		int n, a, b;
		cin >> n >> a >> b;
		vector<char> v(n);
		for (auto& x : v) cin >> x;

		int X{}, Y{};
		for (auto& e : v) {
			switch (e) {
				break; case 'N': ++Y;
				break; case 'E': ++X;
				break; case 'S': --Y;
				break; case 'W': --X;
			}
		}
		int x{}, y{};
		for (auto& e : v) {
			int dx{a - x}, dy{b - y};
			if (X == 0 && Y == 0) {
				if (dx == 0 && dy == 0) return cout << "YES\n", []{}();
			} else if (X == 0) {
				if (dx == 0 && dy % Y == 0 && dy / Y >= 0) return cout << "YES\n", []{}();
			} else if (Y == 0) {
				if (dx % X == 0 && dx / X >= 0 && dy == 0) return cout << "YES\n", []{}();
			} else {
				if (dx % X == 0 && dx / X >= 0 && dy % Y == 0 && dx / X == dy / Y) return cout << "YES\n", []{}();
			}
			switch (e) {
				break; case 'N': ++y;
				break; case 'E': ++x;
				break; case 'S': --y;
				break; case 'W': --x;
			}
		}

		cout << "NO\n";
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

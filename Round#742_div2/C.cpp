#include <iostream>
#include <string>

using namespace std;

namespace C {
	string n{};
	long long ans;
	void func(int i = 0, long long cnt = 1, bool c1 = false, bool c2 = false, bool nz1 = false, bool nz2 = false) {
		if (i == n.size()) {
			if (!c1 && !c2 && nz1 && nz2) ans += cnt;
			return ;
		}

		int d{n[i] - '0'};
		if (c1) {
			if (d < 9) func(i + 1, cnt * (9 - d), c2, false, true, true);
			func(i + 1, cnt * (9 - d + 1), c2, true, true, true);
		} else {
			if (d) {
				if (d > 1) func(i + 1, cnt * (d - 1), c2, false, true, true);
				func(i + 1, cnt, c2, false, nz1, true); // 0 d
				func(i + 1, cnt, c2, false, true, nz2); // d 0
			} else {
				func(i + 1, cnt, c2, false, nz1, nz2); // 0 0
			}

			if (d >= 2) {
				if (d > 2) func(i + 1, cnt * (d - 2), c2, true, true, true);
				func(i + 1, cnt, c2, true, nz1, true); // 0 d-1
				func(i + 1, cnt, c2, true, true, nz2); // d-1 0
			} else if (d == 1) {
				func(i + 1, cnt, c2, true, nz1, nz2); // 0 0
			}
		}
	}

	void solve() {
		cin >> n;

		ans = 0;
		func();

		cout << ans << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) C::solve();

	return 0;
}

//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void solve() {
	auto ask{[](int x, int y) {
		cout << "? " << x << " " << y << endl;
		int r;
		return cin >> r, r;
	}};
	auto ans{[](int x, int y) {
		cout << "! " << x << " " << y << endl;
	}};

	int n, m;
	cin >> n >> m;

	int q1{ask(1, 1)}, q2{ask(n, m)}, q3{ask(n, 1)};

	// x + y = 2 + q1 or n + m - q2
	// -x + y = 1 - n + q3
	auto calc{[&n, &m](int c1, int c2) {
		using pii = pair<int, int>;
		int y{(c1 + c2) / 2}, x{c1 - y};
		if ((c1 + c2) & 1 || !(1 <= x && x <= n && 1 <= y && y <= m)) return pii{0, 0};
		return pair<int, int>{x, y};
	}};

	int a{2 + q1}, b{n + m - q2}, c{1 - n + q3};
	auto [x1, y1]{calc(a, c)};
	auto [x2, y2]{calc(b, c)};

	if (!x2 || (x1 && ask(x1, y1) == 0)) ans(x1, y1);
	else ans(x2, y2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

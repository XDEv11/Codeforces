#include <iostream>

using namespace std;

bool solve() {
	int x;
	if (!(cin >> x)) return false;

	auto pow{[](int b, int e) {
		int r{1};
		while (e--) r *= b;
		return r;
	}};

	int ans;
	if (x <= -3) ans = -pow(x + 4, 2) + 8;
	else if (x <= 2) ans = -2 * x + 1;
	else ans = pow(x, 3) - 14 * x + 17;

	return cout << ans << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (solve()) ;
}


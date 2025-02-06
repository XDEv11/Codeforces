#include <iostream>
#include <array>

using namespace std;

static int func(const array<char, 5>& a, const array<char, 5>& b) {
	int wa{0}, wb{0};
	
	for (int i{0}; i < 10; ++i) {
		if ((i & 1) == 0 && a[i / 2] == '1')  ++wa;
		if ((i & 1) == 1 && b[i / 2] == '1')  ++wb;

		if (wa - wb > (10 - i) / 2) return i + 1;
		if (wb - wa > (10 - i - 1) / 2) return i + 1;
	}
	return 10;
}

void solve() {
	array<char, 10> v;
	for (auto& x : v) cin >> x;

	array<char, 5> a, b;

	for (int i{0}; i < 10; ++i) {
		if ((i & 1) == 0) a[i / 2] = (v[i] == '?' ? '1' : v[i]);
		else b[i / 2] = (v[i] == '?' ? '0' : v[i]);
	}
	int ans{func(a, b)};

	for (int i{0}; i < 10; ++i) {
		if ((i & 1) == 0) a[i / 2] = (v[i] == '?' ? '0' : v[i]);
		else b[i / 2] = (v[i] == '?' ? '1' : v[i]);
	}
	ans = min(ans, func(a, b));

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

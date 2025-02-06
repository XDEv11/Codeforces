#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
	int n;
	char c;
	cin >> n >> c;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	bool flag{true};
	for (auto& x : v)
		if (x != c) flag = false;
	if (flag) return cout << "0\n"s, []{}();

	for (int i{2}; i <= n; ++i) {
		flag = true;
		for (int j{i}; j <= n; j += i) if (v[j - 1] != c) flag = false;
		if (flag) return cout << "1\n"s << i << '\n', []{}();
	}

	cout << "2\n"s << n << ' ' << n - 1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

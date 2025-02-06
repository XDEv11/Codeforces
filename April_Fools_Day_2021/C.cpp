#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	auto transform = [](char c) -> int {
		return c - 'A';
	};

	bool ans{true};
	for (int i{0}; i + 2 < s.size(); ++i)
		if ((transform(s[i]) + transform(s[i + 1])) % 26 != transform(s[i + 2]))
			ans = false;

	cout << (ans ? "YES"s : "NO"s) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	//cin >> t;
	while (t--) solve();

	return 0;
}

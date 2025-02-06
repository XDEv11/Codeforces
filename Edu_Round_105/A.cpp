#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string s;
	cin >> s;

	auto check = [&s](char c) {
		int cnt{0};
		bool p{false}, n{false};
		for (auto& x : s) {
			if (x == c) ++cnt;
			else --cnt;
			if (cnt > 0) p = true;
			if (cnt < 0) n = true;
		}
		return !(p && n);
	};

	int cntA{static_cast<int>(count(s.begin(), s.end(), 'A'))};
	int cntB{static_cast<int>(count(s.begin(), s.end(), 'B'))};
	int cntC{static_cast<int>(count(s.begin(), s.end(), 'C'))};

	bool ans;
	if (cntA + cntB == cntC) ans = check('C');
	else if (cntA + cntC == cntB) ans = check('B');
	else if (cntB + cntC == cntA) ans = check('A');
	else ans = false;

	cout << (ans ? "YES\n" : "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

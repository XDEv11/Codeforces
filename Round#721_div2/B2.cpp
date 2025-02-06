#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

static bool is_palindrome(const vector<char>& v) {
	int n{v.size()};
	for (int i{0}; i < n / 2; ++i)
		if (v[i] != v[n - 1 - i]) return false;
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<char> v(n);
	for (auto& x : v) cin >> x;

	int cnt0{count(v.begin(), v.end(), '0')};
	if (is_palindrome(v)) {
		if (cnt0 != 1 && cnt0 & 1) cout << "ALICE\n"s;
		else cout << "BOB\n"s;
	} else {
		if (cnt0 == 2 && n & 1 && v[n / 2] == '0') cout << "DRAW\n"s;
		else cout << "ALICE\n"s;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s;
	cin >> s;

	for (int i{0}; i < s.size(); ++i) {
		if (i & 1) cout << (s[i] == 'z' ? 'y' : 'z');
		else cout << (s[i] == 'a' ? 'b' : 'a');
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

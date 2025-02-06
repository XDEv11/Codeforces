//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>

using namespace std;

void solve() {
	string s{};
	cin >> s;
	if (s[0] == '0') return cout << "0\n", []{}();

	long long ans{s[0] == '?' ? 9 : 1};
	for (int i{1}; i < s.size(); ++i) ans *= (s[i] == '?' ? 10 : 1);

	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

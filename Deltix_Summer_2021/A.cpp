#include <iostream>
#include <string>

using namespace std;

void solve() {
	long long c, d;
	cin >> c >> d;

	if ((c + d) & 1) cout << "-1\n"s;
	else if (c == 0 && d == 0) cout << "0\n"s;
	else if (c == d) cout << "1\n"s;
	else cout << "2\n"s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

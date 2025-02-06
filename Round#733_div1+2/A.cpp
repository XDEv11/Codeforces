#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string n;
	cin >> n;

	cout << *max_element(n.begin(), n.end()) - '0' << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();

	return 0;
}

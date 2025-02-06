//#pragma GCC optimize ("O3")

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void solve() {
	string n1{}, n2{};
	cin >> n1 >> n2;
	int s{n1.size()};

	int i{0};
	while (i < s && n1[i] == n2[i]) ++i;
	if (i < s && n1[i] < n2[i]) swap(n1[i], n2[i]);
	for (i = i + 1; i < s; ++i) {
		if (n1[i] > n2[i]) swap(n1[i], n2[i]);
	}

	cout << n1 << '\n' << n2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t{1};
	cin >> t;
	while (t--) solve();
}

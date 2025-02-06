//#pragma GCC optimize ("O3")

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

bool solve() {
	int n;
	if (!(cin >> n)) return false;
	vector<int> v(n);
	for (auto& x : v) cin >> x;

	int ans{};
	for (auto& x : v) ans += (x ? 16 / x : 32);

	return cout << (ans / 16.) << '\n', true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(7);
	
	while (solve()) ;
}

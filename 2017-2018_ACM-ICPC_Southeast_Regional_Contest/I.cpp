#include <iostream>
 
using namespace std;
 
bool solve() {
	int n;
	if (!(cin >> n)) return false;
 
	for (int i{2}; i + i - 1 <= n; ++i) {
		if (n % (2 * i - 1) == 0 || (n - i) % (2 * i - 1) == 0) {
			cout << i << ' ' << i - 1 << '\n';
		}
		if (n % i == 0) cout << i << ' ' << i << '\n';
	}
	return true;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
 
	while (solve()) ;
}

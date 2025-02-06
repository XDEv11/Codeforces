#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		n /= 2;
		if (n & 1) cout << "NO" << endl;
		else {
			cout << "YES" << endl;
			for (int i = 1; i <= n; ++i) cout << 2 * i << " ";
			for (int i = 1; i < n; ++i) cout << 2 * i - 1 << " ";
			cout << 3 * n - 1 << endl;
		}
	}
	
	return 0;
}

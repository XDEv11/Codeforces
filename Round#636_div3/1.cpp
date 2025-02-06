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
		int pow2k = 2;
		for (int k = 2; ; ++k) {
			pow2k *= 2;
			if (n % (pow2k-1) == 0) {
				cout << n / (pow2k - 1) << endl;
				break;
			}
		}
	}
	return 0;
}

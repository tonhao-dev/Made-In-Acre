/**
 * 2444 - Volume da TV
 * Adhoc
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	int volume, T;
    cin >> volume >> T;

	while(T--) {
		int pressionado; cin >> pressionado;
		volume = min(100, max(volume + pressionado, 0));
	}

	cout << volume << endl;

    return 0;
}

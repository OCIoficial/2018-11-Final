#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    int n, d;
    int sx, sy;
    int fx, fy;
    int _;

    cin >> n >> d >> sx >> sy >> fx >> fy;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> _;
        }
    }

    cout << (min(abs(sx - fx), abs(sy - fy)) + d - 1) / d << endl;

    return 0;
}

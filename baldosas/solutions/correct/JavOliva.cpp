#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> M >> N;
    int a, b;
    cin >> a >> b;

    cout << ((M+a-1)/a)*((N+b-1)/b);
    return 0;
}

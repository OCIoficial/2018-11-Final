#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define mp make_pair
#define pi pair<int,int>
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, d;
    cin >> N >> d;
    int U, V;
    cin >> U >> V;U--;V--;U+=100;V+=100;swap(U, V);
    int X, Y;
    cin >> X >> Y;X--;Y--;X+=100;Y+=100;swap(X, Y);

    vector<vector<bool> >city(N+400, vector<bool>(N+400, false));
    vector<vector<int> >rev(N+400, vector<int>(N+400, INT_MAX));
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            int a;
            cin >> a;
            city[i+100][j+100]=a;
        }
    }

    rev[U][V]=0;
    queue<pi>COLA;
    COLA.push(mp(U, V));
    while(!COLA.empty()){
        pi p=COLA.front();COLA.pop();
        int x=p.f;
        int y=p.s;
        int jumps=rev[x][y];
        for (int i=-d;i<=d;i++){
            for (int j=-d;j<=d;j++){
                int newx=x+i, newy=y+j;
                if (rev[newx][newy]==INT_MAX and city[newx][newy]){
                    rev[newx][newy]=jumps+1;
                    COLA.push(mp(newx, newy));
                }
            }
        }
    }
    cout << rev[X][Y] << "\n";
    return 0;
}

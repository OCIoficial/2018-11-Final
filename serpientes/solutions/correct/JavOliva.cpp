#include <bits/stdc++.h>
 using namespace std;
#define f first
#define s second
#define mp make_pair
#define pi pair<int,int>
int N, M;
 void avanzaPar(pi &PosActual){
    PosActual.s++;
    if (PosActual.s==M){
        PosActual.f++;
        PosActual.s--;
    }
}
 void avanzaImpar(pi &PosActual){
    PosActual.s--;
    if (PosActual.s==-1){
        PosActual.s++;
        PosActual.f++;
    }
}
 void avanza(pi &PosActual){
    if (PosActual.f%2){
        avanzaImpar(PosActual);
        return;
    }
    avanzaPar(PosActual);
}
 void avanza(pi &PosActual, int dado){
    while(dado--){
        avanza(PosActual);
    }
}
 bool gano(pi PosActual){
    if (PosActual.f>=N-1 and (PosActual.s==0 or PosActual.s==M-1))
        return true;
    return false;
}
 int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    vector<vector<pi> >mapa(N, vector<pi>(M, mp(0, 0)));
    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            mapa[i][j]=mp(i, j);
        }
    }
     int E;
    cin >> E;
    while(E--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mapa[a][b]=mp(c, d);
    }
     pi PosActual=mp(0, 0);
    int T;
    cin >> T;
    while (T--){
        int dado;
        cin >> dado;
        avanza(PosActual, dado);
        if (gano(PosActual)){
            PosActual=mp(N-1, M-1);
            break;
        }
        PosActual=mapa[PosActual.f][PosActual.s];
    }
    cout << PosActual.f << " " << PosActual.s << "\n";
    return 0;
}

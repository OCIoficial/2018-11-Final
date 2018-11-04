#include<iostream>
#include<vector>
#include <utility>
#include<map>

using namespace std;

#define x first
#define y second

pair<int, int > move(map<pair<int, int>, pair<int, int > > &snek, pair<int, int> current, int N, int M, int dice){
    if(current.x < 0) return {-1, -1};
    while(dice > 0){
        if(current.y % 2 == 0){
            if(current.x + dice < M){
                current = {current.x + dice, current.y};
                dice = 0;
            }
            else{
                if(current.y == N - 1){
                    return {-1, -1};
                }
                dice -= (M - current.x);
                current = {M - 1, current.y + 1};
            }
        }
        else{
            if(current.x - dice >= 0){
                current = {current.x - dice, current.y};
                dice = 0;
            }
            else{
                if(current.y == N - 1){
                    return {-1, -1};
                }
                else{
                    dice -= (current.x + 1);
                    current = {0, current.y + 1};
                }
            }
        }
    }
    if(snek.count(current) != 0){
        current = snek[current];
    }
    return current;
}

pair<int, int> final_pos(int N, int M) {
    return N % 2 == 0 ? make_pair(0, N-1) : make_pair(M-1, N-1);
}

int main(){
    int N, M, S, T;
    cin >> N >> M >> S;
    map<pair<int, int>, pair<int, int > > snek;
    for(int i = 0; i < S; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        pair<int, int > start = {b, a};
        pair<int, int > end = {d, c};
        snek.emplace(start, end);
    }
    cin >> T;
    vector<int > turns(T);
    for(int i = 0; i < T; i++)
        cin >> turns[i];
    pair<int, int> current = {0, 0};
    for(int i = 0; i < T; i++){
        current = move(snek, current, N, M, turns[i]);
        if(current.x == -1){
            auto pos = final_pos(N, M);
            cout << pos.y << " " << pos.x << endl;
            return 0;
        }
    }
    cout << current.y << " " << current.x << endl;
    return 0;
}

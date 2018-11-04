#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(int argc, char *argv[]) {
    int n, d;
    int px, py, jumps = 0;
    int fx, fy;
    bool found = false;

    cin >> n >> d >> px >> py >> fx >> fy;

    px--; py--; fx--; fy--;

    vector< vector< int > > grid(n + 1, vector< int >(n + 1, 0));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    queue< int > bfs;

    // Add starting point to queue
    bfs.push(jumps);
    bfs.push(px);
    bfs.push(py);

    // Mark as added
    grid[py][px] = 0;

    while(!bfs.empty()) {
        // Remove from queue
        jumps = bfs.front();
        bfs.pop();
        px = bfs.front();
        bfs.pop();
        px = bfs.front();
        bfs.pop();

        if(px == fx && py == fy) {
          found = true;
          break;
        }

        // Add valid jumps to queue
        for(int i = max(py - d, 0); i <= min(n - 1, py + d); i++) {
          for(int j = max(px - d, 0); j <= min(n - 1, px + d); j++) {
            if (grid[i][j]) {
              // Mark as added
              grid[i][j] = 0;

              // Add to queue
              bfs.push(jumps + 1);
              bfs.push(j);
              bfs.push(i);
            }
          }
        }
    }

    if(found) {
      cout << jumps << endl;
    }
    else {
      cout << "Inalcanzable" << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int MOD = 1000009;
vector<string> dictionary;
vector<int> dp;

int main() {
  int D;
  cin >> D;
  unordered_set<string> dictionary;
  for (int i = 0; i < D; ++i) {
    string word;
    cin >> word;
    dictionary.insert(word);
  }
  string text;
  cin >> text;
  vector<int> dp(text.size() + 1);
  dp[text.size()] = 1;
  for (int i = text.size() - 1; i >= 0; i--) {
    for (int j = i; j >= 0; j--) {
      string word = text.substr(j, i - j + 1);
      if (dictionary.count(word))
        dp[j] = (dp[j] + dp[i + 1]) % MOD;
    }
  }
  cout << dp[0] << "\n";
  return 0;
}

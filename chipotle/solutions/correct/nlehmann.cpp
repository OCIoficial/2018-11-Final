#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000009;
vector<string> dictionary;
vector<int> dp;

long count(uint i, const string &text) {
  if (i == text.size())
    return 1;
  if (dp[i] != -1)
    return dp[i];

  long sum = 0;
  for (string word: dictionary) {
    if (text.substr(i, word.size()) == word)
      sum = (sum + count(i + word.size(), text)) % MOD;
  }
  return dp[i] = sum;
}


int main() {
  int D;
  cin >> D;
  for (int i = 0; i < D; ++i) {
    string word;
    cin >> word;
    dictionary.push_back(word);
  }
  string text;
  cin >> text;
  dp.resize(text.size(), -1);
  cout << count(0, text) << "\n";
  return 0;
}

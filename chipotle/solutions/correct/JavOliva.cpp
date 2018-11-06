#include <bits/stdc++.h>

using namespace std;
#define pis pair<int,string>
#define f first
#define s second
#define mp make_pair

int D, T, mod=1e6+9, largest=0;
vector<int>answer;
vector<vector<int> >graph;
string text;

void gen(int left){
    int sum=answer[left];
    int j=0;
    int node=0;
    for (int i=0;i<largest and left+i<T;i++){
        int value=text[left+i]-'a'+1;
        node=graph[node][value];
        answer[left+i+1]+=(sum*graph[node][0]);
        answer[left+i+1]=answer[left+i+1]%mod;
    }
}

void addGraph(string &w){
    int node=0;
    int NodesCount=graph.size();
    for (int i=0;i<w.size();i++){
        int Next=w[i]-'a'+1;
        int NextNode=graph[node][Next];
        if (NextNode==0){
            graph[node][Next]=NodesCount;
            NodesCount++;
            graph.push_back(vector<int>(27, 0));
            NextNode=NodesCount-1;
        }
        node=NextNode;
        if (i==w.size()-1)
            graph[node][0]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    graph.resize(27, vector<int>(27, 0));
    for (int i=1;i<27;i++){
        graph[0][i]=i;
    }
    cin >> D;
    string word;
    for (int i=0;i<D;i++){
        cin >> word;
        addGraph(word);
        largest=max(largest, (int)word.size());
    }
    cin >> text;
    T=text.size();
    answer.resize(T+1, 0);
    answer[0]=1;

    for (int i=0;i<T;i++){
        gen(i);
    }
    cout << answer[T] << "\n";
    return 0;
}

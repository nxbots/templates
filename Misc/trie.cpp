/*
Given 1e5 strings & 1e5 queries. In each query a string will be given.
Print how many strings contains the queried string as prefix.
Total sum of size of the strings can be 1e6 max.

In trie, the no. of nodes created will be total sum of size of the strings.
N = 1e6+120
from a node, we can have at best 26 edges.
as we start adding a string in the tree, we will increase the count of each node.
It will give us, how many strings built through those nodes.

*/

const int N = 1e6+120; //No. of nodes in the trie.
int to[N][26]; //from u node, using v edge, to the node we can go.
int tot_nodes = 1; // at first, we only have root node.
int cnt[N]; //No. of strings that end in the subtree of u.

void add_string(string &s) {
  int cur = 1; // starting from root node
  cnt[cur]++;
  for(int i = 0; i < s.size(); i++) {
    int ch = s[i]-'a';
    //if there is no node, we can go form cur node using ch edge, we have to create new edge.
    if(!to[cur][ch]) to[cur][ch] = ++tot_nodes;
    cur = to[cur][ch];
    cnt[cur]++;
  }
  //if we want to know in which node, the string ended, we can simply return cur form here.
  //return cur;
}

int query(string &s) {
  int cur = 1;
  for(int i = 0; i < s.size(); i++) {
    int ch = s[i]-'a';
    if(!to[cur][ch]) return 0;
    cur = to[cur][ch];
  }
  return cnt[cur];
}








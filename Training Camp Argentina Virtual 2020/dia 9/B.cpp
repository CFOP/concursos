//Por Bernardo
#include <bits/stdc++.h>
using namespace std;

using pii = pair <int, int>;

int main() {
  int t, a, b;
  int to_play = 1;
  int card, score = 0;
  cin >> t;

  vector<pii> deck;

  while(t--){
    cin >> a >> b;
    deck.push_back({b,a});
  }
  sort(deck.begin(), deck.end(), greater<pii>());

  card = 0;
  while(to_play-- and card  < deck.size()){
    score += deck[card].second;
    to_play += deck[card].first;
    card++;
  }
  cout << score << '\n';
}

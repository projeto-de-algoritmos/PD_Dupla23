#include<bits/stdc++.h>

using namespace std;

#define EMPTY -1
#define PEDIDO_MAX 20
#define PIZZA_MAX 31

int t[PEDIDO_MAX], q[PIZZA_MAX], memo[PEDIDO_MAX][PIZZA_MAX];

int compute(int i, int j) {

  if (i < 0 || j <= 0)
    return 0;

  if (memo[i][j] != EMPTY)
    return memo[i][j];

  if (t[i] > j)
    return memo[i][j] = compute(i - 1, j);

  return memo[i][j] = max(
    compute(i-1, j),
    compute(i-1, j-t[i]) + q[i]
  );
}

int main() {

  int pedidos, max_pizza;
  cin >> pedidos >> max_pizza;

  while(pedidos != 0) {
    memset(memo, EMPTY, sizeof(memo));

    for(int i = 0; i < pedidos; i++)
      cin >> q[i] >> t[i];

    cout << compute(pedidos - 1, max_pizza) << " min.\n";
    cin >> pedidos >> max_pizza;
  }

  return 0;
}

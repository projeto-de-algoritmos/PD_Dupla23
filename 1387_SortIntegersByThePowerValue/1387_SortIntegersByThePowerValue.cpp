#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int getKth(int lo, int hi, int k) {
  int acc;
  int count;

  std::vector<std::pair<int, int>> ans;

  // Armazena os caminhos passados para fazer o caminho de volta e preencher memo
  std::map<int, int> route;
  // Usado para armazenar os powers. Com ele é possivel registrar os memos de
  // valores para reutiliza-los depois
  std::map<int, int> memo = {{1, 0}};

  for (int i = lo; i <= hi; i++, acc = 0, count = 0) {
    int item = i;
    int last = item;

    if (memo[i]) {
      ans.push_back(std::make_pair(memo[i], i));
      continue;
    }

    do {
      if (memo[item]) {
        count = memo[item] + 1;
        break;
      }

      last = item;
      if (item % 2 == 0) {
        route[item / 2] = item;
        item /= 2;
      } else {
        route[3 * item + 1] = item;
        item = 3 * item + 1;
      };
      count++;
    } while (item != 1);

    // Caso o atual item já estiver, atualiza os valores de contador para o que
    // está mapeado. Troca o item para o seu valor anterior a operação
    if (item != 1) {
      acc = count;
      item = last;
    }

    // Faz o mapeamento dos valores encontrados de forma invertida
    while (item != i) {
      memo[item] = acc;
      item = route[item];
      acc++;
    }

    // Registra o power do proprio valor desejado, caso seja necessário para um
    // futuro valor
    memo[item] = acc;
    // Registra o resultado encontrado do power de i. É armazenado em um pair
    // para ordenar pelo acc (power) e depois obter o i.
    ans.push_back(std::make_pair(acc, i));
    // Limpa o mapeamento de rotas
    route.clear();
  };

  std::sort(ans.begin(), ans.end());

  return ans[k - 1].second;
}

int main() {
  std::cout << getKth(12, 15, 2) << std::endl; // 13
  std::cout << getKth(7, 11, 4) << std::endl; // 7
  std::cout << getKth(10, 20, 5) << std::endl; // 13
  std::cout << getKth(1, 1000, 777) << std::endl; // 570
}
# Força Bruta e Backtracking

Backtracking é um refinamento do algoritmo de busca por força bruta, no qual boa parte das soluções podem ser eliminadas sem serem explicitamente examinadas. A ideia central é retroceder quando detectar que a solução candidata é inviável

Exemplo, labirinto:

```cpp
int T;
int maze[5][5];
bool vis[5][5];

map<char, pii> movimento = {
  {'D', {-1, 0}},
  {'E', {1, 0}},
  {'B', {0, 1}},
  {'C', {0, -1}},
};
vector<char> movimentos_possiveis = {'B', 'C', 'D', 'E'};
bool ganhou = false;

bool deslocamento_possivel(int x, int y, char caminho) {
  x += movimento[caminho].f;
  y += movimento[caminho].s;

  if(x >= 0 && x < 5 && y >= 0 && y < 5 && maze[x][y] != 1 && vis[x][y] == 0) return true;
  return false;
}

void backtracking(int x, int y) {
  if(ganhou) return;

  vis[x][y] = true;
  if(x == 4 && y == 4) {
    ganhou = true;
    return;
  }

  for(auto c : movimentos_possiveis) {
    if(!deslocamento_possivel(x, y, c)) continue;
    backtracking(x + movimento[c].f, y + movimento[c].s);
  }
}

// ...

backtracking(0, 0);
```

Dado um tabuleiro de xadrez 𝑛 𝑥 𝑛 e uma posição (𝑥, 𝑦) do tabuleiro, queremos encontrar um passeio de um cavalo que visite cada casa exatamente uma vez.

-   Movimento do cavalo – formato de L:
    -   dois quadrados horizontalmente e um verticalmente, ou
    -   dois quadrados verticalmente e um horizontalmente.

```cpp
int m[MAX][MAX], n;
vector<pii> movimentos = {{2, -1}, {2, 1}, {-2, 1}, {-2, -1}, {1, 2}, {-1, 2}, {-1, -2}, {1, -2}};

bool posicaoValida(int x, int y){
  return (x >= 0) && (x < n) && (y >= 0) && (y < n) && !m[x][y];
}

int passeioCavalo(int x, int y)
{
  if (m[x][y] == n * n)
    return 1;
  for (auto mov : movimentos)
  {
    int x2 = x + mov.first;
    int y2 = y + mov.second;
    if (posicaoValida(x2, y2))
    {
      m[x2][y2] = m[x][y] + 1;
      if (passeioCavalo(x2, y2))
        return 1;
      m[x2][y2] = 0;
    }
  }
  return 0;
}
```

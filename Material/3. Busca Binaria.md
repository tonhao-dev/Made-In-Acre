# Busca Binária

Para aplicar um algoritmo de busca binária preciso de:

-   Uma estrutura de dados ordenada.
-   Acessar qualquer elemento dessa estrutura com a compl exidade contante.

```cpp
#include <bits/stdc++.h>
using namespace std;

// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;

        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }

    // If we reach here, then element was not present
    return -1;
}
```

## Funções

-   **binary_search(first, last, val)**
    -   Retorna um booleano indicando se existe o elemento
-   **lower_bound(first, last, val)**
    -   Retorna iterator para o **primeiro** valor **não-inferior** a **val**
    -   Ou retorna last, caso não encontre **val**
-   **upper_bound(first, last, val)**
    -   Retorna iterator para o **primeiro** valor **superior** a **val**
    -   Ou retorna last, caso não encontre **val**

## Método da bissetriz

Exemplo de cálculo de raiz quadrada:

```cpp
double raiz(double x, double eps = 1e-3)
{
  double l = 0, r = x;
  while (r - l > eps) {
    double m = (l + r) / 2.0;
    cout << m << endl;

    if (m * m < x)
      l = m;
    else
      r = m;
  }

  return (l + r) / 2.0;
}
```

> sqrt(2) = 1.41421
> 1 1.5 1.25 1.375 1.4375 1.40625 1.42188 1.41406 1.41797
> 1.41602 1.41504 1.41455
> raiz(2) = 1.41455

```cpp
ll n;
ll k;
vector<ld> acumuladores(1e4+1);

bool eh_possivel(ld max_energia) {
  ld doadores = 0.0, receptores = 0.0;
  for(ll i = 0; i < n; i++) {
    if(acumuladores[i] > max_energia) doadores += abs(acumuladores[i] - max_energia);

    if(acumuladores[i] < max_energia) receptores += abs(max_energia - acumuladores[i]);
  }

  doadores -= (doadores * k) / 100.0;
  return doadores >= receptores;
}

int main()
{
  speed;
  cin >> n >> k;
  for(ll i = 0; i < n; i++) cin >> acumuladores[i];

  ld l = 0.0, r = 1e12, eps = 1e-6, ans;
  while((r - l) > eps) {
    ld mid = (l + r) / 2.0;

    if(eh_possivel(mid)) {
      ans = mid;
      l = mid;
    } else r = mid;
  }

  cout << fixed << setprecision(9) << (l + r) / 2.0 << endl;

  return 0;
}
```

```cpp
ll N, A;
vll tiras(1e5+1);

ld area_corte(ld altura) {
  ld total = 0.0;

  for(ll i = 0; i < N; i++) {
    if(tiras[i] <= altura) continue;

    total += ((ld)tiras[i] - altura);
  }

  return total;
}

int main()
{
  speed;
  while(cin >> N >> A) {
    if(N == 0 && A == 0) break;

    for(ll i = 0; i < N; i++) cin >> tiras[i];

    ll max_area = 0;
    for(ll i = 0; i < N; i++) {
      max_area += tiras[i];
    }

    if(max_area < A) {
      cout << "-.-" << endl;
      continue;
    }
    if(max_area == A) {
      cout << ":D" << endl;
      continue;
    }

    ld l = 0, r = (ld)max_area;
    while((r - l) > 1e-6) {
      ld mid = (l + r) / 2.0;

      if(area_corte(mid) > A) {
        l = mid;
      } else {
        r = mid;
      }
    }

    cout << fixed << setprecision(4) << ((l + r) / 2.0) << endl;
  }



  return 0;
}
```

## Busca binária na resposta

```cpp
vll pipocas;
ll competidores, tempo, qtd;

bool eh_possivel(ll chute) {
  ll competidor_atual = 1, resta = chute * tempo;
  for(ll i = 0; i < sz(pipocas); i++) {
    if(resta >= pipocas[i]) resta -= pipocas[i];
    else {
      competidor_atual++;
      resta = chute * tempo;
      i--;
    }
    if(competidor_atual > competidores) return false;
  }

  return true;
}

int main()
{
  speed;
  cin >> qtd >> competidores >> tempo;
  pipocas.assign(qtd, 0);

  for(ll i = 0; i < qtd; i++) cin >> pipocas[i];

  ll l = 0, r = 1e9+1;
  while(l < r) {
    ll m = (l + r) / 2;

    if(!eh_possivel(m)) l = m + 1;
    else r = m;
  }

  cout << l << endl;

  return 0;
}
```

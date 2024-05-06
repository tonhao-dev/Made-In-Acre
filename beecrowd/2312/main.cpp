#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int, string> Pais;

bool comp(Pais a, Pais b) {
    if (get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);

    if (get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);

    if (get<2>(a) != get<2>(b)) return get<2>(a) > get<2>(b);

    return get<3>(a) < get<3>(b);
}

int main() {
    int n_paises;
    cin >> n_paises;

    vector<Pais> paises(n_paises);
    for (int i = 0; i < n_paises; i++) {
        string nome;
        int ouro, prata, bronze;
        cin >> nome >> ouro >> prata >> bronze;

        paises[i] = make_tuple(ouro, prata, bronze, nome);
    }

    sort(paises.begin(), paises.end(), comp);

    for (auto pais : paises) {
        // cout << get<3>(pais) << " " << get<0>(pais) << " " << get<1>(pais) << " " << get<2>(pais);
        string nome;
        int ouro, prata, bronze;
        tie(ouro, prata, bronze, nome) = pais;

        cout << nome << " " << ouro << " " << prata << " " << bronze << endl;
    }

    return 0;
}

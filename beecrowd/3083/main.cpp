/**
 * https://www.beecrowd.com.br/judge/pt/problems/view/3083
 * Emreh, Liug E As Strings
 * Strings, KMP
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

#define SPEED                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
#define MOD 1e9 + 7
#define FOR(i, a, b) for (ll i = a; i < (b); i++)
#define rep (i, n) FOR(i, 0, n)
#define Rep (i, a, b) for (ll i = a; i >= (b); i--)
#define all(x) begin(x), end(x)
#define log(x) cout << x << endl
#define endl "\n"
#define db(x) cout << #x << ": " << x << endl

template <typename T>

void read(T& arg) {
    std::cin >> arg;
}

template <typename T, typename... Args>
void read(T& first, Args&... args) {
    std::cin >> first;
    read(args...);
}

void computeLPSArray(string pat, int M, int* lps) {
    // length of the previous longest prefix suffix
    int len = 0;

    lps[0] = 0;  // lps[0] is always 0

    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else  // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];

                // Also, note that we do not increment
                // i here
            } else  // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

vector<ll> KMPSearch(string txt, string pat) {
    int M = pat.size();
    int N = txt.size();

    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    vector<ll> resp;

    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;  // index for txt[]
    int j = 0;  // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }

        if (j == M) {
            resp.push_back(i - j);
            j = lps[j - 1];
        }

        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }

    return resp;
}

int main() {
    SPEED;

    string a, b;
    read(a, b);

    ll q;
    read(q);

    for (ll qi = 0; qi < q; ++qi) {
        ll pos;
        char letra;
        read(pos, letra);

        string copia = a;
        copia[pos - 1] = letra;

        log(KMPSearch(copia, b).size());
    }

    return 0;
}

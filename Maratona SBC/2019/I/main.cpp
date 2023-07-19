#include <algorithm>
#include <iostream>
#include <vector>

#define MOD 1000000007
#define MAX_N 2000
#define lld long long int
#define endl '\n'

#define debug(message, x) cout << message << ": " << x << endl
#define printV(vector)    \
    for (auto x : vector) \
        cout << x << " "; \
    cout << endl

using namespace std;

class Node {
   public:
    vector<lld> lista_emails;
    vector<lld> filhos;
};

class Graph {
   public:
    vector<Node> children;
    lld num_nodes;

    Graph(lld num_nodes) {
        this->children.resize(num_nodes + 1);
        this->num_nodes = num_nodes;
    }

    void add_edge(lld from, lld to) {
        this->children[from].filhos.push_back(to);
    }

    void add_email(lld node_index, lld email) {
        this->children[node_index].lista_emails.push_back(email);
    }

    void deep_first_search(lld root_node, bool (*is_node_allowed)(Node), void (*mark_as_visited)(Node *)) {
        mark_as_visited(&this->children[root_node]);

        for (auto next_node_index : this->children[root_node].filhos) {
            if (!is_node_allowed(this->children[next_node_index])) continue;
            deep_first_search(next_node_index, is_node_allowed, mark_as_visited);
        }
    }
};

lld soma = 0;
vector<bool> emails_is_visited(MAX_N);

bool is_node_allowed_before_optimization(Node node) {
    return true;
}

void mark_as_visited_before_optimization(Node *node) {
    soma += node->lista_emails.size();
}

bool is_node_allowed_after_optimization(Node node) {
    if (node.lista_emails.size() == 0) return true;
    return any_of(node.lista_emails.begin(), node.lista_emails.end(), [](int email) { return !emails_is_visited[email]; });
}

void mark_as_visited_after_optimization(Node *node) {
    for (auto email : node->lista_emails) {
        if (!emails_is_visited[email]) soma++;
        emails_is_visited[email] = true;
    }
}

int main(int argc, char **argv) {
    lld numEnderecos, numListas;
    cin >> numEnderecos >> numListas;

    Graph grafo(numListas);
    for (lld i = 1; i <= numListas; ++i) {
        lld tamanhoLista;
        cin >> tamanhoLista;

        for (lld j = 1; j <= tamanhoLista; ++j) {
            lld endereco;
            cin >> endereco;

            endereco > numListas ? grafo.add_email(i, endereco)
                                 : grafo.add_edge(i, endereco);
        }
    }

    grafo.deep_first_search(1, is_node_allowed_before_optimization, mark_as_visited_before_optimization);
    cout << soma % MOD << " ";

    soma = 0;
    grafo.deep_first_search(1, is_node_allowed_after_optimization, mark_as_visited_after_optimization);
    cout << soma % MOD << endl;

    return 0;
}

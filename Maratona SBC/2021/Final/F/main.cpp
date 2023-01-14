// Fields Division
// https://codeforces.com/gym/103640/problem/F
#include <iostream>
#include <set>
#include <stack>
#include <vector>

#define NODE_NOT_FOUND -1
#define NOBODY -1
#define ANA_OWNER 1
#define BOB_OWNER 2

#define debug(message, x) cout << message << ": " << x << endl

using namespace std;

class Node {
   public:
    vector<int> neighbors;
    char owner;
    bool visited;

    Node() {
        this->owner = NOBODY;
        this->visited = false;
    }
};

class Graph {
   public:
    vector<Node> children;
    int num_nodes;

    Graph(int num_nodes) {
        this->children.resize(num_nodes + 1);
        this->num_nodes = num_nodes;
    }

    void add_edge(int from, int to) {
        this->children[from].neighbors.push_back(to);
        this->children[to].neighbors.push_back(from);
    }

    void deep_first_search(int root_node, bool (*is_node_allowed)(Node), void (*mark_as_visited)(Node*)) {
        mark_as_visited(&this->children[root_node]);

        for (auto next_node_index : this->children[root_node].neighbors) {
            if (!is_node_allowed(this->children[next_node_index])) continue;
            deep_first_search(next_node_index, is_node_allowed, mark_as_visited);
        }
    }
};

bool is_ana_node(Node node) {
    return node.owner == ANA_OWNER;
}

bool is_node_allowed(Node node) {
    return node.visited == false && !is_ana_node(node);
}

void mark_as_visited(Node* node) {
    node->owner = BOB_OWNER;
    node->visited = true;
}

int main(int argc, char** argv) {
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int num_fields, num_roads;
    cin >> num_fields >> num_roads;

    Graph graph(num_fields);

    for (int i = 0; i < num_roads; i++) {
        int from, to;
        cin >> from >> to;

        graph.add_edge(from, to);
    }

    graph.children[num_fields].owner = ANA_OWNER;
    graph.children[num_fields - 1].owner = BOB_OWNER;

    graph.deep_first_search(num_fields - 1, is_node_allowed, mark_as_visited);

    for (int i = 1; i <= num_fields; i++) {
        if (graph.children[i].owner == BOB_OWNER)
            cout << "B";
        else
            cout << "A";
    }

    cout << endl;

    return 0;
}

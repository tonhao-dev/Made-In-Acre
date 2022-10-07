# URI problem
# https://www.urionlinejudge.com.br/judge/pt/problems/view/1082
# Grafo, DFS, Componentes conexos


# Consts
VISIDATED = True
NOT_VISITADED = False
TOP = -1
ALL_SEARCH = -1


class Vertex(object):
    def __init__(self, key):
        self.key = key
        self.is_visited = NOT_VISITADED
        self.neighbors_list = list()

    def __eq__(self, other):
        return self.key == other.key


class Graph(object):
    def __init__(self, vertices_number):
        self.vertices_number = vertices_number
        self.visited_list = [NOT_VISITADED] * self.vertices_number
        self.vertices_list = list()

        # Create a list of vertices
        for i in range(0, self.vertices_number):
            self.vertices_list.append(Vertex(i))

    def add_edge(self, starting_vertex, arrival_vertex):
        self.vertices_list[starting_vertex].neighbors_list.append(
            arrival_vertex)
        self.vertices_list[arrival_vertex].neighbors_list.append(
            starting_vertex)

    def next_adjacent_vertex(self, vertex):
        for v in self.vertices_list[vertex].neighbors_list:
            if self.visited_list[v] == NOT_VISITADED:
                return v

        return None

    def deep_first_search(self, root_vertice, wanted_vertice):
        stack = [root_vertice]
        componente = [root_vertice]

        while len(stack) > 0:
            current_vertice = stack[TOP]
            self.visited_list[current_vertice] = VISIDATED

            if current_vertice == wanted_vertice:
                print('Verice encontrado')
                print(stack)
                break

            current_vertice = self.next_adjacent_vertex(current_vertice)

            if current_vertice is None:
                stack.pop()
            else:
                stack.append(current_vertice)
                componente.append(current_vertice)
        else:
            return componente


for test in range(0, int(input())):
    num_vertices, num_arestas = [int(x) for x in str(input()).split()]

    grafo = Graph(num_vertices)

    for conexoes in range(0, num_arestas):
        v1, v2 = [str(x) for x in str(input()).split()]
        grafo.add_edge(ord(v1) - ord('a'), ord(v2) - ord('a'))

    print('Case #{}:'.format(test + 1))
    num_componentes = 0

    while NOT_VISITADED in grafo.visited_list:
        num_componentes += 1

        vertice_raiz = grafo.visited_list.index(NOT_VISITADED)
        componente = sorted(grafo.deep_first_search(vertice_raiz, ALL_SEARCH))

        for key in componente:
            print('{},'.format(chr(key + ord('a'))), end='')
        print()

    print('{} connected components\n'.format(num_componentes))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countFigurines(int N, int M, int S, vector<string>& arena, string& instructions) {
    vector<int> dx = {-1, 0, 1, 0};  // Deslocamento em x para cada orientação do robô (N, L, S, O)
    vector<int> dy = {0, 1, 0, -1};  // Deslocamento em y para cada orientação do robô (N, L, S, O)
    vector<char> orientations = {'N', 'L', 'S', 'O'};  // Lista de orientações possíveis do robô

    int figurinesCollected = 0;  // Contador de figurinhas coletadas
    int x, y, orientation;  // Posição e orientação inicial do robô

    // Localiza a posição inicial do robô e sua orientação
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (find(orientations.begin(), orientations.end(), arena[i][j]) != orientations.end()) {
                x = i;
                y = j;
                orientation = find(orientations.begin(), orientations.end(), arena[i][j]) - orientations.begin();
            }
        }
    }

    // Executa as instruções do robô
    for (char instruction : instructions) {
        if (instruction == 'D') {
            orientation = (orientation + 1) % 4;  // Gira 90 graus para a direita
        } else if (instruction == 'E') {
            orientation = (orientation + 3) % 4;  // Gira 90 graus para a esquerda
        } else if (instruction == 'F') {
            int nx = x + dx[orientation];
            int ny = y + dy[orientation];
            // Verifica se a próxima célula está dentro da arena e não contém uma pilastra
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && arena[nx][ny] != '#') {
                x = nx;
                y = ny;

                // Verifica se a célula contém uma figurinha e a coleta
                if (arena[nx][ny] == '*') {
                    figurinesCollected++;
                    arena[nx][ny] = '.';  // Marca a célula como vazia após a coleta da figurinha
                }
            }
        }
    }

    return figurinesCollected;
}

int main() {
    while (true) {
        int N, M, S;
        cin >> N >> M >> S;

        if (N == 0 && M == 0 && S == 0) {
            break;
        }

        vector<string> arena(N);
        for (int i = 0; i < N; i++) {
            cin >> arena[i];
        }

        string instructions;
        cin >> instructions;

        int result = countFigurines(N, M, S, arena, instructions);
        cout << result << endl;
    }

    return 0;
}

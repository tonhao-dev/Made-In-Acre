#include <iostream>

using namespace std;

int main() {
    string lixo;
    int diaInicio, diaFinal, horaInicio, horaFinal, minutoInicio, minutoFinal, segundoInicio, segundoFinal;

    cin >> lixo >> diaInicio;
    cin >> horaInicio >> lixo >> minutoInicio >> lixo >> segundoInicio;
    cin >> lixo >> diaFinal;
    cin >> horaFinal >> lixo >> minutoFinal >> lixo >> segundoFinal;

    int totalSegundosInicio = diaInicio * 24 * 60 * 60 + horaInicio * 60 * 60 + minutoInicio * 60 + segundoInicio;
    int totalSegundosFinal = diaFinal * 24 * 60 * 60 + horaFinal * 60 * 60 + minutoFinal * 60 + segundoFinal;

    int totalSegundos = totalSegundosFinal - totalSegundosInicio;

    int dias = totalSegundos / (24 * 60 * 60);
    totalSegundos = totalSegundos % (24 * 60 * 60);
    int horas = totalSegundos / (60 * 60);
    totalSegundos = totalSegundos % (60 * 60);
    int minutos = totalSegundos / 60;
    totalSegundos = totalSegundos % 60;
    int segundos = totalSegundos;

    cout << dias << " dia(s)" << endl;
    cout << horas << " hora(s)" << endl;
    cout << minutos << " minuto(s)" << endl;
    cout << segundos << " segundo(s)" << endl;

    return 0;
}

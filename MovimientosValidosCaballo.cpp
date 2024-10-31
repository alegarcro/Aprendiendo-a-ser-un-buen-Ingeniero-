#include <iostream>
#include <vector>
#include "MovimientosValidosCaballo.h"
using namespace std;

void movimientosValidos::MovimientosValidosCaballo() {
    int movimientos = 0;

    cout << "Ingrese la cantidad de movimientos: ";
    cin >> movimientos;

    vector<vector<int>> MOVIMIENTOS_CABALLO = {
        {4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}
    };

    vector<int> formas(10, 1);

    for (int move = 0; move < movimientos; ++move) {
        vector<int> nueva_forma(10, 0);

        for (int numero = 0; numero < 10; ++numero) {
            for (int vecino : MOVIMIENTOS_CABALLO[numero]) {
                nueva_forma[vecino] += formas[numero];
            }
        }

        formas = nueva_forma;
    }

    int total_movimientos_validos = 0;
    for (int forma : formas) {
        total_movimientos_validos += forma;
    }

    cout << "Movimientos válidos: " << total_movimientos_validos << endl;
}
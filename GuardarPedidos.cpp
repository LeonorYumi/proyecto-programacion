#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;

void guardarPedidos(const vector<Pedido>& pedidos) {
    ofstream archivo(ARCHIVO, ios::app);
    if (archivo.is_open()) {
        archivo << pedidos;
        archivo.close();
    }
}

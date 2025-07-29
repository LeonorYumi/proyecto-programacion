#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
vector<Pedido> leerPedidos() {
    vector<Pedido> pedidos;
    ifstream archivo(ARCHIVO);
    if (archivo.is_open()) {
        archivo >> pedidos;
        archivo.close();
    }
    return pedidos;
}

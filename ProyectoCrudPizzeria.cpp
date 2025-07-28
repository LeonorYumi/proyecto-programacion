#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;

struct Pedido {
    int numero;
    string descripcion;
    double precio;
};
struct Factura {
    string nombre;
    string cedula;
    string direccion;
    int envio;
    int pago;
};

const string ARCHIVO = "C:/Users/Elizabeth/Desktop/PROGRAMACION/archivo.txt";
const string ARCHIVO_FACTURAS = "C:/Users/Elizabeth/Desktop/PROGRAMACION/archivo.txt";

istream& operator>>(istream& is, Pedido& p) {
	string linea;
	if(!getline(is, linea)) return is;
	size_t punto = linea.find('.');
	size_t dolar = linea.find('$');
	if(punto != string::npos && dolar != string::npos){
		p.numero =stoi(linea.substr(0, punto));
		p.descripcion = linea.substr(punto +2, dolar - punto -4);
		p.precio = stod(linea.substr(dolar+1));
	}
	return is;
}

ostream& operator<<(ostream& os, const Pedido& p) {
    return os << p.numero << ". " << p.descripcion << " -$" << p.precio;
}

istream& operator>>(istream& is, vector<Pedido>& pedidos) {
    Pedido p;
    while (is >> p) {
        pedidos.push_back(p);
    }
    return is;
}

ostream& operator<<(ostream& os, const vector<Pedido>& pedidos) {
    for (const auto& p : pedidos) {
        os << p << "\n";
    }
    return os;
}
vector<Pedido> leerPedidos() {
    vector<Pedido> pedidos;
    ifstream archivo(ARCHIVO);
    if (archivo.is_open()) {
        archivo >> pedidos;
        archivo.close();
    }
    return pedidos;
}

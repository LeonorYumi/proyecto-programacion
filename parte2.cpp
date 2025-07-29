
void guardarPedidos(const vector<Pedido>& pedidos) {
    ofstream archivo(ARCHIVO, ios::app);
    if (archivo.is_open()) {
        archivo << pedidos;
        archivo.close();
    }
}

void agregarPedido(vector<Pedido>& pedidos) {
    Pedido p;
    cout << "\nPara satisfacer tu apetito, te presentamos nuestros combos especiales:" << endl;
    int opcion;
    while (true) {
        cout << "\n------MENU DE PRODUCTOS------" << endl;
        cout << "1.- Combo Freddy Fazbear: 1 pizza de pepperoni con extra de queso    ---> 9.99$" << endl;
        cout << "2.- Combo Chica la Pollo: 1 pizza hawaiana + 1 refresco de naranja   ---> 8.50$" << endl;
        cout << "3.- Combo Bonnie el Conejo: 1 pizza vegetariana + 1 batido de fresa  ---> 10.25$" << endl;
        cout << "4.- Combo Foxy el pirata: 1 pizza picante + 1 bebida energetica      ---> 11.75$" << endl;
        cout << "Ingresa una opcion: "; cin >> opcion;
        p.numero = pedidos.empty() ? 1 : pedidos.back().numero + 1;
        switch (opcion) {
            case 1: p.descripcion = "Combo Freddy Fazbear"; p.precio = 9.99; break;
            case 2: p.descripcion = "Combo Chica la Pollo"; p.precio = 8.50; break;
            case 3: p.descripcion = "Combo Bonnie el Conejo"; p.precio = 10.25; break;
            case 4: p.descripcion = "Combo Foxy el pirata"; p.precio = 11.75; break;
            default: cout << "Opcion no valida" << endl; return;
        }
        pedidos.push_back(p);
    
        cout << "Producto agregado correctamente" << endl;

        while (true) {
            cout << "Deseas agregar otro producto?" << endl;
            cout << "1.- Si." << endl;
            cout << "2.- Volver al menu." << endl;
            cout << "Ingresa una opcion: "; cin >> opcion;
            if (opcion == 1) break;
            else if (opcion == 2) return;
            else cout << "\nNo es una opcion valida" << endl;
        }
    }
}

double mostrarPedidos(const vector<Pedido>& pedidos) {
    cout << "------PRODUCTOS SOLICITADOS------" << endl;
    double total = 0;
    for (int i = 0; i < pedidos.size(); i++) {
        cout << "Producto " << i + 1 << ": " << pedidos[i].descripcion << " - " << pedidos[i].precio << "$" << endl;
        total += pedidos[i].precio;
    }
    cout << "\nTotal del pedido: $" << total << endl;
    return total;
}

void modificarPedido(vector<Pedido>& pedidos) {
    if (pedidos.empty()) {
        cout << "No hay productos para modificar" << endl;
        return;
    }
    mostrarPedidos(pedidos);
    int num;
    cout << "\nIngrese el numero del producto que desea modificar: "; cin >> num;
    if (num < 1 || num > pedidos.size()) {
        cout << "Numero invalido" << endl;
        return;
    }
    Pedido& p = pedidos[num - 1];
    cout << "\n------MENU DE PRODUCTOS------" << endl;
	cout << "1.- Combo Freddy Fazbear: 1 pizza de pepperoni con extra de queso    ---> 9.99$" << endl;
	cout << "2.- Combo Chica la Pollo: 1 pizza hawaiana + 1 refresco de naranja   ---> 8.50$" << endl;
	cout << "3.- Combo Bonnie el Conejo: 1 pizza vegetariana + 1 batido de fresa  ---> 10.25$" << endl;
	cout << "4.- Combo Foxy el pirata: 1 pizza picante + 1 bebida energetica      ---> 11.75$" << endl;
    cout << "\nSeleccione el nuevo combo: ";
    int nueva; cin >> nueva;
    switch (nueva) {
        case 1: p.descripcion = "Combo Freddy Fazbear"; p.precio = 9.99; break;
        case 2: p.descripcion = "Combo Chica la Pollo"; p.precio = 8.50; break;
        case 3: p.descripcion = "Combo Bonnie el Conejo"; p.precio = 10.25; break;
        case 4: p.descripcion = "Combo Foxy el pirata"; p.precio = 11.75; break;
        default: cout << "Opcion no valida" << endl; return;
    }
    //guardarPedidos(pedidos);
    cout << "Producto modificado correctamente" << endl;
}

void eliminarPedido(vector<Pedido>& pedidos) {
    if (pedidos.empty()) {
        cout << "No hay productos para eliminar" << endl;
        return;
    }
    mostrarPedidos(pedidos);
    int num;
    cout << "\nIngrese el numero del producto que desea eliminar: "; cin >> num;
    if (num < 1 || num > pedidos.size()) {
        cout << "Numero invalido" << endl;
        return;
    }
    pedidos.erase(pedidos.begin() + num - 1);
    //guardarPedidos(pedidos);
    cout << "Producto eliminado correctamente" << endl;
}

void facturar(vector<Pedido>& pedidos) {
    if (pedidos.empty()) {
        cout << "No hay productos para cobrar" << endl;
        return;
    }
    Factura f;
    cin.ignore();
    cout << "\nIngrese su nombre: ";
    getline(cin, f.nombre);
    cout << "Ingrese su cedula o RUC: "; cin >> f.cedula; cin.ignore();
    cout << "Ingrese su direccion: ";
    getline(cin, f.direccion);

    while (true) {
        cout << "\nDeseas servicio a domicilio o para recoger?" << endl;
        cout << "1.- Domicilio (1.50$)\n2.- Para recoger (Sin recargo)" << endl;
        cout << "Ingresa una opcion: "; cin >> f.envio;
        if (f.envio == 1 || f.envio == 2) break;
        cout << "\nOpcion no valida" << endl;
    }
    while (true) {
        cout << "\nSelecciona tu forma de pago" << endl;
        cout << "1.- Transferencia o efectivo\n2.- Tarjeta (15% de recargo)" << endl;
        cout << "Ingresa una opcion: "; cin >> f.pago;
        if (f.pago == 1 || f.pago == 2) break;
        cout << "\nOpcion no valida" << endl;
    }

    // Mostrar factura en pantalla
    cout << "\n====================FACTURA====================" << endl;
    cout << "Nombre: " << f.nombre << "\nCedula: " << f.cedula << "\nDireccion: " << f.direccion << endl;
    double total = mostrarPedidos(pedidos);
	    if (f.envio == 1) {
	        cout << "Recargo por domicilio: $1.50" << endl;
	        total += 1.50;
	    }
	    if (f.pago == 2) {
	double recargo = round((total * 0.15) * 100.0) / 100.0;
	        cout << "Recargo por tarjeta: " << recargo << "$" << endl;
	        total += recargo;
	    }
    cout << "Total a pagar: " << round(total * 100.0) / 100.0 << "$" << endl;
    if (f.envio == 1){ 
        cout << "\nTu pedido se esta preparando y pronto lo enviaremos con uno de nuestros repartidores" << endl;
    }else{  
	cout << "\nTu pedido se esta preparando y estara pronto listo para que lo retires" << endl;
    cout << "\nGracias por preferir FREDDY'S FAZBEAR!" << endl;
    }
    
    // Guardar en archivo de facturas
    ofstream archivoFactura("C:/Users/Elizabeth/Desktop/PROGRAMACION/"+ f.cedula+".txt", ios::app);
    if (archivoFactura.is_open()) {
        archivoFactura<< "====================FACTURA====================\n";
        archivoFactura<< "Nombre: " << f.nombre << "\n";
        archivoFactura<< "Cedula: " << f.cedula << "\n";
        archivoFactura<< "Direccion: " << f.direccion << "\n";
        archivoFactura<< "----------- PRODUCTOS SOLICITADOS --------------\n";
    }
        double totalFactura = 0;
        for(int i=0;i<pedidos.size();i++){
			archivoFactura<<"Producto "<<i+1<<": "<<pedidos[i].descripcion<<" -$"<<pedidos[i].precio<<endl;
			totalFactura += pedidos[i].precio;
		}
		archivoFactura<<"\nTotal del pedido: $"<<totalFactura<<endl;
		if(f.envio ==1){
			archivoFactura<<"Recargo por domicilio: $1.50"<<endl;
			totalFactura += 1.50;
		}
		if(f.pago ==2){
			double recargoTarjeta = round((totalFactura * 0.15)*100.0) / 100.0;
			archivoFactura<<"Recargo por tarjeta: $"<<recargoTarjeta<<endl;
			totalFactura += recargoTarjeta;
		}
		archivoFactura<<"Total a pagar: $"<<round(totalFactura * 100.0)/100.0<<endl;
		archivoFactura<<"\nGracias por preferir FREDDY'S FAZBEAR!"<<endl;
		archivoFactura<<"================================================="<<endl;
		archivoFactura.close();
		guardarPedidos(pedidos);
		pedidos.clear();
	}
	
void buscarFacturaPorCedula() {

    string cedulaBuscar;
    cout << "Ingresa la cedula del cliente: ";
    cin >> cedulaBuscar;

    ifstream archivo("C:/Users/Elizabeth/Desktop/PROGRAMACION/"+cedulaBuscar+".txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo de facturas." << endl;
        return;
    }
    
    string linea;
    bool encontrada = false;
    while (getline(archivo, linea)) {
        if (linea.find("Cedula: " + cedulaBuscar) != string::npos) {
            encontrada = true;
            cout << "\n--- FACTURA ENCONTRADA ---" << endl;
            cout << linea << endl;
            for (int i = 0; i < 8 && getline(archivo, linea); ++i) {
                cout << linea << endl;
            }
            cout << "--------------------------\n" << endl;
        }
    }
    if (!encontrada) {
        cout << "No se encontro una factura con esa cedula." << endl;
    }

    archivo.close();
}

void menu() {
    vector<Pedido> pedidos;
    int opcion;
    cout << "BIENVENIDOS A PIZZERIA FREDDY'S FAZBEAR" << endl;
    cout<<"\nCon gusto atenderemos tu pedido :)\n\nElige una opcion para comenzar"<<endl;
    do {
        cout << "\n-------MENU PRINCIPAL-------" << endl;
        cout << "1.- Agregar pedido" << endl;
        cout << "2.- Mostrar pedido" << endl;
        cout << "3.- Modificar pedido" << endl;
        cout << "4.- Eliminar pedido" << endl;
        cout << "5.- Facturacion" << endl;
        cout << "6.- Buscar factura" << endl;
        cout << "0.- Salir" << endl;
        cout << "Ingresa una opcion: "; cin >> opcion;
        switch (opcion) {
            case 1: agregarPedido(pedidos); break;
            case 2: mostrarPedidos(pedidos); break;
            case 3: modificarPedido(pedidos); break;
            case 4: eliminarPedido(pedidos); break;
            case 5: facturar(pedidos); return;
            case 6: buscarFacturaPorCedula(); break;
            case 0: cout << "Gracias por su compra!" << endl; break;
            default: cout << "Opcion invalida. Intente de nuevo" << endl; break;
        }
    } while (opcion != 0);
}

int main() {
    menu();
    return 0;
}

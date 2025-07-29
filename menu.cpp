
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

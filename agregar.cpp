

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

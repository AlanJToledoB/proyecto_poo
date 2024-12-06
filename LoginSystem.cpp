#include "LoginSystem.h"
#include <iostream>

LoginSystem::LoginSystem(const string& archivo) : gestor(archivo) {}

void LoginSystem::mostrarMenu() {
	int opcion;
	do {
		cout << "=== Sistema de Login ===\n";
		cout << "1. Iniciar sesión\n";
		cout << "2. Registrar usuario\n";
		cout << "3. Mostrar usuarios\n";
		cout << "4. Salir\n";
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			iniciarSesion();
			break;
		case 2:
			registrarUsuario();
			break;
		case 3:
			gestor.mostrarUsuarios();
			break;
		case 4:
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opción inválida.\n";
		}
	} while (opcion != 4);
}

void LoginSystem::iniciarSesion() {
	string nombre, contra;
	cout << "Nombre de usuario: ";
	cin >> nombre;
	cout << "ingrese la contraseña: ";
	cin >> contra;
	
	if (gestor.validarCredenciales(nombre, contra)) {
		cout << "Inicio de sesión exitoso. Bienvenido, " << nombre << "!\n";
	} else {
		cout << "Credenciales incorrectas.\n";
	}
}

void LoginSystem::registrarUsuario() {
	int id, telefono;
	string nombre, direccion, rol, password;
	
	cout << "ID: ";
	cin >> id;
	cin.ignore();
	cout << "Nombre: ";
	getline(cin, nombre);
	cout << "Dirección: ";
	getline(cin, direccion);
	cout << "Rol (ADM o USR): ";
	cin >> rol;
	cout << "Contraseña: ";
	
	bool caract = true;
	while(caract){
		cin >> password;
		if(password.length() < 8){
			cout<<"su contraseña debe tener almenos 8 caracteres";
			caract = true;
		}else{
			caract = false;
		}
	}

	cout << "Teléfono: ";
	cin >> telefono;
	
	Usuario nuevoUsuario(id, nombre.c_str(), direccion.c_str(), rol.c_str(), password.c_str(), telefono);
	gestor.agregarUsuario(nuevoUsuario);
	
	cout << "Usuario registrado exitosamente.\n";
}

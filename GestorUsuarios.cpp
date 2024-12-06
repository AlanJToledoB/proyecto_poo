#include "GestorUsuarios.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

GestorUsuarios::GestorUsuarios(const string& archivoNombre) : archivo(archivoNombre) {}

void GestorUsuarios::agregarUsuario(const Usuario& nuevoUsuario) {
	ofstream salida(archivo, ios::app);
	if (salida.is_open()) {
		usuario u = nuevoUsuario.getDatos();
		salida << u.Id << "," << u.Nombre << "," << u.Direccion << "," << u.Rol << "," << u.Password << "," << u.telefono << "\n";
		salida.close();
	} else {
		cerr << "No se pudo abrir el archivo para escribir.\n";
	}
}

Usuario GestorUsuarios::buscarUsuarioPorNombre(const string& nombre) {
	auto usuarios = leerUsuarios();
	for (const auto& usuario : usuarios) {
		if (nombre == usuario.getNombre()) {
			return usuario;
		}
	}
	throw runtime_error("Usuario no encontrado.");
}

bool GestorUsuarios::validarCredenciales(const string& nombre, const string& contra) {
	auto usuarios = leerUsuarios();
	for (const auto& usuario : usuarios) {
		if (nombre == usuario.getNombre() && contra == usuario.getPassword()) {
			return true;
		}
	}
	return false;
}

vector<Usuario> GestorUsuarios::leerUsuarios() {
	vector<Usuario> usuarios;
	ifstream entrada(archivo);
	if (entrada.is_open()) {
		string linea;
		while (getline(entrada, linea)) {
			istringstream ss(linea);
			string id, nombre, direccion, rol, password, telefono;
			
			getline(ss, id, ',');
			getline(ss, nombre, ',');
			getline(ss, direccion, ',');
			getline(ss, rol, ',');
			getline(ss, password, ',');
			getline(ss, telefono);
			
			Usuario usuario(stoi(id), nombre.c_str(), direccion.c_str(), rol.c_str(), password.c_str(), stoi(telefono));
			usuarios.push_back(usuario);
		}
		entrada.close();
	}
	return usuarios;
}

void GestorUsuarios::mostrarUsuarios() {
	auto usuarios = leerUsuarios();
	for (const auto& usuario : usuarios) {
		cout << "ID: " << usuario.getId()
			<< ", Nombre: " << usuario.getNombre()
			<< ", Dirección: " << usuario.getDireccion()
			<< ", Rol: " << usuario.getRol()
			<< ", Teléfono: " << usuario.getTelefono() << "\n";
	}
}

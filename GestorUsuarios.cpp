#include "GestorUsuarios.h"
#include <fstream>
#include <iostream>
#include <stdexcept>

GestorUsuarios::GestorUsuarios(const string& archivoNombre) : archivo(archivoNombre) {}

void GestorUsuarios::agregarUsuario(const Usuario& nuevoUsuario) {
	ofstream salida(archivo, ios::binary | ios::app); // Abre el archivo en modo binario de agregar (`append`).
	if (salida.is_open()) {
		usuario datos = nuevoUsuario.getDatos();
		salida.write(reinterpret_cast<const char*>(&datos), sizeof(datos)); // Escribe los datos binarios.
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
	ifstream entrada(archivo, ios::binary); // Abre el archivo en modo binario.
	if (entrada.is_open()) {
		usuario datos;
		while (entrada.read(reinterpret_cast<char*>(&datos), sizeof(datos))) { // Lee cada registro binario.
			Usuario usuario(
							datos.Id, datos.Nombre, datos.DNI, datos.Direccion, 
							datos.Rol, datos.Password, datos.telefono
							);
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

string GestorUsuarios::obtenerRolUsuario(const string& nombre){
	
	vector <Usuario> usuarios = leerUsuarios();
	for(const auto& usuario:usuarios){
		if(usuario.getNombre() == nombre){
			return usuario.getRol();
		}
		
	}
	return "";
}

bool GestorUsuarios::dniExiste(int dni) {
	auto usuarios = leerUsuarios(); // Leer todos los usuarios desde el archivo
	for (const auto& usuario : usuarios) {
		if (usuario.getDni() == dni) {
			return true; // Retorna verdadero si encuentra un DNI duplicado
		}
	}
	return false; // Retorna falso si no hay duplicados
}

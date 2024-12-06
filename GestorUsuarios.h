#ifndef GESTOR_USUARIOS_H
#define GESTOR_USUARIOS_H

#include <vector>
#include <string>
#include "Usuario.h"

using namespace std;

class GestorUsuarios {
private:
	string archivo; // Archivo que contiene los datos de usuarios
	
public:
	GestorUsuarios(const string& archivoNombre); // Constructor
	void agregarUsuario(const Usuario& usuario); // Agregar un usuario al archivo
	Usuario buscarUsuarioPorNombre(const string& nombre); // Buscar usuario por nombre
	bool validarCredenciales(const string& nombre, const string& password); // Validar credenciales de usuario
	void mostrarUsuarios(); // Mostrar lista de usuarios en consola
	
	vector<Usuario> leerUsuarios(); // Leer todos los usuarios (cambiar a public)
};

#endif

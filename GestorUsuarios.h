#ifndef GESTOR_USUARIOS_H
#define GESTOR_USUARIOS_H

#include <vector>
#include <string>
#include "Usuario.h"

using namespace std;

class GestorUsuarios {
private:
	string archivo;
	
public:
	GestorUsuarios(const string& archivoNombre);
	
	void agregarUsuario(const Usuario& usuario);
	Usuario buscarUsuarioPorNombre(const string& nombre);
	bool validarCredenciales(const string& nombre, const string& password);
	void mostrarUsuarios();
	string obtenerRolUsuario(const string& nombre);
	bool dniExiste(int dni);
	
	vector<Usuario> leerUsuarios();
};

#endif

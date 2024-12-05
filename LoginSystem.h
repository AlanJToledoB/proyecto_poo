#ifndef LOGIN_SYSTEM_H
#define LOGIN_SYSTEM_H

#include "GestorUsuarios.h"

class LoginSystem {
private:
	GestorUsuarios gestor;
	
public:
	LoginSystem(const string& archivo);
	
	void mostrarMenu();
	void iniciarSesion();
	void registrarUsuario();
};

#endif

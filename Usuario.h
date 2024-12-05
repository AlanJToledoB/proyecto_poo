#ifndef USUARIO_H
#define USUARIO_H

#include "Estructuras.h"

class Usuario {
private:
	usuario datos;
	
public:
	Usuario(int id = 0, const char* nombre = "", const char* direccion = "", const char* rol = "USR", int telefono = 0);
	
	int getId() const;
	const char* getNombre() const;
	const char* getDireccion() const;
	const char* getRol() const;
	int getTelefono() const;
	
	void setId(int id);
	void setNombre(const char* nombre);
	void setDireccion(const char* direccion);
	void setRol(const char* rol);
	void setTelefono(int telefono);
	
	usuario getDatos() const;
};

#endif

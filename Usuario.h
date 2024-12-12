#ifndef USUARIO_H
#define USUARIO_H

#include "Estructuras.h"

class Usuario {
private:
	usuario datos;
	
public:
	Usuario(int id = 0, const char* nombre = "", int DNI = 0, const char* direccion = "", const char* rol = "USR", const char* password = "", int telefono = 0);
	
	int getId() const;
	const char* getNombre() const;
	int getDni() const;
	const char* getDireccion() const;
	const char* getRol() const;
	const char* getPassword() const;
	int getTelefono() const;
	
	void setId(int id);
	void setNombre(const char* nombre);
	void setDni(int dni);
	void setDireccion(const char* direccion);
	void setRol(const char* rol);
	void setPassword(const char* password);
	void setTelefono(int telefono);
	
	usuario getDatos() const;
};

#endif

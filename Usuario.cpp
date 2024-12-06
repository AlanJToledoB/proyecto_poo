#include "Usuario.h"
#include <cstring>

Usuario::Usuario(int id, const char* nombre, const char* direccion, const char* rol, const char* password, int telefono) {
	datos.Id = id;
	strcpy(datos.Nombre, nombre);
	strcpy(datos.Direccion, direccion);
	strcpy(datos.Rol, rol);
	strcpy(datos.Password, password);
	datos.telefono = telefono;
}

int Usuario::getId() const { return datos.Id; }
const char* Usuario::getNombre() const { return datos.Nombre; }
const char* Usuario::getDireccion() const { return datos.Direccion; }
const char* Usuario::getRol() const { return datos.Rol; }
const char* Usuario::getPassword() const { return datos.Password; }
int Usuario::getTelefono() const { return datos.telefono; }

void Usuario::setId(int id) { datos.Id = id; }
void Usuario::setNombre(const char* nombre) { strcpy(datos.Nombre, nombre); }
void Usuario::setDireccion(const char* direccion) { strcpy(datos.Direccion, direccion); }
void Usuario::setRol(const char* rol) { strcpy(datos.Rol, rol); }
void Usuario::setPassword(const char* password) { strcpy(datos.Password, password); }
void Usuario::setTelefono(int telefono) { datos.telefono = telefono; }

usuario Usuario::getDatos() const { return datos; }

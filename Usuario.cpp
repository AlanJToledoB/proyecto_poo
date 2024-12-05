#include "Usuario.h"
#include <cstring>

Usuario::Usuario(int id, const char* nombre, const char* direccion, const char* rol, int telefono) {
	datos.Id = id;
	strncpy(datos.Nombre, nombre, sizeof(datos.Nombre) - 1);
	datos.Nombre[sizeof(datos.Nombre) - 1] = '\0';
	strncpy(datos.Direccion, direccion, sizeof(datos.Direccion) - 1);
	datos.Direccion[sizeof(datos.Direccion) - 1] = '\0';
	strncpy(datos.Rol, rol, sizeof(datos.Rol) - 1);
	datos.Rol[sizeof(datos.Rol) - 1] = '\0';
	datos.telefono = telefono;
}

int Usuario::getId() const { return datos.Id; }
const char* Usuario::getNombre() const { return datos.Nombre; }
const char* Usuario::getDireccion() const { return datos.Direccion; }
const char* Usuario::getRol() const { return datos.Rol; }
int Usuario::getTelefono() const { return datos.telefono; }

void Usuario::setId(int id) { datos.Id = id; }
void Usuario::setNombre(const char* nombre) {
	strncpy(datos.Nombre, nombre, sizeof(datos.Nombre) - 1);
	datos.Nombre[sizeof(datos.Nombre) - 1] = '\0';
}
void Usuario::setDireccion(const char* direccion) {
	strncpy(datos.Direccion, direccion, sizeof(datos.Direccion) - 1);
	datos.Direccion[sizeof(datos.Direccion) - 1] = '\0';
}
void Usuario::setRol(const char* rol) {
	strncpy(datos.Rol, rol, sizeof(datos.Rol) - 1);
	datos.Rol[sizeof(datos.Rol) - 1] = '\0';
}
void Usuario::setTelefono(int telefono) { datos.telefono = telefono; }

usuario Usuario::getDatos() const { return datos; }

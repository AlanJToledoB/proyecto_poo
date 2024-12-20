#ifndef ADMINEDITUSER_H
#define ADMINEDITUSER_H

#include <wx/wx.h>
#include "GestorUsuarios.h"  // Incluye la clase GestorUsuarios que manejará el registro y validación de usuarios
#include "Usuario.h"  // Incluye la clase GestorUsuarios que manejará el registro y validación de usuarios
class AdminEditUser: public wxFrame{
private: 
	
	
	wxTextCtrl* txtRegNombre;      // Campo de texto para ingresar el nombre del nuevo usuario
	wxTextCtrl* txtDni;            // Campo de texto para ingresar el DNI del nuevo usuario
	wxTextCtrl* txtRegPassword;    // Campo de texto para ingresar la contraseña del nuevo usuario
	wxTextCtrl* txtRol;            // Campo de texto para ingresar el rol del nuevo usuario
	wxTextCtrl* txtDireccion;      // Campo de texto para ingresar la dirección del nuevo usuario
	wxTextCtrl* txtTelefono;       // Campo de texto para ingresar el teléfono del nuevo usuario
	
	
	wxButton* btnRegistrar;        // Botón para ejecutar el registro de un nuevo usuario
	
	// Objeto para gestionar los usuarios
	GestorUsuarios gestor;         // Gestiona las operaciones sobre los usuarios (registro, validación)
public:
	AdminEditUser(const wxString& archivoNombre = "usuarios.dat");
	
};

#endif

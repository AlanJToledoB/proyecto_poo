#ifndef LOGINAPP_H  // Preprocesador: asegura que el archivo solo se incluya una vez
#define LOGINAPP_H

#include <wx/wx.h>           // Incluye la librería wxWidgets, que permite crear interfaces gráficas.
#include "GestorUsuarios.h"  // Incluye la clase GestorUsuarios que manejará el registro y validación de usuarios
#include "Usuario.h"  // Incluye la clase GestorUsuarios que manejará el registro y validación de usuarios

// Declaración de la clase LoginApp, que hereda de wxFrame, la cual es la clase base para ventanas
class LoginApp : public wxFrame {
private:
	// Campos de texto para el inicio de sesión
	wxTextCtrl* txtLoginNombre;    // Campo de texto para ingresar el nombre del usuario
	wxTextCtrl* txtLoginPassword;  // Campo de texto para ingresar la contraseña (se oculta el texto)
	
	// Campos de texto para el registro de un nuevo usuario
	wxTextCtrl* txtRegNombre;      // Campo de texto para ingresar el nombre del nuevo usuario
	wxTextCtrl* txtDni;            // Campo de texto para ingresar el DNI del nuevo usuario
	wxTextCtrl* txtRegPassword;    // Campo de texto para ingresar la contraseña del nuevo usuario
	wxTextCtrl* txtRol;            // Campo de texto para ingresar el rol del nuevo usuario
	wxTextCtrl* txtDireccion;      // Campo de texto para ingresar la dirección del nuevo usuario
	wxTextCtrl* txtTelefono;       // Campo de texto para ingresar el teléfono del nuevo usuario
	
	// Botones de la aplicación
	wxButton* btnLogin;            // Botón para ejecutar el inicio de sesión
	wxButton* btnRegistrar;        // Botón para ejecutar el registro de un nuevo usuario
	wxButton* btnMostrar;          // Botón para mostrar la lista de usuarios registrados
	
	// Objeto para gestionar los usuarios
	GestorUsuarios gestor;         // Gestiona las operaciones sobre los usuarios (registro, validación)
	
public:
	// Constructor de la clase LoginApp
	LoginApp(const wxString& title);
	
	// Métodos de eventos (handlers) asociados a los botones de la interfaz
	void OnLogin(wxCommandEvent& event);      // Evento para el inicio de sesión
	void OnRegistrar(wxCommandEvent& event);  // Evento para registrar un nuevo usuario
	void OnMostrar(wxCommandEvent& event);    // Evento para mostrar los usuarios registrados
};

#endif  // Fin de la guardia de inclusión

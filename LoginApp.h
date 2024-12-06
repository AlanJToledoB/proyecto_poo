#ifndef LOGINAPP_H
#define LOGINAPP_H

#include <wx/wx.h>
#include "GestorUsuarios.h"

class LoginApp : public wxFrame {
private:
	// Campos para el inicio de sesión
	wxTextCtrl* txtLoginNombre;    // Campo para el nombre en login
	wxTextCtrl* txtLoginPassword;  // Campo para la contraseña en login
	
	// Campos para el registro
	wxTextCtrl* txtRegNombre;      // Campo para el nombre en registro
	wxTextCtrl* txtRegPassword;    // Campo para la contraseña en registro
	wxTextCtrl* txtRol;            // Campo para el rol en registro
	wxTextCtrl* txtDireccion;      // Campo para la dirección en registro
	wxTextCtrl* txtTelefono;       // Campo para el teléfono en registro
	
	// Botones de la aplicación
	wxButton* btnLogin;            // Botón para iniciar sesión
	wxButton* btnRegistrar;        // Botón para registrar usuario
	wxButton* btnMostrar;          // Botón para mostrar usuarios
	
	// Gestión de usuarios
	GestorUsuarios gestor;         // Objeto para gestionar los usuarios
	
public:
	LoginApp(const wxString& title);
	void OnLogin(wxCommandEvent& event);      // Evento para inicio de sesión
	void OnRegistrar(wxCommandEvent& event); // Evento para registrar usuario
	void OnMostrar(wxCommandEvent& event);   // Evento para mostrar usuarios
};

#endif

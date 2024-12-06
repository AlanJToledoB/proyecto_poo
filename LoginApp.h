#ifndef LOGINAPP_H
#define LOGINAPP_H

#include <wx/wx.h>
#include "GestorUsuarios.h"

class LoginApp : public wxFrame {
private:
	// Campos para el inicio de sesi�n
	wxTextCtrl* txtLoginNombre;    // Campo para el nombre en login
	wxTextCtrl* txtLoginPassword;  // Campo para la contrase�a en login
	
	// Campos para el registro
	wxTextCtrl* txtRegNombre;      // Campo para el nombre en registro
	wxTextCtrl* txtRegPassword;    // Campo para la contrase�a en registro
	wxTextCtrl* txtRol;            // Campo para el rol en registro
	wxTextCtrl* txtDireccion;      // Campo para la direcci�n en registro
	wxTextCtrl* txtTelefono;       // Campo para el tel�fono en registro
	
	// Botones de la aplicaci�n
	wxButton* btnLogin;            // Bot�n para iniciar sesi�n
	wxButton* btnRegistrar;        // Bot�n para registrar usuario
	wxButton* btnMostrar;          // Bot�n para mostrar usuarios
	
	// Gesti�n de usuarios
	GestorUsuarios gestor;         // Objeto para gestionar los usuarios
	
public:
	LoginApp(const wxString& title);
	void OnLogin(wxCommandEvent& event);      // Evento para inicio de sesi�n
	void OnRegistrar(wxCommandEvent& event); // Evento para registrar usuario
	void OnMostrar(wxCommandEvent& event);   // Evento para mostrar usuarios
};

#endif

#ifndef LOGINAPP_H  // Preprocesador: asegura que el archivo solo se incluya una vez
#define LOGINAPP_H

#include <wx/wx.h>           // Incluye la librer�a wxWidgets, que permite crear interfaces gr�ficas.
#include "GestorUsuarios.h"  // Incluye la clase GestorUsuarios que manejar� el registro y validaci�n de usuarios
#include "Usuario.h"  // Incluye la clase GestorUsuarios que manejar� el registro y validaci�n de usuarios

// Declaraci�n de la clase LoginApp, que hereda de wxFrame, la cual es la clase base para ventanas
class LoginApp : public wxFrame {
private:
	// Campos de texto para el inicio de sesi�n
	wxTextCtrl* txtLoginNombre;    // Campo de texto para ingresar el nombre del usuario
	wxTextCtrl* txtLoginPassword;  // Campo de texto para ingresar la contrase�a (se oculta el texto)
	
	// Campos de texto para el registro de un nuevo usuario
	wxTextCtrl* txtRegNombre;      // Campo de texto para ingresar el nombre del nuevo usuario
	wxTextCtrl* txtDni;            // Campo de texto para ingresar el DNI del nuevo usuario
	wxTextCtrl* txtRegPassword;    // Campo de texto para ingresar la contrase�a del nuevo usuario
	wxTextCtrl* txtRol;            // Campo de texto para ingresar el rol del nuevo usuario
	wxTextCtrl* txtDireccion;      // Campo de texto para ingresar la direcci�n del nuevo usuario
	wxTextCtrl* txtTelefono;       // Campo de texto para ingresar el tel�fono del nuevo usuario
	
	// Botones de la aplicaci�n
	wxButton* btnLogin;            // Bot�n para ejecutar el inicio de sesi�n
	wxButton* btnRegistrar;        // Bot�n para ejecutar el registro de un nuevo usuario
	wxButton* btnMostrar;          // Bot�n para mostrar la lista de usuarios registrados
	
	// Objeto para gestionar los usuarios
	GestorUsuarios gestor;         // Gestiona las operaciones sobre los usuarios (registro, validaci�n)
	
public:
	// Constructor de la clase LoginApp
	LoginApp(const wxString& title);
	
	// M�todos de eventos (handlers) asociados a los botones de la interfaz
	void OnLogin(wxCommandEvent& event);      // Evento para el inicio de sesi�n
	void OnRegistrar(wxCommandEvent& event);  // Evento para registrar un nuevo usuario
	void OnMostrar(wxCommandEvent& event);    // Evento para mostrar los usuarios registrados
};

#endif  // Fin de la guardia de inclusi�n

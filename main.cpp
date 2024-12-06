#include "LoginApp.h"
#include <wx/wx.h>

// Punto de entrada de la aplicación
class MyApp : public wxApp {
public:
	virtual bool OnInit(); // Método para inicializar la aplicación
};

wxIMPLEMENT_APP(MyApp); // Macro para implementar la clase principal de la aplicación

bool MyApp::OnInit() {
	// Crea e inicializa la ventana principal de la aplicación
	LoginApp* loginApp = new LoginApp("Sistema de Gestión de Usuarios");
	loginApp->Show(true); // Muestra la ventana
	return true;
}

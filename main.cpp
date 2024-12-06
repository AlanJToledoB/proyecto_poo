#include "LoginApp.h"
#include <wx/wx.h>

// Punto de entrada de la aplicaci�n
class MyApp : public wxApp {
public:
	virtual bool OnInit(); // M�todo para inicializar la aplicaci�n
};

wxIMPLEMENT_APP(MyApp); // Macro para implementar la clase principal de la aplicaci�n

bool MyApp::OnInit() {
	// Crea e inicializa la ventana principal de la aplicaci�n
	LoginApp* loginApp = new LoginApp("Sistema de Gesti�n de Usuarios");
	loginApp->Show(true); // Muestra la ventana
	return true;
}

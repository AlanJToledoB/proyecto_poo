#ifndef ADMINFRAME_H // Define una guardia de inclusi�n para evitar m�ltiples inclusiones del mismo archivo
#define ADMINFRAME_H
#include <wx/wx.h>// Incluye la biblioteca wxWidgets, que es necesaria para trabajar con interfaces gr�ficas en wxWidgets
#include "AdminEditUser.h"

// Declaraci�n de la clase AdminFrame, que hereda de wxFrame (la clase base para una ventana de marco)
class AdminFrame : public wxFrame{
private: 
	wxButton* btnCrearUsuario;
public: 
	AdminFrame(); // Constructor de la clase
	~AdminFrame(); // Destructor de la clase
	void crearUsu(wxCommandEvent& event);
};


#endif

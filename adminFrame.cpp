#include "AdminFrame.h"  // Incluye el archivo de encabezado de AdminFrame

// Constructor de la clase AdminFrame
AdminFrame::AdminFrame()
	: wxFrame(nullptr, wxID_ANY, "Panel de Administrador", wxDefaultPosition, wxSize(800, 600)) {
	// Crea un nuevo panel en el marco (ventana) principal
	wxPanel* panel = new wxPanel(this);
	
	// Crea un texto estático en la ventana que muestra un mensaje
	new wxStaticText(panel, wxID_ANY, "Bienvenido al Panel de Administrador", wxPoint(20, 20));
	
	// Crea un botón para gestionar usuarios, ubicado en la posición (20, 60) dentro del panel
	btnCrearUsuario = new wxButton(this , wxID_ANY, "Crear usuarios", wxPoint(20, 60));
	
	btnCrearUsuario->Bind(wxEVT_BUTTON, &AdminFrame::crearUsu,this);
	
	// Crea un botón para ver reportes, ubicado en la posición (20, 100) dentro del panel
	new wxButton(panel, wxID_ANY, "Ver Reportes", wxPoint(20, 100));
}


void AdminFrame::crearUsu(wxCommandEvent& event){
	AdminEditUser* adminUser = new AdminEditUser();
	adminUser -> Show();
	
	this->Hide();
	
	wxMessageBox("bienvenido al editor de usuarios", "Exito", wxOK|wxICON_INFORMATION );
}

// Destructor de la clase AdminFrame
AdminFrame::~AdminFrame() {
	// Aquí puedes liberar recursos si es necesario
	// En este caso no se necesita código específico de limpieza
}

#include "AdminFrame.h"  // Incluye el archivo de encabezado de AdminFrame

// Constructor de la clase AdminFrame
AdminFrame::AdminFrame()
	: wxFrame(nullptr, wxID_ANY, "Panel de Administrador", wxDefaultPosition, wxSize(800, 600)) {
	// Crea un nuevo panel en el marco (ventana) principal
	wxPanel* panel = new wxPanel(this);
	
	// Crea un texto est�tico en la ventana que muestra un mensaje
	new wxStaticText(panel, wxID_ANY, "Bienvenido al Panel de Administrador", wxPoint(20, 20));
	
	// Crea un bot�n para gestionar usuarios, ubicado en la posici�n (20, 60) dentro del panel
	new wxButton(panel, wxID_ANY, "Gestionar Usuarios", wxPoint(20, 60));
	
	// Crea un bot�n para ver reportes, ubicado en la posici�n (20, 100) dentro del panel
	new wxButton(panel, wxID_ANY, "Ver Reportes", wxPoint(20, 100));
}

// Destructor de la clase AdminFrame
AdminFrame::~AdminFrame() {
	// Aqu� puedes liberar recursos si es necesario
	// En este caso no se necesita c�digo espec�fico de limpieza
}

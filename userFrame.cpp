#include "UserFrame.h"  // Incluye el archivo de encabezado de UserFrame

// Constructor de la clase UserFrame
UserFrame::UserFrame(): wxFrame(nullptr, wxID_ANY, "Panel de Usuario", wxDefaultPosition, wxSize(800, 600)) {
	// Crea un nuevo panel en el marco (ventana) principal
	wxPanel* panel = new wxPanel(this);
	
	// Crea un texto est�tico en la ventana que muestra un mensaje
	new wxStaticText(panel, wxID_ANY, "Bienvenido al Panel de Usuario", wxPoint(20, 20));
	
	// Crea un bot�n para ver el perfil del usuario
	new wxButton(panel, wxID_ANY, "Ver Perfil", wxPoint(20, 60));
	
	// Crea un bot�n para realizar operaciones del usuario
	new wxButton(panel, wxID_ANY, "Realizar Operaciones", wxPoint(20, 100));
}
UserFrame::~UserFrame() {
	// Aqu� podr�as liberar recursos si fuera necesario
}


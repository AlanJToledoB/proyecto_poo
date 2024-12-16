#include "AdminEditUser.h"

AdminEditUser::AdminEditUser(): wxFrame(nullptr, wxID_ANY, "agregar usuarios", wxDefaultPosition, wxSize(600,400)){
	
	//creamos un texto estatico para mostrar la ventana
	
	new wxStaticText(this, wxID_ANY, "formulario para agregar un nuevo usuario",wxPoint(50,50));
}

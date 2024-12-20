#include "AdminEditUser.h"
#include <wx/stattext.h>

AdminEditUser::AdminEditUser(const wxString& archivoNombre)
	: wxFrame(nullptr, wxID_ANY, "Registro de usuarios", wxDefaultPosition, wxSize(600, 400)),
	gestor(std::string(archivoNombre.mb_str())) // Convertimos wxString a std::string
{
	// Panel principal para contener los elementos
	wxPanel* mainPanel = new wxPanel(this);
	
	// Crear un sizer vertical para organizar los elementos
	wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
	
	// Crear un sizer dentro del panel de registro
	wxStaticBoxSizer* registerSizer = new wxStaticBoxSizer(wxVERTICAL, mainPanel, "Registrar Usuario");
	
	// Etiqueta y campo de texto para el nombre
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "Nombre:"), 0, wxALL, 5);
	txtRegNombre = new wxTextCtrl(mainPanel, wxID_ANY, "");
	registerSizer->Add(txtRegNombre, 0, wxALL | wxEXPAND, 5);
	
	// Etiqueta y campo de texto para el DNI
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "DNI:"), 0, wxALL, 5);
	txtDni = new wxTextCtrl(mainPanel, wxID_ANY, "");
	registerSizer->Add(txtDni, 0, wxALL | wxEXPAND, 5);
	
	// Etiqueta y campo de texto para la contraseña
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "Contraseña:"), 0, wxALL, 5);
	txtRegPassword = new wxTextCtrl(mainPanel, wxID_ANY, "",wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD);
	
	registerSizer->Add(txtRegPassword, 0, wxALL | wxEXPAND, 5);
	
	// Etiqueta y campo de texto para el rol
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "Rol:"), 0, wxALL, 5);
	txtRol = new wxTextCtrl(mainPanel, wxID_ANY, "");
	registerSizer->Add(txtRol, 0, wxALL | wxEXPAND, 5);
	
	// Etiqueta y campo de texto para la dirección
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "Dirección:"), 0, wxALL, 5);
	txtDireccion = new wxTextCtrl(mainPanel, wxID_ANY, "");
	registerSizer->Add(txtDireccion, 0, wxALL | wxEXPAND, 5);
	
	// Etiqueta y campo de texto para el teléfono
	registerSizer->Add(new wxStaticText(mainPanel, wxID_ANY, "Teléfono:"), 0, wxALL, 5);
	txtTelefono = new wxTextCtrl(mainPanel, wxID_ANY, "");
	registerSizer->Add(txtTelefono, 0, wxALL | wxEXPAND, 5);
	
	// Botón para registrar usuario
	btnRegistrar = new wxButton(mainPanel, wxID_ANY, "Registrar");
	registerSizer->Add(btnRegistrar, 0, wxALL | wxALIGN_CENTER, 10);
	
	// Agregar el sizer de registro al sizer principal
	mainSizer->Add(registerSizer, 1, wxALL | wxEXPAND, 10);
	
	// Establecer el sizer principal en el panel
	mainPanel->SetSizer(mainSizer);
	
	// Ajustar los tamaños automáticamente
	mainSizer->SetSizeHints(this);
}

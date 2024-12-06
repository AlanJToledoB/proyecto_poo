#include "LoginApp.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>

// Constructor de la aplicaci�n
LoginApp::LoginApp(const wxString& title) 
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)), gestor("usuarios.txt") {
	
	// Panel principal para contener los subpaneles
	wxPanel* mainPanel = new wxPanel(this);
	
	// Crear un sizer horizontal para dividir el espacio
	wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
	
	// Crear el panel de inicio de sesi�n
	wxPanel* loginPanel = new wxPanel(mainPanel);
	loginPanel->SetBackgroundColour(wxColour(220, 220, 220)); // Color de fondo del panel
	wxStaticBox* loginBox = new wxStaticBox(loginPanel, wxID_ANY, "Iniciar Sesi�n", wxPoint(10, 10), wxSize(280, 160));
	
	// Etiqueta y campo de texto para el nombre
	new wxStaticText(loginPanel, wxID_ANY, "Nombre:", wxPoint(20, 40));
	txtLoginNombre = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(100, 40), wxSize(160, 25));
	
	// Etiqueta y campo de texto para la contrase�a
	new wxStaticText(loginPanel, wxID_ANY, "Contrase�a:", wxPoint(20, 80));
	txtLoginPassword = new wxTextCtrl(loginPanel, wxID_ANY, "", wxPoint(100, 80), wxSize(160, 25), wxTE_PASSWORD);
	
	// Bot�n para iniciar sesi�n
	btnLogin = new wxButton(loginPanel, wxID_ANY, "Iniciar Sesi�n", wxPoint(90, 120));
	btnLogin->Bind(wxEVT_BUTTON, &LoginApp::OnLogin, this); // Vincula el evento al bot�n
	
	// Crear el panel de registro
	wxPanel* registerPanel = new wxPanel(mainPanel);
	registerPanel->SetBackgroundColour(wxColour(240, 240, 240)); // Color de fondo del panel
	wxStaticBox* registerBox = new wxStaticBox(registerPanel, wxID_ANY, "Registrar Usuario", wxPoint(10, 10), wxSize(280, 220));
	
	// Etiqueta y campo de texto para el nombre
	new wxStaticText(registerPanel, wxID_ANY, "Nombre:", wxPoint(20, 40));
	txtRegNombre = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 40), wxSize(160, 25));
	
	// Etiqueta y campo de texto para la contrase�a
	new wxStaticText(registerPanel, wxID_ANY, "Contrase�a:", wxPoint(20, 80));
	txtRegPassword = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 80), wxSize(160, 25), wxTE_PASSWORD);
	
	// Etiqueta y campo de texto para el rol
	new wxStaticText(registerPanel, wxID_ANY, "Rol:", wxPoint(20, 120));
	txtRol = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 120), wxSize(160, 25));
	
	// Etiqueta y campo de texto para la direcci�n
	new wxStaticText(registerPanel, wxID_ANY, "Direcci�n:", wxPoint(20, 160));
	txtDireccion = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 160), wxSize(160, 25));
	
	// Etiqueta y campo de texto para el tel�fono
	new wxStaticText(registerPanel, wxID_ANY, "Tel�fono:", wxPoint(20, 200));
	txtTelefono = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 200), wxSize(160, 25));
	
	// Bot�n para registrar usuario
	btnRegistrar = new wxButton(registerPanel, wxID_ANY, "Registrar", wxPoint(90, 240));
	btnRegistrar->Bind(wxEVT_BUTTON, &LoginApp::OnRegistrar, this); // Vincula el evento al bot�n
	
	// Bot�n para mostrar usuarios
	btnMostrar = new wxButton(registerPanel, wxID_ANY, "Mostrar Usuarios", wxPoint(90, 280));
	btnMostrar->Bind(wxEVT_BUTTON, &LoginApp::OnMostrar, this); // Vincula el evento al bot�n
	
	// A�adir los paneles al sizer
	sizer->Add(loginPanel, 1, wxEXPAND | wxALL, 5);
	sizer->Add(registerPanel, 1, wxEXPAND | wxALL, 5);
	
	// Configurar el sizer del panel principal
	mainPanel->SetSizer(sizer);
}

// Evento: iniciar sesi�n
void LoginApp::OnLogin(wxCommandEvent& event) {
	wxString nombre = txtLoginNombre->GetValue();       // Obtener el nombre ingresado
	wxString password = txtLoginPassword->GetValue();   // Obtener la contrase�a ingresada
	
	if (gestor.validarCredenciales(nombre.ToStdString(), password.ToStdString())) {
		wxMessageBox("Inicio de sesi�n exitoso.", "�xito", wxOK | wxICON_INFORMATION);
	} else {
		wxMessageBox("Credenciales incorrectas.", "Error", wxOK | wxICON_ERROR);
	}
}

// Evento: registrar usuario
void LoginApp::OnRegistrar(wxCommandEvent& event) {
	wxString nombre = txtRegNombre->GetValue();         // Obtener el nombre ingresado
	wxString password = txtRegPassword->GetValue();     // Obtener la contrase�a ingresada
	wxString rol = txtRol->GetValue();                  // Obtener el rol ingresado
	wxString direccion = txtDireccion->GetValue();      // Obtener la direcci�n ingresada
	wxString telefono = txtTelefono->GetValue();        // Obtener el tel�fono ingresado
	
	if (nombre.IsEmpty() || password.IsEmpty() || rol.IsEmpty() || direccion.IsEmpty() || telefono.IsEmpty()) {
		wxMessageBox("Por favor, complete todos los campos.", "Error", wxOK | wxICON_WARNING);
		return;
	}
	
	if (password.length() < 8) {
		wxMessageBox("La contrase�a debe tener al menos 8 caracteres.", "Error", wxOK | wxICON_WARNING);
		return;
	}
	
	static int id = 1; // ID incremental
	Usuario nuevoUsuario(id++, nombre.ToStdString().c_str(), direccion.ToStdString().c_str(), 
						 rol.ToStdString().c_str(), password.ToStdString().c_str(), std::stoi(telefono.ToStdString()));
	
	gestor.agregarUsuario(nuevoUsuario);
	wxMessageBox("Usuario registrado exitosamente.", "�xito", wxOK | wxICON_INFORMATION);
}

// Evento: mostrar usuarios
void LoginApp::OnMostrar(wxCommandEvent& event) {
	auto usuarios = gestor.leerUsuarios();
	
	if (usuarios.empty()) {
		wxMessageBox("No hay usuarios registrados.", "Informaci�n", wxOK | wxICON_INFORMATION);
		return;
	}
	
	wxDialog* dialog = new wxDialog(this, wxID_ANY, "Lista de Usuarios", wxDefaultPosition, wxSize(500, 300));
	wxGrid* grid = new wxGrid(dialog, wxID_ANY, wxPoint(10, 10), wxSize(480, 260));
	
	grid->CreateGrid(usuarios.size(), 5); // Crear una tabla con las columnas necesarias
	grid->SetColLabelValue(0, "ID");
	grid->SetColLabelValue(1, "Nombre");
	grid->SetColLabelValue(2, "Direcci�n");
	grid->SetColLabelValue(3, "Rol");
	grid->SetColLabelValue(4, "Tel�fono");
	
	for (size_t i = 0; i < usuarios.size(); ++i) {
		grid->SetCellValue(i, 0, std::to_string(usuarios[i].getId()));
		grid->SetCellValue(i, 1, usuarios[i].getNombre());
		grid->SetCellValue(i, 2, usuarios[i].getDireccion());
		grid->SetCellValue(i, 3, usuarios[i].getRol());
		grid->SetCellValue(i, 4, std::to_string(usuarios[i].getTelefono()));
	}
	
	dialog->ShowModal();
	dialog->Destroy();
}

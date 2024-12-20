#include "LoginApp.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>

#include "AdminFrame.h"  // Incluir encabezado de AdminFrame
#include "UserFrame.h"   // Incluir encabezado de UserFrame

// Constructor de la aplicaci�n
LoginApp::LoginApp(const wxString& title) 
	: wxFrame(nullptr, wxID_ANY, title, wxDefaultPosition, wxSize(600, 400)), gestor("usuarios.dat") {
	
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
	
	// Etiqueta y campo de texto para el DNI
	new wxStaticText(registerPanel, wxID_ANY, "DNI:", wxPoint(20, 80));
	txtDni = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 80), wxSize(160, 25));
	
	// Etiqueta y campo de texto para la contrase�a
	new wxStaticText(registerPanel, wxID_ANY, "Contrase�a:", wxPoint(20, 120));
	txtRegPassword = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 120), wxSize(160, 25), wxTE_PASSWORD);
	
	// Etiqueta y campo de texto para el rol
	new wxStaticText(registerPanel, wxID_ANY, "Rol:", wxPoint(20, 160));
	txtRol = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 160), wxSize(160, 25));
	
	// Etiqueta y campo de texto para la direcci�n
	new wxStaticText(registerPanel, wxID_ANY, "Direcci�n:", wxPoint(20, 200));
	txtDireccion = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 200), wxSize(160, 25));
	
	// Etiqueta y campo de texto para el tel�fono
	new wxStaticText(registerPanel, wxID_ANY, "Tel�fono:", wxPoint(20, 240));
	txtTelefono = new wxTextCtrl(registerPanel, wxID_ANY, "", wxPoint(100, 240), wxSize(160, 25));
	
	
	// Bot�n para registrar usuario
	btnRegistrar = new wxButton(registerPanel, wxID_ANY, "Registrar", wxPoint(90, 240));
	btnRegistrar->Bind(wxEVT_BUTTON, &LoginApp::OnRegistrar, this); // Vincula el evento al bot�n
	
	// Bot�n para mostrar usuarios
	// Crear el bot�n "Mostrar Usuarios" en el panel de registro
	btnMostrar = new wxButton(registerPanel, wxID_ANY, "Mostrar Usuarios", wxPoint(90, 280));
	
	// Vincular el evento wxEVT_BUTTON del bot�n con el m�todo OnMostrar
	// Cuando el bot�n es presionado, se ejecutar� el m�todo LoginApp::OnMostrar
	btnMostrar->Bind(wxEVT_BUTTON, &LoginApp::OnMostrar, this);
	
	// Agregar los paneles al Sizer para que se distribuyan correctamente en el panel principal
	sizer->Add(loginPanel, 1, wxEXPAND | wxALL, 5); // Agrega loginPanel con proporci�n 1 y un margen de 5
	sizer->Add(registerPanel, 1, wxEXPAND | wxALL, 5); // Agrega registerPanel con proporci�n 1 y un margen de 5
	
	// Configurar el Sizer para el mainPanel para gestionar el dise�o de sus elementos secundarios
	mainPanel->SetSizer(sizer);
	
}




// Evento: iniciar sesi�n
void LoginApp::OnLogin(wxCommandEvent& event) {
	wxString nombre = txtLoginNombre->GetValue();       // Obtener el nombre ingresado
	wxString password = txtLoginPassword->GetValue();   // Obtener la contrase�a ingresada
	
	if (gestor.validarCredenciales(nombre.ToStdString(), password.ToStdString())) {

		std::string rol = gestor.obtenerRolUsuario(nombre.ToStdString());
		if(rol == "adm"){
			AdminFrame* adminFrame = new AdminFrame();
			adminFrame->Show(); //mostrar la pantalla del adminsitrador
			this->Hide(); //Ocultar la ventana del login 
			wxMessageBox("Inicio de sesi�n exitoso.", "�xito", wxOK | wxICON_INFORMATION);
		}
		else if(rol == "usr"){
			UserFrame* userFrame = new UserFrame();
			
			userFrame->Show();
			this->Hide();// Ocultar la ventana de login
			
			wxMessageBox("Inicio de sesi�n exitoso.", "�xito", wxOK | wxICON_INFORMATION);
		}
		if(rol != "adm" && rol != "usr"){
			wxMessageBox("ninguna de los roles de su credencial coinciden", "Error", wxOK | wxICON_ERROR);
		}

	} else {
		wxMessageBox("Credenciales incorrectas.", "Error", wxOK | wxICON_ERROR);
	}
}





void LoginApp::OnRegistrar(wxCommandEvent& event) {
	wxString nombre = txtRegNombre->GetValue();
	wxString dni = txtDni->GetValue();
	wxString password = txtRegPassword->GetValue();
	wxString rol = txtRol->GetValue();
	wxString direccion = txtDireccion->GetValue();
	wxString telefono = txtTelefono->GetValue();
	
	if (nombre.IsEmpty() || password.IsEmpty() || rol.IsEmpty() || direccion.IsEmpty() || telefono.IsEmpty() || dni.IsEmpty()) {
		wxMessageBox("Por favor, complete todos los campos.", "Error", wxOK | wxICON_WARNING);
		return;
	}
	
	if (password.length() < 8) {
		wxMessageBox("La contrase�a debe tener al menos 8 caracteres.", "Error", wxOK | wxICON_WARNING);
		return;
	}
	
	int dniInt = std::stoi(dni.ToStdString());
	
	// Verificar si el DNI ya existe
	if (gestor.dniExiste(dniInt)) {
		wxMessageBox("El DNI ingresado ya est� registrado. Por favor, use un DNI diferente.", "Error", wxOK | wxICON_WARNING);
		return;
	}
	
	static int id = 1; // ID incremental
	Usuario nuevoUsuario(id++, nombre.ToStdString().c_str(), dniInt, direccion.ToStdString().c_str(),
						 rol.ToStdString().c_str(), password.ToStdString().c_str(), std::stoi(telefono.ToStdString()));
	
	gestor.agregarUsuario(nuevoUsuario);
	wxMessageBox("Usuario registrado exitosamente.", "�xito", wxOK | wxICON_INFORMATION);
}




void LoginApp::OnMostrar(wxCommandEvent& event) {
	// Leer la lista de usuarios desde el archivo utilizando el gestor
	auto usuarios = gestor.leerUsuarios();
	
	// Si no hay usuarios registrados, muestra un mensaje y termina la funci�n
	if (usuarios.empty()) {
		wxMessageBox("No hay usuarios registrados.", "Informaci�n", wxOK | wxICON_INFORMATION);
		return;
	}
	
	// Crear un cuadro de di�logo modal para mostrar la lista de usuarios
	wxDialog* dialog = new wxDialog(this, wxID_ANY, "Lista de Usuarios", wxDefaultPosition, wxSize(600, 400));
	
	// Crear una cuadr�cula para mostrar los datos en forma de tabla
	wxGrid* grid = new wxGrid(dialog, wxID_ANY, wxPoint(10, 10), wxSize(580, 350));
	
	// Configurar la cuadr�cula con el n�mero de filas igual al n�mero de usuarios y 6 columnas
	grid->CreateGrid(usuarios.size(), 6);
	
	// Configurar las etiquetas de las columnas
	grid->SetColLabelValue(0, "ID");         // Columna para el ID del usuario
	grid->SetColLabelValue(1, "Nombre");     // Columna para el Nombre del usuario
	grid->SetColLabelValue(2, "DNI");        // Columna para el DNI del usuario
	grid->SetColLabelValue(3, "Direcci�n");  // Columna para la Direcci�n del usuario
	grid->SetColLabelValue(4, "Rol");        // Columna para el Rol del usuario
	grid->SetColLabelValue(5, "Tel�fono");   // Columna para el Tel�fono del usuario
	
	// Llenar la cuadr�cula con los datos de los usuarios
	for (size_t i = 0; i < usuarios.size(); ++i) {
		try {
			// Establecer valores en cada celda de la fila correspondiente al usuario
			grid->SetCellValue(i, 0, std::to_string(usuarios[i].getId()));         // ID
			grid->SetCellValue(i, 1, usuarios[i].getNombre());                    // Nombre
			grid->SetCellValue(i, 2, std::to_string(usuarios[i].getDni()));       // DNI
			grid->SetCellValue(i, 3, usuarios[i].getDireccion());                 // Direcci�n
			grid->SetCellValue(i, 4, usuarios[i].getRol());                       // Rol
			grid->SetCellValue(i, 5, std::to_string(usuarios[i].getTelefono()));  // Tel�fono
		} catch (const std::exception& e) {
			// Capturar cualquier error al establecer valores en la cuadr�cula
			wxMessageBox("Error al mostrar los datos de un usuario.", "Error", wxOK | wxICON_ERROR);
		}
	}
	
	// Mostrar el cuadro de di�logo en modo modal
	dialog->ShowModal();
	
	// Destruir el cuadro de di�logo despu�s de cerrarlo
	dialog->Destroy();
}

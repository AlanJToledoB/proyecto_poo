#ifndef USERFRAME_H   // Define una guardia de inclusión para evitar múltiples inclusiones del mismo archivo
#define USERFRAME_H

#include <wx/wx.h>  // Incluye la biblioteca wxWidgets, necesaria para trabajar con interfaces gráficas

// Declaración de la clase UserFrame, que hereda de wxFrame (la clase base para una ventana de marco)
class UserFrame : public wxFrame {
public:
	UserFrame();  // Constructor de la clase
	virtual ~UserFrame();  // Destructor virtual necesario para wxWidgets
};

#endif // USERFRAME_H

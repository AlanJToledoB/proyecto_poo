#ifndef ADMINFRAME_H // Define una guardia de inclusión para evitar múltiples inclusiones del mismo archivo
#define ADMINFRAME_H
#include <wx/wx.h>// Incluye la biblioteca wxWidgets, que es necesaria para trabajar con interfaces gráficas en wxWidgets


// Declaración de la clase AdminFrame, que hereda de wxFrame (la clase base para una ventana de marco)
class AdminFrame : public wxFrame{
public: 
	AdminFrame(); // Constructor de la clase
	~AdminFrame(); // Destructor de la clase
	
};


#endif

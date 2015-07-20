// Draughts.cpp : main project file.

#include "stdafx.h"
#include "DraughtsForm.h"

using namespace Draughts;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew DraughtsForm());
	return 0;
}

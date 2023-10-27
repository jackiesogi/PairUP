#include "MyForm.h"
#include <Windows.h>
#include <locale>
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:main")


using namespace pairup;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args)
{	
	//std::setlocale(LC_ALL, "en_US.utf8");

	// Enabling Windows XP visual effects before any controls are created
	//Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it
	Application::Run(gcnew MyForm());
	return 0;
}
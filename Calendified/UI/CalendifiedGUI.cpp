#include "CalendifiedGUI.h"


using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) {
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
UI::CalendifiedGUI mainWindow;
Application::Run(%mainWindow);
}

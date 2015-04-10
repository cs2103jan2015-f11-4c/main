#include "CalendifiedGUI.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main(array<String^>^ args) {
	 // Load configuration from file
    el::Configurations conf("/path/to/my-conf.conf");
    // Reconfigure single logger
    el::Loggers::reconfigureLogger("default", conf);
    // Actually reconfigure all loggers instead
    el::Loggers::reconfigureAllLoggers(conf);
    // Now all the loggers will use configuration from file
	LOG(INFO) << "=====Start of Log=====";
Application::EnableVisualStyles();
Application::SetCompatibleTextRenderingDefault(false);
UI::CalendifiedGUI mainWindow;
Application::Run(%mainWindow);
}


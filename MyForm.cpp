#include "MyForm.h"
#include <windows.h>
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void Main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    HighSchoolluProject::MyForm form;
    Application::Run(%form);
}

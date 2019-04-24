#include <cstdlib>
#include <ctime>
#include "BigInt.h"
#include "prime.h"
#include "Algo.h"
#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main() {
	srand(time(NULL));
	InitializeBigInt();
	
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Elgamal::MyForm form;
	Application::Run(%form);
	return 0;
}
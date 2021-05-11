
#pragma once
#include "MyForm.h"


ref class BASE {
private:
	//// var
	windowsform::MyForm^ form;

public:
	
	//// constructor
	explicit BASE(System::Windows::Forms::Form^ pot, int name) {
		//// new form
		form = gcnew windowsform::MyForm(pot);
		form->Text = "Form_ " + name.ToString();
		//// for blending use between STATheading and Threading; it is a bit unsafe; but our case is in dependent, no worry
		form->CheckForIllegalCrossThreadCalls = false;

		// not work
		//// ShowDialog cannot use with MdiParent
		//form->ShowDialog();
		form->MdiParent = pot;
	}

	//// threading function
	void OpenForm() {
		//form->ShowDialog();
		System::Windows::Forms::Application::Run(form);
	}
};

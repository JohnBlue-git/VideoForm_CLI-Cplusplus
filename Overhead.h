/*
Auther: JohnBlue

Time: 2021/5

Platform: VS 2017

Object: It is a application form for video playing.

Thech:
MDI is used for dynamic allocating the number of video can playing at a time.
For showing up child form and doing MDI, overhead or form->show() is used as strategy.
Since opencv is in C++ yet the form is derived from CLR, component like cv::Mat cannot be the memeber of form class;
thereby, extern variable is applied in this project.
*/

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

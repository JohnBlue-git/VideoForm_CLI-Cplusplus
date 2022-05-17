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


#include "MainForm.h"

using namespace windowsform;

// extern var
LinkedList<ALLdata> SSet;
int how_many;

// i have no idea the diference
//[STAThreadAttribute] or [STAThread]

// curremt one
[STAThread]
int main()
{
	// 建立任何控制項之前，先啟用 Windows XP 視覺化效果
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	// method 1
	//Application::Run(gcnew MainForm());
	// method 2
	MainForm^ form = gcnew MainForm();
	Application::Run(form);
	return 0;
}

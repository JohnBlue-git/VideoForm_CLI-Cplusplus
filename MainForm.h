#pragma once
#include "MyForm.h"
#include "Overhead.h"

//// extern var
extern LinkedList<ALLdata> SSet;
extern int how_many;

namespace windowsform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// MainForm 的摘要
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}

			/*
			string f;
			f = "rd /s/q";
			f += " all_data\\";
			system(f.c_str());
			*/

			/*
			// delete all_data
			System::String^ f = "all_data";
			System::IO::DirectoryInfo^ di = gcnew System::IO::DirectoryInfo(f);
			for each(System::IO::DirectoryInfo^ dir in di->GetDirectories())
			{
				dir->Delete(true);
			}
			//System::IO::Directory::Delete(gcnew System::String("all_data"));
			*/
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  檔案ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  新增子視窗ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  排列ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  串列ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  垂直ToolStripMenuItem;

	private:
		int form_num;

	private: System::Windows::Forms::ToolStripMenuItem^  水平ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  檢視子視窗ToolStripMenuItem;
			 /// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->檔案ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->新增子視窗ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->排列ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->串列ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->垂直ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->水平ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->檢視子視窗ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->檔案ToolStripMenuItem,
					this->排列ToolStripMenuItem, this->檢視子視窗ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MdiWindowListItem = this->檢視子視窗ToolStripMenuItem;
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1378, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 檔案ToolStripMenuItem
			// 
			this->檔案ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->新增子視窗ToolStripMenuItem });
			this->檔案ToolStripMenuItem->Name = L"檔案ToolStripMenuItem";
			this->檔案ToolStripMenuItem->Size = System::Drawing::Size(58, 27);
			this->檔案ToolStripMenuItem->Text = L"檔案";
			// 
			// 新增子視窗ToolStripMenuItem
			// 
			this->新增子視窗ToolStripMenuItem->Name = L"新增子視窗ToolStripMenuItem";
			this->新增子視窗ToolStripMenuItem->Size = System::Drawing::Size(182, 30);
			this->新增子視窗ToolStripMenuItem->Text = L"新增子視窗";
			this->新增子視窗ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newForm1ToolStripMenuItem_Click);
			// 
			// 排列ToolStripMenuItem
			// 
			this->排列ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->串列ToolStripMenuItem,
					this->垂直ToolStripMenuItem, this->水平ToolStripMenuItem
			});
			this->排列ToolStripMenuItem->Name = L"排列ToolStripMenuItem";
			this->排列ToolStripMenuItem->Size = System::Drawing::Size(58, 27);
			this->排列ToolStripMenuItem->Text = L"排列";
			// 
			// 串列ToolStripMenuItem
			// 
			this->串列ToolStripMenuItem->Name = L"串列ToolStripMenuItem";
			this->串列ToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->串列ToolStripMenuItem->Text = L"串列";
			this->串列ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cascadeToolStripMenuItem_Click);
			// 
			// 垂直ToolStripMenuItem
			// 
			this->垂直ToolStripMenuItem->Name = L"垂直ToolStripMenuItem";
			this->垂直ToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->垂直ToolStripMenuItem->Text = L"垂直";
			this->垂直ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::verticalToolStripMenuItem_Click);
			// 
			// 水平ToolStripMenuItem
			// 
			this->水平ToolStripMenuItem->Name = L"水平ToolStripMenuItem";
			this->水平ToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->水平ToolStripMenuItem->Text = L"水平";
			this->水平ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::horizontalToolStripMenuItem_Click);
			// 
			// 檢視子視窗ToolStripMenuItem
			// 
			this->檢視子視窗ToolStripMenuItem->Name = L"檢視子視窗ToolStripMenuItem";
			this->檢視子視窗ToolStripMenuItem->Size = System::Drawing::Size(112, 27);
			this->檢視子視窗ToolStripMenuItem->Text = L"檢視子視窗";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1378, 756);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"電子觀察員";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MainForm::CloseF);
			this->Load += gcnew System::EventHandler(this, &MainForm::Form_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

		private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e)
		{
			//// initialize form_num
			form_num = 0;
		}

		private: System::Void newForm1ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
		{
			//// new extern data structure
			ALLdata newForm("Form_ " + std::to_string(form_num));
			SSet.Push_back(newForm);
			
			//// new MyForm 1
			// create an overhead object
			BASE^ form = gcnew BASE((System::Windows::Forms::Form^)this, form_num);
			// threading the object
			Thread^ newthread;
			newthread = gcnew Thread(gcnew ThreadStart(form, &BASE::OpenForm));
			newthread->SetApartmentState(ApartmentState::STA);
			newthread->Start();
			
			//// new MyForm 2
			//MyForm^ f;
			//f = gcnew windowsform::MyForm(this);
			//f->Text = "Form_ " + form_num.ToString();
			// for blending use between STATheading and Threading; it is a bit unsafe; but our case is in dependent, no worry
			//f->CheckForIllegalCrossThreadCalls = false;
			//f->MdiParent = this;
			//f->Show();
			
			//System::Windows::Forms::Application::Run(f);// not allowed, Application::Run suppose to open only once at a time //https://stackoverflow.com/questions/5200292/application-runform-vs-form-show
			
			//f->ShowDialog();// ShowDialog cannot use with MdiParent

			// updating number
			form_num++;
			how_many++;
		}

		/////// the following function is for rearranging MyForms as a child form
		/////// but the size will change if we do so; therefore, a FixFormBorder or Sizable Form border is used here

		private: void FixFormBorder() {
			for each(Form^ f in this->MdiChildren)
			{
				MyForm^ F = dynamic_cast<MyForm^>(f);
				F->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			}
		}

		private: void SizableFormBorder() {
			for each(Form^ f in this->MdiChildren)
			{
				MyForm^ F = dynamic_cast<MyForm^>(f);
				F->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
			}
		}

		private: System::Void cascadeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// fix
			FixFormBorder();
			// Cascade
			this->LayoutMdi(System::Windows::Forms::MdiLayout::Cascade);
			// sizable
			SizableFormBorder();
		}

		private: System::Void verticalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// fix
			FixFormBorder();
			// Vertical
			this->LayoutMdi(System::Windows::Forms::MdiLayout::TileVertical);
			// sizable
			SizableFormBorder();
		}

		private: System::Void horizontalToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			// fix
			FixFormBorder();
			// Horizontal
			this->LayoutMdi(System::Windows::Forms::MdiLayout::TileHorizontal);
			// sizable
			SizableFormBorder();
		}

		/////// close
		private: System::Void CloseF(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			// 2 deconstruction
			for each(Form^ f in this->MdiChildren)
			{
				MyForm^ F = dynamic_cast<MyForm^>(f);
				//F->Dispose();
				F->~MyForm();
			}

			// 1 can close all the System::Windows::Forms::Application::Run(...)
			System::Windows::Forms::Application::Exit();
		}
	};
}

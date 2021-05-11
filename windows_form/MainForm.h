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
	/// MainForm ���K�n
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO:  �b���[�J�غc�禡�{���X
			//
		}

	protected:
		/// <summary>
		/// �M������ϥΤ����귽�C
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
	private: System::Windows::Forms::ToolStripMenuItem^  �ɮ�ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �s�W�l����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �ƦCToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ��CToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;

	private:
		int form_num;

	private: System::Windows::Forms::ToolStripMenuItem^  ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  �˵��l����ToolStripMenuItem;
			 /// <summary>
		/// �]�p�u��һݪ��ܼơC
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->�ɮ�ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�s�W�l����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�ƦCToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��CToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�˵��l����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->�ɮ�ToolStripMenuItem,
					this->�ƦCToolStripMenuItem, this->�˵��l����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->MdiWindowListItem = this->�˵��l����ToolStripMenuItem;
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1378, 31);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// �ɮ�ToolStripMenuItem
			// 
			this->�ɮ�ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->�s�W�l����ToolStripMenuItem });
			this->�ɮ�ToolStripMenuItem->Name = L"�ɮ�ToolStripMenuItem";
			this->�ɮ�ToolStripMenuItem->Size = System::Drawing::Size(58, 27);
			this->�ɮ�ToolStripMenuItem->Text = L"�ɮ�";
			// 
			// �s�W�l����ToolStripMenuItem
			// 
			this->�s�W�l����ToolStripMenuItem->Name = L"�s�W�l����ToolStripMenuItem";
			this->�s�W�l����ToolStripMenuItem->Size = System::Drawing::Size(182, 30);
			this->�s�W�l����ToolStripMenuItem->Text = L"�s�W�l����";
			this->�s�W�l����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::newForm1ToolStripMenuItem_Click);
			// 
			// �ƦCToolStripMenuItem
			// 
			this->�ƦCToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->��CToolStripMenuItem,
					this->����ToolStripMenuItem, this->����ToolStripMenuItem
			});
			this->�ƦCToolStripMenuItem->Name = L"�ƦCToolStripMenuItem";
			this->�ƦCToolStripMenuItem->Size = System::Drawing::Size(58, 27);
			this->�ƦCToolStripMenuItem->Text = L"�ƦC";
			// 
			// ��CToolStripMenuItem
			// 
			this->��CToolStripMenuItem->Name = L"��CToolStripMenuItem";
			this->��CToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->��CToolStripMenuItem->Text = L"��C";
			this->��CToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::cascadeToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::verticalToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(128, 30);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::horizontalToolStripMenuItem_Click);
			// 
			// �˵��l����ToolStripMenuItem
			// 
			this->�˵��l����ToolStripMenuItem->Name = L"�˵��l����ToolStripMenuItem";
			this->�˵��l����ToolStripMenuItem->Size = System::Drawing::Size(112, 27);
			this->�˵��l����ToolStripMenuItem->Text = L"�˵��l����";
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
			this->Text = L"�q�l�[���";
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
			//System::Windows::Forms::Application::Run(f);// not allowed
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
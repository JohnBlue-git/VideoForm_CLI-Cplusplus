#pragma once


//// our
#include "linklist.h"

//// opencv
#include "opencv2\opencv.hpp"

//// std
#include <msclr\marshal_cppstd.h>
#include <math.h>
// string
#include <string>
// file
#include <sstream>
#include <fstream>
// other
#include <ctime>
#include "stdio.h"
#include <io.h>
// close black window in beginning
#include <wingdi.h>
#pragma comment(lib, "libhpdf.lib")// libharu //
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")



using namespace cv;
using namespace std;



#define PLAY_VIDEO_WIN_WIDTH 640
#define PLAY_VIDEO_WIN_HEIGHT 360



//// extern var
extern LinkedList<ALLdata> SSet;
extern int how_many;


//// zoom in out
// opencv's mouse dunction, wheel, delta
//https://answers.opencv.org/question/128489/mouse-wheel-delta/
void onZoom(int event, int x, int y, int flags, void* userdata)
{
	//// var
	ALLdata& SSetr = (*(ALLdata*)userdata);

	//// create list container for storage img
	//static LinkedList<Mat> prev;

	//// determine zoom in or zoom out
	// old static var
	//static int time;*
	//static bool ck = false;*
	// zoom in
	if (event == CV_EVENT_LBUTTONDOWN) {
		// if reach 6 th, don't zoom in any time soon 
		if (SSetr.time == - 6) {
			return;
		}
		// zoom in size
		else {
			// if zoom in size is accptable
			if (((SSetr.zoom_W - 120) > 0) && ((SSetr.zoom_H - 60) > 0)) {
				SSetr.time--;
				//SSetr.zoom_W -= 240;
				//SSetr.zoom_H -= 120;
				SSetr.zoom_W = SSetr.frame.size().width - 120;
				SSetr.zoom_H = SSetr.frame.size().height - 60;
			}
			// otherwise
			else {
				return;
			}
		}

		//// position of mouse
		// horizontal
		if ((x - SSetr.zoom_W / 2) < 0) {
			SSetr.mousex = 0;
		}
		else if ((x + SSetr.zoom_W / 2) >= SSetr.frame.size().width) {
			SSetr.mousex = SSetr.frame.size().width - SSetr.zoom_W;
		}
		else {
			SSetr.mousex = x - SSetr.zoom_W / 2;
		}
		// verticle
		if ((y - SSetr.zoom_H / 2) < 0) {
			SSetr.mousey = 0;
		}
		else if ((y + SSetr.zoom_H / 2) >= SSetr.frame.size().height) {
			SSetr.mousey = SSetr.frame.size().height - SSetr.zoom_H;
		}
		else {
			SSetr.mousey = y - SSetr.zoom_H / 2;
		}

		//// store prev img
		SSetr.prev.Push_front(SSetr.imagen);

		//// zoom in
		Rect rct = Rect(SSetr.mousex, SSetr.mousey, SSetr.zoom_W, SSetr.zoom_H);
		SSetr.imagen = Mat(SSetr.imagen, rct);
		cv::resize(SSetr.imagen, SSetr.imagen, cv::Size(SSetr.frame.size().width, SSetr.frame.size().height), 0, 0, CV_INTER_AREA);

		//// show
		cv::imshow(SSetr.form_name + "Screenshot Frame", SSetr.imagen);
	}
	// zoom out
	else if (event == CV_EVENT_RBUTTONDOWN) {
		//// if reach max size, don't zoom out any time soon
		if (SSetr.time == 0) {
			return;
		}
		//// zoom out size
		else {
			// if the size is acceptable
			if (((SSetr.zoom_W + 120) <= SSetr.frame.size().width) && ((SSetr.zoom_H + 60) <= SSetr.frame.size().height)) {
				SSetr.time++;
				//SSetr.zoom_W += 240;
				//SSetr.zoom_H += 120;
			}
			// otherwise
			else {
				return;
			}
		}

		//// pop out last img
		SSetr.imagen = SSetr.prev.Pop_front();

		//// show
		imshow(SSetr.form_name + "Screenshot Frame", SSetr.imagen);
	}
	// other, don't do anything
	else {
		return;
	}
}


namespace windowsform {
	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace cv;
	using namespace System::Threading;
	using namespace System::Diagnostics;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(Form^ pt)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//

			// ...
			//this->MdiParent = pt;// not used now
		}
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  Speed_Up;
	private: System::Windows::Forms::Button^  Continu_Click;
	private: System::Windows::Forms::Button^  Only_Pause_Click;
	private: System::Windows::Forms::Button^  playVideo;
	private: System::Windows::Forms::TrackBar^  videoTrackbar;
	private: System::Windows::Forms::Button^  stopPlayButton;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  selectVideo;
	private: System::Windows::Forms::TextBox^  videoFilePath;
	private: System::Windows::Forms::TabControl^  tabControl1;

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->playVideo = (gcnew System::Windows::Forms::Button());
			this->pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->videoTrackbar = (gcnew System::Windows::Forms::TrackBar());
			this->Speed_Up = (gcnew System::Windows::Forms::Button());
			this->stopPlayButton = (gcnew System::Windows::Forms::Button());
			this->Only_Pause_Click = (gcnew System::Windows::Forms::Button());
			this->Continu_Click = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->selectVideo = (gcnew System::Windows::Forms::Button());
			this->videoFilePath = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoTrackbar))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->playVideo);
			this->tabPage3->Controls->Add(this->pictureBox);
			this->tabPage3->Controls->Add(this->videoTrackbar);
			this->tabPage3->Controls->Add(this->Speed_Up);
			this->tabPage3->Controls->Add(this->stopPlayButton);
			this->tabPage3->Controls->Add(this->Only_Pause_Click);
			this->tabPage3->Controls->Add(this->Continu_Click);
			this->tabPage3->Controls->Add(this->textBox1);
			this->tabPage3->Controls->Add(this->label1);
			this->tabPage3->Location = System::Drawing::Point(4, 34);
			this->tabPage3->Margin = System::Windows::Forms::Padding(4);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(4);
			this->tabPage3->Size = System::Drawing::Size(768, 558);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"影片播放";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// playVideo
			// 
			this->playVideo->BackColor = System::Drawing::SystemColors::ControlLight;
			this->playVideo->Enabled = false;
			this->playVideo->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->playVideo->ForeColor = System::Drawing::SystemColors::ControlText;
			this->playVideo->Location = System::Drawing::Point(24, 17);
			this->playVideo->Margin = System::Windows::Forms::Padding(4);
			this->playVideo->Name = L"playVideo";
			this->playVideo->Size = System::Drawing::Size(109, 48);
			this->playVideo->TabIndex = 0;
			this->playVideo->Text = L"播放影片";
			this->playVideo->UseVisualStyleBackColor = true;
			this->playVideo->Click += gcnew System::EventHandler(this, &MyForm::playVideo_Click);
			// 
			// pictureBox
			// 
			this->pictureBox->Location = System::Drawing::Point(157, 7);
			this->pictureBox->Name = L"pictureBox";
			this->pictureBox->Size = System::Drawing::Size(604, 453);
			this->pictureBox->TabIndex = 27;
			this->pictureBox->TabStop = false;
			// 
			// videoTrackbar
			// 
			this->videoTrackbar->AccessibleName = L"1";
			this->videoTrackbar->Location = System::Drawing::Point(156, 467);
			this->videoTrackbar->Margin = System::Windows::Forms::Padding(4);
			this->videoTrackbar->Name = L"videoTrackbar";
			this->videoTrackbar->Size = System::Drawing::Size(604, 69);
			this->videoTrackbar->TabIndex = 20;
			this->videoTrackbar->Scroll += gcnew System::EventHandler(this, &MyForm::Scroll);
			// 
			// Speed_Up
			// 
			this->Speed_Up->BackColor = System::Drawing::SystemColors::ControlLight;
			this->Speed_Up->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Speed_Up->ForeColor = System::Drawing::SystemColors::ControlText;
			this->Speed_Up->Location = System::Drawing::Point(24, 150);
			this->Speed_Up->Margin = System::Windows::Forms::Padding(4);
			this->Speed_Up->Name = L"Speed_Up";
			this->Speed_Up->Size = System::Drawing::Size(107, 48);
			this->Speed_Up->TabIndex = 35;
			this->Speed_Up->Text = L"加速影片";
			this->Speed_Up->UseVisualStyleBackColor = true;
			this->Speed_Up->Click += gcnew System::EventHandler(this, &MyForm::SpeedUp);
			// 
			// stopPlayButton
			// 
			this->stopPlayButton->BackColor = System::Drawing::SystemColors::ControlLight;
			this->stopPlayButton->Enabled = false;
			this->stopPlayButton->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->stopPlayButton->ForeColor = System::Drawing::SystemColors::ControlText;
			this->stopPlayButton->Location = System::Drawing::Point(24, 84);
			this->stopPlayButton->Margin = System::Windows::Forms::Padding(4);
			this->stopPlayButton->Name = L"stopPlayButton";
			this->stopPlayButton->Size = System::Drawing::Size(106, 48);
			this->stopPlayButton->TabIndex = 9;
			this->stopPlayButton->Text = L"停止播放";
			this->stopPlayButton->UseVisualStyleBackColor = true;
			this->stopPlayButton->Click += gcnew System::EventHandler(this, &MyForm::stopPlayButton_Click);
			// 
			// Only_Pause_Click
			// 
			this->Only_Pause_Click->Cursor = System::Windows::Forms::Cursors::Default;
			this->Only_Pause_Click->Enabled = false;
			this->Only_Pause_Click->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Only_Pause_Click->Location = System::Drawing::Point(24, 337);
			this->Only_Pause_Click->Margin = System::Windows::Forms::Padding(4);
			this->Only_Pause_Click->Name = L"Only_Pause_Click";
			this->Only_Pause_Click->Size = System::Drawing::Size(107, 48);
			this->Only_Pause_Click->TabIndex = 33;
			this->Only_Pause_Click->Text = L"暫停播放";
			this->Only_Pause_Click->UseVisualStyleBackColor = true;
			this->Only_Pause_Click->Click += gcnew System::EventHandler(this, &MyForm::OnlyPause);
			// 
			// Continu_Click
			// 
			this->Continu_Click->Cursor = System::Windows::Forms::Cursors::Default;
			this->Continu_Click->Enabled = false;
			this->Continu_Click->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Continu_Click->Location = System::Drawing::Point(24, 412);
			this->Continu_Click->Margin = System::Windows::Forms::Padding(4);
			this->Continu_Click->Name = L"Continu_Click";
			this->Continu_Click->Size = System::Drawing::Size(108, 48);
			this->Continu_Click->TabIndex = 34;
			this->Continu_Click->Text = L"繼續播放";
			this->Continu_Click->UseVisualStyleBackColor = true;
			this->Continu_Click->Click += gcnew System::EventHandler(this, &MyForm::Continue);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(54, 269);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(38, 33);
			this->textBox1->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(28, 225);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 25);
			this->label1->TabIndex = 36;
			this->label1->Text = L"影片速度";
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->selectVideo);
			this->tabPage1->Controls->Add(this->videoFilePath);
			this->tabPage1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->tabPage1->Location = System::Drawing::Point(4, 34);
			this->tabPage1->Margin = System::Windows::Forms::Padding(4);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(4);
			this->tabPage1->Size = System::Drawing::Size(768, 558);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"影片選取";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->Location = System::Drawing::Point(24, 22);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 25);
			this->label4->TabIndex = 13;
			this->label4->Text = L"檔案位置";
			// 
			// selectVideo
			// 
			this->selectVideo->AccessibleName = L"1";
			this->selectVideo->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->selectVideo->Location = System::Drawing::Point(514, 52);
			this->selectVideo->Margin = System::Windows::Forms::Padding(4);
			this->selectVideo->Name = L"selectVideo";
			this->selectVideo->Size = System::Drawing::Size(54, 33);
			this->selectVideo->TabIndex = 11;
			this->selectVideo->Tag = L"";
			this->selectVideo->Text = L"...";
			this->selectVideo->UseVisualStyleBackColor = true;
			this->selectVideo->Click += gcnew System::EventHandler(this, &MyForm::selectVideo_Click);
			// 
			// videoFilePath
			// 
			this->videoFilePath->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->videoFilePath->Location = System::Drawing::Point(28, 52);
			this->videoFilePath->Margin = System::Windows::Forms::Padding(4);
			this->videoFilePath->Name = L"videoFilePath";
			this->videoFilePath->Size = System::Drawing::Size(475, 33);
			this->videoFilePath->TabIndex = 12;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->tabControl1->Location = System::Drawing::Point(6, 3);
			this->tabControl1->Margin = System::Windows::Forms::Padding(4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(776, 596);
			this->tabControl1->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl1->TabIndex = 26;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnablePreventFocusChange;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(787, 605);
			this->Controls->Add(this->tabControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Location = System::Drawing::Point(30, 30);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Tag = L"";
			this->Text = L"子視窗";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::Form_Closing);
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->videoTrackbar))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// VAR ////// VAR ////// VAR ////// VAR

		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//
	private:
		// which form
		int which;
		// frame info
		int video_cols_size;
		int video_rows_size;
		// flag
		bool playable = false;
		bool pasue_frame = false;
		bool closeproperty = true;
		// thread
		Thread^ thop;
		Thread^ thzm;
		// delegation
		delegate void MyCallback();
		MyCallback^ callback;
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// FUNCTION ////// FUNCTION ////// FUNCTION ////// FUNCTION

		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//
		//// FILE
		// extract file name from a path
		private: string extract_Filename(string path) {
			size_t found1 = path.find_last_of("/\\");
			string o = path.substr(found1 + 1);
			size_t found2 = o.find_last_of(".");
			return o.substr(0, found2);
		}
		// is the file a video?
		private: bool is_video_file(string path) {
			size_t found = path.find_last_of(".");
			string o = path.substr(found + 1);
			if ((o == "mp4") || (o == "avi") || (o == "rmvb") || (o == "mpeg"))
				return true;
			else
				return false;
		}

		//// PLAY
		// display each frame
		private: bool display(int tp) {
			//// var
			ALLdata& SSetr = SSet[which];

			//// show
			try
			{
				if (tp == 1) {
					SSetr.cap >> SSetr.frame;
				}
				else if (tp == 2) {
					for (int i = 0; i < SSetr.speed; i++) {
						SSetr.cap >> SSetr.frame;
					}
				}

				//// to bitmap
				//cv::Mat poc = SSetr.frame;//not work @@
				cv::Size dsize = cv::Size(400, 300);
				cv::resize(SSetr.frame, SSetr.frame, dsize, 0, 0, INTER_AREA);
				Bitmap^ pic = gcnew Bitmap(SSetr.frame.cols, SSetr.frame.rows, (int)SSetr.frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr)SSetr.frame.data);
				
				//// windows show
				pictureBox->Image = pic;
			}
			catch (System::Exception^ e) {
				return false;
			}
			return true;
		}
		// initialize setting for playing video
		private: void play_initial() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// get video info
			SSetr.frameCount = SSetr.cap.get(CAP_PROP_FRAME_COUNT);//Get total FPS
			SSetr.fps = SSetr.cap.get(cv::CAP_PROP_FPS);

			//// trackbar
			videoTrackbar->Maximum = int(SSetr.frameCount);//set the maximum of trackbar
			SSetr.framePos = 0;
			videoTrackbar->Value = 0;
			//SSetr.framePos = (int)videoTrackbar->Value;

			//// show frame
			display(1);
		}
		// determined cap is opened or not?
		private: bool is_cap_open() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// path
			string path = SSetr.video_path;
			if (path.empty()) {
				path = "c://asz8zxc2vmsdbf1vwerptoiupkja123sdf.mp4";// fool-proof design
			}

			//// assign to cap and determine
			SSetr.cap = VideoCapture(path);
			if (SSetr.cap.isOpened() == 0) {
				return false;
			}
			else {
				return true;
			}
		}
		// set video trackbar
		private: void videoTrackbar_Set() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// set
			videoTrackbar->Value = SSetr.framePos;
		}
		// reset play button
		private: void ResetPlay() {
			//// reset button
			selectVideo->Enabled = true;
			playVideo->Enabled = true;
			Only_Pause_Click->Enabled = false;
			stopPlayButton->Enabled = false;
			
			
			//// reset trackbar
			SSetr.framePos = 0;
			videoTrackbar->Value = 0;
		}
		// video playing loop
		private: void Play() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// loop
			while (true) {
				try
				{
					// set
					SSetr.cap.set(CAP_PROP_POS_FRAMES, videoTrackbar->Value);
					// determined it is finished or not?
					if (!display(2) || SSetr.framePos >= SSetr.frameCount || SSetr.frame.empty() || closeproperty == false)
					{
						break;
					}
					// pos update
					SSetr.framePos = SSetr.cap.get(CAP_PROP_POS_FRAMES);
					callback = gcnew MyCallback(this, &MyForm::videoTrackbar_Set);// delegation
					this->BeginInvoke(callback);                                  // asynchronous callback
					// playing with period
					Thread::Sleep(SSetr.fps);
					// pause thread
					if (pasue_frame == true)
					{
						Thread::Sleep(Timeout::Infinite);// about to sleep infinitely
					}
				}
				// interrupt then awake
				catch (ThreadInterruptedException^ e)
				{
					callback = gcnew MyCallback(this, &MyForm::re_pasue_cap);
					this->BeginInvoke(callback);
					continue;
				}
				// abort then finish
				catch (ThreadAbortException^ e)
				{
					break;
				}
				// any error then finish
				catch (System::Exception^ e)
				{
					break;
				}
				finally{
					//
				}
			}
			//// reset ...
			callback = gcnew MyCallback(this, &MyForm::ResetPlay);// delegation
			this->BeginInvoke(callback);                          // asynchronous callback
			//// release cap
			SSetr.cap.release();
		}
		// for strarting the video thread
		private: void start_cap() {
			thop = gcnew Thread(gcnew ThreadStart(this, &MyForm::Play));
			thop->Start();
		}
		// for pauseing the video thread
		private: void pause_cap() {
			//// flag for pausing and continue
			pasue_frame = true;

			//// snap
			thzm = gcnew Thread(gcnew ThreadStart(this, &MyForm::show_zoom));
			thzm->Start();
		}
		// for continuing the video thread
		private: void continue_cap() {
			thop->Interrupt();
		}
		// for restarting the video thread
		private: void re_pasue_cap() {
			pasue_frame = false;
		}
		// for stopping the video thread
		private: void stop_cap() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// thread
			if (SSetr.cap.isOpened() && thop != nullptr) {// && thop->IsAlive
				//// stop thread
				thop->Abort();
			}
		}

		//// ZOOM
		// show up the zoomed image
		private: System::Void Show_Image(string name, cv::Mat image, double width, double height, double left_margin, double top_margin) {
			cv::namedWindow(name, cv::WINDOW_NORMAL);
			cv::resizeWindow(name, width, height);
			cv::imshow(name, image);
			cv::moveWindow(name, left_margin, top_margin);
		}
		// zoom function
		private: void show_zoom() {
			//// var
			ALLdata& SSetr = SSet[which];

			//// is video exist
			cv::Mat fm = SSetr.frame;
			if (playable == true) {
				////show video 1 srceenshot image
				Show_Image(SSetr.form_name + "Screenshot Frame", fm, 640, 360, 380, 220);

				//// set zoomin zoom out 
				SSetr.mousex = 0;
				SSetr.mousey = 0;
				SSetr.zoom_W = SSetr.frame.size().width;
				SSetr.zoom_H = SSetr.frame.size().height;
				SSetr.imagen = SSetr.frame;
				SSetr.time = 0;// reset time

				//// opencv function callback
				setMouseCallback(SSetr.form_name + "Screenshot Frame", onZoom, &SSetr);
			}

			//// loop for pausing and zoom function
			while (true) {
				//// close_frame flag
				if (pasue_frame == false || cv::waitKey(20) == 27 || closeproperty == false) {
					destroyWindow(SSetr.form_name + "Screenshot Frame");
					break;
				}
			}
		}
		//
		/////////////////////////////////////////////////////////////////////////////////////////////////////

		// CLICK BUTTON ////// CLICK BUTTON ////// CLICK BUTTON ////// CLICK BUTTON

		/////////////////////////////////////////////////////////////////////////////////////////////////////
		//
		//// LOAD
		private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			//// transform MyForm name into string
			string s_tmp = msclr::interop::marshal_as<string>(this->Text);
			
			//// get MyForm index
			int anum;
			string s;
			istringstream iss(s_tmp);
			iss >> s >> anum;
			which = anum;
			
			//// save and set
			// extern var
			ALLdata& SSetr = SSet[which];
			System::String^ name = this->Text;
			SSetr.form_name = msclr::interop::marshal_as<string>(name);
			// textbox
			videoFilePath->Text = "點選右方按鈕選取影片";
			textBox1->Text = SSetr.speed.ToString();
			// picture box
			//pictureBox->Size = System::Drawing::Size(667, 405);// will broken
			//pictureBox->ClientSize = System::Drawing::Size(667, 405);// will broken
			// trackBar
			videoTrackbar->Size = System::Drawing::Size(400, 0);// the height not work
			// static
			//static int test = 0;
			//test++;
			//MessageBox::Show(test.ToString());
		}

		//// SELECT
		private: System::Void selectVideo_Click(System::Object^  sender, System::EventArgs^  e) {  //Select files.
			//// var
			ALLdata& SSetr = SSet[which];
			// reset var
			//SSetr.video_filename = "";

			//// openFileDialog
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog;
			//openFileDialog->Filter = "Video Files (*.mp4;*.avi;*.mpeg)|*.mp4;*.avi;*.mpeg|All files (*.*)|*.*";
			openFileDialog->Filter = "MP4|*.mp4";
			openFileDialog->FileName = "";
			openFileDialog->FilterIndex = 1;
			openFileDialog->RestoreDirectory = true;

			//// get video path and video name
			System::String^ FilePath;
			string standardString;
			string extra_file;
			// get video path name
			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				FilePath = openFileDialog->FileName;
				standardString = msclr::interop::marshal_as<string>(FilePath);
			}
			// extract_Filename
			extra_file = extract_Filename(standardString);

			//// if a video?
			if (!is_video_file(standardString)) {
				//// reset and return
				//MessageBox::Show("影片檔請選擇mp4,avi,mpeg,rmvb");
				MessageBox::Show("影片檔請選擇mp4");
				videoFilePath->Text = "點選右方按鈕選取影片";
				return;
			}
			else {
				//// save file path and file name
				videoFilePath->Text = FilePath;
				SSetr.video_path = standardString;
				SSetr.video_filename = extra_file;
			}

			//// creating folder
			string o = "all_data";
			o += ("\\" + extra_file);
			// if the directory is not exist, create one
			DirectoryInfo^ di = gcnew System::IO::DirectoryInfo(gcnew System::String(o.c_str()));
			if (!di->Exists) {
				// folder root
				di = System::IO::Directory::CreateDirectory(gcnew System::String(o.c_str()));
			}
			// otherwise
			else {
				//// notify
				MessageBox::Show("影片已經有選取過");
				
				//// clean contents
				for each(System::IO::DirectoryInfo^ dir in di->GetDirectories())
				{
					for each(System::IO::FileInfo^ file in dir->GetFiles())
					{
						file->Delete();
					}
				}
			}

			//// deteremined video readable?
			if (is_cap_open() == false) {
				MessageBox::Show("找不到影片檔案");
				//// reset
				// reset play flag
				playable = false;
				// reset button
				playVideo->Enabled = false;
			}
			else {
				//// set
				// set play flag
				playable = true;
				// set button
				playVideo->Enabled = true;

				//// display frame
				display(1);
			}
		}

		//// PLAY
		private: System::Void playVideo_Click(System::Object^  sender, System::EventArgs^  e) {
			//// assigning button
			selectVideo->Enabled = false;
			playVideo->Enabled = false;
			Only_Pause_Click->Enabled = true;
			stopPlayButton->Enabled = true;

			//// initial play setting
			if (is_cap_open() == true) {
				play_initial();
				start_cap();
			}
		}

		//// PAUSE
		private:  System::Void OnlyPause(System::Object^ sender, System::EventArgs^ e) {
			//// assigning button
			Only_Pause_Click->Enabled = false;
			Continu_Click->Enabled = true;
			stopPlayButton->Enabled = false;

			//// pause video thread
			pause_cap();
		}

		//// CONTINUE
		private: System::Void Continue(System::Object^  sender, System::EventArgs^  e) {
			//// assigning button
			Only_Pause_Click->Enabled = true;
			Continu_Click->Enabled = false;
			stopPlayButton->Enabled = true;

			//// continue thread
			continue_cap();
		}

		//// STOP
		private: System::Void stopPlayButton_Click(System::Object^  sender, System::EventArgs^  e) {
			//// reset button
			ResetPlay();

			//// stop the video thread
			stop_cap();
		}

		//// SPEED UP
		private: System::Void SpeedUp(System::Object^  sender, System::EventArgs^  e) {
			//// var
			ALLdata& SSetr = SSet[which];

			//// increase
			SSetr.speed++;
			if (SSetr.speed > 9) {// maximum speed 9, or you can change
				SSetr.speed = 1;
			}

			//// show in textbox
			textBox1->Text = SSetr.speed.ToString();
		}

		//// SROLL
		private: System::Void Scroll(System::Object^  sender, System::EventArgs^  e) {
			//// var
			ALLdata& SSetr = SSet[which];
			
			//// only can sroll when it is pausing
			//if (!pasue_frame && (playVideo->Enabled == false)) {
			if (!pasue_frame) {
				return;
			}

			//// set trackbar
			SSetr.framePos = videoTrackbar->Value;

			//// display frame
			display(1);
		}

		//// CLOSE FROM
		private: System::Void Form_Closing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
		{
			//// var
			//ALLdata& SSetr = SSet[which];

			//// stop threading
			stop_cap();

			//// set the close flag?
			closeproperty = false;
		}

	};

}

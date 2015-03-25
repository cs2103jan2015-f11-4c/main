#pragma once
#include <iostream>
#include "Calendified.h"
#include "logic.h"
#include "parser.h"
#include "storage.h"



namespace UI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CalendifiedGUI
	/// </summary>
	public ref class CalendifiedGUI : public System::Windows::Forms::Form
	{

	public:
		int toggleCount;
		void toggle(){
			if(toggleCount ==0){
				 toggleCount = 1;
				 toggleBox_Calendified->BorderStyle = BorderStyle::Fixed3D;
				 toggleBox_Calendified->Visible = false;
				 toggleBox_ListView->Visible = true;
				 richTextBox1->Visible = false;
				 mainBg->Visible=false;
				 mainBg2->Visible=true;
				 richTextBox2->Visible = true;
				 richTextBox2->Text = richTextBox1->Text;
				 richTextBox2->BackColor = System::Drawing::Color::White;	
				 label_status->Text = "List View Toggled!";
			 }else{
				 toggleCount = 0;
				 toggleBox_Calendified->BorderStyle =  BorderStyle::None;
				 toggleBox_Calendified->Visible = true;
				 toggleBox_ListView->Visible = false;
				 richTextBox2->Visible = false;
				 mainBg2->Visible=false;
				 richTextBox1->Visible = true;
				 richTextBox1->Text = richTextBox2->Text;
				 richTextBox2->BackColor = System::Drawing::Color::Red;
				 mainBg->Visible  = true;	
				 label_status->Text = "Calendified View Toggled!";
			 }
		}
		CalendifiedGUI(void)
		{
			InitializeComponent();
			toggleCount = 0;
			currentTime->Start();
			//
			//TODO: Add the constructor code here
			//
		}	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CalendifiedGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	protected: 


	private: System::Windows::Forms::RichTextBox^  commandBox;



	private: System::Windows::Forms::Button^  button_enter;
	private: System::Windows::Forms::Label^  label_status;



	private: System::Windows::Forms::Label^  lbLengend;


	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PictureBox^  toggleBox_Calendified;

	private: System::Windows::Forms::PictureBox^  notifyBox;


	private: System::Windows::Forms::PictureBox^  mainBg;



	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::PictureBox^  pictureBox_Undo;
	private: System::Windows::Forms::PictureBox^  pictureBox_Redo;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  commandHelpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  typingAToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  commandGuidelinesToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^  mainBg2;
	private: System::Windows::Forms::PictureBox^  toggleBox_ListView;
	private: System::Windows::Forms::Timer^  currentTime;
	private: System::Windows::Forms::Label^  label_currentTime;

	private: System::ComponentModel::IContainer^  components;




	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CalendifiedGUI::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->commandBox = (gcnew System::Windows::Forms::RichTextBox());
			this->button_enter = (gcnew System::Windows::Forms::Button());
			this->label_status = (gcnew System::Windows::Forms::Label());
			this->lbLengend = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toggleBox_Calendified = (gcnew System::Windows::Forms::PictureBox());
			this->notifyBox = (gcnew System::Windows::Forms::PictureBox());
			this->mainBg = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox_Undo = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_Redo = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->commandHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->typingAToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->commandGuidelinesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainBg2 = (gcnew System::Windows::Forms::PictureBox());
			this->toggleBox_ListView = (gcnew System::Windows::Forms::PictureBox());
			this->currentTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_currentTime = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_Calendified))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Undo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Redo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_ListView))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::Color::Black;
			this->richTextBox1->Location = System::Drawing::Point(25, 73);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(611, 320);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// commandBox
			// 
			this->commandBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandBox->Location = System::Drawing::Point(104, 424);
			this->commandBox->Name = L"commandBox";
			this->commandBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Horizontal;
			this->commandBox->Size = System::Drawing::Size(430, 51);
			this->commandBox->TabIndex = 0;
			this->commandBox->Text = L"<Insert Your Command Here>";
			this->commandBox->Enter += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Enter);
			this->commandBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CalendifiedGUI::commandBox_KeyDown);
			this->commandBox->Leave += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Leave);
			// 
			// button_enter
			// 
			this->button_enter->BackColor = System::Drawing::Color::White;
			this->button_enter->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_enter->ForeColor = System::Drawing::Color::Red;
			this->button_enter->Location = System::Drawing::Point(531, 424);
			this->button_enter->Name = L"button_enter";
			this->button_enter->Size = System::Drawing::Size(60, 51);
			this->button_enter->TabIndex = 1;
			this->button_enter->Text = L"Enter";
			this->button_enter->UseVisualStyleBackColor = false;
			// 
			// label_status
			// 
			this->label_status->AutoSize = true;
			this->label_status->BackColor = System::Drawing::Color::White;
			this->label_status->Font = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_status->ForeColor = System::Drawing::Color::Red;
			this->label_status->Location = System::Drawing::Point(100, 481);
			this->label_status->Name = L"label_status";
			this->label_status->Size = System::Drawing::Size(197, 24);
			this->label_status->TabIndex = 7;
			this->label_status->Text = L"Welcome to Calendified!";
			// 
			// lbLengend
			// 
			this->lbLengend->AutoSize = true;
			this->lbLengend->BackColor = System::Drawing::Color::White;
			this->lbLengend->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbLengend->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbLengend->Location = System::Drawing::Point(125, 396);
			this->lbLengend->Name = L"lbLengend";
			this->lbLengend->Size = System::Drawing::Size(417, 20);
			this->lbLengend->TabIndex = 8;
			this->lbLengend->Text = L" Legend: && - Title, $ - Time, % - Date, @ - Location, # - Description";
			// 
			// toggleBox_Calendified
			// 
			this->toggleBox_Calendified->BackColor = System::Drawing::Color::White;
			this->toggleBox_Calendified->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toggleBox_Calendified.BackgroundImage")));
			this->toggleBox_Calendified->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->toggleBox_Calendified->InitialImage = nullptr;
			this->toggleBox_Calendified->Location = System::Drawing::Point(393, 481);
			this->toggleBox_Calendified->Name = L"toggleBox_Calendified";
			this->toggleBox_Calendified->Size = System::Drawing::Size(44, 35);
			this->toggleBox_Calendified->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->toggleBox_Calendified->TabIndex = 10;
			this->toggleBox_Calendified->TabStop = false;
			this->toggleBox_Calendified->Click += gcnew System::EventHandler(this, &CalendifiedGUI::toggleBox_Click);
			// 
			// notifyBox
			// 
			this->notifyBox->BackColor = System::Drawing::Color::White;
			this->notifyBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"notifyBox.Image")));
			this->notifyBox->Location = System::Drawing::Point(447, 481);
			this->notifyBox->Name = L"notifyBox";
			this->notifyBox->Size = System::Drawing::Size(44, 35);
			this->notifyBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->notifyBox->TabIndex = 11;
			this->notifyBox->TabStop = false;
			this->notifyBox->Click += gcnew System::EventHandler(this, &CalendifiedGUI::notifyBox_Click);
			// 
			// mainBg
			// 
			this->mainBg->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mainBg.Image")));
			this->mainBg->Location = System::Drawing::Point(-6, 3);
			this->mainBg->Name = L"mainBg";
			this->mainBg->Size = System::Drawing::Size(668, 542);
			this->mainBg->TabIndex = 13;
			this->mainBg->TabStop = false;
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::White;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox2->ForeColor = System::Drawing::Color::Red;
			this->richTextBox2->Location = System::Drawing::Point(53, 27);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(583, 366);
			this->richTextBox2->TabIndex = 15;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Visible = false;
			// 
			// pictureBox_Undo
			// 
			this->pictureBox_Undo->BackColor = System::Drawing::Color::White;
			this->pictureBox_Undo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox_Undo.BackgroundImage")));
			this->pictureBox_Undo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox_Undo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_Undo->Location = System::Drawing::Point(497, 481);
			this->pictureBox_Undo->Name = L"pictureBox_Undo";
			this->pictureBox_Undo->Size = System::Drawing::Size(45, 35);
			this->pictureBox_Undo->TabIndex = 16;
			this->pictureBox_Undo->TabStop = false;
			// 
			// pictureBox_Redo
			// 
			this->pictureBox_Redo->BackColor = System::Drawing::Color::White;
			this->pictureBox_Redo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox_Redo.BackgroundImage")));
			this->pictureBox_Redo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox_Redo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pictureBox_Redo->Location = System::Drawing::Point(548, 481);
			this->pictureBox_Redo->Name = L"pictureBox_Redo";
			this->pictureBox_Redo->Size = System::Drawing::Size(43, 35);
			this->pictureBox_Redo->TabIndex = 17;
			this->pictureBox_Redo->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox1->Location = System::Drawing::Point(53, 430);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(44, 35);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 18;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &CalendifiedGUI::pictureBox1_MouseEnter);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->commandHelpToolStripMenuItem, 
				this->typingAToolStripMenuItem, this->commandGuidelinesToolStripMenuItem});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(190, 70);
			this->contextMenuStrip1->MouseLeave += gcnew System::EventHandler(this, &CalendifiedGUI::contextMenuStrip1_MouseLeave);
			// 
			// commandHelpToolStripMenuItem
			// 
			this->commandHelpToolStripMenuItem->Name = L"commandHelpToolStripMenuItem";
			this->commandHelpToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->commandHelpToolStripMenuItem->Text = L"Getting Started";
			// 
			// typingAToolStripMenuItem
			// 
			this->typingAToolStripMenuItem->Name = L"typingAToolStripMenuItem";
			this->typingAToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->typingAToolStripMenuItem->Text = L"Entering a Command";
			// 
			// commandGuidelinesToolStripMenuItem
			// 
			this->commandGuidelinesToolStripMenuItem->Name = L"commandGuidelinesToolStripMenuItem";
			this->commandGuidelinesToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->commandGuidelinesToolStripMenuItem->Text = L"Command Guidelines";
			// 
			// mainBg2
			// 
			this->mainBg2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mainBg2.Image")));
			this->mainBg2->Location = System::Drawing::Point(-6, 8);
			this->mainBg2->Name = L"mainBg2";
			this->mainBg2->Size = System::Drawing::Size(668, 542);
			this->mainBg2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->mainBg2->TabIndex = 19;
			this->mainBg2->TabStop = false;
			// 
			// toggleBox_ListView
			// 
			this->toggleBox_ListView->BackColor = System::Drawing::Color::White;
			this->toggleBox_ListView->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toggleBox_ListView.BackgroundImage")));
			this->toggleBox_ListView->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->toggleBox_ListView->Location = System::Drawing::Point(393, 481);
			this->toggleBox_ListView->Name = L"toggleBox_ListView";
			this->toggleBox_ListView->Size = System::Drawing::Size(44, 35);
			this->toggleBox_ListView->TabIndex = 20;
			this->toggleBox_ListView->TabStop = false;
			this->toggleBox_ListView->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CalendifiedGUI::toggleBox_ListView_MouseClick);
			// 
			// currentTime
			// 
			this->currentTime->Tick += gcnew System::EventHandler(this, &CalendifiedGUI::currentTime_Tick);
			// 
			// label_currentTime
			// 
			this->label_currentTime->AutoSize = true;
			this->label_currentTime->BackColor = System::Drawing::Color::White;
			this->label_currentTime->Font = (gcnew System::Drawing::Font(L"Gadugi", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_currentTime->ForeColor = System::Drawing::Color::Blue;
			this->label_currentTime->Location = System::Drawing::Point(394, 516);
			this->label_currentTime->Name = L"label_currentTime";
			this->label_currentTime->Size = System::Drawing::Size(97, 17);
			this->label_currentTime->TabIndex = 21;
			this->label_currentTime->Text = L"Current Time: ";
			// 
			// CalendifiedGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(659, 546);
			this->Controls->Add(this->label_currentTime);
			this->Controls->Add(this->toggleBox_Calendified);
			this->Controls->Add(this->toggleBox_ListView);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox_Redo);
			this->Controls->Add(this->pictureBox_Undo);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->notifyBox);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->lbLengend);
			this->Controls->Add(this->label_status);
			this->Controls->Add(this->button_enter);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->mainBg);
			this->Controls->Add(this->mainBg2);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"CalendifiedGUI";
			this->Text = L"Calendified";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &CalendifiedGUI::CalendifiedGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_Calendified))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Undo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Redo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_ListView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void commandBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if(e->KeyCode==Keys::Enter){
				 
				 //system::string -> std::string
				 char buffer[999];
				 sprintf(buffer,"%s",commandBox->Text);
				 std::string inputCommandBox(buffer);
				 logic newLogic;
				 std::string logicResult = newLogic.readCommand(inputCommandBox);
				 richTextBox1->Text = gcnew String(logicResult.c_str());
				 richTextBox2->Text = gcnew String(logicResult.c_str());				 
				 commandBox->ResetText();				 				 				
				 Windows::Forms::SendKeys::Send("{BACKSPACE}");
				 if(richTextBox1->Text =="Toggled!" || richTextBox2->Text == "Toggled!"){
					 toggle();
				 }
				 /*MessageBoxShowTest
				 std::string newString =newLogic.getDateAndTime(); 
				 String^ str2 = gcnew String(newString.c_str());
				 MessageBox::Show(str2);
				 */

				 /*
				 //std::string ->system::string
				 String^ systemString = gcnew String(inputCommandBox.c_str()); 
				 MessageBox::Show(systemString); 
				 */

			 }
		 }
private: System::Void CalendifiedGUI_Load(System::Object^  sender, System::EventArgs^  e) {
			 UI::CalendifiedGUI::ActiveControl = this->commandBox;
			 
			 storage newStorage;
			 std::string directory;
			 directory = newStorage.retrieveFilePath();
			 if(directory == ""){
					 IO::Stream^ mystream;
					 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

					 saveFileDialog1->InitialDirectory = "c://";
					 saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
					 saveFileDialog1->FilterIndex = 2;
					 saveFileDialog1->RestoreDirectory = true;
					 saveFileDialog1->FileName = "";

					 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 char fileName[999];
						 sprintf(fileName,"%s",saveFileDialog1->FileName);
						 newStorage.saveInformation(fileName);
						 newStorage.createFile(fileName);
						 //IO::StreamWriter^ file = gcnew IO::StreamWriter(saveFileDialog1->FileName);
						 //file->WriteLine("Calendified Database.");
						 //file->Close();
					 }
				 }



				 notifyBox->Text="0!";//need storage return num file;
				 
				 //Own notes
				 /*
				 IO::Stream^ myStream;
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 2;
				 openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
				 if ( (myStream = openFileDialog1->OpenFile()) != nullptr )
				 {
				 // Insert code to read the stream here.
				 myStream->Close();
				 }
				 }
				 */
		 }
private: System::Void commandBox_Leave(System::Object^  sender, System::EventArgs^  e) {
			 this->commandBox->Text="<Enter Your Command Here>";
		 }
private: System::Void commandBox_Enter(System::Object^  sender, System::EventArgs^  e) {
			 this->commandBox->ResetText();
		 }
private: System::Void notifyBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 notifyBox->BorderStyle = BorderStyle::Fixed3D;
			 logic newLogic;
			 std::string logicResult = newLogic.readCommand("display");
			 richTextBox1->Text = gcnew String(logicResult.c_str());
			 richTextBox2->Text = gcnew String(logicResult.c_str());
			 _sleep(500);
			 notifyBox->BorderStyle = BorderStyle::None;			 
		 }
private: System::Void toggleBox_Click(System::Object^  sender, System::EventArgs^  e) {
			 toggle();
		 }

private: System::Void pictureBox1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			 contextMenuStrip1->Show(pictureBox1,0,pictureBox1->Height);
		 }
private: System::Void toggleBox_ListView_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			 toggle();
		 }
private: System::Void contextMenuStrip1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			 contextMenuStrip1->Hide();
		 }
private: System::Void currentTime_Tick(System::Object^  sender, System::EventArgs^  e) {
			 DateTime datetime = DateTime::Now;
			 this->label_currentTime->Text = "Current Time: " + datetime.ToString();
		 }
};
}
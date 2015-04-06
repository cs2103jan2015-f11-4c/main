#pragma once
#include <iostream>
#include "Calendified.h"
#include "logic.h"


std::string const REQUEST_CHANGE_LOCATION =
	"/change location";

int const MAX_PATH = 999999;
std::string const HELP_MAIN_MENU =
	"/Help/Help_Main_Menu.html";
std::string const HELP_ADD =
	"/Help/Help_Add.html";
std::string const HELP_DELETE =
	"/Help/Help_Delete.html";
std::string const HELP_SEARCH =
	"/Help/Help_Search.html";
std::string const HELP_EDIT =
	"/Help/Help_Edit.html";
std::string const HELP_DONE =
	"/Help/Help_Done.html";
std::string const HELP_UNDO_REDO =
	"/Help/Help_Undo_Redo.html";
std::string const HELP_LOCATION_DATABASE = 
	"/Help/Help_Location.html";
std::string const HELP_BUTTONS =
	"/Help/Help_Buttons.html";
/*
1.	Add
2.	Delete
3.	View / Search
4.	Edit
5.	Mark Task as Done
6.	Undo / Redo
7.	Changing Location of Database
8.	Buttons
*/
std::string const HELP_COMMAND_BACK =
	"/back";
std::string const HELP_COMMAND_ADD =
	"/1";
std::string const HELP_COMMAND_DELETE =
	"/2";
std::string const HELP_COMMAND_VIEW_SEARCH =
	"/3";
std::string const HELP_COMMAND_EDIT =
	"/4";
std::string const HELP_COMMAND_DONE =
	"/5";
std::string const HELP_COMMAND_UNDO_OR_REDO =
	"/6";
std::string const HELP_COMMAND_LOCATION_DATABASE =
	"/7";
std::string const HELP_COMMAND_BUTTONS =
	"/8";
std::string const HELP_COMMAND_HELP =
	"/help";
std::string const HELP_COMMAND_CLOSE =
	"/close";


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
		int flipCount;
	public: void toggle(){
				if(toggleCount ==0){
					toggleCount = 1;
					toggleBox_Calendified->BorderStyle = BorderStyle::Fixed3D;
					toggleBox_Calendified->Visible = false;
					toggleBox_ListView->Visible = true;
					richTextBox_CalendifiedViewL->Visible = false;
					richTextBox_CalendifiedViewR->Visible = false;
					mainBg->Visible=false;
					mainBg2->Visible=true;
					richTextBox_ListView->Visible = true;
					richTextBox_CalendifiedViewL->ResetText();
					richTextBox_CalendifiedViewR->ResetText();
					logic newLogic;
					std::string logicResult = newLogic.readCommand("display",flipCount);
					std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					updateListView(displayResults);
					label_status->Text = "List View Toggled!";
				}else{
					toggleCount = 0;
					toggleBox_Calendified->BorderStyle =  BorderStyle::None;
					toggleBox_Calendified->Visible = true;
					toggleBox_ListView->Visible = false;
					richTextBox_ListView->Visible = false;
					mainBg2->Visible=false;
					richTextBox_CalendifiedViewL->Visible = true;
					richTextBox_CalendifiedViewR->Visible = true;
					richTextBox_ListView->ResetText();
					logic newLogic;			
					std::string logicResult = newLogic.readCommand("display",flipCount);
					std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					updateCalendifiedView(displayResults);
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
				String^ getHTMLFilePath(std::string action);
				void changeDirectory();
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
	private: System::Windows::Forms::RichTextBox^  richTextBox_CalendifiedViewL;
	private: System::Windows::Forms::RichTextBox^  richTextBox_CalendifiedViewR;
	protected: 

	protected: 


	private: System::Windows::Forms::RichTextBox^  commandBox;




	private: System::Windows::Forms::Label^  label_status;



	private: System::Windows::Forms::Label^  lbLengend;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PictureBox^  toggleBox_Calendified;

	private: System::Windows::Forms::PictureBox^  notifyBox;


	private: System::Windows::Forms::PictureBox^  mainBg;



	private: System::Windows::Forms::RichTextBox^  richTextBox_ListView;
	private: System::Windows::Forms::PictureBox^  pictureBox_Undo;
	private: System::Windows::Forms::PictureBox^  pictureBox_Redo;
	private: System::Windows::Forms::PictureBox^  pictureBox_Help;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip_HelpContent;
	private: System::Windows::Forms::ToolStripMenuItem^  commandHelpToolStripMenuItem;


	private: System::Windows::Forms::PictureBox^  mainBg2;
	private: System::Windows::Forms::PictureBox^  toggleBox_ListView;
	private: System::Windows::Forms::Timer^  currentTime;
	private: System::Windows::Forms::Label^  label_currentTime;
	private: System::Windows::Forms::ToolStripMenuItem^  changeDatabaseLocationToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
	private: System::Windows::Forms::WebBrowser^  webBrowser_Help;
	private: System::Windows::Forms::PictureBox^  pictureBox_CalendifiedFlipping;
	private: System::Windows::Forms::Timer^  timerCalendifiedFlip;
	private: System::Windows::Forms::PictureBox^  pictureBox_ListViewFlipping;
	private: System::Windows::Forms::Timer^  timerListViewFlip;



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
			this->richTextBox_CalendifiedViewL = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox_CalendifiedViewR = (gcnew System::Windows::Forms::RichTextBox());
			this->commandBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label_status = (gcnew System::Windows::Forms::Label());
			this->lbLengend = (gcnew System::Windows::Forms::Label());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toggleBox_Calendified = (gcnew System::Windows::Forms::PictureBox());
			this->notifyBox = (gcnew System::Windows::Forms::PictureBox());
			this->mainBg = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox_ListView = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox_Undo = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_Redo = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox_Help = (gcnew System::Windows::Forms::PictureBox());
			this->contextMenuStrip_HelpContent = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->changeDatabaseLocationToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->commandHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mainBg2 = (gcnew System::Windows::Forms::PictureBox());
			this->toggleBox_ListView = (gcnew System::Windows::Forms::PictureBox());
			this->currentTime = (gcnew System::Windows::Forms::Timer(this->components));
			this->label_currentTime = (gcnew System::Windows::Forms::Label());
			this->webBrowser_Help = (gcnew System::Windows::Forms::WebBrowser());
			this->pictureBox_CalendifiedFlipping = (gcnew System::Windows::Forms::PictureBox());
			this->timerCalendifiedFlip = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox_ListViewFlipping = (gcnew System::Windows::Forms::PictureBox());
			this->timerListViewFlip = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_Calendified))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Undo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Redo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Help))->BeginInit();
			this->contextMenuStrip_HelpContent->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_ListView))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_CalendifiedFlipping))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_ListViewFlipping))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox_CalendifiedViewL
			// 
			this->richTextBox_CalendifiedViewL->BackColor = System::Drawing::Color::White;
			this->richTextBox_CalendifiedViewL->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox_CalendifiedViewL->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox_CalendifiedViewL->ForeColor = System::Drawing::Color::Black;
			this->richTextBox_CalendifiedViewL->Location = System::Drawing::Point(25, 73);
			this->richTextBox_CalendifiedViewL->Name = L"richTextBox_CalendifiedViewL";
			this->richTextBox_CalendifiedViewL->ReadOnly = true;
			this->richTextBox_CalendifiedViewL->Size = System::Drawing::Size(305, 320);
			this->richTextBox_CalendifiedViewL->TabIndex = 0;
			this->richTextBox_CalendifiedViewL->Text = L"";
			// 
			// richTextBox_CalendifiedViewR
			// 
			this->richTextBox_CalendifiedViewR->BackColor = System::Drawing::Color::White;
			this->richTextBox_CalendifiedViewR->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox_CalendifiedViewR->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox_CalendifiedViewR->ForeColor = System::Drawing::Color::Black;
			this->richTextBox_CalendifiedViewR->Location = System::Drawing::Point(331, 73);
			this->richTextBox_CalendifiedViewR->Name = L"richTextBox_CalendifiedViewR";
			this->richTextBox_CalendifiedViewR->ReadOnly = true;
			this->richTextBox_CalendifiedViewR->Size = System::Drawing::Size(305, 320);
			this->richTextBox_CalendifiedViewR->TabIndex = 0;
			this->richTextBox_CalendifiedViewR->Text = L"";
			// 
			// commandBox
			// 
			this->commandBox->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->commandBox->Location = System::Drawing::Point(104, 424);
			this->commandBox->Name = L"commandBox";
			this->commandBox->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Horizontal;
			this->commandBox->Size = System::Drawing::Size(487, 51);
			this->commandBox->TabIndex = 0;
			this->commandBox->Text = L"<Insert Your Command Here>";
			this->commandBox->Enter += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Enter);
			this->commandBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CalendifiedGUI::commandBox_KeyDown);
			this->commandBox->Leave += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Leave);
			// 
			// label_status
			// 
			this->label_status->AutoSize = true;
			this->label_status->BackColor = System::Drawing::Color::White;
			this->label_status->Font = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 17.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label_status->ForeColor = System::Drawing::Color::Red;
			this->label_status->Location = System::Drawing::Point(100, 481);
			this->label_status->Name = L"label_status";
			this->label_status->Size = System::Drawing::Size(238, 29);
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
			this->lbLengend->Size = System::Drawing::Size(319, 20);
			this->lbLengend->TabIndex = 8;
			this->lbLengend->Text = L" Legend: && - Title, $ - Time, % - Date, @ - Location";
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
			// richTextBox_ListView
			// 
			this->richTextBox_ListView->BackColor = System::Drawing::Color::White;
			this->richTextBox_ListView->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox_ListView->Font = (gcnew System::Drawing::Font(L"Verdana", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->richTextBox_ListView->ForeColor = System::Drawing::Color::Black;
			this->richTextBox_ListView->Location = System::Drawing::Point(53, 27);
			this->richTextBox_ListView->Name = L"richTextBox_ListView";
			this->richTextBox_ListView->ReadOnly = true;
			this->richTextBox_ListView->Size = System::Drawing::Size(583, 366);
			this->richTextBox_ListView->TabIndex = 15;
			this->richTextBox_ListView->Text = L"";
			this->richTextBox_ListView->Visible = false;
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
			this->pictureBox_Undo->Click += gcnew System::EventHandler(this, &CalendifiedGUI::pictureBox_Undo_Click);
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
			// pictureBox_Help
			// 
			this->pictureBox_Help->BackColor = System::Drawing::Color::White;
			this->pictureBox_Help->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox_Help.BackgroundImage")));
			this->pictureBox_Help->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->pictureBox_Help->Location = System::Drawing::Point(53, 430);
			this->pictureBox_Help->Name = L"pictureBox_Help";
			this->pictureBox_Help->Size = System::Drawing::Size(44, 35);
			this->pictureBox_Help->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox_Help->TabIndex = 18;
			this->pictureBox_Help->TabStop = false;
			this->pictureBox_Help->MouseEnter += gcnew System::EventHandler(this, &CalendifiedGUI::pictureBox_Help_MouseEnter);
			// 
			// contextMenuStrip_HelpContent
			// 
			this->contextMenuStrip_HelpContent->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->changeDatabaseLocationToolStripMenuItem1, 
				this->toolStripSeparator2, this->commandHelpToolStripMenuItem});
			this->contextMenuStrip_HelpContent->Name = L"contextMenuStrip1";
			this->contextMenuStrip_HelpContent->Size = System::Drawing::Size(216, 54);
			this->contextMenuStrip_HelpContent->MouseLeave += gcnew System::EventHandler(this, &CalendifiedGUI::contextMenuStrip_HelpContent_MouseLeave);
			// 
			// changeDatabaseLocationToolStripMenuItem1
			// 
			this->changeDatabaseLocationToolStripMenuItem1->Name = L"changeDatabaseLocationToolStripMenuItem1";
			this->changeDatabaseLocationToolStripMenuItem1->Size = System::Drawing::Size(215, 22);
			this->changeDatabaseLocationToolStripMenuItem1->Text = L"Change Database Location";
			this->changeDatabaseLocationToolStripMenuItem1->Click += gcnew System::EventHandler(this, &CalendifiedGUI::changeDatabaseLocationToolStripMenuItem1_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(212, 6);
			// 
			// commandHelpToolStripMenuItem
			// 
			this->commandHelpToolStripMenuItem->Name = L"commandHelpToolStripMenuItem";
			this->commandHelpToolStripMenuItem->Size = System::Drawing::Size(215, 22);
			this->commandHelpToolStripMenuItem->Text = L"Help";
			this->commandHelpToolStripMenuItem->Click += gcnew System::EventHandler(this, &CalendifiedGUI::commandHelpToolStripMenuItem_Click);
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
			// webBrowser_Help
			// 
			this->webBrowser_Help->Location = System::Drawing::Point(38, 73);
			this->webBrowser_Help->MinimumSize = System::Drawing::Size(20, 20);
			this->webBrowser_Help->Name = L"webBrowser_Help";
			this->webBrowser_Help->Size = System::Drawing::Size(607, 320);
			this->webBrowser_Help->TabIndex = 22;
			// 
			// pictureBox_CalendifiedFlipping
			// 
			this->pictureBox_CalendifiedFlipping->Location = System::Drawing::Point(22, 74);
			this->pictureBox_CalendifiedFlipping->Name = L"pictureBox_CalendifiedFlipping";
			this->pictureBox_CalendifiedFlipping->Size = System::Drawing::Size(623, 326);
			this->pictureBox_CalendifiedFlipping->TabIndex = 22;
			this->pictureBox_CalendifiedFlipping->TabStop = false;
			this->pictureBox_CalendifiedFlipping->Visible = false;
			// 
			// timerCalendifiedFlip
			// 
			this->timerCalendifiedFlip->Interval = 1;
			this->timerCalendifiedFlip->Tick += gcnew System::EventHandler(this, &CalendifiedGUI::timerCalendifiedFlip_Tick);
			// 
			// pictureBox_ListViewFlipping
			// 
			this->pictureBox_ListViewFlipping->Location = System::Drawing::Point(52, 29);
			this->pictureBox_ListViewFlipping->Name = L"pictureBox_ListViewFlipping";
			this->pictureBox_ListViewFlipping->Size = System::Drawing::Size(593, 366);
			this->pictureBox_ListViewFlipping->TabIndex = 23;
			this->pictureBox_ListViewFlipping->TabStop = false;
			this->pictureBox_ListViewFlipping->Visible = false;
			// 
			// timerListViewFlip
			// 
			this->timerListViewFlip->Interval = 1;
			this->timerListViewFlip->Tick += gcnew System::EventHandler(this, &CalendifiedGUI::timerListViewFlip_Tick);
			// 
			// CalendifiedGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->ClientSize = System::Drawing::Size(663, 546);
			this->Controls->Add(this->webBrowser_Help);
			this->Controls->Add(this->pictureBox_ListViewFlipping);
			this->Controls->Add(this->pictureBox_CalendifiedFlipping);
			this->Controls->Add(this->label_currentTime);
			this->Controls->Add(this->notifyBox);
			this->Controls->Add(this->richTextBox_CalendifiedViewL);
			this->Controls->Add(this->richTextBox_CalendifiedViewR);
			this->Controls->Add(this->richTextBox_ListView);
			this->Controls->Add(this->toggleBox_Calendified);
			this->Controls->Add(this->toggleBox_ListView);
			this->Controls->Add(this->pictureBox_Help);
			this->Controls->Add(this->pictureBox_Redo);
			this->Controls->Add(this->pictureBox_Undo);
			this->Controls->Add(this->lbLengend);
			this->Controls->Add(this->label_status);
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
			this->Load += gcnew System::EventHandler(this, &CalendifiedGUI::CalendifiedGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_Calendified))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Undo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Redo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_Help))->EndInit();
			this->contextMenuStrip_HelpContent->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox_ListView))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_CalendifiedFlipping))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox_ListViewFlipping))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//author A0125489U
	public: void CalendifiedGUI::highlightRichTextBoxContent(System::Windows::Forms::RichTextBox ^thisRichTextBox, std::string searchString){
				thisRichTextBox->Find(gcnew String(searchString.c_str()), 0 , thisRichTextBox->TextLength, RichTextBoxFinds::MatchCase);		
				if(searchString.compare("FLOAT")==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::Blue;
					thisRichTextBox->SelectionFont =(gcnew System::Drawing::Font(L"Harlow Solid", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));	
				}else{
					thisRichTextBox->SelectionColor = System::Drawing::Color::Red;
					thisRichTextBox->SelectionFont = (gcnew System::Drawing::Font(L"Harlow Solid Italic", 16.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));
				}
				thisRichTextBox->Select(0,0);
			}
			//author A0125489U
	public: void CalendifiedGUI::updateRichTextBoxContent(System::Windows::Forms::RichTextBox ^thisRichTextBox, std::string logicResult, std::string nextDayDate, std::string todayDate){
				std::string floatDate = "FLOAT";
				std::string viewResults ="Results:";
				//Highlight Today
				highlightRichTextBoxContent(thisRichTextBox,todayDate.c_str());
				//Highlight NextDay 
				highlightRichTextBoxContent(thisRichTextBox,nextDayDate.c_str());
				//Highlight Float Text
				highlightRichTextBoxContent(thisRichTextBox,floatDate.c_str());
				//Highlight keyword "Results:" if inputcommand is View
				if(logicResult.substr(0,8).compare(viewResults) ==0){
					highlightRichTextBoxContent(thisRichTextBox,viewResults);
				}
			}
			//author A0125489U
	public: void CalendifiedGUI::updateCalendifiedView(std::vector<std::string> displayResults){
				richTextBox_CalendifiedViewL->ResetText();
				richTextBox_CalendifiedViewR->ResetText();
				//Update CalendifiedView
				if(displayResults.size() == 3){ // Operations for ADD, EDIT, DELETE
					richTextBox_CalendifiedViewL->Text=gcnew String(displayResults[2].c_str());
				}else { //Operations for DISPLAY, VIEW
					richTextBox_CalendifiedViewL->Text = gcnew String(displayResults[2].c_str());
					richTextBox_CalendifiedViewR->Text = gcnew String(displayResults[3].c_str());
					updateRichTextBoxContent(richTextBox_CalendifiedViewL,displayResults[2],displayResults[1],displayResults[0]);
					updateRichTextBoxContent(richTextBox_CalendifiedViewR,displayResults[3],displayResults[1],displayResults[0]);
				}
			}
			//author A0125489U
	public: void CalendifiedGUI::updateListView(std::vector<std::string> displayResults){
				//Update Listview
				richTextBox_ListView->ResetText();
				richTextBox_ListView->Text = gcnew String(displayResults[2].c_str());
				updateRichTextBoxContent(richTextBox_ListView,displayResults[2],displayResults[1],displayResults[0]);
			}
			//author A0125489U
	private: System::Void commandBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 try {
					 if(e->KeyCode==Keys::Enter){
						 //system::string -> std::string
						 char buffer[999];
						 sprintf(buffer,"%s",commandBox->Text);
						 std::string inputCommandBox(buffer);

						 if(inputCommandBox.substr(0,1) == "/"){
							 if(inputCommandBox == HELP_COMMAND_BACK){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
							 }
							 if(inputCommandBox == HELP_COMMAND_ADD){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_ADD));
							 }
							 if(inputCommandBox == HELP_COMMAND_DELETE){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_DELETE));
							 }
							 if(inputCommandBox == HELP_COMMAND_VIEW_SEARCH){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_SEARCH));
							 }
							 if(inputCommandBox == HELP_COMMAND_EDIT){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_EDIT));
							 }
							 if(inputCommandBox == HELP_COMMAND_DONE){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_DONE));
							 }
							 if(inputCommandBox == HELP_COMMAND_UNDO_OR_REDO){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_UNDO_REDO));
							 }
							 if(inputCommandBox == HELP_COMMAND_LOCATION_DATABASE){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_LOCATION_DATABASE));
							 }
							 if(inputCommandBox == HELP_COMMAND_BUTTONS){
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_BUTTONS));
							 }
							 if(inputCommandBox == HELP_COMMAND_HELP){
								 if(toggleCount == 0){ //Calendified 
									 this->webBrowser_Help->Location = System::Drawing::Point(38, 73);
									 this->webBrowser_Help->Size = System::Drawing::Size(610, 320);
									 webBrowser_Help->Show();
								 }else{ //Listview
									 this->webBrowser_Help->Location = System::Drawing::Point(30, 73);
									 this->webBrowser_Help->Size = System::Drawing::Size(615, 280);
									 webBrowser_Help->Show();
								 }
								 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
							 }
							 if(inputCommandBox == HELP_COMMAND_BACK){
								 webBrowser_Help->Hide();
							 }
						 }else {
							 webBrowser_Help->Hide();
						 }

						 if(inputCommandBox == REQUEST_CHANGE_LOCATION){
							 changeDirectory();
						 }

						 logic newLogic;
						 std::vector<std::string> displayResults;

						 if(inputCommandBox.compare("flip")!=0 && inputCommandBox.compare("toggle")!=0){ //This statement resets the flipCount when no countinous flipping is detected
							 flipCount=0;
						 }
						 std::string displayResult = newLogic.readCommand(inputCommandBox,flipCount);

						 String^ updateStatus = gcnew String(displayResult.c_str());
						 if(!updateStatus->Contains("FLOAT")){ // This section renders for operation results: {DISPLAY,VIEW}
							 label_status-> Text =  updateStatus;
							 if(updateStatus=="Flipped!"){ //This statement renders for countinous flipping
								 flip();
								 flipCount++;
							 }
							 displayResults = newLogic.updateUI(newLogic.readCommand("display",flipCount),toggleCount,flipCount);	 
						 }else { //This section renders for operation results {ADD,DELETE,EDIT,FLIP,TOGGLE,UNDO}
							 displayResults = newLogic.updateUI(displayResult,toggleCount,flipCount);
						 }
						 if(toggleCount == 0){ //check for mode [calendified/list] view 
							 updateCalendifiedView(displayResults);
						 }else{
							 updateListView(displayResults);
						 }

						 commandBox->ResetText();				 				 				
						 Windows::Forms::SendKeys::Send("{BACKSPACE}");
						 if(label_status->Text =="Toggled!"){ 
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
				 } catch (const std::exception& e) {
					 String^ systemString = gcnew String(e.what()); 
					 MessageBox::Show(systemString);
				 }
			 }

	private: System::Void CalendifiedGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 UI::CalendifiedGUI::ActiveControl = this->commandBox;

				 logic newLogic;
				 std::string directory = newLogic.newStorage.retrieveFilePath();
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
						 newLogic.newStorage.saveInformation(fileName);
						 newLogic.newStorage.createFile(fileName);
						 //IO::StreamWriter^ file = gcnew IO::StreamWriter(saveFileDialog1->FileName);
						 //file->WriteLine("Calendified Database.");
						 //file->Close();
						 std::string logicResult = newLogic.readCommand("display",flipCount);
						 std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
						 if(toggleCount == 0){ //check for mode [calendified/list] view 
							 updateCalendifiedView(displayResults);
						 }else{
							 updateListView(displayResults);
						 }
					 }
					 webBrowser_Help->Show();
					 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
				 } else{
					 webBrowser_Help->Hide();
					 logic newLogic;			
					 std::string logicResult = newLogic.readCommand("display",flipCount);
					 std::vector<std::string> displayResults = newLogic.updateUI(newLogic.readCommand("display",flipCount),toggleCount,flipCount);
					 if(toggleCount == 0){ //check for mode [calendified/list] view 
						 updateCalendifiedView(displayResults);
					 }else{
						 //Update Listview
						 updateListView(displayResults);
					 }
				 }
				 notifyBox->Text="0!";//need storage return num file;
			 }
	private: System::Void commandBox_Leave(System::Object^  sender, System::EventArgs^  e) {
				 this->commandBox->Text="<Enter Your Command Here>";
			 }
	private: System::Void commandBox_Enter(System::Object^  sender, System::EventArgs^  e) {
				 this->commandBox->ResetText();
			 }
			 //author A0125489U
	private: System::Void notifyBox_Click(System::Object^  sender, System::EventArgs^  e) {
				 notifyBox->BorderStyle = BorderStyle::Fixed3D;
				 _sleep(500);
				 logic newLogic;			
				 flipCount=0;
				 std::string logicResult = newLogic.readCommand("display",flipCount);
				 std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
				 if(toggleCount == 0){ //check for mode [calendified/list] view 
					 updateCalendifiedView(displayResults);
				 }else{
					 //Update Listview
					 updateListView(displayResults);
				 }
				 notifyBox->BorderStyle = BorderStyle::None;			 
			 }
	private: System::Void toggleBox_Click(System::Object^  sender, System::EventArgs^  e) {
				 toggle();
			 }

	private: System::Void pictureBox_Help_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 contextMenuStrip_HelpContent->Show(pictureBox_Help,0,pictureBox_Help->Height);
			 }
	private: System::Void toggleBox_ListView_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 toggle();
			 }
	private: System::Void contextMenuStrip_HelpContent_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 contextMenuStrip_HelpContent->Hide();
			 }
	private: System::Void currentTime_Tick(System::Object^  sender, System::EventArgs^  e) {
				 DateTime datetime = DateTime::Now;
				 this->label_currentTime->Text = "Current Time: " + datetime.ToString();
			 }

	private: System::Void pictureBox_Undo_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
					 logic newLogic;
					 const std::string UNDO = "undo";
					 const std::string DISPLAY = "display";
					 flipCount=0;
					 std::string results = newLogic.readCommand(UNDO,flipCount);
					 String^ statusUpdate = gcnew String(results.c_str());
					 label_status->Text = statusUpdate;
					 std::string logicResult = newLogic.readCommand(DISPLAY,flipCount);
					 std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					 if(toggleCount == 0){ 
						 updateCalendifiedView(displayResults);
					 }else{
						 updateListView(displayResults);
					 }
				 } catch(const std::exception& e) {
					 String^ systemString = gcnew String(e.what()); 
					 MessageBox::Show(systemString);
				 }
			 }

	private: System::Void changeDatabaseLocationToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 changeDirectory();
			 }


			 String^ getHTMLFilePath(std::string htmlHelpDirectory){

				 char path[MAX_PATH];
				 _fullpath(path, ":\\" , MAX_PATH);
				 std::string directoryOfFolder(path);
				 int const size = directoryOfFolder.size();
				 directoryOfFolder = directoryOfFolder.substr(0,size-3);
				 std::string htmlDirectory = directoryOfFolder + htmlHelpDirectory;
				 return gcnew String(htmlDirectory.c_str());
			 }

			 void changeDirectory(){
				 logic newLogic; 
				 IO::Stream^ mystream;
				 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

				 saveFileDialog1->InitialDirectory = "c://";
				 saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
				 saveFileDialog1->FilterIndex = 2;
				 saveFileDialog1->RestoreDirectory = true;
				 saveFileDialog1->FileName = "";

				 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {
					 char newFileName[999];
					 sprintf(newFileName,"%s",saveFileDialog1->FileName);
					 newLogic.newStorage.transferDatabase(newFileName);
					 newLogic.newStorage.setFilePath(newFileName);
				 }
			 }

			 //@author A0125489U
	public: void flip(){
				if(toggleCount ==0){
					Graphics^ gfx = mainBg->CreateGraphics();
					Bitmap^ bmp = gcnew Bitmap(richTextBox_ListView->Width+40, richTextBox_ListView->Height-40);
					gfx = gfx->FromImage(bmp);
					gfx->CopyFromScreen(this->Location.X+30,this->Location.Y+105,0,0,this->Size);
					pictureBox_CalendifiedFlipping->Image=bmp;
					pictureBox_CalendifiedFlipping->Visible=true;
					timerCalendifiedFlip->Start();
				} else if(toggleCount==1){
					Graphics^ gfx = mainBg2->CreateGraphics();
					Bitmap^ bmp = gcnew Bitmap(richTextBox_ListView->Width+10, richTextBox_ListView->Height);
					gfx = gfx->FromImage(bmp);
					gfx->CopyFromScreen(this->Location.X+60,this->Location.Y+60,0,0,this->Size);
					pictureBox_ListViewFlipping->Image=bmp;
					pictureBox_ListViewFlipping->Visible=true;
					timerListViewFlip->Start();
				}
			}

			//@author A0125489U
			int timerCount;
	private: System::Void timerCalendifiedFlip_Tick(System::Object^  sender, System::EventArgs^  e) {
				 pictureBox_CalendifiedFlipping->SizeMode = PictureBoxSizeMode::StretchImage;
				 pictureBox_CalendifiedFlipping->Top -= 1;
				 pictureBox_CalendifiedFlipping->Height-=11;
				 timerCount++;
				 if(timerCount==30){
					 timerCalendifiedFlip->Stop();
					 pictureBox_CalendifiedFlipping->Top += 30;
					 pictureBox_CalendifiedFlipping->Height += 330;
					 timerCount =0;
					 pictureBox_CalendifiedFlipping->Visible=false;
				 }
			 }
			 //@author A0125489U
	private: System::Void timerListViewFlip_Tick(System::Object^  sender, System::EventArgs^  e) {
				 pictureBox_ListViewFlipping->SizeMode = PictureBoxSizeMode::StretchImage;
				 pictureBox_ListViewFlipping->Left -= 1;
				 pictureBox_ListViewFlipping->Width-=20;
				 timerCount++;
				 if(timerCount==30){
					 timerListViewFlip->Stop();
					 pictureBox_ListViewFlipping->Left += 30;
					 pictureBox_ListViewFlipping->Width += 600;
					 timerCount =0;
					 pictureBox_ListViewFlipping->Visible=false;
				 }

			 }
	private: System::Void commandHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 webBrowser_Help->Show();
				 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
			 }
	};
}
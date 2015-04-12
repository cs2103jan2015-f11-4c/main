#pragma once
#include <iostream>
#include "logic.h"

std::string const WELCOME_MESSAGE =
	"  **********************Welcome to Calendified!**********************\n"
	"         To Start, first input your desired location of your database,\n "
	"             or you can just click ok to save it in the default folder.\n"
	"  Note: you can change your location of storage anytime you want.\n"
	"  ***********************************************************************";

const std::string TYPE_UNDO 
	= "undo";

std::string const REQUEST_CHANGE_LOCATION =
	"/change location";

std::string const MESSAGE_ERROR_INVALID_INPUT =
	"Invalid input - '/help' for Help Menu!";

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
std::string const HELP_HOTKEYS =
	"/Help/Help_HotKeys.html";

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
std::string const HELP_COMMAND_HOTKEYS =
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
					std::string logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
					std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					updateListView(displayResults);
					label_status->Text = "List View Toggled!";
					webBrowser_Help->Hide();
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
					std::string logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
					std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					updateCalendifiedView(displayResults);
					mainBg->Visible  = true;	
					label_status->Text = "Calendified View Toggled!";
					webBrowser_Help->Hide();
				}
			}
			CalendifiedGUI(void)
			{
				InitializeComponent();
				toggleCount = 0;
				currentTime->Start();
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
			this->lbLengend->Size = System::Drawing::Size(0, 20);
			this->lbLengend->TabIndex = 8;
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
		int highlightPos;
	public: void CalendifiedGUI::highlightRichTextBoxContent(System::Windows::Forms::RichTextBox ^thisRichTextBox, std::string searchString, std::string todayDate, std::string nextdayDate, std::string todayMonth){
				highlightPos = thisRichTextBox->Find(gcnew String(searchString.c_str()), highlightPos , thisRichTextBox->TextLength, RichTextBoxFinds::MatchCase);		
				if(searchString.compare(KEYWORD_DONE)==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::Teal;
					thisRichTextBox->SelectionFont =(gcnew System::Drawing::Font(L"Harlow Solid", 10.00F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));	
				} else if(searchString.compare(KEYWORD_DUE)==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::Salmon;
					thisRichTextBox->SelectionFont =(gcnew System::Drawing::Font(L"Harlow Solid", 10.00F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));	
				} else if(searchString.compare(KEYWORD_TO_DO_LIST)==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::DodgerBlue;
					thisRichTextBox->SelectionFont =(gcnew System::Drawing::Font(L"Arial Narrow", 16.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));	
				} else if(searchString.compare(TYPE_RESULTS)==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::DeepPink;
					thisRichTextBox->SelectionFont = (gcnew System::Drawing::Font(L"Harlow Solid", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));
				} else if(searchString.compare(todayDate)==0 || searchString.compare(nextdayDate)==0 || searchString.compare(todayMonth)==0){
					thisRichTextBox->SelectionColor = System::Drawing::Color::DeepPink;
					thisRichTextBox->SelectionFont = (gcnew System::Drawing::Font(L"Arial Narrow", 16.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
						static_cast<System::Byte>(0)));
				}else{
					thisRichTextBox->SelectionColor = System::Drawing::Color::SlateGray;
				}
				thisRichTextBox->Select(0,0);
				highlightPos++;
			}
			//author A0125489U
	public: void CalendifiedGUI::updateRichTextBoxContent(System::Windows::Forms::RichTextBox ^thisRichTextBox, std::string logicResult, std::string nextDayDate, std::string todayDate, std::string todayYear, std::string todayMonth){
				std::string searchDate;
				int divider=21;
				int numHighlight;
				numHighlight = logicResult.length()/divider;
				//Highlight Today
				highlightPos=0;
				highlightRichTextBoxContent(thisRichTextBox,todayDate.c_str(),todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				//Highlight NextDay
				highlightPos=0;
				highlightRichTextBoxContent(thisRichTextBox,nextDayDate.c_str(),todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				//Highlight Month
				highlightPos=0;
				highlightRichTextBoxContent(thisRichTextBox,todayMonth.c_str(),todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				//Highlight To-Do Text
				highlightPos=0;
				highlightRichTextBoxContent(thisRichTextBox,KEYWORD_TO_DO_LIST.c_str(),todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				//Highlight keyword "Results:" if inputcommand is Search
				if(logicResult.substr(0,8).compare(TYPE_RESULTS) ==0){
					highlightPos=0;
					highlightRichTextBoxContent(thisRichTextBox,TYPE_RESULTS,todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				}

				//Highlight [DONE] Text
				highlightPos=0;
				for(int i =0;i < numHighlight;i++){
					highlightRichTextBoxContent(thisRichTextBox,KEYWORD_DONE,todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				}
				//Highlight [DUE] Text
				highlightPos=0;
				for(int i =0;i < numHighlight;i++){
					highlightRichTextBoxContent(thisRichTextBox,KEYWORD_DUE,todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
				}
				//Highlight Date
				highlightPos=0;
				for(int month=1; month <=12;month++){
					for(int day =1; day <=31; day++){
						searchDate = std::to_string(day)+KEYWORD_DATE_SEPARATOR+std::to_string(month)+KEYWORD_DATE_SEPARATOR+todayYear.c_str();
						highlightRichTextBoxContent(thisRichTextBox,searchDate.c_str(),todayDate.c_str(),nextDayDate.c_str(),todayMonth.c_str());
					}
				}
			}
			//author A0125489U
	public: void CalendifiedGUI::updateCalendifiedView(std::vector<std::string> displayResults){
				richTextBox_CalendifiedViewL->ResetText();
				richTextBox_CalendifiedViewR->ResetText();
				//Update CalendifiedView
				if(displayResults.size() == 3){ // Operations for ADD, EDIT, DELETE
					richTextBox_CalendifiedViewL->Text=gcnew String(displayResults[4].c_str());
				}else { //Operations for DISPLAY, VIEW
					richTextBox_CalendifiedViewL->Text = gcnew String(displayResults[4].c_str());
					richTextBox_CalendifiedViewR->Text = gcnew String(displayResults[5].c_str());
					updateRichTextBoxContent(richTextBox_CalendifiedViewL,displayResults[4],displayResults[1],displayResults[0],displayResults[2],displayResults[3]);
					updateRichTextBoxContent(richTextBox_CalendifiedViewR,displayResults[5],displayResults[1],displayResults[0],displayResults[2],displayResults[3]);
				}
			}
			//author A0125489U
	public: void CalendifiedGUI::updateListView(std::vector<std::string> displayResults){
				//Update Listview
				richTextBox_ListView->ResetText();
				richTextBox_ListView->Text = gcnew String(displayResults[4].c_str());
				updateRichTextBoxContent(richTextBox_ListView,displayResults[4],displayResults[1],displayResults[0],displayResults[2],displayResults[3]);
			}

	private: System::Void commandBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
				 logic newLogic;
				 std::vector<std::string> displayResults;
				 std::string displayResult;
				 String^ updateStatus;
				 char buffer[999];
				 String ^ checkFlip1 = gcnew String("flip");
				 String ^ checkFlip2 = gcnew String("fli");
				 String ^ checkFlip3 = gcnew String("flip ");
				 String ^ msgFlip = gcnew String("eg. flip ddmmYYYY | eg. flip 01042015");
				 String ^ checkAdd1 = gcnew String("add");
				 String ^ checkAdd2 = gcnew String("ad");
				 String ^ checkAdd3 = gcnew String("add  ");
				 String ^ msgAdd = gcnew String("eg. add dinner with alicia 04/06/2016 @ECP");
				 String ^ checkSearch1 = gcnew String("search");
				 String ^ checkSearch2 = gcnew String("searc");
				 String ^ checkSearch3 = gcnew String("search ");
				 String ^ msgSearch = gcnew String("eg. search [before|after] ddmmYYYY | search \"dinner with\" | search dinner with");
				 String ^ checkEdit1 = gcnew String("edit");
				 String ^ checkEdit2 = gcnew String("edi");
				 String ^ checkEdit3 = gcnew String("edit ");
				 String ^ msgEdit = gcnew String("eg. edit 1 @new location");
				 String ^ checkDelete1 = gcnew String("delete");
				 String ^ checkDelete2 = gcnew String("delet");
				 String ^ checkDelete3 = gcnew String("delete ");
				 String ^ msgDelete = gcnew String("eg. delete 1");
				 String ^ checkDone1 = gcnew String("done");
				 String ^ checkDone2 = gcnew String("don");
				 String ^ checkDone3 = gcnew String("done ");
				 String ^ msgDone = gcnew String("eg. done 1");
				 String ^ checkUndone1 = gcnew String("undone");
				 String ^ checkUndone2 = gcnew String("undon");
				 String ^ checkUndone3 = gcnew String("undone ");
				 String ^ msgUndone = gcnew String("eg. undone 1");
				 try {
					 if(e->KeyCode==Keys::Enter){
						 //system::string -> std::string 
						 sprintf(buffer,"%s",commandBox->Text);
						 std::string inputCommandBox(buffer);
						 //@author A0114411B
						 if(isValidInput(inputCommandBox)){
							 if(inputCommandBox == HELP_COMMAND_CLOSE){
								 webBrowser_Help->Hide();
							 } else {
								 webBrowser_Help->Navigate(getHTMLFilePath(getHelpType(inputCommandBox)));
							 }
						 }

						 if(inputCommandBox == REQUEST_CHANGE_LOCATION){
							 changeDirectory();
							 label_status->Text = "Directory changed";
						 }

						 //author A0125489U
						 
						 if(inputCommandBox.compare("flip")!=0 && inputCommandBox.compare("toggle")!=0){ //This statement resets the flipCount when no countinous flipping is detected
							 flipCount=0;
						 }
						 displayResult = newLogic.readCommand(inputCommandBox,toggleCount,flipCount);
						 updateStatus = gcnew String(displayResult.c_str());
						 label_status->ResetText();
						 if(!updateStatus->Contains(gcnew String(KEYWORD_TO_DO_LIST.c_str())) && !updateStatus->Contains(gcnew String(TYPE_RESULTS.c_str())) ){ // This section renders for operation results: {TYPE_DISPLAY,SEARCH}
							 label_status-> Text =  updateStatus;
							 if(updateStatus=="Flipped!"){ //This statement renders for countinous flipping
								 flip();
								 flipCount++;
								 flipCount += newLogic.updateUIFlipCount();
							 }
							 displayResults = newLogic.updateUI(newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount),toggleCount,flipCount);	 
						 }else { //This section renders for operation results {ADD,DELETE,EDIT,FLIP,TOGGLE,TYPE_UNDO}
							 displayResults = newLogic.updateUI(displayResult,toggleCount,flipCount);
						 }
						 if(toggleCount == 0){ //check for mode [calendified/list] view 
							 updateCalendifiedView(displayResults);
						 }else{
							 updateListView(displayResults);
						 }

						 commandBox->ResetText();				 				 										 Windows::Forms::SendKeys::Send("{BACKSPACE}");
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

					 } else if(e->Control && e->KeyCode==Keys::Z){//Shortcut for Ctrl+Z
						 try{
							 flipCount=0;
							 displayResult = newLogic.readCommand(TYPE_UNDO,toggleCount,flipCount);
							 updateStatus = gcnew String(displayResult.c_str());
							 label_status->Text = updateStatus;
							 displayResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
							 displayResults = newLogic.updateUI(displayResult,toggleCount,flipCount);
							 if(toggleCount == 0){ 
								 updateCalendifiedView(displayResults);
							 }else{
								 updateListView(displayResults);
							 }
						 } catch(const std::exception& e) {
							 MessageBox::Show(gcnew String("Invalid Format"));
						 }
					 } else if(e->Control && e->KeyCode==Keys::D){//Shortcut for CTRL + D
						 commandBox->Text = "delete " + commandBox->Text;
					 } else if(e->Control && e->KeyCode==Keys::F){//Shortcut for CTRL + F
						 displayResult = newLogic.readCommand("flip",toggleCount,flipCount);
						 updateStatus = gcnew String(displayResult.c_str());label_status->ResetText();
						 if(!updateStatus->Contains(gcnew String(KEYWORD_TO_DO_LIST.c_str())) && !updateStatus->Contains(gcnew String(TYPE_RESULTS.c_str())) ){ // This section renders for operation results: {TYPE_DISPLAY,SEARCH}
							 label_status-> Text =  updateStatus;
							 if(updateStatus=="Flipped!"){ //This statement renders for countinous flipping
								 flip();
								 flipCount++;
							 }
							 displayResults = newLogic.updateUI(newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount),toggleCount,flipCount);	 
						 }else { //This section renders for operation results {ADD,DELETE,EDIT,FLIP,TOGGLE,UNDO}
							 displayResults = newLogic.updateUI(displayResult,toggleCount,flipCount);
						 }
						 if(toggleCount == 0){ //check for mode [calendified/list] view 
							 updateCalendifiedView(displayResults);
						 }else{
							 updateListView(displayResults);
						 }
					 } else if(e->Control && e->KeyCode==Keys::A){//Shortcut for CTRL + A
						 commandBox->Text = "add " + commandBox->Text;
					 } else if(e->Control && e->KeyCode==Keys::T){//Shortcut for CTRL + T
						 toggle();
					 } else if(e->Control && e->KeyCode==Keys::S){//Shortcut for CTRL + S
						 commandBox->Text = "search " + commandBox->Text;
					 } else if(e->Control && e->KeyCode==Keys::Y){//Shortcut for CTRL + Y
						 //REDO not implemented yet
						 /* try{
						 logic newLogic;
						 const std::string TYPE_REDO = "redo";
						 flipCount=0;
						 std::string results = newLogic.readCommand(TYPE_UNDO,toggleCount,flipCount);
						 String^ statusUpdate = gcnew String(results.c_str());
						 label_status->Text = statusUpdate;
						 std::string logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
						 std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
						 if(toggleCount == 0){ 
						 updateCalendifiedView(displayResults);
						 }else{
						 updateListView(displayResults);
						 }
						 } catch(const std::exception& e) {
						 String^ systemString = gcnew String(e.what()); 
						 MessageBox::Show(systemString);
						 }*/
					 } else if(e->Control && e->KeyCode==Keys::E){//Shortcut for CTRL + E
						 commandBox->Text = "edit " + commandBox->Text;
					 } else if(e->Control && e->KeyCode==Keys::H){//Shortcut for CTRL + H
						 webBrowser_Help->Navigate(getHTMLFilePath(getHelpType(HELP_COMMAND_HELP)));
					 } else if(e->Control && e->KeyCode==Keys::W){//Shortcut for CTRL + W // exit
						 Application::Exit();
					 }

				 } catch (const std::exception& e) {
					 MessageBox::Show(gcnew String("Invalid Format"));
				 }
				 
				 if(commandBox->Text->ToLower() == checkFlip1 || 
					 commandBox->Text->ToLower() == checkFlip2 || 
					 commandBox->Text->ToLower() == checkFlip3){ //Check for flip input
					 lbLengend->Text = msgFlip;	
				 } else if(commandBox->Text->ToLower() == checkAdd1 || 
					 commandBox->Text->ToLower() == checkAdd2 || 
					 commandBox->Text->ToLower() == checkAdd3){ //Check for add input
						 lbLengend->Text = msgAdd;
				 } else if(commandBox->Text->ToLower() == checkSearch1 || 
					 commandBox->Text->ToLower() == checkSearch2 || 
					 commandBox->Text->ToLower() == checkSearch3){ //Check for search input
						 lbLengend->Text = msgSearch;
				 } else if(commandBox->Text->ToLower() == checkEdit1 || 
					 commandBox->Text->ToLower() == checkEdit2 || 
					 commandBox->Text->ToLower() == checkEdit3){ //Check for edit input
						 lbLengend->Text = msgEdit;
				 } else if(commandBox->Text->ToLower() == checkDelete1 || 
					 commandBox->Text->ToLower() == checkDelete2 || 
					 commandBox->Text->ToLower() == checkDelete3){ //Check for delete input
						 lbLengend->Text = msgDelete;
				 } else if(commandBox->Text->ToLower() == checkDone1 || 
					 commandBox->Text->ToLower() == checkDone2|| 
					 commandBox->Text->ToLower() == checkDone3){ //Check for done input
						 lbLengend->Text = msgDone;
				 } else if(commandBox->Text->ToLower() == checkUndone1|| 
					 commandBox->Text->ToLower() == checkUndone2 || 
					 commandBox->Text->ToLower() == checkUndone3){ //Check for undone input
						 lbLengend->Text = msgUndone;
				 } else{
					lbLengend->Text = "";
				 }
			 }

			 //@author A0114411B
			 bool isValidInput(std::string inputCommandBox){
				 if(inputCommandBox == HELP_COMMAND_ADD
					 || inputCommandBox == HELP_COMMAND_BACK
					 || inputCommandBox == HELP_COMMAND_CLOSE
					 || inputCommandBox == HELP_COMMAND_DELETE
					 || inputCommandBox == HELP_COMMAND_DONE
					 || inputCommandBox == HELP_COMMAND_EDIT
					 || inputCommandBox == HELP_COMMAND_HELP
					 || inputCommandBox == HELP_COMMAND_HOTKEYS
					 || inputCommandBox == HELP_COMMAND_LOCATION_DATABASE
					 || inputCommandBox == HELP_COMMAND_UNDO_OR_REDO
					 || inputCommandBox == HELP_COMMAND_VIEW_SEARCH){
						 return true;
				 }else {
					 return false;
				 }
			 }

			 //@author A0114411B
			 public: std::string CalendifiedGUI::getHelpType(std::string inputCommandBox){
				 if(inputCommandBox == HELP_COMMAND_BACK){
					 return HELP_MAIN_MENU;
				 } else	if(inputCommandBox == HELP_COMMAND_ADD){
					 return HELP_ADD;
				 } else if(inputCommandBox == HELP_COMMAND_DELETE){
					 return HELP_DELETE;
				 } else if(inputCommandBox == HELP_COMMAND_VIEW_SEARCH){
					 return HELP_SEARCH;
				 } else if(inputCommandBox == HELP_COMMAND_EDIT){
					 return HELP_EDIT;
				 } else if(inputCommandBox == HELP_COMMAND_DONE){
					 return HELP_DONE;
				 } else if(inputCommandBox == HELP_COMMAND_UNDO_OR_REDO){
					 return HELP_UNDO_REDO;
				 } else if(inputCommandBox == HELP_COMMAND_LOCATION_DATABASE){
					 return HELP_LOCATION_DATABASE;
				 } else if(inputCommandBox == HELP_COMMAND_HOTKEYS){
					 return HELP_HOTKEYS;
				 } else if(inputCommandBox == HELP_COMMAND_HELP){
					 if(toggleCount == 0){ //Calendified 
						 this->webBrowser_Help->Location = System::Drawing::Point(22, 73);
						 this->webBrowser_Help->Size = System::Drawing::Size(620, 320);
						 webBrowser_Help->Show();
					 }else{ //Listview
						 this->webBrowser_Help->Location = System::Drawing::Point(35, 29);
						 this->webBrowser_Help->Size = System::Drawing::Size(605, 370);
						 webBrowser_Help->Show();
					 }
					 return HELP_MAIN_MENU;
				 }
				 return HELP_MAIN_MENU;
			 }

			 //@author A0114411B
	private: System::Void CalendifiedGUI_Load(System::Object^  sender, System::EventArgs^  e) {
				 UI::CalendifiedGUI::ActiveControl = this->commandBox;

				 logic newLogic;
				 std::string logicResult;
				 std::vector<std::string> displayResults;
				 String^ welcomeMessage;
				 IO::Stream^ mystream;
				 SaveFileDialog^ saveFileDialog1;
				 char fileName[999];
				 std::string directory = newLogic.newStorage.retrieveFilePath();
				 if(directory == ""){
					 welcomeMessage = gcnew String(WELCOME_MESSAGE.c_str());
					 MessageBox::Show(welcomeMessage);		 
					 saveFileDialog1 = gcnew SaveFileDialog;
					 saveFileDialog1->InitialDirectory = "c://";
					 saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
					 saveFileDialog1->FilterIndex = 2;
					 saveFileDialog1->RestoreDirectory = true;
					 saveFileDialog1->FileName = "Calendified Storage";

					 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 sprintf(fileName,"%s",saveFileDialog1->FileName);
						 newLogic.newStorage.saveInformation(fileName);
						 newLogic.newStorage.createFile(fileName);
						 //IO::StreamWriter^ file = gcnew IO::StreamWriter(saveFileDialog1->FileName);
						 //file->WriteLine("Calendified Database.");
						 //file->Close();
						 logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
						 displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
						 if(toggleCount == 0){ //check for mode [calendified/list] view 
							 updateCalendifiedView(displayResults);
						 }else{
							 updateListView(displayResults);
						 }
					 }
					 if(toggleCount == 0){ //Calendified 
						 this->webBrowser_Help->Location = System::Drawing::Point(22, 73);
						 this->webBrowser_Help->Size = System::Drawing::Size(620, 320);
					 }else{ //Listview
						 this->webBrowser_Help->Location = System::Drawing::Point(35, 29);
						 this->webBrowser_Help->Size = System::Drawing::Size(605, 370);
					 }
					 webBrowser_Help->Show();
					 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
				 } else{
					 webBrowser_Help->Hide();		
					 logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
					 displayResults = newLogic.updateUI(newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount),toggleCount,flipCount);
					 if(toggleCount == 0){ //check for mode [calendified/list] view 
						 updateCalendifiedView(displayResults);
					 }else{
						 //Update Listview
						 updateListView(displayResults);
					 }
				 }
				 notifyBox->Text="0!";//need storage return num file;
			 }

			 //@author A0114411B
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
				 std::string logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
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
			 //@author A0114411B
	private: System::Void pictureBox_Help_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
				 contextMenuStrip_HelpContent->Show(pictureBox_Help,0,pictureBox_Help->Height);
			 }
	private: System::Void toggleBox_ListView_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 toggle();
			 }
			 //@author A0114411B
	private: System::Void contextMenuStrip_HelpContent_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
				 contextMenuStrip_HelpContent->Hide();
			 }
			 //@author A0114411B
	private: System::Void currentTime_Tick(System::Object^  sender, System::EventArgs^  e) {
				 DateTime datetime = DateTime::Now;
				 this->label_currentTime->Text = "Current Time: " + datetime.ToString();
			 }
			 //@author A0114411B
	private: System::Void pictureBox_Undo_Click(System::Object^  sender, System::EventArgs^  e) {
				 try{
					 logic newLogic;
					 flipCount=0;
					 std::string results = newLogic.readCommand(TYPE_UNDO,toggleCount,flipCount);
					 String^ statusUpdate = gcnew String(results.c_str());
					 label_status->Text = statusUpdate;
					 std::string logicResult = newLogic.readCommand(TYPE_DISPLAY,toggleCount,flipCount);
					 std::vector<std::string> displayResults = newLogic.updateUI(logicResult,toggleCount,flipCount);
					 if(toggleCount == 0){ 
						 updateCalendifiedView(displayResults);
					 }else{
						 updateListView(displayResults);
					 }
				 } catch(const std::exception& e) {
					 MessageBox::Show(gcnew String(e.what()));
				 }
			 }
			 //@author A0114411B
	private: System::Void changeDatabaseLocationToolStripMenuItem1_Click(System::Object^  sender, System::EventArgs^  e) {
				 changeDirectory();
				 label_status->Text = "Directory changed";
			 }

			 //@author A0114411B
			 String^ getHTMLFilePath(std::string htmlHelpDirectory){

				 char path[MAX_PATH];
				 _fullpath(path, ":\\" , MAX_PATH);
				 std::string directoryOfFolder(path);
				 int const size = directoryOfFolder.size();
				 directoryOfFolder = directoryOfFolder.substr(0,size-3);
				 std::string htmlDirectory = directoryOfFolder + htmlHelpDirectory;
				 return gcnew String(htmlDirectory.c_str());
			 }
			 //@author A0114411B
			 void changeDirectory(){
				 logic newLogic; 
				 IO::Stream^ mystream;
				 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
				 saveFileDialog1->InitialDirectory = "c://";
				 saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
				 saveFileDialog1->FilterIndex = 2;
				 saveFileDialog1->RestoreDirectory = true;
				 saveFileDialog1->FileName = "";
				 char newFileName[999];
				 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				 {					 
					 sprintf(newFileName,"%s",saveFileDialog1->FileName);
					 newLogic.newStorage.transferDatabase(newFileName);
					 newLogic.newStorage.setFilePath(newFileName);
				 }
			 }

			 //@author A0125489U
	public: void flip(){
				Graphics^ gfx;
				Bitmap^ bmp;
				if(toggleCount ==0){
					gfx = mainBg->CreateGraphics();
					bmp = gcnew Bitmap(richTextBox_ListView->Width+40, richTextBox_ListView->Height-40);
					gfx = gfx->FromImage(bmp);
					gfx->CopyFromScreen(this->Location.X+30,this->Location.Y+105,0,0,this->Size);
					pictureBox_CalendifiedFlipping->Image=bmp;
					pictureBox_CalendifiedFlipping->Visible=true;
					timerCalendifiedFlip->Start();
				} else if(toggleCount==1){
					gfx = mainBg2->CreateGraphics();
					bmp = gcnew Bitmap(richTextBox_ListView->Width+10, richTextBox_ListView->Height);
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
			 //@author A0114411B
	private: System::Void commandHelpToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 webBrowser_Help->Show();
				 webBrowser_Help->Navigate(getHTMLFilePath(HELP_MAIN_MENU));
			 }
	};
}
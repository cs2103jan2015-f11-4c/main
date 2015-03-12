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
				 toggleBox->BorderStyle = BorderStyle::Fixed3D;
				 richTextBox1->Visible = false;
				 mainBg->Visible=false;
				 richTextBox2->Visible = true;
				 richTextBox2->Text = richTextBox1->Text;
				 richTextBox2->BackColor = System::Drawing::SystemColors::Window;
				 mainBg2->Visible  = true;			 
			 }else{
				 toggleCount = 0;
				 toggleBox->BorderStyle =  BorderStyle::None;
				 richTextBox2->Visible = false;
				 mainBg2->Visible=false;
				 richTextBox1->Visible = true;
				 richTextBox1->Text = richTextBox2->Text;
				 mainBg->Visible  = true;	
			 }
		}
		CalendifiedGUI(void)
		{
			InitializeComponent();
			toggleCount = 0;
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
	private: System::Windows::Forms::Label^  lbInstructions;


	private: System::Windows::Forms::Button^  button_enter;
	private: System::Windows::Forms::Button^  button_undo;
	private: System::Windows::Forms::Label^  lb_results;

	private: System::Windows::Forms::Label^  lbLengend;

	private: System::Windows::Forms::Button^  button_help;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::PictureBox^  toggleBox;
	private: System::Windows::Forms::PictureBox^  notifyBox;


	private: System::Windows::Forms::PictureBox^  mainBg;
	private: System::Windows::Forms::PictureBox^  mainBg2;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;




	protected: 


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CalendifiedGUI::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->commandBox = (gcnew System::Windows::Forms::RichTextBox());
			this->lbInstructions = (gcnew System::Windows::Forms::Label());
			this->button_enter = (gcnew System::Windows::Forms::Button());
			this->button_undo = (gcnew System::Windows::Forms::Button());
			this->lb_results = (gcnew System::Windows::Forms::Label());
			this->lbLengend = (gcnew System::Windows::Forms::Label());
			this->button_help = (gcnew System::Windows::Forms::Button());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toggleBox = (gcnew System::Windows::Forms::PictureBox());
			this->notifyBox = (gcnew System::Windows::Forms::PictureBox());
			this->mainBg = (gcnew System::Windows::Forms::PictureBox());
			this->mainBg2 = (gcnew System::Windows::Forms::PictureBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->BeginInit();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->richTextBox1->Enabled = false;
			this->richTextBox1->Location = System::Drawing::Point(3, 153);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(633, 236);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// commandBox
			// 
			this->commandBox->Location = System::Drawing::Point(3, 418);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(540, 74);
			this->commandBox->TabIndex = 3;
			this->commandBox->Text = L"<Insert Your Command Here>";
			this->commandBox->Enter += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Enter);
			this->commandBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CalendifiedGUI::commandBox_KeyDown);
			this->commandBox->Leave += gcnew System::EventHandler(this, &CalendifiedGUI::commandBox_Leave);
			// 
			// lbInstructions
			// 
			this->lbInstructions->AutoSize = true;
			this->lbInstructions->BackColor = System::Drawing::Color::WhiteSmoke;
			this->lbInstructions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbInstructions->Location = System::Drawing::Point(0, 392);
			this->lbInstructions->Name = L"lbInstructions";
			this->lbInstructions->Size = System::Drawing::Size(210, 18);
			this->lbInstructions->TabIndex = 4;
			this->lbInstructions->Text = L"Insert Your Command Below:  ";
			// 
			// button_enter
			// 
			this->button_enter->BackColor = System::Drawing::Color::Transparent;
			this->button_enter->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_enter->ForeColor = System::Drawing::Color::Maroon;
			this->button_enter->Location = System::Drawing::Point(549, 418);
			this->button_enter->Name = L"button_enter";
			this->button_enter->Size = System::Drawing::Size(89, 75);
			this->button_enter->TabIndex = 5;
			this->button_enter->Text = L"Enter";
			this->button_enter->UseVisualStyleBackColor = false;
			// 
			// button_undo
			// 
			this->button_undo->Location = System::Drawing::Point(140, 492);
			this->button_undo->Name = L"button_undo";
			this->button_undo->Size = System::Drawing::Size(75, 23);
			this->button_undo->TabIndex = 6;
			this->button_undo->Text = L"UNDO";
			this->button_undo->UseVisualStyleBackColor = true;
			// 
			// lb_results
			// 
			this->lb_results->AutoSize = true;
			this->lb_results->BackColor = System::Drawing::Color::Transparent;
			this->lb_results->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lb_results->ForeColor = System::Drawing::Color::Red;
			this->lb_results->Location = System::Drawing::Point(12, 497);
			this->lb_results->Name = L"lb_results";
			this->lb_results->Size = System::Drawing::Size(122, 13);
			this->lb_results->TabIndex = 7;
			this->lb_results->Text = L"Welcome to Calendified!";
			// 
			// lbLengend
			// 
			this->lbLengend->AutoSize = true;
			this->lbLengend->BackColor = System::Drawing::Color::Silver;
			this->lbLengend->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lbLengend->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->lbLengend->Location = System::Drawing::Point(254, 397);
			this->lbLengend->Name = L"lbLengend";
			this->lbLengend->Size = System::Drawing::Size(382, 13);
			this->lbLengend->TabIndex = 8;
			this->lbLengend->Text = L" Legend: && - Title, $ - Time, % - Date, @ - Location, # - Description";
			// 
			// button_help
			// 
			this->button_help->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_help->Location = System::Drawing::Point(221, 492);
			this->button_help->Name = L"button_help";
			this->button_help->Size = System::Drawing::Size(75, 23);
			this->button_help->TabIndex = 9;
			this->button_help->Text = L"Help";
			this->button_help->UseVisualStyleBackColor = true;
			// 
			// toggleBox
			// 
			this->toggleBox->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->toggleBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toggleBox.Image")));
			this->toggleBox->InitialImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toggleBox.InitialImage")));
			this->toggleBox->Location = System::Drawing::Point(40, 19);
			this->toggleBox->Name = L"toggleBox";
			this->toggleBox->Size = System::Drawing::Size(26, 28);
			this->toggleBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->toggleBox->TabIndex = 10;
			this->toggleBox->TabStop = false;
			this->toggleBox->Click += gcnew System::EventHandler(this, &CalendifiedGUI::toggleBox_Click);
			// 
			// notifyBox
			// 
			this->notifyBox->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"notifyBox.Image")));
			this->notifyBox->Location = System::Drawing::Point(12, 12);
			this->notifyBox->Name = L"notifyBox";
			this->notifyBox->Size = System::Drawing::Size(23, 35);
			this->notifyBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->notifyBox->TabIndex = 11;
			this->notifyBox->TabStop = false;
			this->notifyBox->Click += gcnew System::EventHandler(this, &CalendifiedGUI::notifyBox_Click);
			// 
			// mainBg
			// 
			this->mainBg->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mainBg.Image")));
			this->mainBg->Location = System::Drawing::Point(-14, 43);
			this->mainBg->Name = L"mainBg";
			this->mainBg->Size = System::Drawing::Size(692, 346);
			this->mainBg->TabIndex = 13;
			this->mainBg->TabStop = false;
			// 
			// mainBg2
			// 
			this->mainBg2->Enabled = false;
			this->mainBg2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"mainBg2.Image")));
			this->mainBg2->Location = System::Drawing::Point(3, 43);
			this->mainBg2->Name = L"mainBg2";
			this->mainBg2->Size = System::Drawing::Size(658, 351);
			this->mainBg2->TabIndex = 14;
			this->mainBg2->TabStop = false;
			this->mainBg2->Visible = false;
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Enabled = false;
			this->richTextBox2->Location = System::Drawing::Point(22, 67);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(593, 303);
			this->richTextBox2->TabIndex = 15;
			this->richTextBox2->Text = L"";
			this->richTextBox2->Visible = false;
			// 
			// CalendifiedGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(663, 520);
			this->Controls->Add(this->notifyBox);
			this->Controls->Add(this->toggleBox);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->mainBg2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->mainBg);
			this->Controls->Add(this->button_help);
			this->Controls->Add(this->lbLengend);
			this->Controls->Add(this->lb_results);
			this->Controls->Add(this->button_undo);
			this->Controls->Add(this->button_enter);
			this->Controls->Add(this->lbInstructions);
			this->Controls->Add(this->commandBox);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"CalendifiedGUI";
			this->Text = L"Calendified";
			this->Load += gcnew System::EventHandler(this, &CalendifiedGUI::CalendifiedGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->toggleBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->notifyBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainBg2))->EndInit();
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
				 if(!newStorage.isFileExist()){
					 IO::Stream^ mystream;
					 SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

					 saveFileDialog1->InitialDirectory = "c://";
					 saveFileDialog1->Filter = "txt files (*.txt)|*.txt";
					 saveFileDialog1->FilterIndex = 2;
					 saveFileDialog1->RestoreDirectory = true;
					 saveFileDialog1->FileName = "storage";

					 if(saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
					 {
						 IO::StreamWriter^ file = gcnew IO::StreamWriter(saveFileDialog1->FileName);
						 file->WriteLine("Calendified Database.");
						 file->Close();
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
};
}

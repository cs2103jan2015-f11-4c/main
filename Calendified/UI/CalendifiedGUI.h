#pragma once
#include <iostream>
#include "Calendified.h"
#include "logic.h"
#include "parser.h"

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
		CalendifiedGUI(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Button^  button_notification;
	private: System::Windows::Forms::Button^  change_view_button;
	private: System::Windows::Forms::RichTextBox^  commandBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button_enter;
	private: System::Windows::Forms::Button^  button_undo;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button_help;

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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button_notification = (gcnew System::Windows::Forms::Button());
			this->change_view_button = (gcnew System::Windows::Forms::Button());
			this->commandBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_enter = (gcnew System::Windows::Forms::Button());
			this->button_undo = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button_help = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(12, 43);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(864, 346);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button_notification
			// 
			this->button_notification->Enabled = false;
			this->button_notification->Location = System::Drawing::Point(12, 14);
			this->button_notification->Name = L"button_notification";
			this->button_notification->Size = System::Drawing::Size(75, 23);
			this->button_notification->TabIndex = 1;
			this->button_notification->Text = L"Notification";
			this->button_notification->UseVisualStyleBackColor = true;
			// 
			// change_view_button
			// 
			this->change_view_button->Location = System::Drawing::Point(110, 13);
			this->change_view_button->Name = L"change_view_button";
			this->change_view_button->Size = System::Drawing::Size(75, 23);
			this->change_view_button->TabIndex = 2;
			this->change_view_button->Text = L"changeviewbutton";
			this->change_view_button->UseVisualStyleBackColor = true;
			// 
			// commandBox
			// 
			this->commandBox->Location = System::Drawing::Point(12, 417);
			this->commandBox->Name = L"commandBox";
			this->commandBox->Size = System::Drawing::Size(782, 74);
			this->commandBox->TabIndex = 3;
			this->commandBox->Text = L"<Insert Your Command Here>";
			this->commandBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &CalendifiedGUI::commandBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 396);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(210, 18);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Insert Your Command Below:  ";
			// 
			// button_enter
			// 
			this->button_enter->BackColor = System::Drawing::Color::Transparent;
			this->button_enter->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_enter->ForeColor = System::Drawing::Color::Maroon;
			this->button_enter->Location = System::Drawing::Point(705, 417);
			this->button_enter->Name = L"button_enter";
			this->button_enter->Size = System::Drawing::Size(89, 74);
			this->button_enter->TabIndex = 5;
			this->button_enter->Text = L"Enter";
			this->button_enter->UseVisualStyleBackColor = false;
			// 
			// button_undo
			// 
			this->button_undo->Location = System::Drawing::Point(211, 507);
			this->button_undo->Name = L"button_undo";
			this->button_undo->Size = System::Drawing::Size(75, 23);
			this->button_undo->TabIndex = 6;
			this->button_undo->Text = L"UNDO";
			this->button_undo->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(11, 507);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(180, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Welcome to Calendified!";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Silver;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(334, 398);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(460, 16);
			this->label3->TabIndex = 8;
			this->label3->Text = L" Legend: && - Title, $ - Time, % - Date, @ - Location, # - Description";
			// 
			// button_help
			// 
			this->button_help->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button_help->Location = System::Drawing::Point(709, 13);
			this->button_help->Name = L"button_help";
			this->button_help->Size = System::Drawing::Size(75, 23);
			this->button_help->TabIndex = 9;
			this->button_help->Text = L"Help";
			this->button_help->UseVisualStyleBackColor = true;
			// 
			// CalendifiedGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(796, 570);
			this->Controls->Add(this->button_help);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button_undo);
			this->Controls->Add(this->button_enter);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->commandBox);
			this->Controls->Add(this->change_view_button);
			this->Controls->Add(this->button_notification);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"CalendifiedGUI";
			this->Text = L"Calendified";
			this->Load += gcnew System::EventHandler(this, &CalendifiedGUI::CalendifiedGUI_Load);
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
				 
				 parser newParser;
				 std::string newString = newParser.readCommand(inputCommandBox);
				 
				 
				 String^ str2 = gcnew String(newString.c_str());
				 MessageBox::Show(str2);
				 commandBox->Text = "";

				 /*
				 //std::string ->system::string
				 String^ systemString = gcnew String(inputCommandBox.c_str()); 
				 MessageBox::Show(systemString); 
				 */

			 }
		 }
private: System::Void CalendifiedGUI_Load(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

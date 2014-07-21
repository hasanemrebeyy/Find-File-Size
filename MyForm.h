#pragma once

namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Drawing;
    using namespace System::IO;
  
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(650, 75);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"See byte ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(72, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Enter the directory:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(92, 40);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(633, 20);
			this->textBox1->TabIndex = 2;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(499, 75);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(139, 22);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Add 1 bytes in file";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(737, 112);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 
				 try {
IO::FileInfo ^dosyaBoyut = nullptr;
dosyaBoyut = gcnew System::IO::FileInfo(textBox1->Text);
MessageBox::Show("Dosya Boyut: " + dosyaBoyut->Length + " byte(s) \n" 
				 "Dosya Boyut2: " + dosyaBoyut->Length/1024 + " kbyte(s) \n"
				 "Dosya Boyut3: " + dosyaBoyut->Length/1024/1024 + " mbyte(s) \n"
				 );}catch(...)
{

MessageBox::Show("Hatalı dosya dizini , lütfen kontrol ediniz... \n"
				 "Dosya dizininiz " + textBox1->Text + ""
				 
				 );
}






			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

			try {	FileStream^ fs = gcnew FileStream(textBox1->Text, FileMode::Open);
          StreamReader^ sr = gcnew StreamReader(fs);
		System::String^ s; 
		s = sr->ReadLine();
         
		sr->Close();

	    StreamWriter^ sw = gcnew StreamWriter(textBox1->Text);
		char a;
	    sw->WriteLine(s+ a);
	
        sw->Close();
        MessageBox::Show("1 byte value added to the file...");
			}catch (...){
			
			MessageBox::Show("An error has occurred upgrade be required, please restart the program...");
			
			}
			 }

};
}

#include "BigInt.h"
#include "prime.h"
#include "Algo.h"


namespace Elgamal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBoxKeySize;

	private: System::Windows::Forms::Button^  buttonGenerateKey;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBoxInputFile;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TextBox^  textBoxInputDecrypt;

	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  labelll;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;
	private: System::Windows::Forms::TextBox^  textOutputFile;

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog3;
	private: System::Windows::Forms::Button^  buttonDecrypt;
	private: System::Windows::Forms::Button^  buttonEncrypt;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Button^  buttonDecryptText;
	private: System::Windows::Forms::Button^  buttonEncryptText;
	private: System::Windows::Forms::Button^  buttonGenerateKeyText;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ComboBox^  comboBoxTextKeySize;
	private: System::Windows::Forms::RichTextBox^  richTextBoxOutputText;
	private: System::Windows::Forms::RichTextBox^  richTextBoxInputText;


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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->buttonDecryptText = (gcnew System::Windows::Forms::Button());
			this->buttonEncryptText = (gcnew System::Windows::Forms::Button());
			this->buttonGenerateKeyText = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->comboBoxTextKeySize = (gcnew System::Windows::Forms::ComboBox());
			this->richTextBoxOutputText = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBoxInputText = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->buttonDecrypt = (gcnew System::Windows::Forms::Button());
			this->buttonEncrypt = (gcnew System::Windows::Forms::Button());
			this->textOutputFile = (gcnew System::Windows::Forms::TextBox());
			this->textBoxInputDecrypt = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->labelll = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBoxInputFile = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxKeySize = (gcnew System::Windows::Forms::ComboBox());
			this->buttonGenerateKey = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog3 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(-1, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(709, 291);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->label7);
			this->tabPage1->Controls->Add(this->buttonDecryptText);
			this->tabPage1->Controls->Add(this->buttonEncryptText);
			this->tabPage1->Controls->Add(this->buttonGenerateKeyText);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->comboBoxTextKeySize);
			this->tabPage1->Controls->Add(this->richTextBoxOutputText);
			this->tabPage1->Controls->Add(this->richTextBoxInputText);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(701, 265);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Szyfrowanie tekstu";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(286, 31);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(84, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Tekst wyjœciowy";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(22, 31);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(88, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Tekst Wejœciowy";
			// 
			// buttonDecryptText
			// 
			this->buttonDecryptText->Location = System::Drawing::Point(570, 160);
			this->buttonDecryptText->Name = L"buttonDecryptText";
			this->buttonDecryptText->Size = System::Drawing::Size(121, 29);
			this->buttonDecryptText->TabIndex = 6;
			this->buttonDecryptText->Text = L"Odszyfruj tekst";
			this->buttonDecryptText->UseVisualStyleBackColor = true;
			this->buttonDecryptText->Click += gcnew System::EventHandler(this, &MyForm::buttonDecryptText_Click);
			// 
			// buttonEncryptText
			// 
			this->buttonEncryptText->Location = System::Drawing::Point(570, 124);
			this->buttonEncryptText->Name = L"buttonEncryptText";
			this->buttonEncryptText->Size = System::Drawing::Size(121, 29);
			this->buttonEncryptText->TabIndex = 5;
			this->buttonEncryptText->Text = L"Zaszyfruj tekst";
			this->buttonEncryptText->UseVisualStyleBackColor = true;
			this->buttonEncryptText->Click += gcnew System::EventHandler(this, &MyForm::buttonEncryptText_Click);
			// 
			// buttonGenerateKeyText
			// 
			this->buttonGenerateKeyText->Location = System::Drawing::Point(570, 89);
			this->buttonGenerateKeyText->Name = L"buttonGenerateKeyText";
			this->buttonGenerateKeyText->Size = System::Drawing::Size(121, 29);
			this->buttonGenerateKeyText->TabIndex = 4;
			this->buttonGenerateKeyText->Text = L"Wygeneruj klucz";
			this->buttonGenerateKeyText->UseVisualStyleBackColor = true;
			this->buttonGenerateKeyText->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerateKeyText_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(567, 31);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Wielkoœæ klucza";
			// 
			// comboBoxTextKeySize
			// 
			this->comboBoxTextKeySize->FormattingEnabled = true;
			this->comboBoxTextKeySize->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"64", L"128", L"192", L"256", L"512",
					L"1024"
			});
			this->comboBoxTextKeySize->Location = System::Drawing::Point(570, 61);
			this->comboBoxTextKeySize->Name = L"comboBoxTextKeySize";
			this->comboBoxTextKeySize->Size = System::Drawing::Size(121, 21);
			this->comboBoxTextKeySize->TabIndex = 2;
			this->comboBoxTextKeySize->Text = L"64";
			// 
			// richTextBoxOutputText
			// 
			this->richTextBoxOutputText->Location = System::Drawing::Point(286, 61);
			this->richTextBoxOutputText->Name = L"richTextBoxOutputText";
			this->richTextBoxOutputText->Size = System::Drawing::Size(268, 174);
			this->richTextBoxOutputText->TabIndex = 1;
			this->richTextBoxOutputText->Text = L"";
			// 
			// richTextBoxInputText
			// 
			this->richTextBoxInputText->Location = System::Drawing::Point(22, 61);
			this->richTextBoxInputText->Name = L"richTextBoxInputText";
			this->richTextBoxInputText->Size = System::Drawing::Size(258, 174);
			this->richTextBoxInputText->TabIndex = 0;
			this->richTextBoxInputText->Text = L"";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->buttonDecrypt);
			this->tabPage2->Controls->Add(this->buttonEncrypt);
			this->tabPage2->Controls->Add(this->textOutputFile);
			this->tabPage2->Controls->Add(this->textBoxInputDecrypt);
			this->tabPage2->Controls->Add(this->button4);
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->labelll);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->textBoxInputFile);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->comboBoxKeySize);
			this->tabPage2->Controls->Add(this->buttonGenerateKey);
			this->tabPage2->Controls->Add(this->label1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(701, 265);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Szyfrowanie pliku";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// buttonDecrypt
			// 
			this->buttonDecrypt->Location = System::Drawing::Point(384, 175);
			this->buttonDecrypt->Name = L"buttonDecrypt";
			this->buttonDecrypt->Size = System::Drawing::Size(93, 20);
			this->buttonDecrypt->TabIndex = 18;
			this->buttonDecrypt->Text = L"Deszyfruj plik";
			this->buttonDecrypt->UseVisualStyleBackColor = true;
			this->buttonDecrypt->Click += gcnew System::EventHandler(this, &MyForm::buttonDecrypt_Click);
			// 
			// buttonEncrypt
			// 
			this->buttonEncrypt->Location = System::Drawing::Point(384, 122);
			this->buttonEncrypt->Name = L"buttonEncrypt";
			this->buttonEncrypt->Size = System::Drawing::Size(93, 23);
			this->buttonEncrypt->TabIndex = 17;
			this->buttonEncrypt->Text = L"Zaszyfruj plik";
			this->buttonEncrypt->UseVisualStyleBackColor = true;
			this->buttonEncrypt->Click += gcnew System::EventHandler(this, &MyForm::buttonEncrypt_Click);
			// 
			// textOutputFile
			// 
			this->textOutputFile->Location = System::Drawing::Point(35, 234);
			this->textOutputFile->Name = L"textOutputFile";
			this->textOutputFile->Size = System::Drawing::Size(200, 20);
			this->textOutputFile->TabIndex = 16;
			// 
			// textBoxInputDecrypt
			// 
			this->textBoxInputDecrypt->Location = System::Drawing::Point(35, 176);
			this->textBoxInputDecrypt->Name = L"textBoxInputDecrypt";
			this->textBoxInputDecrypt->Size = System::Drawing::Size(200, 20);
			this->textBoxInputDecrypt->TabIndex = 15;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(241, 234);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 21);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Wybierz plik";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(241, 176);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(73, 20);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Wybierz plik";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(32, 212);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Plik wyjœciowy";
			// 
			// labelll
			// 
			this->labelll->AutoSize = true;
			this->labelll->Location = System::Drawing::Point(32, 159);
			this->labelll->Name = L"labelll";
			this->labelll->Size = System::Drawing::Size(87, 13);
			this->labelll->TabIndex = 9;
			this->labelll->Text = L"Deszyfracja pliku";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(29, 103);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Œcie¿ka pliku";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(241, 122);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 20);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Wybierz plik";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBoxInputFile
			// 
			this->textBoxInputFile->Location = System::Drawing::Point(32, 122);
			this->textBoxInputFile->Name = L"textBoxInputFile";
			this->textBoxInputFile->Size = System::Drawing::Size(203, 20);
			this->textBoxInputFile->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(29, 80);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Szyfrowanie pliku";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 50);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"D³ugoœæ klucza";
			// 
			// comboBoxKeySize
			// 
			this->comboBoxKeySize->FormattingEnabled = true;
			this->comboBoxKeySize->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"64", L"128", L"192", L"256", L"512", L"1024",
					L"2048", L"4096"
			});
			this->comboBoxKeySize->Location = System::Drawing::Point(114, 47);
			this->comboBoxKeySize->Name = L"comboBoxKeySize";
			this->comboBoxKeySize->Size = System::Drawing::Size(121, 21);
			this->comboBoxKeySize->TabIndex = 3;
			this->comboBoxKeySize->Text = L"64";
			// 
			// buttonGenerateKey
			// 
			this->buttonGenerateKey->Location = System::Drawing::Point(241, 47);
			this->buttonGenerateKey->Name = L"buttonGenerateKey";
			this->buttonGenerateKey->Size = System::Drawing::Size(73, 21);
			this->buttonGenerateKey->TabIndex = 2;
			this->buttonGenerateKey->Text = L"Wygeneruj klucz";
			this->buttonGenerateKey->UseVisualStyleBackColor = true;
			this->buttonGenerateKey->Click += gcnew System::EventHandler(this, &MyForm::buttonGenerateKey_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Generacja klucza";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog2_FileOk);
			// 
			// openFileDialog3
			// 
			this->openFileDialog3->FileName = L"openFileDialog3";
			this->openFileDialog3->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog3_FileOk);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 288);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Elgamal";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
		int keySize = 0;
		#pragma endregion
	private: System::Void buttonGenerateKey_Click(System::Object^  sender, System::EventArgs^  e) {
		keySize = Convert::ToInt32(comboBoxKeySize->Text);
		SetBigIntSize(keySize);
		auto elgamal = new ElgamalAlg();
		elgamal->generateKey(keySize);
		MessageBox::Show("Wygenerowano poprawnie klucze");
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->ShowDialog();
}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	textBoxInputFile->Text = openFileDialog1->FileName;
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog2->ShowDialog();
}
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	textBoxInputDecrypt->Text = openFileDialog2->FileName;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog3->ShowDialog();
}
private: System::Void openFileDialog3_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	textOutputFile->Text = openFileDialog3->FileName;
}
private: System::Void buttonEncrypt_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBoxInputFile->Text->Length == 0)
		MessageBox::Show("Musisz wybraæ plik do zaszyfrowania");
	
	if (textOutputFile->Text->Length == 0)
		MessageBox::Show("Musisz wybraæ nazwê pliku wyjœciowego");

	keySize = Convert::ToInt32(comboBoxKeySize->Text);
	SetBigIntSize(keySize);
	auto elgamal = new ElgamalAlg();

	elgamal->keyLenghtSet(keySize);
	elgamal->readKeyEncrypt();

	elgamal->EncryptFile(textBoxInputFile->Text, textOutputFile->Text);

	MessageBox::Show("Zaszyfrowano podany plik");
}
private: System::Void buttonDecrypt_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBoxInputDecrypt->Text->Length == 0)
		MessageBox::Show("Musisz wybraæ plik do odszyfrowania");

	if (textOutputFile->Text->Length == 0)
		MessageBox::Show("Musisz wybraæ nazwê pliku wyjœciowego");

	keySize = Convert::ToInt32(comboBoxKeySize->Text);
	SetBigIntSize(keySize);
	auto elgamal = new ElgamalAlg();

	elgamal->keyLenghtSet(keySize);
	elgamal->readKeyDecrypt();

	elgamal->DecryptFile(textBoxInputDecrypt->Text, textOutputFile->Text);

	MessageBox::Show("Odszyfrowano podany plik");
}
private: System::Void buttonGenerateKeyText_Click(System::Object^  sender, System::EventArgs^  e) {
	keySize = Convert::ToInt32(comboBoxTextKeySize->Text);
	SetBigIntSize(keySize);
	auto elgamal = new ElgamalAlg();
	elgamal->generateKey(keySize);
	MessageBox::Show("Wygenerowano poprawnie klucze");
}
private: System::Void buttonEncryptText_Click(System::Object^  sender, System::EventArgs^  e) {
	keySize = Convert::ToInt32(comboBoxTextKeySize->Text);
	String^ inputText = richTextBoxInputText->Text;

	SetBigIntSize(keySize);

	auto elgamal = new ElgamalAlg();
	elgamal->keyLenghtSet(keySize);
	elgamal->readKeyEncrypt();
	richTextBoxOutputText->Text = elgamal->encrptText(inputText);
	
	
}
private: System::Void buttonDecryptText_Click(System::Object^  sender, System::EventArgs^  e) {
	keySize = Convert::ToInt32(comboBoxTextKeySize->Text);
	String^ inputText = richTextBoxInputText->Text;

	SetBigIntSize(keySize);


	auto elgamal = new ElgamalAlg();
	elgamal->keyLenghtSet(keySize);
	elgamal->readKeyDecrypt();
	String^ tekst = elgamal->decryptText(inputText);
	String^ tekst2 = "";

	for (int i = 0; i < tekst->Length; i++) {
		if (tekst[i] != '\0') {
			tekst2 += tekst[i];
		}
			
	}
	richTextBoxOutputText->Text = tekst2;
}
};
}

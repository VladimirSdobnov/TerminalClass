#pragma once
#include "Rational.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung fьr Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufьgen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ plus;
	private: System::Windows::Forms::Button^ minus;
	private: System::Windows::Forms::Button^ multiplicate;
	private: System::Windows::Forms::Button^ divizion;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode fьr die Designerunterstьtzung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geдndert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->multiplicate = (gcnew System::Windows::Forms::Button());
			this->divizion = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->divizion);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->plus);
			this->groupBox1->Controls->Add(this->minus);
			this->groupBox1->Controls->Add(this->multiplicate);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(362, 244);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Главное меню";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(4, 91);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(62, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Результат:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(98, 48);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(48, 20);
			this->textBox3->TabIndex = 9;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(150, 48);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(48, 20);
			this->textBox4->TabIndex = 8;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(150, 24);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(48, 20);
			this->textBox2->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(98, 24);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(48, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->Location = System::Drawing::Point(0, 0);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(75, 19);
			this->label3->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(4, 53);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Второе число";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(4, 31);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Первое число";
			// 
			// plus
			// 
			this->plus->Location = System::Drawing::Point(219, 24);
			this->plus->Margin = System::Windows::Forms::Padding(2);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(44, 20);
			this->plus->TabIndex = 2;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = true;
			this->plus->Click += gcnew System::EventHandler(this, &Form1::plus_Click);
			// 
			// minus
			// 
			this->minus->Location = System::Drawing::Point(219, 48);
			this->minus->Margin = System::Windows::Forms::Padding(2);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(44, 20);
			this->minus->TabIndex = 1;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = true;
			this->minus->Click += gcnew System::EventHandler(this, &Form1::minus_Click);
			// 
			// multiplicate
			// 
			this->multiplicate->Location = System::Drawing::Point(267, 24);
			this->multiplicate->Margin = System::Windows::Forms::Padding(2);
			this->multiplicate->Name = L"multiplicate";
			this->multiplicate->Size = System::Drawing::Size(44, 21);
			this->multiplicate->TabIndex = 0;
			this->multiplicate->Text = L"*";
			this->multiplicate->UseVisualStyleBackColor = true;
			this->multiplicate->Click += gcnew System::EventHandler(this, &Form1::multiplicate_Click);
			// 
			// divizion
			// 
			this->divizion->Location = System::Drawing::Point(267, 48);
			this->divizion->Margin = System::Windows::Forms::Padding(2);
			this->divizion->Name = L"divizion";
			this->divizion->Size = System::Drawing::Size(44, 20);
			this->divizion->TabIndex = 14;
			this->divizion->Text = L"/";
			this->divizion->UseVisualStyleBackColor = true;
			this->divizion->Click += gcnew System::EventHandler(this, &Form1::divizion_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(380, 265);
			this->Controls->Add(this->groupBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void plus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" ||
			textBox4->Text == "")
			MessageBox::Show(this, "Числа не указанны!", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			Rational A(int::Parse(textBox1->Text), int::Parse(textBox2->Text));
			Rational B(int::Parse(textBox3->Text), int::Parse(textBox4->Text));
			Rational Res = A + B;
			label4->Text = "Результат: " + (Res.get_numerator()).ToString() + "/" + (Res.get_denominator().ToString());
		}
	}
	private: System::Void multiplicate_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" ||
			textBox4->Text == "")
			MessageBox::Show(this, "Числа не указанны!", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			Rational A(int::Parse(textBox1->Text), int::Parse(textBox2->Text));
			Rational B(int::Parse(textBox3->Text), int::Parse(textBox4->Text));
			Rational Res = A * B;

			label4->Text = "Результат: " + (Res.get_numerator()).ToString() + "/" + (Res.get_denominator().ToString());
		}
	}
	private: System::Void minus_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" ||
			textBox4->Text == "")
			MessageBox::Show(this, "Числа не указанны!", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			Rational A(int::Parse(textBox1->Text), int::Parse(textBox2->Text));
			Rational B(int::Parse(textBox3->Text), int::Parse(textBox4->Text));
			Rational Res = A - B;

			label4->Text = "Результат: " + (Res.get_numerator()).ToString() + "/" + (Res.get_denominator().ToString());
		}
	}
	private: System::Void divizion_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox1->Text == "" || textBox2->Text == "" || textBox3->Text == "" ||
			textBox4->Text == "")
			MessageBox::Show(this, "Числа не указанны!", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			Rational A(int::Parse(textBox1->Text), int::Parse(textBox2->Text));
			Rational B(int::Parse(textBox3->Text), int::Parse(textBox4->Text));
			Rational Res = A / B;

			label4->Text = "Результат: " + (Res.get_numerator()).ToString() + "/" + (Res.get_denominator().ToString());
		}
	}
private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}

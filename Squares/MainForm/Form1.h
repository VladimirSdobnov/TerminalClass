#pragma once
#include "Rational.h"
#include "Pred.h"

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
	private: System::Windows::Forms::TextBox^ Salary_box;



	private: System::Windows::Forms::TextBox^ Post_box;
	private: System::Windows::Forms::TextBox^ FIO_box;



	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ Post_label;

	private: System::Windows::Forms::Label^ FIO_lable;




	private: System::Windows::Forms::Button^ plus;
	private: System::Windows::Forms::Button^ minus;
	private: System::Windows::Forms::Button^ multiplicate;
	private: System::Windows::Forms::Button^ divizion;
	private: System::Windows::Forms::Label^ Salary_label;


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
			this->divizion = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Salary_box = (gcnew System::Windows::Forms::TextBox());
			this->Post_box = (gcnew System::Windows::Forms::TextBox());
			this->FIO_box = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Post_label = (gcnew System::Windows::Forms::Label());
			this->FIO_lable = (gcnew System::Windows::Forms::Label());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->multiplicate = (gcnew System::Windows::Forms::Button());
			this->Salary_label = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Salary_label);
			this->groupBox1->Controls->Add(this->divizion);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->Salary_box);
			this->groupBox1->Controls->Add(this->Post_box);
			this->groupBox1->Controls->Add(this->FIO_box);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->Post_label);
			this->groupBox1->Controls->Add(this->FIO_lable);
			this->groupBox1->Controls->Add(this->plus);
			this->groupBox1->Controls->Add(this->minus);
			this->groupBox1->Controls->Add(this->multiplicate);
			this->groupBox1->Location = System::Drawing::Point(9, 10);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(749, 511);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Главное меню";
			// 
			// divizion
			// 
			this->divizion->Location = System::Drawing::Point(199, 283);
			this->divizion->Margin = System::Windows::Forms::Padding(2);
			this->divizion->Name = L"divizion";
			this->divizion->Size = System::Drawing::Size(44, 20);
			this->divizion->TabIndex = 14;
			this->divizion->Text = L"/";
			this->divizion->UseVisualStyleBackColor = true;
			this->divizion->Click += gcnew System::EventHandler(this, &Form1::divizion_Click);
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
			// Salary_box
			// 
			this->Salary_box->Location = System::Drawing::Point(247, 30);
			this->Salary_box->Margin = System::Windows::Forms::Padding(2);
			this->Salary_box->Name = L"Salary_box";
			this->Salary_box->Size = System::Drawing::Size(87, 20);
			this->Salary_box->TabIndex = 9;
			this->Salary_box->TextChanged += gcnew System::EventHandler(this, &Form1::textBox3_TextChanged);
			// 
			// Post_box
			// 
			this->Post_box->Location = System::Drawing::Point(132, 30);
			this->Post_box->Margin = System::Windows::Forms::Padding(2);
			this->Post_box->Name = L"Post_box";
			this->Post_box->Size = System::Drawing::Size(111, 20);
			this->Post_box->TabIndex = 8;
			// 
			// FIO_box
			// 
			this->FIO_box->Location = System::Drawing::Point(0, 30);
			this->FIO_box->Margin = System::Windows::Forms::Padding(2);
			this->FIO_box->Name = L"FIO_box";
			this->FIO_box->Size = System::Drawing::Size(126, 20);
			this->FIO_box->TabIndex = 7;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(128, 436);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(48, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Post_label
			// 
			this->Post_label->AutoSize = true;
			this->Post_label->Location = System::Drawing::Point(155, 15);
			this->Post_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Post_label->Name = L"Post_label";
			this->Post_label->Size = System::Drawing::Size(65, 13);
			this->Post_label->TabIndex = 4;
			this->Post_label->Text = L"Должность";
			this->Post_label->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// FIO_lable
			// 
			this->FIO_lable->AutoSize = true;
			this->FIO_lable->Location = System::Drawing::Point(48, 15);
			this->FIO_lable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->FIO_lable->Name = L"FIO_lable";
			this->FIO_lable->Size = System::Drawing::Size(34, 13);
			this->FIO_lable->TabIndex = 3;
			this->FIO_lable->Text = L"ФИО";
			this->FIO_lable->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// plus
			// 
			this->plus->Location = System::Drawing::Point(51, 283);
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
			this->minus->Location = System::Drawing::Point(132, 283);
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
			this->multiplicate->Location = System::Drawing::Point(267, 282);
			this->multiplicate->Margin = System::Windows::Forms::Padding(2);
			this->multiplicate->Name = L"multiplicate";
			this->multiplicate->Size = System::Drawing::Size(44, 21);
			this->multiplicate->TabIndex = 0;
			this->multiplicate->Text = L"*";
			this->multiplicate->UseVisualStyleBackColor = true;
			this->multiplicate->Click += gcnew System::EventHandler(this, &Form1::multiplicate_Click);
			// 
			// Salary_label
			// 
			this->Salary_label->AutoSize = true;
			this->Salary_label->Location = System::Drawing::Point(264, 15);
			this->Salary_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Salary_label->Name = L"Salary_label";
			this->Salary_label->Size = System::Drawing::Size(55, 13);
			this->Salary_label->TabIndex = 15;
			this->Salary_label->Text = L"Зарплата";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(769, 532);
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
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}


};
}

#pragma once
#include "Rational.h"
#include "Pred.h"
#include <msclr\marshal_cppstd.h>

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
	private: System::Windows::Forms::Label^ Annual_label;
	protected:

	private: System::Windows::Forms::TextBox^ Salary_box;



	private: System::Windows::Forms::TextBox^ Post_box;
	private: System::Windows::Forms::TextBox^ FIO_box;
	private: System::Windows::Forms::TextBox^ Annual_box;




	private: System::Windows::Forms::Label^ Post_label;

	private: System::Windows::Forms::Label^ FIO_lable;
	private: System::Windows::Forms::Button^ sort_name_button;






	private: System::Windows::Forms::Button^ add_button;

	private: System::Windows::Forms::Button^ multiplicate;
	private: System::Windows::Forms::Button^ divizion;
	private: System::Windows::Forms::Label^ Salary_label;
	private: System::Windows::Forms::TextBox^ experience_box;
	private: System::Windows::Forms::TextBox^ date_box;
	private: System::Windows::Forms::Label^ date_label;
	private: System::Windows::Forms::Label^ experience_label;
	private: System::Windows::Forms::Label^ phone_label;
	private: System::Windows::Forms::Label^ email_label;
	private: System::Windows::Forms::Label^ adres_label;
	private: System::Windows::Forms::TextBox^ email_box;

	private: System::Windows::Forms::TextBox^ phone_box;
	private: System::Windows::Forms::TextBox^ adres_box;
	private: System::Windows::Forms::TextBox^ title_box;

	private: System::Windows::Forms::Label^ title_lable;




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
			this->adres_box = (gcnew System::Windows::Forms::TextBox());
			this->email_box = (gcnew System::Windows::Forms::TextBox());
			this->phone_box = (gcnew System::Windows::Forms::TextBox());
			this->phone_label = (gcnew System::Windows::Forms::Label());
			this->email_label = (gcnew System::Windows::Forms::Label());
			this->adres_label = (gcnew System::Windows::Forms::Label());
			this->experience_box = (gcnew System::Windows::Forms::TextBox());
			this->date_box = (gcnew System::Windows::Forms::TextBox());
			this->date_label = (gcnew System::Windows::Forms::Label());
			this->experience_label = (gcnew System::Windows::Forms::Label());
			this->Salary_label = (gcnew System::Windows::Forms::Label());
			this->divizion = (gcnew System::Windows::Forms::Button());
			this->Annual_label = (gcnew System::Windows::Forms::Label());
			this->Salary_box = (gcnew System::Windows::Forms::TextBox());
			this->Post_box = (gcnew System::Windows::Forms::TextBox());
			this->FIO_box = (gcnew System::Windows::Forms::TextBox());
			this->Annual_box = (gcnew System::Windows::Forms::TextBox());
			this->Post_label = (gcnew System::Windows::Forms::Label());
			this->FIO_lable = (gcnew System::Windows::Forms::Label());
			this->sort_name_button = (gcnew System::Windows::Forms::Button());
			this->add_button = (gcnew System::Windows::Forms::Button());
			this->multiplicate = (gcnew System::Windows::Forms::Button());
			this->title_lable = (gcnew System::Windows::Forms::Label());
			this->title_box = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->title_box);
			this->groupBox1->Controls->Add(this->title_lable);
			this->groupBox1->Controls->Add(this->adres_box);
			this->groupBox1->Controls->Add(this->email_box);
			this->groupBox1->Controls->Add(this->phone_box);
			this->groupBox1->Controls->Add(this->phone_label);
			this->groupBox1->Controls->Add(this->email_label);
			this->groupBox1->Controls->Add(this->adres_label);
			this->groupBox1->Controls->Add(this->experience_box);
			this->groupBox1->Controls->Add(this->date_box);
			this->groupBox1->Controls->Add(this->date_label);
			this->groupBox1->Controls->Add(this->experience_label);
			this->groupBox1->Controls->Add(this->Salary_label);
			this->groupBox1->Controls->Add(this->divizion);
			this->groupBox1->Controls->Add(this->Annual_label);
			this->groupBox1->Controls->Add(this->Salary_box);
			this->groupBox1->Controls->Add(this->Post_box);
			this->groupBox1->Controls->Add(this->FIO_box);
			this->groupBox1->Controls->Add(this->Annual_box);
			this->groupBox1->Controls->Add(this->Post_label);
			this->groupBox1->Controls->Add(this->FIO_lable);
			this->groupBox1->Controls->Add(this->sort_name_button);
			this->groupBox1->Controls->Add(this->add_button);
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
			// adres_box
			// 
			this->adres_box->Location = System::Drawing::Point(238, 67);
			this->adres_box->Margin = System::Windows::Forms::Padding(2);
			this->adres_box->Name = L"adres_box";
			this->adres_box->Size = System::Drawing::Size(104, 20);
			this->adres_box->TabIndex = 25;
			// 
			// email_box
			// 
			this->email_box->Location = System::Drawing::Point(130, 67);
			this->email_box->Margin = System::Windows::Forms::Padding(2);
			this->email_box->Name = L"email_box";
			this->email_box->Size = System::Drawing::Size(104, 20);
			this->email_box->TabIndex = 24;
			// 
			// phone_box
			// 
			this->phone_box->Location = System::Drawing::Point(22, 67);
			this->phone_box->Margin = System::Windows::Forms::Padding(2);
			this->phone_box->Name = L"phone_box";
			this->phone_box->Size = System::Drawing::Size(104, 20);
			this->phone_box->TabIndex = 23;
			this->phone_box->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged_1);
			// 
			// phone_label
			// 
			this->phone_label->AutoSize = true;
			this->phone_label->Location = System::Drawing::Point(43, 52);
			this->phone_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->phone_label->Name = L"phone_label";
			this->phone_label->Size = System::Drawing::Size(52, 13);
			this->phone_label->TabIndex = 22;
			this->phone_label->Text = L"Телефон";
			// 
			// email_label
			// 
			this->email_label->AutoSize = true;
			this->email_label->Location = System::Drawing::Point(174, 52);
			this->email_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->email_label->Name = L"email_label";
			this->email_label->Size = System::Drawing::Size(34, 13);
			this->email_label->TabIndex = 21;
			this->email_label->Text = L"e-mail";
			this->email_label->Click += gcnew System::EventHandler(this, &Form1::email_label_Click);
			// 
			// adres_label
			// 
			this->adres_label->AutoSize = true;
			this->adres_label->Location = System::Drawing::Point(273, 52);
			this->adres_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->adres_label->Name = L"adres_label";
			this->adres_label->Size = System::Drawing::Size(38, 13);
			this->adres_label->TabIndex = 20;
			this->adres_label->Text = L"Адрес";
			this->adres_label->Click += gcnew System::EventHandler(this, &Form1::adres_label_Click);
			// 
			// experience_box
			// 
			this->experience_box->Location = System::Drawing::Point(561, 30);
			this->experience_box->Margin = System::Windows::Forms::Padding(2);
			this->experience_box->Name = L"experience_box";
			this->experience_box->Size = System::Drawing::Size(111, 20);
			this->experience_box->TabIndex = 19;
			// 
			// date_box
			// 
			this->date_box->Location = System::Drawing::Point(446, 30);
			this->date_box->Margin = System::Windows::Forms::Padding(2);
			this->date_box->Name = L"date_box";
			this->date_box->Size = System::Drawing::Size(111, 20);
			this->date_box->TabIndex = 18;
			// 
			// date_label
			// 
			this->date_label->AutoSize = true;
			this->date_label->Location = System::Drawing::Point(446, 15);
			this->date_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->date_label->Name = L"date_label";
			this->date_label->Size = System::Drawing::Size(111, 13);
			this->date_label->TabIndex = 17;
			this->date_label->Text = L"Дата начала работы";
			// 
			// experience_label
			// 
			this->experience_label->AutoSize = true;
			this->experience_label->Location = System::Drawing::Point(580, 15);
			this->experience_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->experience_label->Name = L"experience_label";
			this->experience_label->Size = System::Drawing::Size(74, 13);
			this->experience_label->TabIndex = 16;
			this->experience_label->Text = L"Опыт работы";
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
			// divizion
			// 
			this->divizion->Location = System::Drawing::Point(323, 105);
			this->divizion->Margin = System::Windows::Forms::Padding(2);
			this->divizion->Name = L"divizion";
			this->divizion->Size = System::Drawing::Size(103, 37);
			this->divizion->TabIndex = 14;
			this->divizion->Text = L"/";
			this->divizion->UseVisualStyleBackColor = true;
			this->divizion->Click += gcnew System::EventHandler(this, &Form1::divizion_Click);
			// 
			// Annual_label
			// 
			this->Annual_label->AutoSize = true;
			this->Annual_label->Location = System::Drawing::Point(344, 15);
			this->Annual_label->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->Annual_label->Name = L"Annual_label";
			this->Annual_label->Size = System::Drawing::Size(98, 13);
			this->Annual_label->TabIndex = 12;
			this->Annual_label->Text = L"Годовая нагрузка";
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
			// Annual_box
			// 
			this->Annual_box->Location = System::Drawing::Point(338, 30);
			this->Annual_box->Margin = System::Windows::Forms::Padding(2);
			this->Annual_box->Name = L"Annual_box";
			this->Annual_box->Size = System::Drawing::Size(104, 20);
			this->Annual_box->TabIndex = 6;
			this->Annual_box->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
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
			// sort_name_button
			// 
			this->sort_name_button->Location = System::Drawing::Point(108, 105);
			this->sort_name_button->Margin = System::Windows::Forms::Padding(2);
			this->sort_name_button->Name = L"sort_name_button";
			this->sort_name_button->Size = System::Drawing::Size(104, 37);
			this->sort_name_button->TabIndex = 2;
			this->sort_name_button->Text = L"Сортировать по имени";
			this->sort_name_button->UseVisualStyleBackColor = true;
			this->sort_name_button->Click += gcnew System::EventHandler(this, &Form1::sort_name_button_Click);
			// 
			// add_button
			// 
			this->add_button->Location = System::Drawing::Point(0, 105);
			this->add_button->Margin = System::Windows::Forms::Padding(2);
			this->add_button->Name = L"add_button";
			this->add_button->Size = System::Drawing::Size(104, 37);
			this->add_button->TabIndex = 1;
			this->add_button->Text = L"Добавить запись";
			this->add_button->UseVisualStyleBackColor = true;
			this->add_button->Click += gcnew System::EventHandler(this, &Form1::add_button_Click);
			// 
			// multiplicate
			// 
			this->multiplicate->Location = System::Drawing::Point(216, 105);
			this->multiplicate->Margin = System::Windows::Forms::Padding(2);
			this->multiplicate->Name = L"multiplicate";
			this->multiplicate->Size = System::Drawing::Size(103, 37);
			this->multiplicate->TabIndex = 0;
			this->multiplicate->Text = L"*";
			this->multiplicate->UseVisualStyleBackColor = true;
			this->multiplicate->Click += gcnew System::EventHandler(this, &Form1::multiplicate_Click);
			// 
			// title_lable
			// 
			this->title_lable->AutoSize = true;
			this->title_lable->Location = System::Drawing::Point(382, 52);
			this->title_lable->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->title_lable->Name = L"title_lable";
			this->title_lable->Size = System::Drawing::Size(88, 13);
			this->title_lable->TabIndex = 26;
			this->title_lable->Text = L"Ученая степень";
			this->title_lable->Click += gcnew System::EventHandler(this, &Form1::title_lable_Click);
			// 
			// title_box
			// 
			this->title_box->Location = System::Drawing::Point(346, 67);
			this->title_box->Margin = System::Windows::Forms::Padding(2);
			this->title_box->Name = L"title_box";
			this->title_box->Size = System::Drawing::Size(154, 20);
			this->title_box->TabIndex = 27;
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
	private: System::Void sort_name_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
	private: System::Void add_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (FIO_box->Text == "")
			MessageBox::Show(this, "Укажите имя!", "Сообщение",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
		else {
			std::string fio_string = msclr::interop::marshal_as<std::string>(FIO_box->Text);
			std::string date_string = msclr::interop::marshal_as<std::string>(date_box->Text);
			
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


private: System::Void email_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void adres_label_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void title_lable_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}

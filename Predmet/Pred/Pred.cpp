#include <iostream>
#include <stdlib.h>
#include <time.h>

class SNS {
	std::string surname;
	std::string name;
	std::string secondname;

	SNS() {
		surname = "";
		name = "";
		secondname = "";
	}
	SNS(std::string _surname, std::string _name, std::string _secondname) {
		surname = _surname;
		name = _name;
		secondname = _secondname;
	}
	SNS(const SNS& _sns) {
		name = _sns.name;
		surname = _sns.surname;
		secondname = _sns.secondname;
	}

	void swap(SNS& _sns) {
		std::swap(name, _sns.name);
		std::swap(surname, _sns.surname);
		std::swap(secondname, _sns.secondname);
	}
	SNS& operator=(const SNS& _sns){
		if (this != &_sns) {
			SNS tmp(_sns);
			this->swap(tmp);
		}
		return *this;
	}
	bool operator==(const SNS& _sns) const {
		return (name == _sns.name && surname == _sns.surname && secondname == _sns.secondname);
	}
	bool operator!=(const SNS& _sns) const {
		return not((name == _sns.name && surname == _sns.surname && secondname == _sns.secondname));
	}
	bool operator>(const SNS& _sns) const;
	bool operator<(const SNS& _sns) const;

	void set_surname(const std::string _surname) {
		surname = _surname;
	}
	void set_name(const std::string _name) {
		name = _name;
	}
	void set_secondname(const std::string _secondname) {
		surname = _secondname;
	}
	std::string get_surname() const {
		return surname;
	}
	std::string get_name() const {
		return name;
	}
	std::string get_surname() const {
		return surname;
	}
};

class Contact_details {
	std::string phone_number;
	std::string email;
	std::string adress;

	Contact_details() {
		phone_number = "";
		email = "";
		adress = "";
	}
	Contact_details(const Contact_details& _contact) {
		phone_number = _contact.phone_number;
		email = _contact.email;
		adress = _contact.adress;
	}

	void set_phone_number(const std::string _phone) {
		phone_number = _phone;
	}
	void set_email(const std::string _email) {
		email = _email;
	}
	void set_adress(const std::string _adress) {
		adress = _adress;
	}
	std::string get_phone_number() const {
		return phone_number;
	}
	std::string get_email() const {
		return email;
	}
	std::string get_adress() const {
		return adress;
	}
};

class Post {
	std::string post_name;
	float salary;
	int annual_load;

	Post() {
		salary = 0;
		annual_load = 0;
		post_name = "";
	}
	Post(std::string _post_name, float _salary, int _annual_load) {
		post_name = _post_name;
		salary = _salary;
		annual_load = _annual_load;
	}
	Post(const Post& _post) {
		post_name = _post.post_name;
		salary = _post.salary;
		annual_load = _post.annual_load;
	}


};

class Date {

};

class Teacher {
	SNS sns;
	Post post;
	std::string scientific_title;
	Date start_work_date;
	int experience;
	float personal_coefficient;
};

class Department {
	Teacher* teachers;
	Teacher head_departmens;
	Contact_details departmens_contact;
};
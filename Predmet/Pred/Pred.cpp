#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Pred.h"


FIO::FIO() {
	surname = "";
	name = "";
	secondname = "";
}
FIO::FIO(std::string _surname, std::string _name, std::string _secondname) {
	surname = _surname;
	name = _name;
	secondname = _secondname;
}
FIO::FIO(const FIO& _sns) {
	name = _sns.name;
	surname = _sns.surname;
	secondname = _sns.secondname;
}
void FIO::swap(FIO& _sns) {
	std::swap(name, _sns.name);
	std::swap(surname, _sns.surname);
	std::swap(secondname, _sns.secondname);
}
FIO& FIO::operator=(const FIO& _sns) {
	if (this != &_sns) {
		FIO tmp(_sns);
		this->swap(tmp);
	}
	return *this;
}
bool FIO::operator==(const FIO& _sns) const {
	return (name == _sns.name && surname == _sns.surname && secondname == _sns.secondname);
}
bool FIO::operator!=(const FIO& _sns) const {
	return not((name == _sns.name && surname == _sns.surname && secondname == _sns.secondname));
}
bool FIO::operator>(const FIO& _sns) const {
	if (*this == _sns) {
		return 0;
	}
	else if (this->surname > _sns.name) {
		return 1;
	}
	else if (this->name > _sns.name) {
		return 1;
	}
	else if (this->secondname > _sns.secondname) {
		return 1;
	}
	else { return 0; }
}
bool FIO::operator>=(const FIO& _sns) const {
	return (*this > _sns) || (*this == _sns);
}
bool FIO::operator<(const FIO& _sns) const {
	if (*this == _sns) {
		return 0;
	}
	else if (this->surname < _sns.name) {
		return 1;
	}
	else if (this->name < _sns.name) {
		return 1;
	}
	else if (this->secondname < _sns.secondname) {
		return 1;
	}
	else { return 0; }
}
bool FIO::operator<=(const FIO& _sns) const {
	return not((*this > _sns) || (*this == _sns));
}
void FIO::set_surname(const std::string _surname) {
	surname = _surname;
}
void FIO::set_name(const std::string _name) {
	name = _name;
}
void FIO::set_secondname(const std::string _secondname) {
	surname = _secondname;
}
std::string FIO::get_surname() const {
	return surname;
}
std::string FIO::get_name() const {
	return name;
}
std::string FIO::get_surname() const {
	return surname;
}



Contact_details::Contact_details() {
	phone_number = "";
	email = "";
	adress = "";
}
Contact_details::Contact_details(std::string _phone, std::string _email, std::string _adress) {
	phone_number = _phone;
	email = _email;
	adress = _adress;
}
Contact_details::Contact_details(const Contact_details& _contact) {
	phone_number = _contact.phone_number;
	email = _contact.email;
	adress = _contact.adress;
}
void Contact_details::set_phone_number(const std::string _phone) {
	phone_number = _phone;
}
void Contact_details::set_email(const std::string _email) {
	email = _email;
}
void Contact_details::set_adress(const std::string _adress) {
	adress = _adress;
}
std::string Contact_details::get_phone_number() const {
	return phone_number;
}
std::string Contact_details::get_email() const {
	return email;
}
std::string Contact_details::get_adress() const {
	return adress;
}
void Contact_details::swap(Contact_details& _contact) {
	std::swap(phone_number, _contact.phone_number);
	std::swap(email, _contact.email);
	std::swap(adress, _contact.adress);
}
Contact_details& Contact_details::operator=(const Contact_details& _contact) {
	if (this != &_contact) {
		Contact_details tmp(_contact);
		this->swap(tmp);
	}
	return *this;
}



Worker::Worker() {
	salary = 0;
	annual_load = 0;
	post_name = "";
}
Worker::Worker(FIO _fio, std::string _post_name, float _salary, int _annual_load, Date _start_work, int experience) {
	fio = _fio;
	post_name = _post_name;
	salary = _salary;
	annual_load = _annual_load;
	start_work_date = _start_work;
	experience = experience;
}
Worker::Worker(const Worker& _post) {
	post_name = _post.post_name;
	salary = _post.salary;
	annual_load = _post.annual_load;
}

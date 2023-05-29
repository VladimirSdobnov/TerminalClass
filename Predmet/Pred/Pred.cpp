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
std::string FIO::get_secondname() const {
	return secondname;
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
	experience = 0;
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
	fio = _post.fio;
	post_name = _post.post_name;
	salary = _post.salary;
	annual_load = _post.annual_load;
	start_work_date = _post.start_work_date;
	experience = _post.experience;
}



Date::Date() {
	day = 1;
	month = 1;
	year = 1950;
}
Date::Date(int _day, int _month, int _year) {
	if ((_day > 0 && _month > 0 && _year > 0) && (_day < 32 && _month < 13)) {
		if ((_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) && _day <= 31) {
			day = _day;
			month = _month;
			year = _year;
		}
		if ((_month == 4 || _month == 6 || _month == 9 || _month == 11) && _day <= 30) {
			day = _day;
			month = _month;
			year = _year;
		}
		if ((_month == 2 && _year % 4 == 0 && _day <= 29) || (_month == 2 && _year % 4 != 0 && _day <= 28)) {
			day = _day;
			month = _month;
			year = _year;
		}
	}
	else {
		throw std::logic_error("invalid date");
	}
	
}
Date::Date(const Date& _date) {
	day = _date.day;
	month = _date.month;
	year = _date.year;
}
bool Date::operator>(const Date& _date) const {
	if (year > _date.year) { return true; }
	if (year < _date.year) { return false; }
	if (month > _date.month) { return true; }
	if (month < _date.month) { return false; }
	if (day > _date.day) { return true; }
	if (day < _date.day) { return false; }
	return false;
	
}
Date& Date::operator=(const Date& _date) {
	if (this != &_date) {
		day = _date.day;
		month = _date.month;
		year = _date.year;
	}
	return *this;
}
bool Date::operator==(const Date& _date) const {
	return day == _date.day && month == _date.month && year == _date.year;
}
void Date::swap(Date& _date) {
	std::swap(day, _date.day);
	std::swap(month, _date.month);
	std::swap(year, _date.year);
}



Teacher::Teacher() {};
Teacher::Teacher(FIO _fio, std::string _post_name, float _salary, int _annual_load, Date _start_work, int _experience, std::string _title, Contact_details _details) {
	fio = _fio;
	post_name = _post_name;
	salary = _salary;
	annual_load = _annual_load;
	start_work_date = _start_work;
	experience = _experience;
	scientific_title = _title;
	contact = _details;
}
void Teacher::swap(Teacher& _teacher) {
	fio.swap(_teacher.fio);
	std::swap(post_name, _teacher.post_name);
	std::swap(salary, _teacher.salary);
	std::swap(annual_load, _teacher.annual_load);
	start_work_date.swap(_teacher.start_work_date);
	std::swap(experience, _teacher.experience);
	std::swap(scientific_title, _teacher.scientific_title);
}


Department::Department() {
	teachers = NULL;
	count = 0;
	head_departmens = NULL;
}
void Department::add_teacher(const Teacher& teacher) {
	Teacher* tmp_mass = new Teacher[count + 1];
	for (int i = 0; i < count; i++) { tmp_mass[i] = teachers[i]; }
	tmp_mass[count] = teacher;
	delete[] teachers;
	teachers = tmp_mass;
	count++;
}
void Department::sort_fio() {
	int left = 0;
	int right = count - 1;
	while (left <= right) {
		for (int i = right; i > left; --i) {
			if (teachers[i - 1].fio > teachers[i].fio) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i) {
			if (teachers[i - 1].fio > teachers[i].fio) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		--right;
	}
}
void Department::sort_post_name() {
	int left = 0;
	int right = count - 1;
	while (left <= right) {
		for (int i = right; i > left; --i) {
			if (teachers[i - 1].post_name > teachers[i].post_name) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i) {
			if (teachers[i - 1].post_name > teachers[i].post_name) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		--right;
	}
}
void Department::sort_start_work() {
	int left = 0;
	int right = count - 1;
	while (left <= right) {
		for (int i = right; i > left; --i) {
			if (teachers[i - 1].start_work_date > teachers[i].start_work_date) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i) {
			if (teachers[i - 1].start_work_date > teachers[i].start_work_date) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		--right;
	}
}
void Department::sort_annual() {
	int left = 0;
	int right = count - 1;
	while (left <= right) {
		for (int i = right; i > left; --i) {
			if (teachers[i - 1].annual_load > teachers[i].annual_load) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i) {
			if (teachers[i - 1].annual_load > teachers[i].annual_load) {
				teachers[i - 1].swap(teachers[i]);
			}
		}
		--right;
	}
}
Department::~Department() {
	delete[] teachers;
}

std::string split(std::string& string, char del) {
	std::string tmp = "";
	int i = 0;
	while (string[i] != del && i < string.length()) {
		tmp = tmp + string[i];
		i++;
	}
	if (i + 1 < string.length()) {
		string = string.substr(i + 1);
	}
	else {
		string = string.substr(i);
	}
	return tmp;
}
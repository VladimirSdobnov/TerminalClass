#include <iostream>
#include <stdlib.h>
#include <time.h>

class FIO {
	std::string surname;
	std::string name;
	std::string secondname;
public:
	FIO();
	FIO(std::string _surname, std::string _name, std::string _secondname);
	FIO(const FIO& _sns);
private:
	void swap(FIO& _sns);
public:
	FIO& operator=(const FIO& _sns);
	bool operator==(const FIO& _sns) const;
	bool operator!=(const FIO& _sns) const;
	bool operator>(const FIO& _sns) const;
	bool operator>=(const FIO& _sns) const;
	bool operator<(const FIO& _sns) const;
	bool operator<=(const FIO& _sns) const;

	void set_surname(const std::string _surname);
	void set_name(const std::string _name);
	void set_secondname(const std::string _secondname);
	std::string get_surname() const;
	std::string get_name() const;
	std::string get_surname() const;
};

class Contact_details {
	std::string phone_number;
	std::string email;
	std::string adress;

public:
	Contact_details();
	Contact_details(std::string _phone, std::string _email, std::string _adress);
	Contact_details(const Contact_details& _contact);

	void set_phone_number(const std::string _phone);
	void set_email(const std::string _email);
	void set_adress(const std::string _adress);
	std::string get_phone_number() const;
	std::string get_email() const;
	std::string get_adress() const;
private:
	void swap(Contact_details& _contact);
	Contact_details& operator=(const Contact_details& _contact);
};

class Worker {
protected:
	FIO fio;
	std::string post_name;
	float salary;
	int annual_load;
	Date start_work_date;
	int experience;
	float personal_coefficient;
public:
	Worker();
	Worker(FIO _fio, std::string _post_name, float _salary, int _annual_load, Date _start_work, int experience);
	Worker(const Worker& _post);
};

class Date {
	int day;
	int month;
	int year;
public:
	Date();
	Date(int _day, int _month, int _year);
	Date(const Date& _date);
	bool operator>(const Date& _date) const;
	Date& operator=(const Date& _date);
	bool operator==(const Date& _sns) const;
};

class Teacher : Worker {
	std::string scientific_title;
public:
	Teacher();
	Teacher(FIO _fio, std::string _post_name, float _salary, int _annual_load, Date _start_work, int experience, std::string title);
};

class Department {
	Teacher* teachers;
	int count;
	Teacher* head_departmens;
	Contact_details departmens_contact;
public:
	Department();
	Department(const Department& _dep);
	void sort_fio();
	void sort_post_name();
	void sort_start_work();
	void sort_annual();
	void add_teacher(const Teacher& teacher);
	Teacher found_name(const FIO& fio);
	Teacher* found_post(const std::string post);
};

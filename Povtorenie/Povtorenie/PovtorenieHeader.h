#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80
#define KEY_ENTER 13
#define KEY_SPACE 32
#define KEY_ESCAPE 27

class FIO {
	std::string surname;
	std::string name;
	std::string secondname;
public:
	FIO();
	FIO(std::string _surname, std::string _name, std::string _secondname);
	FIO(const FIO& _sns);
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
	std::string get_secondname() const;
	friend std::ostream& operator<<(std::ostream& os, const FIO& stud);
};

std::ostream& operator<<(std::ostream& os, const FIO& stud);

class Student {
	FIO fio;
	int id;
	float av_mark;
	char base_st;
	char scholarship;
	static int last_id;
public:
	Student();
	Student(const Student& stud);
	Student(FIO _fio, float _av_mark, char _base_st, char _scholarship);
	~Student();
	void swap(Student& stud);
	Student& operator=(const Student& _stud);
	friend std::ostream& operator<<(std::ostream& os, const Student& stud);
	friend class Archive;
};

std::ostream& operator<<(std::ostream& os, const Student& stud);

class Archive {
public:
	std::string name;
	int quant;
	Student* students;
	Archive(std::string _name);
	~Archive();
	void add_stud(const Student& stud);
	Student& found_FIO(const FIO& _fio);
	int delete_id(int _id);
	void sort();
};


void cursor_move(std::string* menu_names, int menu_size, short* choose_pos, int* iKey);
void constract_MainMenu(Archive archive);
#include "PovtorenieHeader.h"

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
std::ostream& operator<<(std::ostream& os, const FIO& stud) {
	os << stud.surname << ' ' << stud.name << ' ' << stud.secondname;
	return os;
}


int Student::last_id = 10000000;
Student::Student() {
	id = last_id + 1;
	last_id++;
	av_mark = 0;
	base_st = '-';
	scholarship = '-';
}
Student::Student(const Student& stud) {
	fio = stud.fio;
	id = stud.id;
	av_mark = stud.av_mark;
	base_st = stud.base_st;
	scholarship = stud.scholarship;
}
Student::Student(FIO _fio, float _av_mark, char _base_st, char _scholarship) {
	fio = _fio;
	id = last_id + 1;
	last_id++;
	av_mark = _av_mark;
	base_st = _base_st;
	scholarship = _scholarship;
}
Student::~Student() {};
void Student::swap(Student& stud) {
	std::swap(av_mark, stud.av_mark);
	std::swap(base_st, stud.base_st);
	std::swap(id, stud.id);
	std::swap(scholarship, stud.scholarship);
	fio.swap(stud.fio);
}
Student& Student::operator=(const Student& _stud) {
	if (this != &_stud) {
		Student tmp(_stud);
		this->swap(tmp);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Student& stud) {
	os << stud.fio << ' ' << stud.id << ' ' << stud.av_mark << ' '
		<< stud.base_st << ' ' << stud.scholarship;
	return os;
}

Archive::Archive(std::string _name) {
	students = NULL;
	quant = 0;
	name = _name;
}
Archive::~Archive() {
	delete[] students;
}
void Archive::add_stud(const Student& stud) {
	Student* tmp_mass = new Student[quant + 1];
	for (int i = 0; i < quant; i++) { tmp_mass[i] = students[i]; }
	tmp_mass[quant] = stud;
	delete[] students;
	students = tmp_mass;
	quant++;
}
Student& Archive::found_FIO(const FIO& _fio) {
	int i = 0;
	while ((i < quant) && (students[i].fio != _fio)) {
		i++;
	}
	return students[i];
}
int Archive::delete_id(int id) {
	int i = 0;
	while ((i < quant) && (students[i].id != id)) {
		i++;
	}
	if (i == quant) { return 1; }
	Student* tmp_mass = new Student[quant - 1];
	for (int i2 = 0; i2 < i; i2++) {
		tmp_mass[i2] = students[i2];
	}
	for (int i2 = i; i2 < quant - 1; i2++) {
		tmp_mass[i2] = students[i2 + 1];
	}
	quant -= 1;
	delete[] students;
	students = tmp_mass;
}
void Archive::sort() {
	int left = 0;
	int right = quant - 1;
	while (left <= right) {
		for (int i = right; i > left; --i) {
			if (students[i - 1].av_mark > students[i].av_mark) {
				students[i - 1].swap(students[i]);
			}
		}
		++left;
		for (int i = left; i < right; ++i) {
			if (students[i - 1].av_mark > students[i].av_mark) {
				students[i - 1].swap(students[i]);
			}
		}
		--right;
	}
}

void cursor_move(std::string* menu_names, int menu_size, short* choose_pos, int* iKey) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPos;
	short x;
	while (*iKey != KEY_ENTER) {
		switch (*iKey) {
		case KEY_ARROW_UP:
			cursorPos = { 0, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			x = menu_names[*choose_pos].length() + 4;
			cursorPos = { x, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			(*choose_pos)--;
			break;
		case KEY_ARROW_DOWN:
			cursorPos = { 0, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			x = menu_names[*choose_pos].length() + 4;
			cursorPos = { x, *choose_pos };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			printf("  ");
			(*choose_pos)++;
			break;
		}
		if (*choose_pos < 0) { *choose_pos = menu_size - 1; }
		if (*choose_pos > menu_size - 1) { *choose_pos = 0; }
		cursorPos = { 0, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf("<<");
		x = menu_names[*choose_pos].length() + 4;
		cursorPos = { x, *choose_pos };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		printf(">>");
		*iKey = _getch();
	}

}

void constract_MainMenu(Archive archive) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(hStdOut, &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &structCursorInfo);
	system("cls");

	std::string menu_names[6] = { "Add Student", "Found by name", "Delete by id", "Sort by av mark", "Show Arcive", "Exit"};
	bool exit_flag = FALSE;
	short choose_pos = 0;
	int menu_size = 6;
	int iKey;
	int flag;
	COORD cursorPos;
	system("cls");
	while (!exit_flag) {
		iKey = 67;
		cursorPos = { 0, 0 };
		SetConsoleCursorPosition(hStdOut, cursorPos);
		for (short i = 0; i < menu_size; i++) {
			cursorPos = { 3, i };
			SetConsoleCursorPosition(hStdOut, cursorPos);
			std::cout << menu_names[i];
		}
		cursor_move(menu_names, menu_size, &choose_pos, &iKey);

		switch (choose_pos) {
		case 0:
		{
			system("cls");
			std::string sur;
			std::string name;
			std::string sec;
			float av_mark;
			char base;
			char scholarship;
			std::cout << "Enter surname: ";
			std::cin >> sur;
			std::cout << "Enter name: ";
			std::cin >> name;
			std::cout << "Enter secondname: ";
			std::cin >> sec;
			std::cout << "Enter status of base: ";
			std::cin >> base;
			std::cout << "Enter av mark: ";
			std::cin >> av_mark;
			std::cout << "Enter status of scholarship: ";
			std::cin >> scholarship;
			FIO fio(sur, name, sec);
			Student stud(fio, av_mark, base, scholarship);
			archive.add_stud(stud);
			system("cls");
			std::cout << "Student create\n";
			system("pause");
			system("cls");
			break;
		}
		case 1:
		{
			system("cls");
			std::string sur;
			std::string name;
			std::string sec;
			std::cout << "Enter surname: ";
			std::cin >> sur;
			std::cout << "Enter name: ";
			std::cin >> name;
			std::cout << "Enter secondname: ";
			std::cin >> sec;
			FIO fio(sur, name, sec);
			system("cls");
			std::cout << archive.found_FIO(fio)<<"\n";
			system("pause");
			system("cls");
			break;
		}
			
		case 2:
		{
			int id;
			system("cls");
			std::cout << "Enter id: ";
			std::cin >> id;
			archive.delete_id(id);
			std::cout << "Student deleted\n";
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			archive.sort();
			std::cout << "Archive sorted\n";
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			for (int i = 0; i < archive.quant; i++) {
				std::cout << archive.students[i] << "\n";
			}
			system("pause");
			system("cls");
			break;
		}
		case 5:
			system("cls");
			exit_flag = TRUE;
			break;
		}
	}
}

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define RESET "\003[0m"
#define BLACK "\003[30m"
#define RED   "\003[31m"
#define GREEN "\003[32m"
enum Status { WRONG_RETURN, WRONG_ARG_1, WRONG_ARG_2, PASSED, ERROR_WORK };

template < typename T1, typename T2 >
bool swap(T1& a, T2& b) {
	try {
		a = a - b;
		b = b + a;
		a = -1 * (a - b);
	}
	catch (...) {
		std::cout << "Swap don't work";
	}
	return 1;
}

template < typename first_arg, typename second_arg, typename func_res >
class Test {
	std::string name;
	first_arg a, expect_a;
	second_arg b, expect_b;
	func_res result;
	Status status;
	time_t timer;
	func_res(*func)(first_arg&, second_arg&);
public:
	Test(std::string _name) {
		name = _name;
	}
	void test( func_res(*_func)(first_arg&, second_arg&), const first_arg& _a, const first_arg _a_expect,  const second_arg& _b, const second_arg _b_expect, func_res _result ) {
		func = _func;
		a = _a;
		expect_a = _a_expect;
		b = _b;
		expect_b = _b_expect;
		result = _result;
		timer = time(0);
		try {
			if (result != func(a, b)) { status = WRONG_RETURN; }
			else if (a != expect_a) { status = WRONG_ARG_1; }
			else if (b != expect_b) { status = WRONG_ARG_2;	}
			else { status = PASSED;	}
		}
		catch (...) {
			status = ERROR_WORK;
		}
		print_result();
	}
	void print_result() {
		if (status == PASSED) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
			std::cout << "[PASSED]" << std::endl;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		}
		if (status == WRONG_ARG_1) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			std::cout << "[FAILED] ";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			std::cout << std::endl << "expected a:" << expect_a << std::endl << "Witch is: " << a << std::endl;
		}
		if (status == WRONG_ARG_2) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			std::cout << "[FAILED] ";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			std::cout << std::endl << "expected b:" << expect_b << std::endl << "Witch is: " << b << std::endl;
		}
		if (status == WRONG_RETURN) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			std::cout << "[FAILED] ";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			std::cout << std::endl << "Not expected result" << std::endl;
		}
		if (status == ERROR_WORK) {
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			std::cout << "[ERROR] ";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			std::cout << std::endl << "Error" << std::endl;
		}
	}
};

int main() {
	Test<int, int, bool> test("Swap_test");
	int a = 3, b = 5;
	test.test(swap, a, 5, b, 3, 1);
	float k = 3.6, r = 7.9;
	Test<float, float, bool> test2("Swap_test");
	test2.test(swap, k, 7.9, r, 3.6, 1);
}
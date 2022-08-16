#include <iostream>
#include <stdexcept>
#include "Fraction.h"

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "ru");

	try {

		Fraction f1(4, 3);
		Fraction f2(6, 11);

		std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
		std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
		std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
		std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
		std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
		std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

	}
	catch (std::logic_error ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (std::exception ex) {
		std::cout << ex.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error" << std::endl;
	}

	return 0;
}
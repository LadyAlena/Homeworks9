#include <iostream>
#include <string>
#include <stdexcept>
#include "Fraction.h"

int main(int argc, char* argv[]) {

	setlocale(LC_ALL, "ru");

	try {

		std::string valueN;
		std::string valueD;

		int value_n = 0;
		int value_d = 0;

		do {
			std::cout << "������� ��������� ����� 1: ";
			std::getline(std::cin, valueN);
			try {
				value_n = std::stoi(valueN);
				break;
			}
			catch (std::invalid_argument) {
				std::cout << "����� ������� ������ �����! ��������� ����" << std::endl;
			}
		} while (true);

		do {
			std::cout << "������� ����������� ����� 1: ";
			std::getline(std::cin, valueD);
			try {
				value_d = std::stoi(valueD);
				break;
			}
			catch (std::invalid_argument) {
				std::cout << "����� ������� ������ �����! ��������� ����" << std::endl;
			}
		} while (true);

		Fraction f1(value_n, value_d);

		do {
			std::cout << "������� ��������� ����� 2: ";
			std::getline(std::cin, valueN);
			try {
				value_n = std::stoi(valueN);
				break;
			}
			catch (std::invalid_argument) {
				std::cout << "����� ������� ������ �����! ��������� ����" << std::endl;
			}
		} while (true);

		do {
			std::cout << "������� ����������� ����� 2: ";
			std::getline(std::cin, valueD);
			try {
				value_d = std::stoi(valueD);
				break;
			}
			catch (std::invalid_argument) {
				std::cout << "����� ������� ������ �����! ��������� ����" << std::endl;
			}
		} while (true);

		Fraction f2(value_n, value_d);

		std::cout << f1.GetValueFraction() << " + " << f2.GetValueFraction() << " = " << (f1 + f2).GetValueFraction() << std::endl;
		std::cout << f1.GetValueFraction() << " - " << f2.GetValueFraction() << " = " << (f1 - f2).GetValueFraction() << std::endl;
		std::cout << f1.GetValueFraction() << " * " << f2.GetValueFraction() << " = " << (f1 * f2).GetValueFraction() << std::endl;
		std::cout << f1.GetValueFraction() << " / " << f2.GetValueFraction() << " = " << (f1 / f2).GetValueFraction() << std::endl;
		std::cout << " ++ " << f1.GetValueFraction();
		std::cout << " * " << f2.GetValueFraction() << " = " << (++f1 * f2).GetValueFraction() << std::endl;
		std::cout << "�������� ����� 1: " << f1.GetValueFraction() << std::endl;
		std::cout << f1.GetValueFraction();
		std::cout << " -- " << " * " << f2.GetValueFraction() << " = " << (f1-- * f2).GetValueFraction() << std::endl;
		std::cout << "�������� ����� 1: " << f1.GetValueFraction() << std::endl;

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

#include <iostream>
#include "Abonent.h"
#include <string>
#include <sstream>
using namespace std;
const int monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
Abonent::Abonent() {
	this->name = "";
	this->address = "";
	this->tariph = 0;
	this->registration = Date();
	this->last_check = Date();
	this->size = 0;
	this->list_check = new Date[0];
	this->isBorg = false;
	
}
Abonent::Abonent(string name, string address, int tariph, bool isBorg, Date registration, Date last_check, int size, Date* list_check) {
	this->name = name;
	this->address = address;
	this->tariph = tariph;
	this->registration = registration;
	this->last_check = last_check;
	this->size = size;
	this->list_check = new Date[100];
	for (int i = 0; i < size; i++) {
		this->list_check[i] = list_check[i];
	}
	this->isBorg = isBorg;
}
Abonent::Abonent(const Abonent& abonent) {
	this->name = abonent.get_name();
	this->address = abonent.get_address();
	this->tariph = abonent.get_tariph();
	this->registration = abonent.get_registration();
	this->last_check = abonent.get_last_check();
	this->size = abonent.get_size();
	this->list_check = new Date[size];
	for (int i = 0; i < size; i++) {
		this->list_check[i] = abonent.list_check[i];
	}
	this->isBorg = abonent.get_isBorg();
}
Abonent::~Abonent() {
	delete[] list_check;
}
string Abonent::get_name()const {
	return this->name;
};
string Abonent::get_address()const {
	return this->address;
};
int Abonent::get_tariph()const {
	return this->tariph;
};
bool Abonent::get_isBorg()const {
	return this->isBorg;
};
Date Abonent::get_registration()const {
	return this->registration;
};
Date Abonent::get_last_check()const {
	return this->last_check;
};
int Abonent::get_size()const {
	return this->size;
}
int Abonent::get_kDay() const
{
	return this->kDay;
}
;
Date* Abonent::get_list_ckeck()const {
	Date* copy_list_check = new Date[this->size];
	for (int i = 0; i < this->size; i++) {
		copy_list_check[i] = this->list_check[i];
	}
	return copy_list_check;
};
void Abonent::set_name(string name) {
	this->name = name;
}
void Abonent::set_kDay(int kDay)
{
	this->kDay = kDay;
}
;
void Abonent::set_address(string address) {
	this->address = address;
};
void Abonent::set_tariph(int tariph) {
	this->tariph = tariph;
};
void Abonent::set_isBorg(bool isBorg) {
	this->isBorg = isBorg;
};
void Abonent::set_registration(Date registration) {
	this->registration = registration;
};
void Abonent::set_last_check(Date last_check) {
	this->last_check = last_check;
};
void Abonent::set_size(int size) {
	this->size = size;
};
void Abonent::set_list_ckeck(int size, Date* list_check) {
	delete[] this->list_check;
	this->size = size;
	this->list_check = new Date[100];
	for (int i = 0; i < size; i++) {
		this->list_check[i] = list_check[i];
	}
};
void input_date(Date& date, istream& in) {
	//cout << "Input year: ";
	in >> date.year;
	//cout << "Input month: ";
	in >> date.month;
	//cout << "Input day: ";
	in >> date.day;
}
void Abonent::input(istream& in) {
	cout << "Input name: ";
	getline(in >> ws, this->name);
	cout << "Input address: ";
	getline(in >> ws, this->address);
	cout << "Input tariff: ";
	in >> this->tariph;
	cout << "Is postpone?(Y/N)";
	string input;
	in >> input;
	input == "Y" ? this->isBorg = true : this->isBorg = false;
	cout << "Input registration date:\n";
	input_date(this->registration, in);
	cout << "Input last check date:\n";
	input_date(this->last_check, in);
	cout << "Input number of checks: ";
	in >> this->size;
	delete[] this->list_check;
	this->list_check = new Date[this->size];
	cout << "Input checking dates in following strings:\n";
	for (int i = 0; i < this->size; i++) {
		input_date(this->list_check[i], in);
	}
};
void print_date(const Date& date, ostream& os) {
	os << date.day << "." << date.month << "." << date.year << "\n";
}
void Abonent::print(ostream& os)const {
	os << "Name: " << this->name << "\n"
		<< "Address: " << this->address << "\n"
		<< "Tariff: " << this->tariph << "\n"
		<< "Postpone: " << (isBorg ? "Yes" : "No") << "\n"
		<< "Registration: ";
	print_date(this->registration, os);
	os << "Last check: ";
	print_date(this->last_check, os);
	os << "Checking dates:\n";
	for (int i = 0; i < this->size; i++) {
		print_date(this->list_check[i], os);
	}
};
int Abonent::get_price()const {
	if (isBorg) {
		return tariph * 3;
	}
	return tariph;
};
bool Abonent::isPostpone(Date now, int years)const { //3  2019 09 20  2022 09 19
	int time = 0;
	if (now.month >= this->last_check.month && now.day >= this->last_check.day) {
		time = now.year - this->last_check.year;
	}
	else {
		time = now.year - this->last_check.year - 1;
	}
	return time >= years;
};
int Abonent::count_days(Date now, Date will_check)const {
	int years_1 = now.year;
	int years_2 = will_check.year;
	if (now.month <= 2) {
		years_1--;
	}
	if (will_check.month <= 2) {
		years_2--;
	}
	long int n1 = now.year * 365 + now.day;
	for (int i = 0; i < now.month - 1; i++) {
		n1 += monthDays[i];
	}
	n1 += (years_1 / 4 - years_1 / 100 + years_1 / 400);

	long int n2 = will_check.year * 365 + will_check.day;
	for (int i = 0; i < will_check.month - 1; i++)
		n2 += monthDays[i];
	n2 += (years_2 / 4 - years_2 / 100 + years_2 / 400);
	return (n2 - n1);
}
void Abonent::ReadFF(istream& in)
{
	getline(in, name, ',');
	getline(in,address, ',');
	in >> tariph >> isBorg;
	input_date(registration, in);
	input_date(last_check, in);
	in >> size;
	delete[]list_check;
	list_check = new Date[size + 1];
	for (int i = 0; i < size; i++) {
		input_date(list_check[i], in);
	}

}
;
Abonent& Abonent::operator=(const Abonent& abonent) {
	if (this != &abonent) {
		this->name = abonent.get_name();
		this->address = abonent.get_address();
		this->tariph = abonent.get_tariph();
		this->registration = abonent.get_registration();
		this->last_check = abonent.get_last_check();
		this->size = abonent.get_size();
		this->list_check = new Date[size];
		for (int i = 0; i < size; i++) {
			list_check[i] = abonent.list_check[i];
		}
		this->isBorg = abonent.get_isBorg();
	}
	return *this;
}

bool Abonent::operator==(const Abonent& abonent) {
	return this->registration.day == abonent.get_registration().day && this->registration.month == abonent.get_registration().month && this->registration.year == abonent.get_registration().year;
}

bool Abonent::operator!=(const Abonent& abonent) {
	return !this->operator==(abonent);
}

bool Abonent::operator<=(const Abonent& abonent) {
	if (this->registration.year == abonent.get_registration().year) {
		if (this->registration.month == abonent.get_registration().month) {
			if (this->registration.day <= abonent.get_registration().day) {
				return true;
			}
			return false;
		}
		else if (this->registration.month < abonent.get_registration().month) {
			return true;
		}
		return false;
	}
	else if (this->registration.year < abonent.get_registration().year) {
		return true;
	}
	return false;
}

bool Abonent::operator>=(const Abonent& abonent) {
	if (operator==(abonent) || !operator<=(abonent)) {
		return true;
	}
	return false;
}

bool Abonent::operator<(const Abonent& abonent) {
	return !operator>=(abonent);
}

bool Abonent::operator>(const Abonent& abonent) {
	return !operator<=(abonent);
}

Abonent& Abonent::operator++() {//++i
	this->tariph++;
	return *this;
}
Abonent Abonent::operator++(int) { //i++
	Abonent old = *this;
	this->tariph++;
	return old;
}

Abonent& Abonent::operator--() {
	this->tariph--;
	return *this;
}
Abonent Abonent::operator--(int) {
	Abonent old = *this;
	this->tariph--;
	return old;
}

Abonent::operator string() {
	stringstream ss("");
	ss << this;
	return ss.str();
}
istream& operator>>(istream& in, Abonent& abonent) {
	//cout << "Input name: ";
	getline(in >> ws, abonent.name);
	//cout << "Input address: ";
	getline(in >> ws, abonent.address);
	//cout << "Input tariff: ";
	in >> abonent.tariph;
	//cout << "Is postpone?(Y/N)";
	string input;
	in >> input;
	input == "Y" ? abonent.isBorg = true : abonent.isBorg = false;
	//cout << "Input registration date:\n";
	input_date(abonent.registration, in);
	//cout << "Input last check date:\n";
	input_date(abonent.last_check, in);
	//cout << "Input number of checks: ";
	in >> abonent.size;
	delete[] abonent.list_check;
	abonent.list_check = new Date[abonent.size];
	//cout << "Input checking dates in following strings:\n";
	for (int i = 0; i < abonent.size; i++) {
		input_date(abonent.list_check[i], in);
	}
	return in;
};
ostream& operator << (ostream& out, const Abonent& abonent) {
	out << "Name: " << abonent.name << "\n"
		<< "Address: " << abonent.address << "\n"
		<< "Tariff: " << abonent.tariph << "\n"
		<< "Postpone: " << (abonent.isBorg ? "Yes" : "No") << "\n"
		<< "Registration: ";
	print_date(abonent.registration, out);
	out << "Last check: ";
	print_date(abonent.last_check, out);
	out << "Checking dates:\n";
	for (int i = 0; i < abonent.size; i++) {
		print_date(abonent.list_check[i], out);
	}
	return  out;
};


#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Date {
	int year, month, day;
};
class Abonent {
protected:
	string name, address;
	int tariph, size;
	Date registration, last_check;
	Date* list_check;
	bool isBorg;
	int kDay;
public:
	Abonent();
	Abonent(string name, string address, int tariph, bool isBorg, Date registration, Date last_check, int size, Date* list_ckeck);
	Abonent(const Abonent& abonent);
	virtual ~Abonent();
	string get_name()const;
	string get_address()const;
	int get_tariph()const;
	bool get_isBorg()const;
	Date get_registration()const;
	Date get_last_check()const;
	int get_size()const;
	int get_kDay()const;
	Date* get_list_ckeck()const;
	void set_name(string name);
	void set_kDay(int kDay);
	void set_address(string address);
	void set_tariph(int tariph);
	void set_isBorg(bool isBorg);
	void set_registration(Date registration);
	void set_last_check(Date last_check);
	void set_size(int size);
	void set_list_ckeck(int size, Date* list_check);
	virtual void input(istream& is);
	virtual void print(ostream& os)const;
	virtual int get_price()const;
	virtual bool isPostpone(Date now, int years)const;
	virtual int count_days(Date now, Date will_check)const;
	virtual void ReadFF(istream& in);
	Abonent& operator = (const Abonent& abonent);
	bool operator == (const Abonent& abonent);
	bool operator != (const Abonent& abonent);
	bool operator <= (const Abonent& abonent);
	bool operator >= (const Abonent& abonent);
	bool operator < (const Abonent& abonent);
	bool operator > (const Abonent& abonent);
	Abonent& operator++();
	Abonent operator++(int);
	Abonent& operator--();
	Abonent operator--(int);
	operator string();
	friend istream& operator >> (istream& in, Abonent& abonent);
	friend ostream& operator << (ostream& out, const Abonent& abonent);
};

#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const string filename = "PhoneBook.txt";

class PhoneBook {
private:

	struct Contact {

		char name[15];
		char mobileNumber[20];
		char homeNumber[10];
	};
	Contact* book;
	static int size;

public:

	PhoneBook();
	void AddnewContact(const char* _name, const  char* _mobileNumber, const char* _homeNumber);
	void DeleteContact(const char* _name);
	void SearchContact_name(const char* _name)const;
	void SearchContact_number(const char* _mobileNumber)const;
	void Show_all_Contact()const;
	void Save()const;
	~PhoneBook();
	void Load();
	static int Get_counter_contact();
};
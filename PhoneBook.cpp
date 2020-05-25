#include"PhoneBook.h"

int PhoneBook::size = 0;

void PhoneBook::info_Contact(int _i) const
{
	cout << "name :" << book[_i].name << endl;
	cout << "mobile Number :" << book[_i].mobileNumber << endl;
	cout << "home Number :" << book[_i].homeNumber << endl;
}

PhoneBook::PhoneBook()
{
	size = 0;
	book = nullptr;
}

void PhoneBook::AddnewContact(const char* _name, const  char* _mobileNumber, const char* _homeNumber)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(book[i].name, _name) == 0)
		{
			cout << "This name is already taken"<<endl;
			return;
		}
	}
	Contact* arr_contact = new Contact[size + 1];
	for (int i = 0; i < size; i++)
	{
		arr_contact[i] = book[i];
	}
	strcpy_s(arr_contact[size].name, _name);
	strcpy_s(arr_contact[size].mobileNumber, _mobileNumber);
	strcpy_s(arr_contact[size].homeNumber, _homeNumber);
	delete[] book;
	++size;
	book = arr_contact;
}

void PhoneBook::DeleteContact(const char* _name)
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(book[i].name, _name) == 0)
		{
			Contact* arr_contact = new Contact[size - 1];
			for (int i = 0, j = 0; i < size; i++)
			{
				if (strcmp(book[i].name, _name) != 0)
				{
					arr_contact[j] = book[i];
					++j;
				}
			}
			delete[] book;
			--size;
			book = arr_contact;
			break;
		}
	}
}

void PhoneBook::SearchContact_name(const char* _name)const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(book[i].name, _name) == 0)
		{
			info_Contact(i);
			break;
		}
		else
		{
			cout << "no information" << endl;
		}
	}
}

void PhoneBook::SearchContact_number(const char* _mobileNumber)const
{
	for (int i = 0; i < size; i++)
	{
		if (strcmp(book[i].mobileNumber, _mobileNumber) == 0)
		{
			info_Contact(i);
			break;
		}
		else
		{
			cout << "no information" << endl;
		}
	}
}

void PhoneBook::Show_all_Contact()const
{
	if (size > 0)
	{
		cout << " ALL CONTACT\n";
		for (int i = 0; i < size; i++)
		{
			info_Contact(i);
		}
	}
	else
	{
		cout << "  no contacts" << endl;
	}
}

void PhoneBook::Save()const
{
	ofstream fout;
	fout.open(filename);
	bool isOpen = fout.is_open();
	if (isOpen == false)
	{
		cout << " File not open" << endl;
		return;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			fout << book[i].name << endl;
			fout << book[i].mobileNumber << endl;
			fout << book[i].homeNumber << endl;

		}
		fout.close();
	}

}

PhoneBook::~PhoneBook()
{
	delete[] book;
}

void PhoneBook::Load()
{
	char data1[20];
	int number = 0;
	ifstream fin;
	fin.open(filename);
	bool isOpen = fin.is_open();
	if (isOpen == false)
	{
		cout << "Error" << endl;
	}
	else
	{
		while (!fin.eof())
		{
			fin >> data1;
			number++;
		}
		size = (number - 1) / 3;

		fin.close();
		if (size > 0)
		{
			int currentString = 0;
			fin.open(filename);
			Contact* newContact = new Contact[size];
			bool isOpen1 = fin.is_open();
			if (isOpen1 == false)
			{
				cout << "Error" << endl;
			}
			else
			{
				int j = 0;
				while (!fin.eof())
				{
					fin >> data1;
					currentString++;
					for (; j < size;)
					{
						if (currentString == 1)
						{
							strcpy_s(newContact[j].name, data1);
							break;
						}

						else if (currentString == 2)
						{
							strcpy_s(newContact[j].mobileNumber, data1);
							break;
						}
						else if (currentString == 3)
						{
							strcpy_s(newContact[j].homeNumber, data1);
							currentString = 0;
							++j;
							break;

						}
					}
				}
			}
			fin.close();
			delete[] book;
			book = newContact;

		}
	}

}
int PhoneBook::Get_counter_contact()
{
	return size;
}






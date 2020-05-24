#include"Triangle.h"
#include "PhoneBook.h"


int main()
{
	//Triangle px(5,6);
	//px.Print();
	//cout << "area " << px.GetArea() << endl;
	//cout << "perimeter" << px.GetPerimeter() << endl;
	//Triangle px1(7, 9);
	//cout << "area " << px1.GetArea() << endl;
	//cout << "perimeter" << px1.GetPerimeter() << endl;
	//cout << Triangle::Show_count_Triangle() << endl;
	//cout << Triangle::Show_Area()<<endl;

	PhoneBook d1;
	d1.AddnewContact("vasa","7754763735", "656465");
	d1.AddnewContact("vas", "2345356563", "656465");
	d1.Save();
	d1.Load();
	d1.Show_all_Contact();	
	d1.DeleteContact("vas");
	d1.Show_all_Contact();
	d1.SearchContact_name("vasa");
	d1.Show_all_Contact();

	system("pause");
	return 0;

}
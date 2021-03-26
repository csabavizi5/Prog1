#include "std_lib_facilities.h"

//1. Define a struct Person containing a string name and an int age.

struct Person{
	string name;
	int age;
	//string name;
	//int age;

	
//	string name;
//	int age;
};

//3. Define an input (>>) and an output (<<) operator for Person;
// read in a Person from the keyboard (cin) and write it out to the screen (cout).

ostream& operator<<(ostream& os, Person p){
	return os << p.name << " " << p.age;


}
//Person operator<<(Person& p){
//
//	cout<<name<<" "<<age;
//
//}


int main(){

//2. Define a variable of type Person, initialize it with “Goofy” and 63,
// and write it to the screen (cout).


	Person p;
	Person p2;
	p.name = "Goofy";
	p.age = 63;

	//cout << p.name << " " << p.age << "\n";

	//cout << p;
	cout << endl;
	//cout << p;

//	cin>>p2;
//	cout<<p2;
//	cout<<"\n";


//4. Give Person a constructor initializing name and age.

//5. Make the representation of Person private, and provide const member functions
// name() and age() to read the name and age.

//6. Modify >> and << to work with the redefined Person.

//7. Modify the constructor to check that age is [0:150)
// and that name doesn’t contain any of the characters ; : " ' [ ] * & ^ % $ # @ !.
// Use error() in case of error. Test.

//8. Read a sequence of Persons from input (cin) into a vector<Person>;
// write them out again to the screen (cout). Test with correct and erroneous input.

//9. Change the representation of Person to have first_name and second_name instead of name.
// Make it an error not to supply both a first and a second name. Be sure to fix >> and << also.
// Test.

}
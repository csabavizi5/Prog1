#include <vector>
#include <iostream>
#include <list>
#include <algorithm>

template<typename C>
void printout(const C& c)
{
	for(int i = 0; i < c.size(); ++i)
		std::cout << c[i] << '\t';
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{	
	if(f1==e1)
		std::cout << "Nincsenek másolandó elemek!\n";

	while(f1 != e1)
	{
		*f2 = *f1;
		f1++;
		f2++;
	}
	return f2;

}


int main()
{
	int array[] {0,1,2,3,4,5,6,7,8,9};
	std::vector<int> v {0,1,2,3,4,5,6,7,8,9};
	std::list<int>  lst {0,1,2,3,4,5,6,7,8,9};
	

	//kontenerek kiirasa
	std::cout << std::endl << "array: \n";
	for(int i= 0; i<10; ++i)
		std::cout << array[i] << '\t';

	std::cout << std::endl << "vector: \n";
	printout(v);

	std::cout << std::endl << "list: \n";
	for(auto v : lst)
		std::cout << v << '\t';


	//uj tomb letrhozasa, feltoltesa ertekekkel
	int array2[10];
	for(int i = 0; i < 10; ++i)
		array2[i] = array[i];

	//vector es lista letrehozasa, feltoltese
	std::vector<int> v2 = v;
	std::list<int> lst2 = lst;


	//ujtarolok kiirasa
	std::cout << std::endl << "array2: \n";
	for(int i= 0; i<10; ++i)
		std::cout << array2[i] << '\t';

	std::cout << std::endl << "vector2: \n";
	printout(v2);

	std::cout << std::endl << "list2: \n";
	for(auto v : lst2)
		std::cout << v << '\t';

	std::cout << std::endl;

	//elemek novelese, array-ben 2-vel, vectorban 3-al, list-ben 5-el
	for(int i= 0; i<v.size(); ++i)
		v[i]+=3;

	for(int i = 0; i < 10; ++i)
		array[i] = i+2;

	for(auto p = lst.begin(); p != lst.end(); ++p)
	{
		*p+=5; 
	}

	//megnovelt elemek kiirasa
	std::cout << std::endl << "array, miután megnöveltük 2-vel az értékeket: \n";
	for(int i= 0; i<10; ++i)
		std::cout << array[i] << '\t';

	std::cout << std::endl << "vector, miután megnöveltük az értékeket 3-al: \n";
	printout(v);

	std::cout << std::endl << "list, miután megnöveltük az értékeit 5-el: \n";
	for(auto v : lst)
		std::cout << v << '\t';

	std::cout << std::endl;

	//array atmasolasa vectorba, majd list masolasa array-be
	my_copy(array, array+10, v.begin());

	std::cout << std::endl << "vector, miután belemásoltuk array elemeit: \n";
	printout(v);

	my_copy(lst.begin(), lst.end(), array);

	std::cout << std::endl << "array, miután belemásoltuk list elemeit: \n";
	for(int i= 0; i<10; ++i)
		std::cout << array[i] << '\t';

	std::cout << std::endl << std::endl;

	//keressuk meg 3-at a vectorban, 27et a listában
	int x = 3;
	auto p = std::find(v.begin(), v.end(), x);
	if(p == v.end())
		std::cout << x << " nincs ebben a vectorban!\n";
	else
		std::cout << x << " helye a vektorban: " << distance(v.begin(), p) << std::endl;

	int w = 27;
	auto r = std::find(lst.begin(), lst.end(), w);
	if(r == lst.end())
		std::cout << w << " nincs ebben a listában!\n";
	else
		std::cout << w << " helye a listában: " << distance(lst.begin(), r) << std::endl;


	std::cout << std::endl;
	return 0;
}
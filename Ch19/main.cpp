#include <iostream>
#include <vector>
#include <string>


template<typename T>
struct S {
private:
	T val;

public:	
	S(T s): val(s) {}
	
	T get() { return val; }
	T get() const { return val; }
	//void set(int value) { val = value; }
	void operator=(const T& value) { val = value; }
};

//T S::get() { return val; }

template<typename T>
T read_val(T v) { std::cin >> v; return v; }

int main()
{
	S<int> si(42);
	S<double> sd = 3.14;
	S<char> sc('c');
	S<std::string> ss("apple");
	S<std::vector<int>> svi = std::vector<int> {1,2,3,4};

	
	std::cout << "si.val: \t" << si.get() << std::endl;	
	std::cout << "sc.val: \t" << sd.get() << std::endl;
	std::cout << "sc.val: \t" << sc.get() << std::endl;	
	std::cout << "ss.val: \t" << ss.get() << std::endl;	
	std::cout << "svi.val:" << std::endl;
	for(int i = 0; i < svi.get().size(); ++i)
	{
		std::cout << svi.get()[i] << " ";
	}
	std::cout << std::endl;

	
	std::cout << "Type in an integer and press ENTER!\n";
	si = read_val(si.get());
	std::cout << "Type in a double and press ENTER!\n";
	sd = read_val(sd.get());
	std::cout << "Type in a char and press ENTER!\n";
	sc = read_val(sc.get());
	std::cout << "Type in a string and press ENTER!\n";
	ss = read_val(ss.get());
	

	std::cout << "si.val: \t" << si.get() << std::endl;
	std::cout << "sd.val: \t" << sd.get() << std::endl;
	std::cout << "sc.val: \t" << sc.get() << std::endl;
	std::cout << "ss.val: \t" << ss.get() << std::endl;






/*
	si = read_val(si.get());
	std::cout << si.get() << std::endl;

	

	
/*
	S<double> sd(3.14);
	read_val(sd.get());
	std::cout << sd.get() << std::endl;

	std::string s;
	read_val(s);
	std::cout << s << std::endl;
	//std::cout << si.get() << std::endl;
*/

	//std::cout << "Az int: \t" << si.val << std::endl;
	//S<char> sc();
	
	//std::cout << sd.get() << std::endl;

	//S<std::string> ss {"Eszti"};
	//S<std::vector<int>> svi {1, 2, 3, 4};
	return 0;
}

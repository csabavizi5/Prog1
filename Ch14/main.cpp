#include "std_lib_facilities.h"

class B1 {
public:
	virtual void pvf() const =0;	//pure virtual function, absztraktá teszi az osztályt
	virtual void vf() const {cout << "B1::vf()\n";}
	virtual void f() const {cout << "B1::f()\n";}	//csak a virtual functionokat lehet overrideolni
};

class D1 : public B1 {
public:
	void vf() const override {cout << "D1::vf()\n";}
	void f() const override {cout << "D1::f()\n";}//csak akkor overrideolható,
												//ha az eredeti function virtual
	void pvf() const override {cout << "This was the pure virtual function, but now D1::pvf()\n";}
};					//override szükséges a leszármazott osztályokban,
					//különben absztrakt marad a leszármazott osztály is


class D2 : public D1 {
	void vf() const {cout << "D2::vf()\n";}
	void f() const {cout << "D2::f()\n";}
	void pvf() const override {cout << "This was the pure virtual function, but now D2::pvf()\n";}

};

class B2 {
public:
	virtual void pvf() const =0;
};

class D21 : public B2 {
public:
	string s = "word";
	void pvf() const override {cout << s << "\n";}
};

class D22 : public B2 {
public:
	int i = 42;
	void pvf() const override {cout << i << "\n";}
};

void f(const B2& b2){
	b2.pvf();
}


void call(const B1& b){
	b.vf();
	b.f();
	b.pvf();
}



int main()
{
	//B1 b;				//pvf() esetén nem hívhatunk B1 objectre, mert absztrakt
	D1 d;
	D2 d2;
	B1& bref = d;

	D21 d21;
	D22 d22;
	
	cout << "Tasks 1-6:\n";
	//call(b);
	call(d);
	call(d2);
	call(bref);
	cout << "call end\n";

	cout << "\nTask 7:\n";
	f(d21);
	f(d22);

	


}


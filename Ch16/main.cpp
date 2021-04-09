// g++ main5.cpp Graph.cpp Window.cpp GUI.cpp Lines_window.cpp -o main5 `fltk-config --ldflags --use-images`

#include "GUI.h"
#include "Lines_window.h"

int main()
try{
	Lines_window win{Point{100,100},800,600, "lines"};
	return gui_main();
}
catch(exception& e){
	cerr<<"exception: "<<e.what()<<'\n';
	return 1;
}
catch(...){
	cerr<<"Some exception\n";
	return 2;
}

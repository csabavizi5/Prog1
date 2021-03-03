#include "Simple_window.h"
#include "Graph.h"

int main(){

	int x_max = 1000;
	int y_max = 800;
	Simple_window win {Point{100,100}, x_max, y_max, "My window"};


	win.wait_for_button();
}
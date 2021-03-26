
//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Graph.h"
#include "Simple_window.h"

double one(double x){return 1;}
double slope(double x){return x/2;}
double square(double x){ return x*x;}
double sloping_cos(double x){return (x)+cos(x);}

int main(){

	Simple_window win {Point{100,100}, 600, 600, "Function Graphs"};

	int x_orig = 300;
	int y_orig = 300;
	Point orig {x_orig,y_orig};
	int xlength = 400;
	int ylength = 400;
	int xscale = 20;
	int yscale = 20;

	Axis x {Axis::x, Point{100,y_orig},xlength,xlength/xscale, "1 == 20 pixels"};

	Axis y {Axis::y, Point{x_orig,500},ylength,ylength/yscale, "1 == 20 pixels"};
	x.set_color(Color::red);
	y.set_color(Color::red);
/*
	In the following, use a separate Shape for each function to be graphed:

1. Graph the function double one(double x) { return 1; } in the range [–10,11] with (0,0)
	 at (300,300) using 400 points and no scaling (in the window).

2. Change it to use x scale 20 and y scale 20.

3. From now on use that range, scale, etc. for all graphs.

4. Add double slope(double x) { return x/2; } to the window.

5. Label the slope with a Text "x/2" at a point just above its bottom left end point.

6. Add double square(double x) { return x*x; } to the window.

7. Add a cosine to the window (don’t write a new function).

8. Make the cosine blue.

9. Write a function sloping_cos() that adds a cosine to slope() (as defined above)
 and add it to the window.
*/
	
	double interval_min = -10;
	double interval_max = 11;
	int number_of_points = 400;
	double scale = 20;



	Function xfn {one, interval_min, interval_max, orig, number_of_points, scale, scale}; 
	//{fuggveny, intervallum eleje, vege, fuggveny {0,0} pontja, pontok száma, 
	
	Function slopefn {slope, interval_min, interval_max, orig, number_of_points, scale, scale};
	Text t {Point{100,390}, "x/2"};

	Function squarefn {square, interval_min, interval_max, orig, number_of_points, scale, scale};

	Function cosfn {cos, interval_min, interval_max, orig, number_of_points, scale, scale};
	cosfn.set_color(Color::blue);

	Function sloping_cosfn {sloping_cos, interval_min, interval_max, orig, number_of_points, scale, scale};

	win.attach(slopefn);
	win.attach(xfn);
	win.attach(x);
	win.attach(y);
	win.attach(t);
	win.attach(squarefn);
	win.attach(cosfn);
	win.attach(sloping_cosfn);

	win.wait_for_button();
}
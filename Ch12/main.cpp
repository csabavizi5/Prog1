
// g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

double one(double) {return 1;}

double square(double x) {return x*x;}

int main()
{
	using namespace Graph_lib;

	Point p{100, 100};
	int xmax = 1600;
	int ymax = 900;

	int x_orig = xmax/2;
	int y_orig = ymax/2;

	int rmin = -11;
	int rmax = 11;

	int n_points = 400;

	Simple_window win {p, xmax, ymax, "Canvas"};


	Polygon poly;      

	poly.add(Point{300,200});
	poly.add(Point{350,100});
	poly.add(Point{400,200});

	poly.set_color(Color::blue);
	poly.set_style(Line_style::dashdotdot);
	poly.set_fill_color(Color::dark_blue);

	Closed_polyline poly_rect;

	poly_rect.add(Point{100,50});
	poly_rect.add(Point{200,50});
	poly_rect.add(Point{200,100});
	poly_rect.add(Point{100,100});
	poly_rect.add(Point{50,75});

	poly_rect.set_color(Color::dark_red);
	poly_rect.set_style(Line_style::dash);

	

/*
	Ellipse e {Point{100,200}, 75, 25};
	set.color(Color::dark_red);
	win.attach(e);
*/
	Point origo {x_orig, y_orig};

	int xlength = xmax - 40;
	int ylength = ymax - 40;

	int xscale = 30, yscale = 30;

	Function s (one, rmin, rmax, origo, n_points, xscale, yscale);

	Function sq(square, rmin, rmax, origo, n_points, xscale, yscale);	

	Axis x {Axis::x, Point{20,y_orig}, xlength, xlength/xscale, "x"};
	Axis y {Axis::y, Point{x_orig,ylength + 20}, ylength, ylength/yscale, "y"};

	Rectangle r {Point{900,600}, 100, 50};
	r.set_fill_color(Color::yellow);
	r.set_style(Line_style(Line_style::dash, 4));

	Text t {Point{1000,160}, "Hello, graphics!"};
	t.set_font(Font::times_bold);
	t.set_font_size(45);
	t.set_color(Color::magenta);

	Image ii {Point{20,440}, "badge.jpg"};

	Mark m {Point{1200,300}, 'x'};
	m.set_color(Color::cyan);
	

	ostringstream oss;

	oss << "screen size: " << x_max() << "*" << y_max()
		<< ", window size: " << win.x_max() << "*" << win.y_max();
	
	Text sizes {Point{20,20}, oss.str()};		


	Circle c {Point{1200,675}, 50};
	c.set_color(Color::red);
	c.set_style(Line_style(Line_style::dashdot, 4));

	win.attach(sizes);
	win.attach(m);
	win.attach(ii);
	win.attach(c);
	win.attach(t);
	win.attach(r);
	win.attach(x);
	win.attach(y);
	win.attach(s);
	win.attach(sq);
	win.attach(poly_rect);
	win.attach(poly);

	win.wait_for_button();
}
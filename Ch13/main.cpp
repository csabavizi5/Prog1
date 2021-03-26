
//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`

#include "Simple_window.h"
#include "Graph.h"

int main(){

	int x_max = 1000;
	int y_max = 800;

	int grid_max = 800;
	int x_grid = 100;
	int y_grid = 100;

	Simple_window win {Point{100,100}, x_max, y_max, "Chapter 13 Drill"};



	Lines grid;
	for(int x=x_grid; x<=grid_max; x+=x_grid)
		grid.add(Point{x,0},Point{x,grid_max});
	

	for(int y=y_grid; y<=grid_max; y+=y_grid)
		grid.add(Point{0,y},Point{grid_max,y});

	win.attach(grid);



	Vector_ref<Rectangle> rectangles;
	for(int i = 0; i<8; i++){
		rectangles.push_back(new Rectangle{Point{i*100,i*100},100,100});    //mivel negyzetek, egyenlo az oldaluk, {0,0}{100,100} stb.
		rectangles[rectangles.size()-1].set_fill_color(Color::red);  //minden futáskor pirosra színezi az utolsó elemet
		win.attach(rectangles[rectangles.size()-1]); //minden futáskor felteszi az utolsó elemet

	}

	Vector_ref<Image> images;
	for(int i=0; i<3; i++){
		images.push_back(new Image{Point{i*200,(i*200)+200}, "200.jpg"});
		win.attach(images[images.size()-1]);
	}


	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			Image img100 {Point{j*100,i*100}, "pic.jpg"};
			win.attach(img100);
			win.wait_for_button();
		}
	}


	//win.wait_for_button();
}
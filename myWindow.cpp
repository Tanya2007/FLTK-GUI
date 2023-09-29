#include "myWindow.h"
///////////////////////////////////////////////////////////////////////////////////
//Определение методов класса Drawing..............................................
///////////////////////////////////////////////////////////////////////////////////
void Drawing::draw()
{
	Fl_Box::draw();
	fl_color(FL_BLACK);
	Fl_Font font_face = fl_font();
	fl_font(font_face, 10);
	double x_step = 20;
	double y_step = 20;

	double x_center = x() + w() / 2;
	double y_center = y() + h() / 2;

	fl_line_style(FL_DASH);
	fl_begin_line();
	fl_line(x() + 10, y_center, x() + w() - 10, y_center);
	fl_line(x_center, y() + 10, x_center, y() + h() - 10);
	fl_line(x() + w() - 20, y_center - 5, x() + w() - 10, y_center);
	fl_line(x() + w() - 20, y_center + 5, x() + w() - 10, y_center);
	fl_line(x_center - 5, y() + 20, x_center, y() + 10);
	fl_line(x_center + 5, y() + 20, x_center, y() + 10);
	for(int i = 1, j = x_center + x_step; j < x() + w() - 10 - x_step; ++i, j += x_step)
	{
		fl_line(j, y_center - 5, j, y_center + 5);
		fl_draw(std::to_string(i).c_str(), j - 5, y_center + 20);
	}
	for(int i = -1, j = x_center - x_step; j > x() + 10 + x_step; --i, j -= x_step)
	{
		fl_line(j, y_center - 5, j, y_center + 5);
		fl_draw(std::to_string(i).c_str(), j - 7, y_center + 20);
	}
	for(int i = -1, j = y_center + y_step; j < y() + h() - 10 - y_step; --i, j += y_step)
	{
		fl_line(x_center - 5, j, x_center + 5, j);
		fl_draw(std::to_string(i).c_str(), x_center - 20, j + 5);
	}
	for(int i = 1, j = y_center - y_step; j > y() + 10 + y_step; ++i, j -= y_step)
	{
		fl_line(x_center - 5, j, x_center + 5, j);
		fl_draw(std::to_string(i).c_str(), x_center - 20, j + 5);
	}
	fl_end_line();
	fl_line_style(0);
	fl_font(font_face, FL_NORMAL_SIZE);
	fl_draw("0", x_center - 12, y_center + 12);
	fl_draw("x", x() + w() - 20, y_center + 20);
	fl_draw("y", x_center - 20, y() + 20);

	const std::vector<int> vec_int = figure_plane->getInputInt();
	fl_push_clip(x(),y(),w(),h());
	fl_push_matrix();
	fl_color(figure_plane->getColorFigure());
	if(m_type == "Круг")
	{	
		fl_circle(x_center + vec_int[0] * x_step, 
			y_center - vec_int[1] * y_step , vec_int[2] * x_step);
	}
	else if(m_type == "Треугольник")
	{
		fl_begin_loop();
		fl_line(x_center + vec_int[0] * x_step, 
			y_center - vec_int[1] * y_step, x_center + vec_int[2] * x_step, 
			y_center - vec_int[3] * y_step);
		fl_line(x_center + vec_int[2] * x_step, 
			y_center - vec_int[3] * y_step, x_center + vec_int[4] * x_step, 
			y_center - vec_int[5] * y_step);
		fl_line(x_center + vec_int[4] * x_step, 
			y_center - vec_int[5] * y_step, x_center + vec_int[0] * x_step, 
			y_center - vec_int[1] * y_step);
		fl_end_loop();
	}
	else if(m_type == "Прямоугольник")
	{
		fl_begin_loop();
		fl_line(x_center + vec_int[0] * x_step, 
			y_center - vec_int[1] * y_step, x_center + vec_int[2] * x_step, 
			y_center - vec_int[1] * y_step);
		fl_line(x_center + vec_int[2] * x_step, 
			y_center - vec_int[1] * y_step, x_center + vec_int[2] * x_step, 
			y_center - vec_int[3] * y_step);
		fl_line(x_center + vec_int[2] * x_step, 
			y_center - vec_int[3] * y_step, x_center + vec_int[0] * x_step, 
			y_center - vec_int[3] * y_step);
		fl_line(x_center + vec_int[0] * x_step, 
			y_center - vec_int[3] * y_step, x_center + vec_int[0] * x_step, 
			y_center - vec_int[1] * y_step);
		fl_end_loop();
	}
	fl_pop_matrix();
    fl_pop_clip();
}
////////////////////////////////////////////////////////////////////////////////////
//Конец Drawing.............................................................
////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
//Определение методов класса MyWindow.....................................
///////////////////////////////////////////////////////////////////////////////////
Fl_Menu_Item MyWindow::m_menutable[]
{
	{"Круг", 0, MyWindow::drawFigure, 0, 0, FL_SHADOW_LABEL, FL_BOLD+FL_ITALIC, 20, FL_GREEN},
	{"Треугольник", 0, MyWindow::drawFigure, 0, 0, FL_SHADOW_LABEL, FL_BOLD+FL_ITALIC, 20, FL_RED},
	{"Прямоугольник",  0, MyWindow::drawFigure, 0, 0, FL_SHADOW_LABEL, FL_BOLD+FL_ITALIC, 20, FL_MAGENTA}
};
//--------------------------------------------------------------------------------
MyWindow::MyWindow(int W, int H, const char *label)
	: Fl_Double_Window(W, H, label),
	  m_menubar(0,0,W,30),
	  m_gr_circle(20, 40, W - 40, 110, FL_GREEN),
	  m_gr_triangle(20, 40, W - 40, 110, FL_RED),
	  m_gr_rectangle(20, 40, W - 40, 110, FL_MAGENTA),
	  m_draw_box(20, 170, W / 2 + 100, H / 2 + 100),
	  m_button(W / 2 + 140, 170, W / 4, 30, "Нарисовать и рассчитать"),
	  m_square(W / 2 + 140, 250, W / 4, 30, "Площадь круга:"),
	  m_perimeter(W / 2 + 140, 320, W / 4, 30, "Длина окружности:")
{
	Fl_Color c = fl_rgb_color(197, 251, 225);
	m_menubar.menu(m_menutable);
	m_menubar.color(c);
	m_draw_box.box(FL_ROUNDED_BOX);
	m_draw_box.color(FL_WHITE);
	m_draw_box.setFigurePlane(&m_gr_circle);
	m_draw_box.setType("Круг");
	m_gr_triangle.hide();
	m_gr_rectangle.hide();
	m_button.color(FL_YELLOW);
	m_button.box(FL_DOWN_BOX);
	m_button.labelfont(FL_BOLD);
	m_button.callback(MyWindow::my_static_callback);
	m_square.align(FL_ALIGN_TOP);
	m_perimeter.align(FL_ALIGN_TOP);
	color(c);
	resizable(*this);
	Fl::visual(FL_DOUBLE|FL_INDEX);
	show();
	end();
}
//---------------------------------------------------------------------------------------
void MyWindow::my_static_callback(Fl_Widget* w)
{
	MyWindow *ptr_gr = static_cast<MyWindow*>(w->parent());
	ptr_gr->my_callback(ptr_gr->m_draw_box.getFigure());
}
//-----------------------------------------------------------------------------------------
void MyWindow::my_callback(FigureOnPlane* type_figure)
{	
	fillCalculations(type_figure);
	m_draw_box.redraw();
}
//-----------------------------------------------------------------------------------------
void MyWindow::fillCalculations(FigureOnPlane* type_figure)
{
	const std::vector<int> vec_int = type_figure->getInputInt();
	double len{}, sq{};
	if(vec_int.size() == 3)			//Круг
	{
		double x = vec_int[0];
		double y = vec_int[1];
		double radius = vec_int[2];
		
		len = 2.0 * M_PI * radius;
		sq = M_PI * std::pow(radius, 2);
	}
	else if(vec_int.size() == 6)	//Треугольник
	{
		double x1 = vec_int[0];
		double y1 = vec_int[1];
		double x2 = vec_int[2];
		double y2 = vec_int[3];
		double x3 = vec_int[4];
		double y3 = vec_int[5];
		double side1 = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
		double side2 = std::sqrt(std::pow(x3 - x1, 2) + std::pow(y3 - y1, 2));
		double side3 = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
		
		len = side1 + side2 + side3;
		double len_h = len / 2;
		sq = std::sqrt(len_h * (len_h - side1) * (len_h - side2) * (len_h - side3));
	}
	else if(vec_int.size() == 4)	//Прямоугольник
	{
		double x1 = vec_int[0];
		double y1 = vec_int[1];
		double x2 = vec_int[2];
		double y2 = vec_int[3];
		
		double w_r = std::abs(y1 - y2);
		double l_r = std::abs(x1 - x2);
		
		len = 2 * w_r + 2 * l_r;
		sq = w_r * l_r;
	}
	
	m_perimeter.value(std::to_string(len).c_str());
	m_square.value(std::to_string(sq).c_str());
}
//----------------------------------------------------------------------------------------
void MyWindow::drawFigure(Fl_Widget* figure, void*)
{
	Fl_Menu_ *f = static_cast<Fl_Menu_*>(figure);
	MyWindow *ptr_window = static_cast<MyWindow*>(f->parent());
	std::string str_type{(f->mvalue())->label()};
	ptr_window->drawFigureWindow(str_type);
}
//------------------------------------------------------------------------------------------
void MyWindow::drawFigureWindow(const std::string &str_type)
{
	FigureOnPlane* type_figure;
	if(str_type == "Круг")
	{
		m_gr_circle.show();
		m_gr_triangle.hide();
		m_gr_rectangle.hide();
		m_draw_box.setFigurePlane(&m_gr_circle);
		m_square.label("Площадь круга:");
		m_perimeter.label("Длина окружности:");
		type_figure = &m_gr_circle;
	}
	else if(str_type == "Треугольник")
	{
		m_gr_circle.hide();
		m_gr_triangle.show();
		m_gr_rectangle.hide();
		m_draw_box.setFigurePlane(&m_gr_triangle);
		m_square.label("Площадь треугольника:");
		m_perimeter.label("Периметр треугольника:");
		type_figure = &m_gr_triangle;
	}
	else if(str_type == "Прямоугольник")
	{
		m_gr_circle.hide();
		m_gr_triangle.hide();
		m_gr_rectangle.show();
		m_draw_box.setFigurePlane(&m_gr_rectangle);
		m_square.label("Площадь прямоугольника:");
		m_perimeter.label("Периметр прямоугольника:");
		type_figure = &m_gr_rectangle;
	}
	
	fillCalculations(type_figure);
	m_draw_box.setType(str_type);
}
////////////////////////////////////////////////////////////////////////////////////
//Конец MyWindow....................................................................
////////////////////////////////////////////////////////////////////////////////////
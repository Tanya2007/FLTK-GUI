#include "Figures.h"
///////////////////////////////////////////////////////////////////////////////////
//Определение методов класса Fl_Group_Circle.......................................
///////////////////////////////////////////////////////////////////////////////////
Fl_Group_Circle::Fl_Group_Circle(int X, int Y, int W, int H, const Fl_Color &c_f)
	: FigureOnPlane(X, Y, W, H, c_f),
	  m_int_x_radius_circle(40, 60, 200, 30, "Координата X центра круга:"),
	  m_int_y_radius_circle(40, 110, 200, 30, "Координата Y центра круга:"),
	  m_int_radius_circle(280, 60, 200, 30, "Радиус круга:")

{
	m_int_x_radius_circle.align(FL_ALIGN_TOP);
	m_int_y_radius_circle.align(FL_ALIGN_TOP);
	m_int_radius_circle.align(FL_ALIGN_TOP);
	end();
}
//----------------------------------------------------------------------------------
const std::vector<int>& Fl_Group_Circle::getInputInt()
{
	vec_input.clear();
	int x = atoi(m_int_x_radius_circle.value());
	vec_input.push_back(x);
	int y = atoi(m_int_y_radius_circle.value());
	vec_input.push_back(y);
	int r = atoi(m_int_radius_circle.value());
	vec_input.push_back(r);
	
	return vec_input;
}
////////////////////////////////////////////////////////////////////////////////////
//Конец Fl_Group_Circle.............................................................
////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
//Определение методов класса Fl_Group_Triangle.....................................
///////////////////////////////////////////////////////////////////////////////////
Fl_Group_Triangle::Fl_Group_Triangle(int X, int Y, int W, int H, const Fl_Color &c_f)
	: FigureOnPlane(X, Y, W, H, c_f),
	  m_int_x1_triangle(40, 60, 100, 30, "Точка X1:"),
	  m_int_y1_triangle(40, 110, 100, 30, "Точка Y1:"),
	  m_int_x2_triangle(160, 60, 100, 30, "Точка X2:"),
	  m_int_y2_triangle(160, 110, 100, 30, "Точка Y2:"),
	  m_int_x3_triangle(280, 60, 100, 30, "Точка X3:"),
	  m_int_y3_triangle(280, 110, 100, 30, "Точка Y3:")

{
	m_int_x1_triangle.align(FL_ALIGN_TOP);
	m_int_y1_triangle.align(FL_ALIGN_TOP);
	m_int_x2_triangle.align(FL_ALIGN_TOP);
	m_int_y2_triangle.align(FL_ALIGN_TOP);
	m_int_x3_triangle.align(FL_ALIGN_TOP);
	m_int_y3_triangle.align(FL_ALIGN_TOP);
	end();
}
//----------------------------------------------------------------------------------
const std::vector<int>& Fl_Group_Triangle::getInputInt()
{
	vec_input.clear();
	int x1 = atoi(m_int_x1_triangle.value());
	vec_input.push_back(x1);
	int y1 = atoi(m_int_y1_triangle.value());
	vec_input.push_back(y1);
	int x2 = atoi(m_int_x2_triangle.value());
	vec_input.push_back(x2);
	int y2 = atoi(m_int_y2_triangle.value());
	vec_input.push_back(y2);
	int x3 = atoi(m_int_x3_triangle.value());
	vec_input.push_back(x3);
	int y3 = atoi(m_int_y3_triangle.value());
	vec_input.push_back(y3);
	
	return vec_input;
}
////////////////////////////////////////////////////////////////////////////////////
//Конец Fl_Group_Triangle...........................................................
////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////////////////
//Определение методов класса Fl_Group_Rectangle....................................
///////////////////////////////////////////////////////////////////////////////////
Fl_Group_Rectangle::Fl_Group_Rectangle(int X, int Y, int W, int H, const Fl_Color &c_f)
	: FigureOnPlane(X, Y, W, H, c_f),
	  m_int_x1_rectangle(40, 60, 200, 30, "Левый верхний угол X:"),
	  m_int_y1_rectangle(40, 110, 200, 30, "Левый верхний угол Y:"),
	  m_int_x2_rectangle(260, 60, 200, 30, "Правый нижний угол X:"),
	  m_int_y2_rectangle(260, 110, 200, 30, "Правый нижний угол Y:")
{
	m_int_x1_rectangle.align(FL_ALIGN_TOP);
	m_int_y1_rectangle.align(FL_ALIGN_TOP);
	m_int_x2_rectangle.align(FL_ALIGN_TOP);
	m_int_y2_rectangle.align(FL_ALIGN_TOP);
	end();
}
//----------------------------------------------------------------------------------
const std::vector<int>& Fl_Group_Rectangle::getInputInt()
{
	vec_input.clear();
	int x1 = atoi(m_int_x1_rectangle.value());
	vec_input.push_back(x1);
	int y1 = atoi(m_int_y1_rectangle.value());
	vec_input.push_back(y1);
	int x2 = atoi(m_int_x2_rectangle.value());
	vec_input.push_back(x2);
	int y2 = atoi(m_int_y2_rectangle.value());
	vec_input.push_back(y2);
	
	return vec_input;
}
////////////////////////////////////////////////////////////////////////////////////
//Конец Fl_Group_Rectangle..........................................................
////////////////////////////////////////////////////////////////////////////////////
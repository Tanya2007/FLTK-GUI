#ifndef FIGURES_H
#define FIGURES_H

#include "figureOnPlane.h"
////////////////////////////////////////////////////////////
class Fl_Group_Circle : public FigureOnPlane
{
	private:
		Fl_Int_Input m_int_x_radius_circle;
		Fl_Int_Input m_int_y_radius_circle;
		Fl_Int_Input m_int_radius_circle;

	public:
		Fl_Group_Circle(int X, int Y, int W, int H, const Fl_Color &c_f);	
		virtual const std::vector<int>& getInputInt() override;	
};
///////////////////////////////////////////////////////////// 
class Fl_Group_Triangle : public FigureOnPlane
{
	private:
		Fl_Int_Input m_int_x1_triangle;
		Fl_Int_Input m_int_y1_triangle;
		Fl_Int_Input m_int_x2_triangle;
		Fl_Int_Input m_int_y2_triangle;
		Fl_Int_Input m_int_x3_triangle;
		Fl_Int_Input m_int_y3_triangle;

	public:
		Fl_Group_Triangle(int X, int Y, int W, int H, const Fl_Color &c_f);
		virtual const std::vector<int>& getInputInt() override;
};
/////////////////////////////////////////////////////////////
class Fl_Group_Rectangle : public FigureOnPlane
{
	private:
		Fl_Int_Input m_int_x1_rectangle;
		Fl_Int_Input m_int_y1_rectangle;
		Fl_Int_Input m_int_x2_rectangle;
		Fl_Int_Input m_int_y2_rectangle;
		
	public:
		Fl_Group_Rectangle(int X, int Y, int W, int H, const Fl_Color &c_f);
		virtual const std::vector<int>& getInputInt() override;
};
///////////////////////////////////////////////////////////////
#endif
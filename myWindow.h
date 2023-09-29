#ifndef MY_WINDOW_H
#define MY_WINDOW_H

#include "Figures.h"
class Drawing : public Fl_Box
{
	private:
		std::string m_type;
		void draw();
		FigureOnPlane *figure_plane;

	public:
		Drawing(int X, int Y, int W, int H)
			: Fl_Box(X, Y, W, H), m_type{}, figure_plane(nullptr)
		{
			box(FL_ROUNDED_BOX);
			color(FL_WHITE);
		}

		void setType(const std::string &str)
		{
			m_type = str;
		}
		
		void setFigurePlane(FigureOnPlane *f_p)
		{
			figure_plane = f_p;
		}
		
		FigureOnPlane* getFigure() const
		{
			return figure_plane;
		}
};

class MyWindow : public Fl_Double_Window
{
	private:
		Fl_Menu_Bar m_menubar;
		static Fl_Menu_Item m_menutable[3];
		Fl_Group_Circle m_gr_circle;
		Fl_Group_Triangle m_gr_triangle;
		Fl_Group_Rectangle m_gr_rectangle;
		Drawing m_draw_box;
		Fl_Button m_button;
		Fl_Input m_square;
		Fl_Input m_perimeter;

	public:
		MyWindow(int W, int H, const char* label = "");
		static void drawFigure(Fl_Widget* figure, void*);
		static void my_static_callback(Fl_Widget* w);
		void drawFigureWindow(const std::string&);
		void my_callback(FigureOnPlane* type_figure);
		void fillCalculations(FigureOnPlane* type_figure);
};

#endif
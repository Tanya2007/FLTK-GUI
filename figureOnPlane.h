#ifndef FIGURE_ON_PLANE_H
#define FIGURE_ON_PLANE_H

#include <FL/Fl.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Sys_Menu_Bar.H>
#include <FL/Fl_Int_Input.H>
#include <vector>
#include <cmath>
#include <string>
#include <map>

class FigureOnPlane : public Fl_Group
{
	protected:
		Fl_Color color_figure;
		std::vector<int> vec_input;
		
	public:
		FigureOnPlane(int X, int Y, int W, int H, const Fl_Color &c_f)
			: Fl_Group(X, Y, W, H), color_figure(c_f), vec_input{}
		{
			box(FL_ROUNDED_BOX);
			Fl_Color c = fl_rgb_color(197, 251, 225);
			color(c);
		}
		
		const Fl_Color& getColorFigure() const
		{
			return color_figure;
		}
		
		virtual const std::vector<int>& getInputInt() = 0;
};

#endif
#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include <types.hpp>

struct OpenGL_Context;
class OpenGL_Context_Handle
{
	private:
		OpenGL_Context& context;
	public:
		OpenGL_Context_Handle(bool create = true);
		OpenGL_Context_Handle(const OpenGL_Context&);
		~OpenGL_Context_Handle();
		bool create();
		bool create(const OpenGL_Context_Handle&);
		bool destroy();
		bool is_current();
		bool make_current();
};

struct OpenGL_Window;
class OpenGL_Window_Handle
{
	private:
		OpenGL_Window& window;
	public:
		OpenGL_Window_Handle(bool create_context = true);
		~OpenGL_Window_Handle();
		bool create();
		bool destroy();
		OpenGL_Context* get_current_context();
};

class Keyboard
{
	//--> Structures <--//
    public:
		struct KeyEvent
		{
		};
		struct SpecialState
		{
		};
	//--> Static members <--//
    public:
		static const SpecialState& get_special_state();
};

class Mouse
{
	//--> Structures <--//
    public:
		struct MotionEvent
		{
		};
		struct ButtonEvent
		{
		};
		struct ButtonState
		{
		};
	//--> Static members <--//
    public:
		static const ButtonState& get_button_state();
        static coord_t get_x_pos();
        static coord_t get_y_pos();
        static bool is_inside();
        static void set_position(coord_t x, coord_t y);
        static bool catch_cursor();
        static bool release_cursor();
};

class System
{
	void init();
	void is_init();
};

#endif//__INTERFACE_HPP__

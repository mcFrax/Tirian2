#include <interface.hpp>

#include <GL/gl.h>

#ifdef __unix
//--------------------------------------------------------------------//
//------------------------------- Unix -------------------------------//
//--------------------------------------------------------------------//

#include <GL/glx.h>
#include <X11/Xlib.h>

static Display *dsp = 0;

struct OpenGL_Context
{
	GLXContext context;
	uint handles;
		//~ OpenGL_Context(bool create = true);
		//~ OpenGL_Context(const OpenGL_Context&);
		//~ ~OpenGL_Context();
		//~ bool create();
		//~ bool create(const OpenGL_Context_Handle&);
		//~ bool destroy();
		//~ bool is_current();
		//~ bool make_current();
};

struct OpenGL_Window
{
	GLXWindow window;
	uint handles;
		//~ OpenGL_Context* get_contex();
		//~ OpenGL_Window(bool create_context = true);
		//~ ~OpenGL_Window();
		//~ bool create();
		//~ bool destroy();
		//~ OpenGL_Context* get_current_context();
};

#else
//--------------------------------------------------------------------//
//------------------------------ Windows -----------------------------//
//--------------------------------------------------------------------//
#ifdef _WIN32
	#error Windows interface not implemented yet
#else
	#error Platform not handled
#endif
#endif

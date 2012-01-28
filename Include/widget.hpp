#ifndef __WIDGET_HPP__
#define __WIDGET_HPP__

#include <types.hpp>
#include <interface.hpp>
#include <memory>
#include <string>
#include <set>
#include <map>

typedef uint WidgetId;
typedef uint WidgetTime;

class Widget;

class WidgetObj
{
    //--> type definitions <--//
    public:
        typedef void (*Callback) (WidgetObj&);
        enum Anchor
        {
            anch_left = 1,
            anch_right = 2,
            anch_top = 4,
            anch_bottom = 8
        };
    //--> Static members <--//
    private:
		static std::map<WidgetId, WidgetObj*> map;
		static std::set<Widget> under_mouse;
        //^got mouse enter and haven't got mouse escaped or anything
		static WidgetTime now;
    //--> Friends <--//
	friend class Widget;
    //--> Fields <--//
    private:
		WidgetTime change_time;
		WidgetObj* int_parent;
		std::set<WidgetObj*> children;
        bool val_visible;
        bool val_enabled;
        bool val_tab_focusable;
        bool val_focused;
        bool val_tab_focusing;
        //^afects tab focusing of children
        int_coord_t int_left;
        int_coord_t int_top;
        int_coord_t int_width;
        int_coord_t int_height;
    protected:
		const std::set<WidgetObj*> get_children();
    public:
		const WidgetId id;
		const std::string name;
        uint anchors;
		//--> Callbacks <--//
    //--> Methods <--//
	private:
        void add_child(WidgetObj*);
        void rem_child(WidgetObj*);
	protected:
		WidgetObj(const std::string& name);
		WidgetObj(const std::string& name, const Widget& parent,
                coord_t xoff, coord_t yoff,
                coord_t width, coord_t height);
        virtual void draw(int_coord_t x_off, int_coord_t y_off,
				int_coord_t window_height);
        virtual bool mouse_motion_event(const Mouse::MotionEvent&);
        virtual bool mouse_button_event(const Mouse::ButtonEvent&);
        virtual bool keyboard_key_event(const Keyboard::KeyEvent&);
	public:
		bool is_orphan();
        void unparent();
        void dock(const Widget& parent, coord_t xoff, coord_t yoff,
                coord_t width, coord_t height);
		//~ template<class... Args> static Widget create( Args... args );
		virtual void remove();
		virtual ~WidgetObj();
};

class Widget
{
    //--> Fields <--//
	private:
		WidgetId id;
		WidgetObj* instance;
    //--> Methods <--//
	public:
        //--> constructors <--//
		Widget();
		Widget(WidgetObj&);
        //--> operators <--//
		WidgetObj& operator* () { return *instance; }
		WidgetObj* operator-> () { return instance; }
		operator bool();
};

//~ template<class... Args> Widget WidgetObj::create( Args... args )
//~ {
	//~ return
//~ }

#endif//__WIDGET_HPP__

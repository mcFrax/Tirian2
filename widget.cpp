#include <widget.hpp>

//----> static variables <----//
static WidgetId nextid = 2;
const static WidgetObj::Anchor topleft_anchor =
		WidgetObj::anch_left | WidgetObj::anch_top;

//--------------------------------------------------------------------//
//----------------------------> WidgetObj <---------------------------//
//--------------------------------------------------------------------//

//----> WidgetObj static members <----//
std::map<WidgetId, WidgetObj*> WidgetObj::map;
std::set<Widget> WidgetObj::under_mouse;
WidgetTime WidgetObj::now = 0;

//----> WidgetObj constructors <----//
WidgetObj::WidgetObj(const std::string& arg_name)
	: int_parent(0), val_visible(0), val_enabled(0),
	val_tab_focusable(0), val_focused(0), val_tab_focusing(1),
	change_time(now++), id(nextid++), name(arg_name),
	anchors(topleft_anchor)
{
	WidgetObj::map.insert(std::make_pair(this->id, this));
}

//----> WidgetObj destructor <----//
WidgetObj::~WidgetObj()
{
	WidgetObj::map.erase( id );
}

//----> WidgetObj methods <----//
void WidgetObj::draw(int_coord_t x_off, int_coord_t y_off,
		int_coord_t window_height)
{
	self_draw();
	if (on_draw)
		on_draw(this);
	for (auto i = this->children.begin(); i != this->children.end();
			++i){
		glPushMatrix();
		glScissor(x_off, window_height-(*i)->int_top-(*i)->int_height,
				(*i)->int_width, (*i)->int_height);
		glTranslate((*i)->int_left, (*i)->int_top, 0);
		(*i)->draw(x_off+(*i)->int_left, y_off+(*i)->int_top);
		glPopMatrix();
	}
	after_draw();
}

const std::set<WidgetObj*> WidgetObj::get_children()
{
	return children;
}

bool WidgetObj::is_orphan()
{
	return !int_parent;
}

//----> Widget constructors <----//
Widget::Widget()
	: id(0), instance(0)
{
}

Widget::Widget(WidgetObj& w)
	: id(w.id), instance(&w)
{
}

//----> Widget methods <----//
Widget::operator bool()
{
	return instance != 0 && WidgetObj::map.count( id );
}

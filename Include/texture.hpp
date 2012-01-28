#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include <memory>

#include <types.hpp>

struct TextureBinding;

//~ class TextureSource
//~ {
	//~ public:
		//~ virtual bool is_reusable() {return 0;}
//~ }

class Texture
{
	private:
		static bool instant_removement();
		static bool instant_removement(bool);
	protected:
		shared_ptr<TextureBinding> binding;
		bool need;
	public:
		Texture();
		~Texture();
		void load_from_file(const char* path);
		void create_as_subtexture(const Texture, Point2 p1, Point2 p2, Point2 p3, Point2 p4);
		void free();
		void force_free(); //<nie wiem, czy to jest implementowalne
		void dont_care(); 
		void reload(); //assumes need
		void bind();
		void glTexCoord(int);
		Point get_point(int);
		//~ TextureSource* get_source();
};

#endif//__TEXTURE_HPP__

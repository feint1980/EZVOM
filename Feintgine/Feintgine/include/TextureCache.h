#ifndef TEXTURECACHE_H
#define TEXTURECACHE_H

#include <map>
#include "GLTexture.h"
#include <string>
namespace Feintgine{


	class TextureCache
	{
	public:
		TextureCache();
		~TextureCache();
		GLTexture getTexture(std::string filePath);
	private:
		std::map<std::string, GLTexture> _textureMap;
	};
}


#endif // TEXTURECACHE_H

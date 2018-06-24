#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "TextureCache.h"
#include <string>
namespace Feintgine
{

	class ResourceManager
	{
	public:
		static GLTexture getTexture(std::string filePath);

		static GLuint boundTexture;

	private:
		static TextureCache _textureCache;
	};
}

#endif // RESOURCEMANAGER_H

#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#include "GLTexture.h"
#include <string>
#include "IOManager.h"
#include "picoPNG.h"

#include "Error.h"

namespace Feintgine
{

	class ImageLoader
	{
	public:
		static GLTexture loadPNG(std::string filePath);
	};
}

#endif // IMAGELOADER_H

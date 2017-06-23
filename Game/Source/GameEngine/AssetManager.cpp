#include "AssetManager.h"

namespace Blz
{
	//static variable defintions
	TextureCache AssetManager::textureCache;

	AssetManager::AssetManager()
	{
	}


	AssetManager::~AssetManager()
	{
	}

	Blz::Graphics::GLTexture AssetManager::GetTexture(Blz::string texturePath)
	{
		return textureCache.GetTexture(texturePath);
	}
}
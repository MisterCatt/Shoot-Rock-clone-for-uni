#pragma once
#include "Core.h"

class GameManager
{
public:
	GameManager();
	~GameManager();

	void AddTexture(std::string, Texture2D);
	void AddSound(std::string, Sound);

	void PlaySound(std::string);
	void DrawTexture(std::string, float, int, int);

	void Input();

	std::map<std::string, Sound> sounds;

private:

	
	std::map<std::string, Texture2D> textures;

};


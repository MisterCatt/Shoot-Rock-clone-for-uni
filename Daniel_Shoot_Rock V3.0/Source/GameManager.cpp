#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
	sounds.clear();
	textures.clear();
}

void GameManager::AddTexture(std::string name, Texture2D texture)
{
	textures[name] = texture;
}

void GameManager::AddSound(std::string name, Sound sound)
{
	sounds[name] = sound;
}

void GameManager::PlaySound(std::string name)
{
	PlaySoundMulti(sounds.at(name));
	std::cout << "PlayedSound: " << name << std::endl;
}

void GameManager::DrawTexture(std::string name, float angle, int x, int y)
{
	DrawTexturePro(
		textures.at(name),
		Rectangle{ 0.0f, 0.0f, (float)textures.at(name).width, (float)textures.at(name).height },
		Rectangle{ (float)x,(float)y,
		(float)textures.at(name).width, (float)textures.at(name).height },
		Vector2{ (float)textures.at(name).width / 2, (float)textures.at(name).height / 2 },
		angle,
		WHITE);
}

void GameManager::Input()
{
	KeyboardKey k;

	k = (KeyboardKey)GetKeyPressed();

	switch (k)
	{
	case KEY_ONE:
		PlaySound("Charge");
		break;
	case KEY_TWO:
		break;
	case KEY_THREE:
		break;
	case KEY_FOUR:
		break;
	case KEY_FIVE:
		break;
	case KEY_SIX:
		break;
	case KEY_SEVEN:
		break;
	case KEY_EIGHT:
		break;
	case KEY_NINE:
		break;
	default:
		break;
	}
}

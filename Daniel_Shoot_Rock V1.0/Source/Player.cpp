#include "Player.h"


Player::Player()
{
	texture = LoadTexture("Assets/TestSpin.png");

	rotation = 0;

	position.SetX(800/2);
	position.SetY(450/2);

	charging = false;
	chargeTime = 0;
}

Player::~Player()
{
}

void Player::Update() {

	Input();
	Charging();

}

void Player::Input() {
	/*if (IsKeyDown(KEY_E)) {
		rotation++;
	}
	if (IsKeyDown(KEY_Q)) {
		rotation--;
	}*/

	if (IsKeyDown(KEY_A)) {
		position.x--;
	}
	if (IsKeyDown(KEY_D)) {
		position.x++;
	}
	if (IsKeyDown(KEY_W)) {
		position.y--;
	}
	if (IsKeyDown(KEY_S)) {
		position.y++;
	}

	if (IsKeyDown(KEY_Z)) {
		charging = true;
	}
	if (IsKeyReleased(KEY_Z)) {
		charging = false;

		if (chargeTime >= 120) {
			std::cout << "Shot" << std::endl;
		}
	}
}

void Player::Render() {
	
	DrawTexturePro(
		texture, 
		Rectangle{ 0.0f, 0.0f, 25, 50}, 
		Rectangle{ position.x,position.y, 
		(float)texture.width, (float)texture.height}, 
		Vector2{(float)texture.width/2, (float)texture.height/2}, 
		rotation, 
		WHITE);
}

void Player::Charging() {
	if (charging == true) {
		chargeTime++;
		std::cout << "Charging" << std::endl;
	}
	else {
		chargeTime = 0;
	}
}
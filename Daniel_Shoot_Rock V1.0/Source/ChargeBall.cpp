#include "ChargeBall.h"

ChargeBall::ChargeBall(Color col, float playerSpeed, bool right) : GameObject("Bullet")
{
	baseX = baseY = 0;

	colour = col;

	radius = 30;

	startDir = rightDir = right;
	upDir = GetRandomValue(0,1);

	speed = playerSpeed;

	spacing = 50;

	timer = 120;

	launching = false;

	SetActive(false);
}

ChargeBall::~ChargeBall()
{
}

void ChargeBall::SetRightDir(bool goingRight)
{
	rightDir = goingRight;
}

void ChargeBall::Update()
{
	if (IsActive()) {
		Jitter();

		if (launching) {


			baseY -= speed*5;

			position.y += (upDir) ? speed * 5 : -(speed * 5);

			if (timer >= 0)
				timer--;

			if (timer <= 0) {
				Destroy();
			}
		}
	}
}

void ChargeBall::Render()
{
	if(IsActive())
	DrawCircle((int)position.x, (int)position.y, radius, colour);


}

void ChargeBall::Reset(float x, float y)
{
	baseX = position.x = x;
	baseY = position.y = y;

	position.x += GetRandomValue(-10, 10);

	spacing = 50;
	timer = 120;
	radius = 30;

	launching = false;

	rightDir = startDir;

	SetActive(true);
}

void ChargeBall::Launch() {
	launching = true;
}

void ChargeBall::Jitter()
{
	if (!launching) {

		if (IsKeyDown(KEY_A)) {
			if (baseX > 0 + radius)
				baseX -= speed;
		}
		if (IsKeyDown(KEY_D)) {
			if (baseX < (GetScreenWidth() - radius))
				baseX += speed;
		}
		if (IsKeyDown(KEY_W)) {
			if (baseY > 0 - (radius + 10))
				baseY -= speed;
		}
		if (IsKeyDown(KEY_S)) {
			if (baseY < GetScreenHeight() - radius)
				baseY += speed;
		}

		
		position.y += (upDir) ? speed * 2 : -(speed * 2);

	}
		

	position.x += (rightDir) ? speed * 2 : -(speed * 2);

	

	if (position.x > baseX + spacing)
		rightDir = false;

	if (position.x < baseX - spacing)
		rightDir = true;

	if (position.y > baseY - 7)
		upDir = false;

	if (position.y < baseY)
		upDir = true;

	if (radius > 15) {
		radius -= 0.5f;
	}

	if (spacing > 5)
		spacing -= 2;
}

void ChargeBall::Destroy() {
	SetActive(false);
}




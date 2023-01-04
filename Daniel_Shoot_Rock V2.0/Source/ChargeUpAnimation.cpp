#include "ChargeUpAnimation.h"

ChargeUpAnimation::ChargeUpAnimation()
{
	player = Player::GetInstance();

	charging = false;

	ballMinRadius = 10;
	ballMaxRadius = 40;

	ball3 = ball2 = ball1 = { ballMaxRadius, player->GetPosition().x,player->GetPosition().y};
}

ChargeUpAnimation::~ChargeUpAnimation()
{
}

void ChargeUpAnimation::Render()
{
	
}

void ChargeUpAnimation::Update()
{

	ball3 = ball2 = ball1 = { ballMaxRadius, player->GetPosition().x,player->GetPosition().y + ballMaxRadius };
}

void ChargeUpAnimation::Charge()
{
	charging = true;
}

void ChargeUpAnimation::Reset()
{
	ball3 = ball2 = ball1 = { ballMaxRadius, player->GetPosition().x,player->GetPosition().y + ballMaxRadius };
}

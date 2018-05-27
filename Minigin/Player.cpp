#include "MiniginPCH.h"
#include "Player.h"
#include "TextureComponent.h"
#include "RenderComponent.h"
#include "InputComponent.h"
#include "Maths.h"


Player::Player(const glm::vec2& pos, const std::string texturePath, ControlsType controllerType)
	:mTexturePath(texturePath)
	,mControllerType(controllerType)
{
	GetComponent<Transform>()->SetPosition(pos.x, pos.y);
}


Player::~Player()
{
}

void Player::Init()
{
	AddComponent(std::make_shared<TextureComponent>(mTexturePath));
	AddComponent(std::make_shared<RenderComponent>(GetComponent<TextureComponent>()->GetTexture()));
	AddComponent(std::make_shared<InputComponent>());
	if(mControllerType == KEYBOARD)
	{
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::UPARROW, std::make_shared<SetDir>(UP, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::DOWNARROW, std::make_shared<SetDir>(DOWN, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::LEFTARROW, std::make_shared<SetDir>(LEFT, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::RIGHTARROW, std::make_shared<SetDir>(RIGHT, std::static_pointer_cast<Player>(shared_from_this())));
	}
	else
	{
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::DPAD_UP, std::make_shared<SetDir>(UP, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::DPAD_DOWN, std::make_shared<SetDir>(DOWN, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::DPAD_LEFT, std::make_shared<SetDir>(LEFT, std::static_pointer_cast<Player>(shared_from_this())));
		GetComponent<InputComponent>()->AddInput(InputComponent::Button::DPAD_RIGHT, std::make_shared<SetDir>(RIGHT, std::static_pointer_cast<Player>(shared_from_this())));
	}
	
	
}

void Player::SetDirection(Dir direction)
{
	mDirection = direction;
}

void Player::Move(glm::vec2 currentPos, glm::vec2 futurePos,float deltaTime)
{
	mMoveTimer = 0.0f;
	mMoveTimer += deltaTime;
	if (mMoveTimer > 1.0f) mMoveTimer = 0.0f;
	auto pos = Lerp(currentPos, futurePos, mMoveTimer);
	GetComponent<Transform>()->SetPosition(pos.x, pos.y);
	mMoveTimer = 0.0f;
}

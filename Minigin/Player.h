#pragma once
#include "GameObject.h"

class Player : public GameObject
{
	enum ControlsType
	{
		KEYBOARD,
		CONTROLLER
	};
public:
	enum Dir
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};
	explicit Player(const glm::vec2& pos,const std::string texturePath,ControlsType controllerType = KEYBOARD);
	virtual ~Player();

	void Init() override;
	Dir GetDirection()const { return  mDirection; }
	void SetDirection(Dir direction);
	void Move(glm::vec2 currentPos, glm::vec2 futurePos,float deltaTime);
private:
	
	const std::string mTexturePath;
	Dir mDirection = LEFT;
	Dir mLastDirection;
	ControlsType mControllerType;
	float mMoveTimer = 0.0f;
};


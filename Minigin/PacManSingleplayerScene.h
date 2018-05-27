#pragma once
#include "Scene.h"
#include "Grid.h"
#include "Player.h"

class PacManSingleplayerScene final: public Scene
{
public:
	PacManSingleplayerScene();
	~PacManSingleplayerScene();

	void Init() override;
	void SceneUpdate(float deltaTime) override;
private:
	std::shared_ptr<Player> mPacMan;
	std::shared_ptr<Grid> mGrid;
	std::shared_ptr<GameObject> mFpsCounter;
	std::shared_ptr<GameObject> mScoreCounter;
	std::shared_ptr<GameObject> mLifeCounter;


	float mFPSIntervalCounter = 0.0f;
	float mFPSTimeInterval = 1.0f;
	int mScore = 0;
	int mLives = 3;
};


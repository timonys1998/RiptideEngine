#include "MiniginPCH.h"
#include "PacManSingleplayerScene.h"
#include "Grid.h"
#include "RenderComponent.h"
#include "TextureComponent.h"
#include "TextComponent.h"
#include "FPSCalculatorComponent.h"
#include "Player.h"


PacManSingleplayerScene::PacManSingleplayerScene()
	:Scene("PacManSinglePlayer")
{
	Init();
}


PacManSingleplayerScene::~PacManSingleplayerScene()
{
}

void PacManSingleplayerScene::Init()
{
	
	mPacMan = std::make_shared<Player>(glm::vec2(320, 352),"SinglePacMan.png");
	mGrid = std::make_shared<Grid>("level1.txt",mPacMan,640);
	Add(mGrid);

	mFpsCounter = std::make_shared<GameObject>();
	mFpsCounter->AddComponent(std::make_shared<TextComponent>("Lingua.otf", 20, SDL_Color{ 200,155,15 }));
	mFpsCounter->AddComponent(std::make_shared<FPSCalculatorComponent>());
	mFpsCounter->GetComponent<TextComponent>()->SetText(std::to_string(mFpsCounter->GetComponent<FPSCalculatorComponent>()->GetFps()));
	mFpsCounter->AddComponent(std::make_shared<RenderComponent>(mFpsCounter->GetComponent<TextComponent>()->GetTexture()));
	mFpsCounter->GetComponent<Transform>()->SetPosition(0.0f, 0);
	Add(mFpsCounter);

	mScoreCounter = std::make_shared<GameObject>();
	mScoreCounter->AddComponent(std::make_shared<TextComponent>("Lingua.otf", 20, SDL_Color{ 200,155,15 }));
	mScoreCounter->GetComponent<TextComponent>()->SetText("Score: " + std::to_string(mScore));
	mScoreCounter->AddComponent(std::make_shared<RenderComponent>(mScoreCounter->GetComponent<TextComponent>()->GetTexture()));
	mScoreCounter->GetComponent<Transform>()->SetPosition(200.0f, 0.0f);
	Add(mScoreCounter);

	mLifeCounter = std::make_shared<GameObject>();
	mLifeCounter->AddComponent(std::make_shared<TextComponent>("Lingua.otf", 20, SDL_Color{ 200,155,15 }));
	mLifeCounter->GetComponent<TextComponent>()->SetText("Lifes: " + std::to_string(mLives));
	mLifeCounter->AddComponent(std::make_shared<RenderComponent>(mLifeCounter->GetComponent<TextComponent>()->GetTexture()));
	mLifeCounter->GetComponent<Transform>()->SetPosition(400.0f, 0.0f);
	Add(mLifeCounter);

}

void PacManSingleplayerScene::SceneUpdate(float deltaTime)
{
	
	mFPSIntervalCounter += deltaTime;
	if (mFPSIntervalCounter >= mFPSTimeInterval) {
		mFpsCounter->GetComponent<TextComponent>()->SetText(std::to_string(mFpsCounter->GetComponent<FPSCalculatorComponent>()->GetFps()));
		mFpsCounter->GetComponent<RenderComponent>()->ChangeRenderingTexture(mFpsCounter->GetComponent<TextComponent>()->GetTexture());
		mFPSIntervalCounter = 0.0f;
	}
	mScoreCounter->GetComponent<TextComponent>()->SetText("Score: " + std::to_string(mScore));
	mScoreCounter->GetComponent<RenderComponent>()->ChangeRenderingTexture(mScoreCounter->GetComponent<TextComponent>()->GetTexture());

	mLifeCounter->GetComponent<TextComponent>()->SetText("Lifes: " + std::to_string(mLives));
	mLifeCounter->GetComponent<RenderComponent>()->ChangeRenderingTexture(mLifeCounter->GetComponent<TextComponent>()->GetTexture());

	if (mPacMan->GetDirection() == Player::LEFT)
	{
		auto tile = mGrid->GetTiles().at(mGrid->GetTileLeftIdx());
		if (tile->GetType() != Tile::GhostWall && tile->GetType() != Tile::Wall)
		{
			mPacMan->Move(mPacMan->GetComponent<Transform>()->GetPosition(), tile->GetComponent<Transform>()->GetPosition(),deltaTime);
		}
	}
	else if (mPacMan->GetDirection() == Player::RIGHT)
	{
		auto tile = mGrid->GetTiles().at(mGrid->GetTileRightIdx());
		if (tile->GetType() != Tile::GhostWall && tile->GetType() != Tile::Wall)
		{
			mPacMan->Move(mPacMan->GetComponent<Transform>()->GetPosition(), tile->GetComponent<Transform>()->GetPosition(),deltaTime);
		}
	}
	else if (mPacMan->GetDirection() == Player::DOWN)
	{
		auto tile = mGrid->GetTiles().at(mGrid->GetTileDownIdx());
		if (tile->GetType() != Tile::GhostWall && tile->GetType() != Tile::Wall)
		{
			mPacMan->Move(mPacMan->GetComponent<Transform>()->GetPosition(), tile->GetComponent<Transform>()->GetPosition(),deltaTime);
		}
	}
	else if (mPacMan->GetDirection() == Player::UP)
	{
		auto tile = mGrid->GetTiles().at(mGrid->GetTileUpIdx());
		if(tile->GetType() != Tile::GhostWall && tile->GetType() != Tile::Wall)
		{
			mPacMan->Move(mPacMan->GetComponent<Transform>()->GetPosition(), tile->GetComponent<Transform>()->GetPosition(),deltaTime);
		}
	}
	
	
}




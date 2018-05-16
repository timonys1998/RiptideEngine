#include "MiniginPCH.h"
#include "MainMenuScene.h"
#include "TextObject.h"
#include "ResourceManager.h"


MainMenuScene::MainMenuScene()
	:dae::Scene("MainMenu")
{
	Init();
}


MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Init()
{
	go = std::make_shared<dae::GameObject>();
	go->SetTexture("background.jpg");
	go->GetComponent<dae::Transform>()->SetPosition(50.0f,50);
	
	Add(go);
	//go->GetComponent<dae::Transform>();

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.png");
	Add(go);
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextObject>("Programming 4", font);
	to->SetPosition(80, 20);
	Add(go);
}

void MainMenuScene::Update()
{
	for(auto o : GetObjects())
	{
		o->Update();
	}
}

void MainMenuScene::Render() const
{
	for(auto o : GetObjects())
	{
		o->Render();
	}
}


#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"
#include <algorithm>


void dae::SceneManager::Update()
{
	if (mActiveScene)
		mActiveScene->Update();
	else
		std::cout << "No scene set as active scene \n";
}

void dae::SceneManager::Render()
{
	if (mActiveScene)
		mActiveScene->Render();
	else
		std::cout << "No scene set as active scene \n";

}

void dae::SceneManager::CreateScene(std::shared_ptr<Scene> gameScene)
{
	mScenes.push_back(gameScene);
}

void dae::SceneManager::SetActiveScene(const std::string name)
{
	auto it = find_if(mScenes.begin(),mScenes.end(),[name](std::shared_ptr<Scene> scene)
	{
		return name == scene->GetName();
	});

	if(it != mScenes.end())
	{
		mActiveScene = *it;
	}
}


#pragma once
#include "Scene.h"

class MainMenuScene final : public dae::Scene
{
public:
	MainMenuScene();
	virtual ~MainMenuScene();

	void Init() override;
	void Update() override;
	void Render() const override;

private:
	std::shared_ptr<dae::GameObject> go;
};


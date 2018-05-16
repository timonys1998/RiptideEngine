#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "BaseComponent.h"

dae::GameObject::GameObject()
{
	mComponents.push_back(mTransform);
}

void dae::GameObject::Init()
{
	
}


dae::GameObject::~GameObject() = default;

void dae::GameObject::Update()
{
	for(auto c : mComponents)
	{
		c->Update();
	}
}

void dae::GameObject::Render() const
{
	const auto pos = mTransform->GetPosition();
	Renderer::GetInstance().RenderTexture(*mTexture, pos.x, pos.y);
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	mTexture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::AddComponent(std::shared_ptr<BaseComponent> component)
{
	if(typeid(component) == typeid(Transform))
	{
		std::cout << "GameObject::AddComponent >> Cannot add transform component, this is done at initialization of the object \n";
		return;
	}
	for(auto comp : mComponents )
	{
		if(component == comp)
		{
			std::cout << "GameObject::AddComponent >> Cannot add a component already on the gameobject \n";
		}
	}
	mComponents.push_back(component);
	//component->mOwner = this;
}



//void dae::GameObject::RemoveComponent(const BaseComponent& component)
//{
//
//	//mComponents.erase(std::remove(mComponents.begin(), mComponents.end(), component), mComponents.end());
//}



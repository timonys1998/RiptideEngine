#pragma once
#include <memory>

#include "Transform.h"
#include "Texture2D.h"

class BaseComponent;

namespace dae
{
	class GameObject
	{
	public:
		void Init();
		void Update();
		void Render() const ;
	
		void SetTexture(const std::string& filename);//Will be done with texture component

		void AddComponent(std::shared_ptr<BaseComponent> component);
		//void RemoveComponent(const BaseComponent& component);


		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		//Templated functions
		template<class T>
		std::shared_ptr<T> GetComponent()
		{
			for(auto comp : mComponents)
			{
				//We dont check for nullptr cause the component should not be in the vector if its nullptr / We only check if its the type
				if(std::dynamic_pointer_cast<T>(comp))
				{
					std::cout << "Component found \n";
					return std::dynamic_pointer_cast<T>(comp);
				}
			}
			return nullptr;
		}

	private:
		friend class BaseComponent;
		std::shared_ptr<Transform> mTransform = std::make_shared<Transform>();
		std::shared_ptr<Texture2D> mTexture;
		std::vector<std::shared_ptr<BaseComponent>> mComponents;
	};
}

#pragma once

class GameObject;

namespace dae {
	class BaseComponent
	{
	public:
		BaseComponent();
		virtual ~BaseComponent();
		virtual void Update() = 0;


		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;
	private:
		std::shared_ptr<GameObject> mOwner;

	};
}


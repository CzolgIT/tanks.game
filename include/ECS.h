#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <memory>

class GameObject;


class Component{
public:
  GameObject * gameObject;
  virtual void Start() {}
  virtual void Update() {}
  virtual ~Component() {}
};


class GameObject{
private:
  bool isActive = true;
  std::vector<std::unique_ptr<Component>> components;
public:
  void Start()
  {
    for (int i = 0 ; i < static_cast<int>(components.size()); i++)
    {
      components[i]->Start();
    }
  }
  void Update()
  {
    for (int i = 0 ; i < static_cast<int>(components.size()); i++)
    {
      components[i]->Update();
    }
  }
  void Destroy() { isActive = false; }

  template <typename T> bool hasComponent() const {
    for (int i = 0 ; i < static_cast<int>(components.size()); i++)
    {
      if (typeid(components[i]) == typeid(T))
      return true;
    }
    return false;

  }

  template <typename T, typename... TArgs> void AddComponent(TArgs&&... targs){

    T* com(new T(std::forward<TArgs>(targs)...));
    com->gameObject = this;
    std::unique_ptr<Component> p { com };
    components.emplace_back(std::move(p));
    com->Start();

  }
  template <typename T> T& getComponent() const
  {
    std::type_info id = typeid(T);
    for (int i = 0 ; i < static_cast<int>(components.size()); i++)
    {
      if (typeid(components[i]) == id)
      return *static_cast<T*>(components[i]);
    }

  }


};

class Manager {
private:
  std::vector<GameObject*> gameObjects;
public:



};

#include <vector>

#ifndef ECS_h
#define ECS_h

class Component{
private:

public:
  virtual void Start();
  virtual void Update();
};

class GameObject{
private:
  bool isActve = true;
  std::vector<Component*> components;
public:
  void Start();
  void Update()
  {
    for (int i = 0 ; i < static_cast<int>(components.size()); i++)
    {
      components[i]->Update();
    }
  }

};

#endif

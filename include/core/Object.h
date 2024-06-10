//
// Created by 青fa on 2024-06-10.
//

#ifndef PVZ_OBJECT_H
#define PVZ_OBJECT_H

#include "Base.h"
#include "SceneComponent.h"

// 前向声明
class SceneComponent;
class Component;
struct Vector2D;

class Object : public Base {
    friend void Component::Destruct();
    friend void SceneComponent::processDestruct();// 友元函数

protected:
    SceneComponent *root = nullptr;            // 根组件（场景对象支持坐标变换）
    std::set<Component *> components;          // component容器
    std::set<Component *> componentsToDestruct;// component垃圾回收的容器

public:
    template<typename T>
    T *ConstructComponent(Vector2D pos);// 由该 Object创建出一个 Component
};

#endif//PVZ_OBJECT_H

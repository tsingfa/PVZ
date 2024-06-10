//
// Created by 青fa on 2024-06-10.
//

#ifndef PVZ_OBJECT_H
#define PVZ_OBJECT_H

#include "Base.h"
#include "SceneComponent.h"

class Object : public Base {
protected:
    SceneComponent *root = nullptr;// 根组件（场景对象支持坐标变换）
public:
    template<typename T>
    T *ConstructComponent(Vector2D pos);// Component及其子类才能用，否则会报错
};

#endif//PVZ_OBJECT_H

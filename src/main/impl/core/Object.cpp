//
// Created by 青fa on 2024-06-10.
//
#include "core/Object.h"

// Component及其子类才能用，否则会报错
template<typename T>
T *Object::ConstructComponent(Vector2D pos) {
    T *com = new T();
    com->SetPosition(pos);
    return com;
}

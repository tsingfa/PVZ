//
// Created by 青fa on 2024-06-08.
//

#include "core/Transform.h"

Transform::Transform() : position(0, 0), scale(1, 1), rotation(0) {}

Transform::Transform(const Vector2D &pos, const Vector2D &scl, float rot) : position(pos), scale(scl), rotation(rot) {}

void Transform::setPosition(const Vector2D &pos) {
    this->position = pos;
}

void Transform::setScale(const Vector2D &scl) {
    this->scale = scl;
}

void Transform::setRotation(float rot) {
    this->rotation = rot;
}

Vector2D Transform::getPosition() const {
    return position;
}

Vector2D Transform::getScale() const {
    return scale;
}

float Transform::getRotation() const {
    return rotation;
}

// 默认标准的坐标变换
Transform Transform::Default() {
    return {Vector2D(0, 0), Vector2D(1, 1), 0};
}

//
// Created by 青fa on 2024-06-03.
//

#include "core/Component.h"

void Component::Update() {
}

void Component::setOwner(Object *oneOwner) {
    this->owner = oneOwner;
}

Object *Component::getOwner() const {
    return this->owner;
}

void Component::SetPosition(Vector2D vector2D) {
}

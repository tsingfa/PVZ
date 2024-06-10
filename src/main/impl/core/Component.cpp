//
// Created by 青fa on 2024-06-03.
//

#include "core/Component.h"

void Component::Update() {
}

void Component::setOwner(Object *oneOwner) {
    this->owner = oneOwner;
}

void Component::Destruct() {
}

Object *Component::getOwner() const {
    return this->owner;
}

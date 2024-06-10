//
// Created by 青fa on 2024-06-08.
//

#include "core/SceneComponent.h"

void SceneComponent::Update() {
    Component::Update();
}

/**
 * 设置或更改所绑定的父亲组件
 **/
void SceneComponent::setAttachment(SceneComponent *newParent) {
    if (this->parent != nullptr) {
        this->parent->children.erase(this);// 将该组件从原先的父亲组件的 children中移除
    }
    // 建立新的父子绑定关系
    this->parent = newParent;
    if (newParent != nullptr) {
        newParent->children.insert(this);
        this->owner = newParent->owner;// 指定组件的 owner
    }
}

/**
 * 销毁 SceneComponent组件（包含自己及其子组件等），即垃圾回收
 **/
void SceneComponent::Destruct() {
    if (this->parent != nullptr) {// 将自己从原父亲的 children中移除
        this->parent->children.erase(this);
    }
    this->processDestruct();// 将自己，孩子，孩子的孩子等添加到待销毁集合中
}

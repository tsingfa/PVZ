//
// Created by 青fa on 2024-06-10.
//
#include "core/Object.h"

// Object 主动构建 Component 容器
// Component及其子类才能用，否则会报错
template<typename T>
T *Object::ConstructComponent(Vector2D pos) {
    T *com = new T();
    // 如果是子类 component组件，则可静态转换为 component指针（子类转父类）
    if (auto *buffer = static_cast<Component *>(com)) {// 如果转换成功
        buffer->SetPosition(pos);
        buffer->setOwner(this);// component的 owner设置为这个 Object本身
        this->components.insert(buffer);
        return com;// 转换成功，返回
    }
    return nullptr;// 转换不成功，即创建失败，返回空指针
}

// 递归将自己，孩子，孩子的孩子等添加到待销毁集合中
void SceneComponent::processDestruct() {
    if (!this->children.empty()) {// 孩子不为空
        for (auto &child: children) {
            child->processDestruct();
        }
    }
    this->owner->componentsToDestruct.insert(this);// 添加到待销毁的容器集合中
}

void Component::Destruct() {
    this->owner->componentsToDestruct.insert(this);
}

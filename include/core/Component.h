//
// Created by 青fa on 2024-06-03.
//

#ifndef PVZ_COMPONENT_H
#define PVZ_COMPONENT_H

#include "Base.h"
#include <set>

/**
 * 所有的 Component都能与 Object绑定，
 * Object实现了一个 Components容器，来统一管理由 Object创建的 Component，
 * 每个 Component都能都一个指针指向 Object。
 **/

class Component : public Base {
protected:
    class Object *owner = nullptr;             // 指向 Object 类的指针
    std::set<Component *> componentsToDestruct;// 要销毁的 component集合

public:
    void Update() override;
    Object *getOwner() const;
    void setOwner(Object *oneOwner);// *为指针，&为引用
    virtual void Destruct();
};


#endif//PVZ_COMPONENT_H

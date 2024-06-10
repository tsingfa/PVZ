//
// Created by 青fa on 2024-06-08.
//

#ifndef PVZ_SCENECOMPONENT_H
#define PVZ_SCENECOMPONENT_H

#include "Component.h"
#include "Transform.h"
#include <set>

class SceneComponent : public Component {
protected:
    Transform transform;                // 支持场景的坐标伸缩变换
    std::set<SceneComponent *> children;// 存储子类组件的容器
    SceneComponent *parent = nullptr;   // 父指针

    void processDestruct();// 辅助删除销毁操作
public:
    void Update() override;
    void setAttachment(SceneComponent *);
    void Destruct() override;// 删除销毁组件
};


#endif//PVZ_SCENECOMPONENT_H

//
// Created by 青fa on 2024-06-08.
//

#ifndef PVZ_TRANSFORM_H
#define PVZ_TRANSFORM_H

#include "Vector2D.h"

// 用于场景的坐标伸缩变换、旋转等
struct Transform {
    Vector2D position;// 二维坐标
    Vector2D scale;   // 横纵放缩倍数
    float rotation;   // 旋转角度

    // 构造函数
    Transform();
    Transform(const Vector2D &pos, const Vector2D &scl, float rot);

    // Getter 和 Setter
    void setPosition(const Vector2D &pos);
    void setScale(const Vector2D &scl);
    void setRotation(float rot);

    Vector2D getPosition() const;
    Vector2D getScale() const;
    float getRotation() const;

    Transform Default();// 默认标准的坐标变换
};

#endif//PVZ_TRANSFORM_H

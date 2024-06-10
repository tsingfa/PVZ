//
// Created by 青fa on 2024-05-31.
//

#ifndef PVZ_VECTOR2D_H
#define PVZ_VECTOR2D_H

#include <cmath>
#include <iosfwd>
#include <iostream>

using namespace std;

// 二维向量 结构体
struct Vector2D {
    float x;
    float y;
    /************* 构造函数 *************/
    Vector2D();
    Vector2D(float a, float b);

    /************* 重载运算符（便于向量运算） *************/
    bool operator==(const Vector2D &another) const;
    bool operator!=(const Vector2D &another) const;
    Vector2D operator+(const Vector2D &another) const;
    Vector2D operator-(const Vector2D &another) const;
    Vector2D operator*(float scale) const;
    Vector2D operator/(float scale) const;
    Vector2D &operator+=(const Vector2D &another);
    Vector2D &operator-=(const Vector2D &another);
    Vector2D &operator*=(float scale);
    Vector2D &operator/=(float scale);
    Vector2D operator-() const;
    float operator*(const Vector2D &another) const;// 向量点乘
    // 重载输出流 << 运算符
    friend std::ostream &operator<<(std::ostream &os, const Vector2D &d);

    /************* 功能函数 *************/
    static float Distance(const Vector2D &a, const Vector2D &b);
    static Vector2D RotateVector(const Vector2D &vec, float angle);
};

#endif// PVZ_VECTOR2D_H

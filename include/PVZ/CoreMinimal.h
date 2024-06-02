//
// Created by 青fa on 2024-05-31.
//

/************************************
 *         核心代码文件
 *
 *     基础外部头文件、基础结构体、
 *    基础类、基础函数、基础全局变量
 ************************************/

#ifndef PVZ_COREMINIMAL_H
#define PVZ_COREMINIMAL_H

/************* 数学相关 *************/

#include <cmath>
#include <iosfwd>
#include <iostream>

#define PI 3.1415926535

using namespace std;

// 二维向量 结构体
struct Vector2D {
    float x;
    float y;

    Vector2D() : x(0), y(0) {}                // 默认构造函数
    Vector2D(float a, float b) : x(a), y(b) {}// 有参构造函数

    // 重载运算符（便于坐标计算）
    // 入参 const代表入参对象的成员变量不会被修改，
    // 函数末尾的 const代表调用该函数的对象的成员变量不会被修改
    Vector2D operator+(const Vector2D &another) const {
        // this指针指向当前对象，指针本身不是对象，访问指针成员要用 "->", 访问对象成员要用 "."
        return {this->x + another.x, this->y + another.y};
    }

    Vector2D operator-(const Vector2D &another) const {
        return {this->x - another.x, this->y - another.y};
    }

    // 这里会修改对象内部的成员变量，所以函数末尾没有 const
    Vector2D operator+=(const Vector2D &another) {
        this->x += another.x;
        this->y += another.y;
        return *this;
    }

    Vector2D operator-=(const Vector2D &another) {
        this->x -= another.x;
        this->y -= another.y;
        return *this;
    }

    // 重载 << 运算符
    // 将 "operator<<"声明为友元函数，使其可访问类的私有成员变量
    friend ostream &operator<<(ostream &os, const Vector2D &d) {
        os << "("
           << "x: " << d.x << ","
           << " y: " << d.y << ")";
        return os;// 返回一个 ostream& 对象
    }

    static float Distance(const Vector2D &a, const Vector2D &b) {
        return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    }

    // 将指定向量（绕原点逆时针）旋转指定的角度
    static Vector2D RotateVector(const Vector2D &vec, float angle) {
        // 角度转弧度，便于后续使用三角函数计算新坐标
        double radian = PI / 180 * angle;
        //旋转角的三角函数
        auto fsin = float(sin(radian));// auto 自动推断变量类型
        auto fcos = float(cos(radian));
        return {vec.x * fcos - vec.y * fsin, vec.x * fsin + vec.y * fcos};
    }
};

#endif// PVZ_COREMINIMAL_H

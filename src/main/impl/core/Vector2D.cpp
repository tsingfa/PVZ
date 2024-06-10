//
// Created by 青fa on 2024-06-02.
//

#include "core/Vector2D.h"

/**
 * 知识点小结
 * <p>
 * 1. const
 * <p>
 *  入参 const代表入参对象的成员变量不会被修改，
 *  函数末尾的 const代表调用该函数的对象的成员变量不会被修改
 * <p>
 * 2. this指针
 * <p>
 *  this指针指向当前对象，指针本身不是对象，
 *  访问指针成员要用 "->"，访问对象成员要用 "."，
 *  在不引起歧义的情况下，"this->"一般可省略
 * <p>
 * 3. 运算符重载
 * <p>
 * 运算符可以重载为类的成员函数和友元函数（使其可访问类的私有成员变量），
 * 成员函数的一元操作符没有参数，二元操作符有一个参数，通常为右操作数；
 * 友元函数的一元操作符为一个参数，二元操作符为两个参数（左操作数和右操作数）
 **/

#define PI 3.1415926535

Vector2D::Vector2D() : x(0), y(0) {}                // 默认构造函数
Vector2D::Vector2D(float a, float b) : x(a), y(b) {}// 有参构造函数

/************* 重载运算符（便于向量运算） *************/

// 入参 const代表入参对象的成员变量不会被修改，
// 函数末尾的 const代表调用该函数的对象的成员变量不会被修改
bool Vector2D::operator==(const Vector2D &another) const {
    return this->x == another.x && this->y == another.y;
}

bool Vector2D::operator!=(const Vector2D &another) const {
    return this->x != another.x || this->y != another.y;
}

Vector2D Vector2D::operator+(const Vector2D &another) const {
    // this指针指向当前对象，指针本身不是对象，
    // 访问指针成员要用 "->"，访问对象成员要用 "."，在不引起歧义的情况下，"this->"一般可省略
    return {this->x + another.x, this->y + another.y};
}

Vector2D Vector2D::operator-(const Vector2D &another) const {
    return {this->x - another.x, this->y - another.y};
}

// 数乘，乘以实数
Vector2D Vector2D::operator*(float scale) const {
    return {this->x * scale, this->y * scale};
}

Vector2D Vector2D::operator/(float scale) const {
    return {this->x / scale, this->y / scale};
}

// 这里会修改对象内部的成员变量，所以函数末尾没有 const
Vector2D &Vector2D::operator+=(const Vector2D &another) {
    this->x += another.x;
    this->y += another.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &another) {
    this->x -= another.x;
    this->y -= another.y;
    return *this;
}

Vector2D &Vector2D::operator*=(float scale) {
    this->x *= scale;
    this->y *= scale;
    return *this;
}

Vector2D &Vector2D::operator/=(float scale) {
    this->x /= scale;
    this->y /= scale;
    return *this;
}

// 取反
Vector2D Vector2D::operator-() const {
    return {-x, -y};
}

// 向量点乘
float Vector2D::operator*(const Vector2D &another) const {
    return this->x * another.x + this->y * another.y;
}

// 重载输出流 << 运算符
// 将 "operator<<"声明为友元函数，使其可访问类的私有成员变量
std::ostream &operator<<(ostream &os, const Vector2D &d) {
    os << "("
       << "x: " << d.x << ","
       << " y: " << d.y << ")";
    return os;// 返回一个 ostream& 对象
}

/************* 功能函数 *************/

float Vector2D::Distance(const Vector2D &a, const Vector2D &b) {
    return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// 将指定向量（绕原点逆时针）旋转指定的角度
Vector2D Vector2D::RotateVector(const Vector2D &vec, float angle) {
    // 角度转弧度，便于后续使用三角函数计算新坐标
    double radian = PI / 180 * angle;
    //旋转角的三角函数
    auto fsin = float(sin(radian));// auto 自动推断变量类型
    auto fcos = float(cos(radian));
    return {vec.x * fcos - vec.y * fsin, vec.x * fsin + vec.y * fcos};
}

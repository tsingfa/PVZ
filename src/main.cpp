
#include "core/Vector2D.h"
#include <iostream>


using namespace std;

int main() {
    Vector2D A(-1, -1);
    Vector2D B(1, 1);
    cout << Vector2D::Distance(A, B) << endl;

    Vector2D C(1, 0);
    cout << Vector2D::RotateVector(C, 90) << endl;

    return 0;
}
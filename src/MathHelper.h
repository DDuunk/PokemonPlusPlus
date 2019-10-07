/**
 * @file		NA
 * @date		17-09-2019
 * @author		Dylan Duunk
 *
 * @brief		Contains all the math functions that will be needed in the framework.
 */
#pragma once

#include <math.h>

#define PI 3.14159265
#define DEG_TO_RAD PI / 180.0f

 /**
  * @brief		Vector2 structs consist of x and y values discribing a 2D vector,
  *				along with vector magnitude calculations, normalization, and operator overloading of += and -=
  */
struct Vector2 {
	float x;
	float y;

	Vector2(float _x = 0.0f, float _y = 0.0f)
		: x(_x), y(_y) {}

	/**
	 * @brief		Calculates the square of the magnitude (preferably used instead of Magnitude if possible)
	 */
	float MagnitudeSqr() {
		return x * x + y * y;
	}
	/**
	 * @brief		Calculates the magnitude of the vector
	 */
	float Magnitude() {
		return (float)sqrt(x * x + y * y);
	}
	/**
	 * @brief		Returns a directional Vector2 with the same direction as the Vector2 but of length 1
	 * 				(Does not change the x and y values of the original vector)
	 */
	Vector2 Normalized() {
		float mag = Magnitude();

		return Vector2(x / mag, y / mag);
	}

	Vector2& operator +=(const Vector2& rhs) {
		x += rhs.x;
		y += rhs.y;

		return *this;
	}

	Vector2& operator -=(const Vector2& rhs) {
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}
};

inline Vector2 operator + (const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Vector2 operator - (const Vector2& lhs, const Vector2& rhs) {
	return Vector2(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Vector2 operator * (const Vector2& lhs, const float& rhs) {
	return Vector2(lhs.x * rhs, lhs.y * rhs);
}

/**
 * @brief		Rotates the given vector by the given angle around the origin
 *				(Does not change the original vector)
 */
inline Vector2 RotateVector(Vector2& vec, float angle) {
	// Converting the angle to radians to be used in sin and cos functions
	float radAngle = (float)(angle * DEG_TO_RAD);

	return Vector2((float)(vec.x * cos(radAngle) - vec.y * sin(radAngle)), (float)(vec.x * sin(radAngle) + vec.y * cos(radAngle)));
}

const Vector2 VEC2_ZERO = { 0.0f, 0.0f };
const Vector2 VEC2_ONE = { 1.0f, 1.0f };
const Vector2 VEC2_UP = { 0.0f, 1.0f };
const Vector2 VEC2_RIGHT = { 1.0f, 0.0f };
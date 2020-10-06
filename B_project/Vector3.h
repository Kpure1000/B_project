#pragma once
#include<cmath>
namespace bf
{

	template <typename T>
	class Vector3
	{
	public:
		Vector3() :x(0), y(0), z(0) {}

		Vector3(T const& X, T const& Y, T const& Z) :x(X), y(Y), z(Z) {}
		/****************/
		template <typename T>
		Vector3<T> operator+(Vector3<T> const& right)
		{
			return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
		}

		template <typename T>
		Vector3<T> operator-(Vector3<T> const& right)
		{
			return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
		}

		template <typename T>
		Vector3<T> operator*(T right)
		{
			return Vector3<T>(this->x *= right, this->y * right, this->z * right);
		}
		/****************/
		template <typename T>
		void operator+=(Vector3<T> const& right)
		{
			this->x += right.x, this->y += right.y, this->z += right.z;
		}

		template <typename T>
		void operator-=(Vector3<T> const& right)
		{
			this->x -= right.x, this->y -= right.y, this->z -= right.z;
		}

		template <typename T>
		void operator*=(T right)
		{
			this->x *= right, this->y *= right, this->z *= right;
		}
		/****************/
		template <typename T>
		T Magnitude()
		{
			return sqrt((this->x * this->x + this->y * this->y + this->z * this->z));
		}

		template <typename T>
		Vector3<T> Normalize()
		{
			T Len = this->Magnitude();
			if (abs(Len) > 1e-6)
			{
				this->x /= Len;
				this->y /= Len;
				this->z /= Len;
			}
			return *this;
		}

		template <typename T>
		static T Dot(Vector3<T> left, Vector3<T> right)
		{
			return left.x * right.x + left.y * right.y + left.z * right.z;
		}

		template <typename T>
		static Vector3 Cross(Vector3<T>left, Vector3<T> right)
		{
			Vector3 vCross;
			vCross.x = ((left.y * right.z) - (left.z * right.y));
			vCross.y = ((left.z * right.x) - (left.x * right.z));
			vCross.z = ((left.x * right.y) - (left.y * right.x));
			return vCross;
		}

		T x, y, z;
	};

	template <typename T>
	Vector3<T> operator*(T left, Vector3<T> const& right)
	{
		return Vector3<T>(right.x *= left, right.y * left, right.z * left);
	}

	typedef Vector3<float> Vector3f;
	typedef Vector3<int> Vector3i;
	typedef Vector3<double> Vector3d;

}
#pragma once
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include"Vector3.h"
#include"Color.h"
namespace bf
{
	class Vertex
	{
	public:

		Vertex() :position(), texCoords(), color() {}

		Vertex(Vector3f vPosition) :position(vPosition), texCoords(), color() {}

		Vertex(Vector3f vPosition, Color vColor) :position(vPosition), texCoords(), color(vColor) {}

		Vertex(Vector3f Position, Vector3f vTexCoords) :position(Position), texCoords(vTexCoords), color() {}

		Vertex(Vector3f Position, Color vColor, Vector3f vTexCoords) :position(Position), texCoords(vTexCoords), color(vColor) {}

		/*  */

		Vector3f position;

		Vector3f texCoords;

		Color color;
	};
}


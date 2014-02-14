#include "stdafx.h"
#include "CppUnitTest.h"

#include "Vector.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace mathematical;

namespace UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(VectorAddition)
		{
			vec2f v1 = vec2f(1.0f, 2.0f);
			vec2f v2 = vec2f(-1.0f, -2.0f);
			vec2f v3 = v1 + v2;
			Assert::IsTrue(v3.x == 0.0f && v3.y == 0.0f);

			vec3f v4 = vec3f(1.0f, 2.0f, 3.0f);
			vec3f v5 = vec3f(-1.0f, -2.0f, -3.0f);
			vec3f v6 = v4 + v5;
			Assert::IsTrue(v6.x == 0.0f && v6.y == 0.0f && v6.z == 0.0f);

			vec4f v7 = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
			vec4f v8 = vec4f(-1.0f, -2.0f, -3.0f, -4.0f);
			vec4f v9 = v7 + v8;
			Assert::IsTrue(v9.x == 0.0f && v9.y == 0.0f && v9.z == 0.0f && v9.w == 0.0f);
		}



	};
}
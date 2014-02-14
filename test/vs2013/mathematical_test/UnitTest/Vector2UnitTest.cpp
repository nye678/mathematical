#include "stdafx.h"
#include "CppUnitTest.h"

using namespace mathematical;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Vector2UnitTest)
	{
	public:
		
		TEST_METHOD(Vector2_Addition)
		{
			vec2f v1 = vec2f(1.0f, 2.0f);
			vec2f v2 = vec2f(-1.0f, -2.0f);
			vec2f v3 = v1 + v2;
			Assert::IsTrue(v3.x == 0.0f && v3.y == 0.0f);
		}

		TEST_METHOD(Vector2_DotProduct)
		{
			vec2f v1 = vec2f(1.0f, 2.0f);
			vec2f v2 = vec2f(3.0f, 4.0f);
			float dot = v1.dot(v2);
			Assert::AreEqual<float>(dot, 11.0f);
		}

		TEST_METHOD(Vector2_Length)
		{
			vec2f v1 = vec2f(3.0f, 4.0f);
			float length = v1.length();
			float lengthsqrd = v1.lengthsqrd();
			Assert::AreEqual<float>(length, 5.0f);
			Assert::AreEqual<float>(lengthsqrd, 25.0f);
		}

		TEST_METHOD(Vector2_Normalize)
		{
			vec2f v1 = vec2f(3.0f, 4.0f);
			v1.normalize();

			Assert::IsTrue(v1.x == 0.6f && v1.y == 0.8f);
			Assert::AreEqual<float>(v1.length(), 1.0f);
		}

		TEST_METHOD(Vector2_Swizzle)
		{
			vec4f v1 = vec4f(3.0f, 4.0f, 5.0f, 6.0f);
			vec2f v2 = Swizzlef::yw(v1);

			Assert::IsTrue(v2.x == 4.0f && v2.y == 6.0f);
		}

	};
}
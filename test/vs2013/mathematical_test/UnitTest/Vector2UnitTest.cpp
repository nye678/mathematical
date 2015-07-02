#include "stdafx.h"
#include "CppUnitTest.h"

using namespace mathematical;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Vector2UnitTest)
	{
	public:
		
		TEST_METHOD(Vector2_Creation)
		{
			vec2f v1 = { 0 };
			Assert::AreEqual(0.0f, v1.x);
			Assert::AreEqual(0.0f, v1.y);

			vec2f v2 = { 1.0f, 2.0f };
			Assert::AreEqual(1.0f, v2.x);
			Assert::AreEqual(2.0f, v2.y);

			vec2f v3(0.0f);
			Assert::AreEqual(0.0f, v3.x);
			Assert::AreEqual(0.0f, v3.y);

			vec2f v4(1.0f, 2.0f);
			Assert::AreEqual(1.0f, v4.x);
			Assert::AreEqual(2.0f, v4.y);

			vec2f v5 = vec2f(1.0f, 2.0f);
			Assert::AreEqual(1.0f, v5.x);
			Assert::AreEqual(2.0f, v5.y);

			vec2f t = vec2f(1.0f, 2.0f);
			vec2f v6(t);
			Assert::AreEqual(1.0f, v6.x);
			Assert::AreEqual(2.0f, v6.y);

			vec2f v6b = t;
			Assert::AreEqual(1.0f, v6b.x);
			Assert::AreEqual(2.0f, v6b.y);

			vec2f v7(vec3f(1.0f, 2.0f, 3.0f));
			Assert::AreEqual(1.0f, v7.x);
			Assert::AreEqual(2.0f, v7.y);

			vec2f v8(vec4f(1.0f, 2.0f, 3.0f, 4.0f));
			Assert::AreEqual(1.0f, v8.x);
			Assert::AreEqual(2.0f, v8.y);

			vec3f t2 = vec3f(1.0f, 2.0f, 3.0f);
			vec2f v9 = t2;
			Assert::AreEqual(1.0f, v9.x);
			Assert::AreEqual(2.0f, v9.y);

			vec4f t3 = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
			vec2f v10 = t3;
			Assert::AreEqual(1.0f, v10.x);
			Assert::AreEqual(2.0f, v10.y);
		}

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
			
			Assert::AreEqual(0.6f, v1.x);
			Assert::AreEqual(0.8f, v1.y);
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
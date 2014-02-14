#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Vector3UnitTest)
	{
	public:
		
		TEST_METHOD(Vector3_Addition)
		{
			vec3f v1 = vec3f(1.0f, 2.0f, 3.0f);
			vec3f v2 = vec3f(-1.0f, -2.0f, -3.0f);
			vec3f v3 = v1 + v2;
			Assert::IsTrue(v3.x == 0.0f && v3.y == 0.0f && v3.z == 0.0f);
		}

		TEST_METHOD(Vector3_DotProduct)
		{
			vec3f v1 = vec3f(1.0f, 2.0f, 3.0f);
			vec3f v2 = vec3f(4.0f, 5.0f, 6.0f);
			float dot = v1.dot(v2);
			float answer = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
			Assert::AreEqual<float>(dot, answer);
		}

		TEST_METHOD(Vector3_Length)
		{
			vec3f v1 = vec3f(3.0f, 4.0f, 5.0f);
			float length = v1.length();
			float lengthsqrd = v1.lengthsqrd();
			float answer = v1.x *  v1.x + v1.y * v1.y + v1.z * v1.z;
			Assert::AreEqual<float>(length, sqrtf(answer));
			Assert::AreEqual<float>(lengthsqrd, answer);
		}

		TEST_METHOD(Vector3_Normalize)
		{
			vec3f v1 = vec3f(3.0f, 4.0f, 5.0f);
			v1.normalize();

			float length = sqrt(50.0f);
			float answer[3] = { 3.0f / length, 4.0f / length, 5.0f / length };

			Assert::IsTrue(v1.x == answer[0] && v1.y == answer[1] && v1.z == answer[2]);
			Assert::AreEqual<float>(v1.length(), 1.0f);
		}

	};
}
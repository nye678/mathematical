#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Vector4UnitTest)
	{
	public:
		
		TEST_METHOD(Vector4_Addition)
		{
			vec4f v1 = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
			vec4f v2 = vec4f(-1.0f, -2.0f, -3.0f, -4.0f);
			vec4f v3 = v1 + v2;
			Assert::IsTrue(v3.x == 0.0f && v3.y == 0.0f && v3.z == 0.0f && v3.w == 0.0f);
		}

		TEST_METHOD(Vector4_DotProduct)
		{
			vec4f v1 = vec4f(1.0f, 2.0f, 3.0f, 4.0f);
			vec4f v2 = vec4f(5.0f, 6.0f, 7.0f, 8.0f);
			float dot = v1.dot(v2);
			float answer = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
			Assert::AreEqual<float>(dot, answer);
		}

		TEST_METHOD(Vector4_Length)
		{
			vec4f v1 = vec4f(3.0f, 4.0f, 5.0f, 6.0f);
			float length = v1.length();
			float lengthsqrd = v1.lengthsqrd();
			float answer = v1.x *  v1.x + v1.y * v1.y + v1.z * v1.z + v1.w * v1.w;
			Assert::AreEqual<float>(length, sqrtf(answer));
			Assert::AreEqual<float>(lengthsqrd, answer);
		}

		TEST_METHOD(Vector4f_Normalize)
		{
			vec4f v1 = vec4f(3.0f, 4.0f, 5.0f, 6.0f);
			v1.normalize();

			float length = sqrt(86.0f);
			float answer[4] = { 3.0f / length, 4.0f / length, 5.0f / length, 6.0f / length };
			float vlen = v1.lengthsqrd();

			Assert::IsTrue(v1.x == answer[0] && v1.y == answer[1] && v1.z == answer[2] && v1.w == answer[3]);
			Assert::AreEqual<float>(v1.length(), 1.0f);
		}

		TEST_METHOD(Vector4d_Normalize)
		{
			vec4d v1 = vec4d(3.0, 4.0, 5.0, 6.0);
			v1.normalize();

			double length = sqrt(86.0);
			double answer[4] = { 3.0 / length, 4.0 / length, 5.0 / length, 6.0 / length };
			double vlen = v1.lengthsqrd();

			Assert::IsTrue(v1.x == answer[0] && v1.y == answer[1] && v1.z == answer[2] && v1.w == answer[3]);
			Assert::AreEqual<double>(v1.length(), 1.0);
		}

	};
}
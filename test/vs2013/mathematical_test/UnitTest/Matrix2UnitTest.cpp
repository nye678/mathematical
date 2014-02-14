#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Microsoft { namespace VisualStudio { namespace CppUnitTestFramework {
	template <> static std::wstring ToString<mat2f>(const mat2f & t) { std::wstringstream _s; _s << t[0] << t[1] << t[2] << t[3]; return _s.str(); }
}}}

namespace UnitTest
{
	TEST_CLASS(Matrix2UnitTest)
	{
	public:
		TEST_METHOD(Matrix2_Instantiation)
		{
			mat2f m1;
			m1[0] = 1.0f;
			m1[3] = 1.0f;

			mat2f m2 = mat2f(1.0f);
			mat2f m3 = { 1.0f, 0.0f,
						 0.0f, 1.0f };
			mat2f m4 = m3;

			Assert::IsTrue(m1[0] == 1.0f &&	m1[1] == 0.0f && m1[2] == 0.0f && m1[3] == 1.0f);
			Assert::AreEqual<mat2f>(m1, m2);
			Assert::AreEqual<mat2f>(m1, m3);
			Assert::AreEqual<mat2f>(m1, m4);
		}

		TEST_METHOD(Matrix2_Addition)
		{
			mat2f m1 = mat2f::identity();
			mat2f m2 = mat2f::identity();
			mat2f m3 = m1 + m2;

			Assert::IsTrue(m3[0] == 2.0f &&	m3[1] == 0.0f && m3[2] == 0.0f && m3[3] == 2.0f);
		}

		TEST_METHOD(Matrix2_Multiplication)
		{
			mat2f m1 = mat2f::identity();
			mat2f m2 = mat2f(2.0f);
			mat2f m3 = m1 * m2;

			Assert::IsTrue(m3[0] == 2.0f &&	m3[1] == 0.0f && m3[2] == 0.0f && m3[3] == 2.0f);
		}
	};
}
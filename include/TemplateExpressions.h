#ifndef __MATHEMATICAL_TEMPLATEEXPRESSIONS_H_
#define __MATHEMATICAL_TEMPLATEEXPRESSIONS_H_

namespace mathematical {
	namespace temps {
		// Arithmetic Operators 
		// Used by the Meta Expressions so operators can be passed as arguments.
		template <typename T>
		struct ArithmeticOps {
			static inline T opPlus(T a, T b) { return a + b; }
			static inline T opMinus(T a, T b) { return a - b; }
			static inline T opMulti(T a, T b) { return a * b; }
			static inline T opDivide(T a, T b) { return a / b; }
		};

		// Boolean Operators
		// Same thing as arithmetic only boolean.
		template <typename T>
		struct BooleanOps {
			static inline bool opEquals(T a, T b) { return a == b; }
		};

		// Meta Expressions
		// The meta expressions generate code during compilation to implement all the
		// vector operations. Meta expressions use inlining and template recusion to
		// generate the exact operations and avoid loops.
		// S = some class with operator[] defined, T = the type of the data.
		template <typename S, typename T>
		struct MetaExp {

			typedef T(*ArithOp)(T, T);
			typedef bool(*BoolOp)(T, T);

			// Meta Execute Vector Expression
			// Performs the given operation on all elements in the vectors, storing the
			// results in the first vector argument.
			template <int I>
			static inline void execute(S &lhs, const S &rhs, ArithOp op) {
				lhs[I] = op(lhs[I], rhs[I]);
				return execute<I - 1>(lhs, rhs, op);
			}

			template <>
			static inline void execute<0>(S &lhs, const S &rhs, ArithOp op) {
				lhs[0] = op(lhs[0], rhs[0]);
			}

			// Meta Execute Scalar Expression
			// Same as the vector version except the second argument is a scalar and is
			// applied to all elements of the first vector using the given operation.
			template <int I>
			static inline void execute(S &lhs, T rhs, ArithOp op) {
				lhs[I] = op(lhs[I], rhs);
				return execute<I - 1>(lhs, rhs, op);
			}

			template <>
			static inline void execute<0>(S &lhs, T rhs, ArithOp op) {
				lhs[0] = op(lhs[0], rhs);
			}

			// Meta Test Express
			// Performs some boolean operation on the two vectors, comparing element to element.
			template <int I>
			static inline bool test(const S &lhs, const S &rhs, BoolOp op) {
				return op(lhs[I], rhs[I]) && test<I - 1>(lhs, rhs, op);
			}

			template <>
			static inline bool test<0>(const S &lhs, const S &rhs, BoolOp op) {
				return op(lhs[0], rhs[0]);
			}

			// Meta Sum Expression
			// Requires two operations. The 'op' operation is performed on each element, and then
			// those elements are totaled using the sumOp operation. Used for dot products mostly.
			template <int I>
			static inline T sum(S &lhs, const S &rhs, ArithOp sumOp, ArithOp op) {
				return sumOp(op(lhs[I], rhs[I]), sum<I - 1>(lhs, rhs, sumOp, op));
			}

			template <>
			static inline T sum<0>(S &lhs, const S &rhs, ArithOp sumOp, ArithOp op) {
				return op(lhs[0], rhs[0]);
			}
		};

		template <typename S, typename T, size_t N>
		struct MatrixMeta {
			// Meta Dot
			// Performs a dot product calculation on the row of the left matrix and the column
			// of the right matrix. Used for matrix multiplication.
			template <size_t I>
			static inline T matrixDot(S &lhs, const S &rhs, size_t row, size_t col)
			{
				return lhs[row + I * N] * rhs[col + I] + matrixDot<I - 1>(lhs, rhs, row, col);
			}

			template <>
			static inline T matrixDot<0>(S &lhs, const S &rhs, size_t row, size_t col)
			{
				return lhs[row] * rhs[col];
			}

			// Meta Multiply
			// Used to multiply two matricies together. It recusively generates code
			// to perform dot products on each cell and then stuffs them all in the
			// left matrix.
			template <int I>
			static inline void matrixMulti(S &lhs, const S &rhs) {
				size_t row = I % N;
				size_t col = (I / N) * N;
				T dot = matrixDot<N - 1>(lhs, rhs, row, col);
				matrixMulti<I - 1>(lhs, rhs);
				lhs[I] = dot;
			}

			template <>
			static inline void matrixMulti<0>(S &lhs, const S &rhs) {
				lhs[0] = matrixDot<N - 1>(lhs, rhs, 0, 0);
			}

			// Meta Diagonal
			// Sets all the diagonal cells in the matrix to the given value.
			template <int I>
			static inline void diagonal(S &matrix, T value)
			{
				matrix[I*(N + 1)] = value;
				return diagonal<I - 1>(matrix, value);
			}

			template <>
			static inline void diagonal<0>(S &matrix, T value)
			{
				matrix[0] = value;
			}
		};
	}
}

#endif
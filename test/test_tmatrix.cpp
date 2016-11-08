#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
	ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
	ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
	ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
	TMatrix<int> m(5);

	ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	EXPECT_EQ(m1, m2);

}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(m1);
	m2[3][3] = 2;
	EXPECT_NE(m1[3][3], m2[3][3]);
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m(5);
	EXPECT_EQ(5, m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m(5);
	m[1][3] = 4;
	EXPECT_EQ(4, m[1][3]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[-1][2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m(4);
	ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE + 1][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> m1(3);
	TMatrix<int> m2=m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	int size = 3;
	TMatrix<int> m1(size);
	TMatrix<int> m2(size);
	m1 = m2;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	const int size1 = 2, size2 = 5;
	TMatrix<int> m1(size1), m2(size2);
	m2 = m1;
	EXPECT_EQ(2, (m2[0]).GetSize());
}
TEST(TMatrix, can_assign_matrices_of_different_size)
{
	const int size1 = 2, size2 = 5;
	TMatrix<int> m1(size1), m2(size2);
	m2 = m1;
	EXPECT_EQ(m1, m2);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	const int size1 = 2;
	TMatrix<int> m1(size1), m2(m1);
	EXPECT_TRUE(m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(4);
	EXPECT_TRUE(m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	const int size1 = 2, size2 = 5;
	TMatrix<int> m1(size1), m2(size2);
	EXPECT_TRUE(m1 != m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(4), m2(4);
	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++)
		{
			m1[i][j] = i ;
			m2[i][j] = j;
		}
	TMatrix<int> m3(m1);
	for (int i = 0; i < 4; i++)
		
		m3[i] =m1[i] +  m2[i];
	EXPECT_EQ((m1 + m2), m3);
	ASSERT_NO_THROW(m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(4), m2(6);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(4), m2(4);
	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++)
		{
			m1[i][j] = i;
			m2[i][j] = j;
		}
	TMatrix<int> m3(m1);
	for (int i = 0; i < 4; i++)

		m3[i] = m1[i] - m2[i];
	EXPECT_EQ((m1 - m2), m3);
	ASSERT_NO_THROW(m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(4), m2(6);
	ASSERT_ANY_THROW(m1 - m2);
}


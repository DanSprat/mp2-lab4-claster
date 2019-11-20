#include "pch.h"
#include "../mp2-lab4-claster/queue.h"
TEST(TPQueue, can_create_queue) {
	ASSERT_NO_THROW(TPQueue <int> a);
}
TEST(TPQueue, can_is_empty) {
	TPQueue <int> a;
	EXPECT_EQ(1, a.IsEmpty());
}
TEST(TPQueue, throw_when_pop_from_empty_queue) {
	TPQueue <int> a;
	ASSERT_ANY_THROW(a.pop());
}
TEST(TPQueue, throw_when_front_from_empty_queue) {
	TPQueue <int> a;
	ASSERT_ANY_THROW(a.front());
}
TEST(TPQueue, can_push_in_empty_queue) {
	TPQueue <int> a;
	a.push(1, 1);
	EXPECT_EQ(1, a.front());
}
TEST(TPQueue, can_get_elem_with_biggest_priority) {
	TPQueue <int> a;
	a.push(1, 1);
	a.push(2, 2);
	EXPECT_EQ(2, a.front());
}
TEST(TPQueue, can_get_lenght)
{
	TPQueue <int> a;
	a.push(5, 1);
	EXPECT_EQ(1, a.lenght());
}
TEST(TPQueue, can_pop_from_not_empty_queue)
{
	TPQueue <int> a;
	a.push(5, 1);
	a.pop();
	EXPECT_EQ(0, a.lenght());
}
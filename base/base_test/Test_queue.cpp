#include <gtest.h>
#include "queue.h"
TEST(queue, can_create_queue) {
	ASSERT_NO_THROW(queue <int> a);
}
TEST(queue, can_is_empty)
{
	queue <int> a;
	EXPECT_EQ(1, a.IsEmpty());
}
TEST(queue, throw_when_pop_from_empty_queue)
{
	queue <int> a;
	ASSERT_ANY_THROW(a.pop());
}
TEST(queue, throw_when_front_from_empty_queue)
{
	queue <int> a;
	ASSERT_ANY_THROW(a.front());
}
TEST(queue, can_push_in_empty_queue)
{
	queue <int> a;
	a.push(5);
	EXPECT_EQ(5, a.front());
}
TEST(queue, can_get_lenght)
{
	queue <int> a;
	a.push(5);
	EXPECT_EQ(1, a.lenght());
}
TEST(queue, can_pop_from_not_empty_queue)
{
	queue <int> a;
	a.push(5);
	a.pop();
	EXPECT_EQ(0, a.lenght());
}
TEST(queue, can_push_in_not_empty_queue)
{
	queue <int> a;
	a.push(5);
	a.push(4);
	a.pop();
	EXPECT_EQ(4, a.front());
}
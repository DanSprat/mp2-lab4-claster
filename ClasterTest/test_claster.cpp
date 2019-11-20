#include "pch.h"
#include "../mp2-lab4-claster/Cluster.h"
#include "../mp2-lab4-claster/Cluster.cpp"
TEST(cluster, can_create_cluster_with_valid_metrics)
{
	ASSERT_NO_THROW(Cluster a(4, 10, 0.5, 1));
}
TEST(cluster, throw_when_create_cluster_with_negative_time)
{
	ASSERT_ANY_THROW(Cluster a(10, -10, 0.5));
}
TEST(cluster, throw_when_create_cluster_with_invalid_num_of_processors)
{
	ASSERT_ANY_THROW(Cluster a(-5, 10, 0.5));
}
TEST(cluster, throw_when_create_cluster_with_invalid_value_of_chance)
{
	ASSERT_ANY_THROW(Cluster a(10, 10, 1.1));
}

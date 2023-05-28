#include "gtest/gtest.h"
#include "marsvin_instance_counter.hpp"

class MyTestClass {};

TEST(InstanceCounter, Test_Zero_Instances) {
    EXPECT_EQ(0, marsvin::InstanceCounter<int>::counter());
}

TEST(InstanceCounter, Test_multiple_instances) {
    marsvin::InstanceCounter<MyTestClass> instance_one;
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
    marsvin::InstanceCounter<MyTestClass> instance_two;
    EXPECT_EQ(2, marsvin::InstanceCounter<MyTestClass>::counter());
    EXPECT_EQ(1, instance_one.id());
    EXPECT_EQ(2, instance_two.id());
}

TEST(InstanceCounter, Test_copy_instances) {
    marsvin::InstanceCounter<MyTestClass> instance_one;
    EXPECT_EQ(1, instance_one.id());
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
    marsvin::InstanceCounter<MyTestClass> instance_two;
    EXPECT_EQ(2, marsvin::InstanceCounter<MyTestClass>::counter());
    EXPECT_EQ(2, instance_two.id());
    marsvin::InstanceCounter<MyTestClass> instance_three = instance_one;
    EXPECT_EQ(3, instance_three.id());

}

TEST(InstanceCounter, Test_move_instances) {
    marsvin::InstanceCounter<MyTestClass> instance_one;
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
    marsvin::InstanceCounter<MyTestClass> instance_two = std::move(instance_one);
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
    EXPECT_EQ(1, instance_one.id());
    EXPECT_EQ(1, instance_two.id());
}

TEST(InstanceCounter, Test_destructor) {
    marsvin::InstanceCounter<MyTestClass> instance_one;
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
    {
        marsvin::InstanceCounter<MyTestClass> instance_two;
        EXPECT_EQ(2, marsvin::InstanceCounter<MyTestClass>::counter());
    }
    EXPECT_EQ(1, marsvin::InstanceCounter<MyTestClass>::counter());
}


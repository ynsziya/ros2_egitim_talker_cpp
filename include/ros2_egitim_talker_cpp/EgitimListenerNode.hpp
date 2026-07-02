#ifndef ROS2_EGITIM_TALKER_CPP__EGITIMLISTENERNODE_HPP_
#define ROS2_EGITIM_TALKER_CPP__EGITIMLISTENERNODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace ros2_egitim_talker_cpp 
{
    class EgitimListenerNode : public rclcpp::Node 
    {
        public:
            EgitimListenerNode();

        private:
            void subscription_callback(const std_msgs::msg::String::SharedPtr msg);

            rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    };
}

#endif


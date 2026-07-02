#include "ros2_egitim_talker_cpp/EgitimListenerNode.hpp"

namespace ros2_egitim_talker_cpp 
{
    using std::placeholders::_1;

    EgitimListenerNode::EgitimListenerNode() : Node("egitim_listener")
    {
        subscription_ = create_subscription<std_msgs::msg::String>(
            "chatter", 10,
            std::bind(&EgitimListenerNode::subscription_callback, this, _1)
        );
    }

    void EgitimListenerNode::subscription_callback(const std_msgs::msg::String::SharedPtr msg)
    {
        RCLCPP_INFO(get_logger(), "AlIndI: '%s'", msg->data.c_str());
    }
}
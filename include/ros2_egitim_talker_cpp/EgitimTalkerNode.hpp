#ifndef ROS2_EGITIM_TALKER_CPP__EGITIMTALKERNODE_HPP_
#define ROS2_EGITIM_TALKER_CPP__EGITIMTALKERNODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace ros2_egitim_talker_cpp 
{
    class EgitimTalkerNode : public rclcpp::Node
    {
        public:
            EgitimTalkerNode();

        private:
            void timer_callback();

            rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
            rclcpp::TimerBase::SharedPtr timer_;

            int count_{0};
    };
    
} // namespace ros2_egitim_talker_cpp

#endif
#include "ros2_egitim_talker_cpp/EgitimTalkerNode.hpp"

namespace ros2_egitim_talker_cpp 
{
    using namespace std::chrono_literals;

    EgitimTalkerNode::EgitimTalkerNode() : Node("egitim_talker") 
    {
        // Varsayılan 1.0 saniye - launch tan override edilebiir
        declare_parameter<double>("publish_period", 1.0);
        double period = get_parameter("publish_period").as_double();

        publisher_ = create_publisher<std_msgs::msg::String>("chatter", 10);

        auto period_ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration<double>(period));

        timer_ = create_wall_timer(
            period_ms, std::bind(&EgitimTalkerNode::timer_callback, this)
        );

        RCLCPP_INFO(get_logger(), "Mesaj periyodu: %.1f sn", period);
    }

    void EgitimTalkerNode::timer_callback()
    {
        auto msg = std_msgs::msg::String();
        msg.data = "Merhaba ROS2! Mesaj #" + std::to_string(count_++);
        publisher_->publish(msg);
        RCLCPP_INFO(get_logger(), "Yayınlandı: '%s'", msg.data.c_str());
    }
}


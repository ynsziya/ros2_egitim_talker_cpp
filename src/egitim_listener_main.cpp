#include <memory>

#include "ros2_egitim_talker_cpp/EgitimListenerNode.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<ros2_egitim_talker_cpp::EgitimListenerNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
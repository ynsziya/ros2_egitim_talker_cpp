from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node

def generate_launch_description():

    listener_cmd = Node(
        package = 'ros2_egitim_talker_cpp',
        executable = 'egitim_listener',
        output = 'screen',
        remappings = [
            ('chatter', '/egitim/chatter'),  # kaynak - hedef
        ],
    )

    period_arg = DeclareLaunchArgument(
        'publish_period',
        default_value = '1.0',
        description = 'Mesaj yayın periyodu (saniye)',

    )


    talker_cmd = Node(
        package = 'ros2_egitim_talker_cpp',
        executable = 'egitim_talker',
        output = 'screen',
        remappings = [
            ('chatter', '/egitim/chatter')
        ],
        parameters = [{
            'publish_period' : LaunchConfiguration('publish_period'),
        }],
    )

    ld = LaunchDescription()
    ld.add_action(period_arg)
    ld.add_action(listener_cmd) # önce listener - dinleyici hazIr olsun
    ld.add_action(talker_cmd)

    return ld
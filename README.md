# ros2_egitim_talker_cpp

A simple ROS 2 C++ talker/listener example package for learning publisher–subscriber communication with `rclcpp` and `std_msgs`.

**ROS 2 Distro:** [Jazzy Jalisco](https://docs.ros.org/en/jazzy/)

## Overview

| Node | Executable | Role |
|------|------------|------|
| `egitim_talker` | `egitim_talker` | Publishes `std_msgs/msg/String` messages on a timer |
| `egitim_listener` | `egitim_listener` | Subscribes and logs received messages |

Both nodes use **reliable** QoS with a history depth of 10.

### Topic

| Default topic | Remapped (launch) | Type |
|---------------|-------------------|------|
| `chatter` | `/egitim/chatter` | `std_msgs/msg/String` |

### Parameters

| Parameter | Node | Default | Description |
|-----------|------|---------|-------------|
| `publish_period` | `egitim_talker` | `1.0` | Publish interval in seconds |

## Dependencies

- `rclcpp`
- `std_msgs`
- `launch` / `launch_ros` (for the launch file)

## Build

Clone or copy this package into a ROS 2 workspace `src` folder, then:

```bash
source /opt/ros/jazzy/setup.bash
cd ~/your_ws
colcon build --packages-select ros2_egitim_talker_cpp
source install/setup.bash
```

## Run

### Launch both nodes

```bash
ros2 launch ros2_egitim_talker_cpp talker_listener.launch.py
```

Custom publish period (seconds):

```bash
ros2 launch ros2_egitim_talker_cpp talker_listener.launch.py publish_period:=0.5
```

### Run nodes separately

Terminal 1 — listener:

```bash
ros2 run ros2_egitim_talker_cpp egitim_listener
```

Terminal 2 — talker:

```bash
ros2 run ros2_egitim_talker_cpp egitim_talker
```

With a custom period:

```bash
ros2 run ros2_egitim_talker_cpp egitim_talker --ros-args -p publish_period:=0.5
```

## Package layout

```
ros2_egitim_talker_cpp/
├── include/ros2_egitim_talker_cpp/
│   ├── EgitimTalkerNode.hpp
│   └── EgitimListenerNode.hpp
├── src/
│   ├── egitim_talker_main.cpp
│   ├── egitim_listener_main.cpp
│   └── ros2_egitim_talker_cpp/
│       ├── EgitimTalkerNode.cpp
│       └── EgitimListenerNode.cpp
├── launch/
│   └── talker_listener.launch.py
├── CMakeLists.txt
└── package.xml
```

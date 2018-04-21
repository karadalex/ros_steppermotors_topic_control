ROS & Arduino - Control Stepper motors
======================================

## Instructions

1. Enter the ROS environment `source /opt/ros/<distro>/setup.bash`
2. Start ROS master `roscore`
3. Upload .ino file to arduino (Make sure you have installed rosserial_arduino) and run it.
4. In a new terminal run `rosrun rosserial_python serial_node.py /dev/ttyACM0` . Make sure to specify the correct port (same port you used in the Arduino IDE to upload the code)
5. In a new terminal interact with your Arduino program through ROS topics.<br>
e.g.
`rostopic pub motor1/start std_msgs/Empty --once` will execute once the following method
```c++
void startMotor1(const std_msgs::Empty& toggle_msg)
```
ROS & Arduino - Control Stepper motors
======================================

## Requirements

- Arduino IDE with [rosserial_arduino](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup) installed (and Teensy plugin 
if you use the Teensy board)
- Arduino board (I used a Teensy 3.5)
- 3 stepper motors (I used NEMA 17)
- 3 motor drivers (I used A4988 but you can also use DRV8825 by making the appropriate changes in code)
- 3 electrolytic capacitors (at least 47μF)
- Some LED's (I used one RGB LED)
- Power Supply (I used a 12V 8.5A)

## Instructions

1. Enter the ROS environment `source /opt/ros/<distro>/setup.bash`
2. Start ROS master `roscore`
3. Upload .ino file to arduino (Make sure you have installed rosserial_arduino) and run it.
4. In a new terminal run `rosrun rosserial_python serial_node.py /dev/ttyACM0` . Make sure to specify the correct port (same port you used in the Arduino IDE to upload the code)
5. In a new terminal interact with your Arduino program through ROS topics.<br>
e.g.
`rostopic pub motor2/start std_msgs/Empty --once` will execute once the following method
```c++
void startMotor2(const std_msgs::Empty& toggle_msg)
``` 
whereas `rostopic pub motor1/start std_msgs/Int8 15 --once` will execute once the following method
```c++
void startMotor1(const std_msgs::Int8& rpm)
``` 
by passing as an argument an rpm of 15

6. You can see all available topics by running in a terminal `rostopic list`
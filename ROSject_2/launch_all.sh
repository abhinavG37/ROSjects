sudo killall rosmaster
sudo killall gzserver
sudo killall gzclient
roslaunch mybot_gazebo mybot_world.launch
roslaunch mybot_control mybot_control.launch

## from rclpy import client
import os
from launch import LaunchDescription
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import ThisLaunchFileDir,LaunchConfiguration
from launch_ros.actions import Node
from launch.actions import ExecuteProcess
from ament_index_python.packages import get_package_share_directory

controller_config = os.path.join(get_package_share_directory('ifv_simu'),'config','controller.yaml')
def generate_launch_description():
    print(controller_config)
    use_sim_time = LaunchConfiguration('use_sim_time', default='True')
    world_file_name = 'ifv_mesh.world'
    pkg_dir = get_package_share_directory('ifv_simu')
 
    #os.environ["GAZEBO_MODEL_PATH"] = os.path.join(pkg_dir, 'model')
 
    world = os.path.join(pkg_dir, 'world/gazebo11', world_file_name)
    launch_file_dir = os.path.join(pkg_dir, 'launch')
 
    gazebo = ExecuteProcess(
            cmd=['gazebo', '--verbose', world,'-u','-s', 'libgazebo_ros_init.so', 
            '-s', 'libgazebo_ros_factory.so'],
            output='screen')
    
    #GAZEBO_MODEL_PATH has to be correctly set for Gazebo to be able to find the model
    #spawn_entity = Node(package='gazebo_ros', node_executable='spawn_entity.py',
    #                    arguments=['-entity', 'demo', 'x', 'y', 'z'],
    #                    output='screen')
    spawn_entity = Node(package='ifv_simu',
                        name='main_node', 
                        executable='ifv_listener',
                        output='screen',
                        parameters = [controller_config]
                        )
 
    return LaunchDescription([
        gazebo,
        spawn_entity,

    ])

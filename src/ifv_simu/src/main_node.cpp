#include "main_node.hpp"

MainNode::MainNode(): Node("main_node")
{
   // RCLCPP_INFO(this->get_logger(),"pdgain, %f",pdgain[0]);
   this->declare_parameter("pdgain",rclcpp::PARAMETER_DOUBLE_ARRAY);
   // RCLCPP_INFO(this->get_logger(),"pdgain, %f",pdgain[0]);
   pdgain = this->get_parameter("pdgain").as_double_array();

   // this->declare_parameter("camera_height_list",rclcpp::PARAMETER_DOUBLE_ARRAY);
   // camera_height=this->get_parameter("camera_height_list").as_double_array();
   

}

MainNode::~MainNode()
{
}

void MainNode::init()
{
   subscription1_ = this->create_subscription<sensor_msgs::msg::JointState>(
      "IFV/my_joint_states", 100, std::bind(&MainNode::jointstate_callback, this, _1));
   subscription2_ = this->create_subscription<sensor_msgs::msg::Imu>(
      "IFV/imu_topic/data", 100, std::bind(&MainNode::imu_callback, this, _1));
   publisher_ = this->create_publisher<ifv_interfaces::msg::Torque12dof>("IFV/applied_torque", rclcpp::SystemDefaultsQoS());
   timer_ = this->create_wall_timer(10ms, std::bind(&MainNode::timer_callback, this));
   controller_ptr = std::make_shared<PDController>(pdgain);
}

void MainNode::jointstate_callback(const sensor_msgs::msg::JointState & msg)
{
   controller_ptr->get_jointstate(msg);
   start_pub=1;
}

void MainNode::imu_callback(const sensor_msgs::msg::Imu & msg)
{
   controller_ptr->get_imu(msg); 
}

void MainNode::timer_callback()
{
   controller_ptr->compute_torque();
   RCLCPP_INFO(this->get_logger(),"start_pub %d",start_pub);
   if (start_pub == 1){
      auto message = ifv_interfaces::msg::Torque12dof();
      message.lf1 = controller_ptr->applied_torque[0];
      message.lf2 = controller_ptr->applied_torque[1];
      message.lf3 = controller_ptr->applied_torque[2];
      message.rf1 = controller_ptr->applied_torque[3];
      message.rf2 = controller_ptr->applied_torque[4];
      message.rf3 = controller_ptr->applied_torque[5];
      message.lh1 = controller_ptr->applied_torque[6];
      message.lh2 = controller_ptr->applied_torque[7];
      message.lh3 = controller_ptr->applied_torque[8];
      message.rh1 = controller_ptr->applied_torque[9];
      message.rh2 = controller_ptr->applied_torque[10];
      message.rh3 = controller_ptr->applied_torque[11];
      //RCLCPP_INFO(this->get_logger(),"publishing '%f'" ,message.lf1);
      publisher_->publish(message);
   }
}




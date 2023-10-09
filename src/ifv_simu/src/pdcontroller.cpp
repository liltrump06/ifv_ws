#include "pdcontroller.hpp"

PDController::PDController(std::vector<double> out_pdgain)
{
   get_pdgain(out_pdgain);
   init();
}

PDController::~PDController()
{
}

void PDController::init()
{
   applied_torque.resize(12,0);
}


void PDController::get_pdgain(std::vector<double> out_pdgain)
{
   RCLCPP_INFO(logger,"pdgain size(), %d",out_pdgain.size());
   pdgain.resize(out_pdgain.size());
   for(int i=0;i<out_pdgain.size();i++)
   {
      pdgain[i] = out_pdgain[i];
      RCLCPP_INFO(logger,"pdgain %ld, %f", i,pdgain[i]);
   }
}
void PDController::get_jointstate(sensor_msgs::msg::JointState msg)
{
   joint_position = msg.position;
   joint_velocity = msg.velocity;
}

void PDController::get_imu(const sensor_msgs::msg::Imu msg)
{
   imu_orientation = msg.orientation;
   imu_angular_velocity = msg.angular_velocity;
   imu_linear_acceleration = msg.linear_acceleration;
}

void PDController::get_reference()
{
   position_ref.resize(12,0);
   // for(int i = 0;i<position_re)

}

void PDController::compute_torque()
{
   // pdgain[0] hip position 
   // pdgain[1] thigh position
   // pdgain[2] calf position
   // pdgain[3] hip velo 
   // pdgain[4] thigh velo
   // pdgain[5] calf velo
   get_reference();
   // RCLCPP_INFO(logger,"position_ref.size() %ld", position_ref.size());
   // RCLCPP_INFO(logger,"joint_velocity.size() %ld", joint_velocity.size());
   // RCLCPP_INFO(logger,"applied_torque.size() %ld", applied_torque.size());

   for(unsigned int it = 0;it < joint_position.size();it++)
   {
      // RCLCPP_INFO(logger,"joint_velocity %ld, %f", it,joint_velocity[it]);
      // RCLCPP_INFO(logger,"joint_position %ld, %f", it,joint_position[it]);
      if (it == 0 || it == 3 || it == 6 || it == 9)
      {
         applied_torque[it] = pdgain[0]*(position_ref[it]-joint_position[it])+pdgain[3]*(0-joint_velocity[it]);
      }
      else if (it == 1 || it == 4 || it == 7 || it == 10)
      {
         applied_torque[it] = pdgain[1]*(position_ref[it]-joint_position[it])+pdgain[4]*(0-joint_velocity[it]);
      }
      else{
         applied_torque[it] = pdgain[2]*(position_ref[it]-joint_position[it])+pdgain[5]*(0-joint_velocity[it]);
      }
      RCLCPP_INFO(logger,"applied_torque %ld, %f", it,applied_torque[it]);
   }
}




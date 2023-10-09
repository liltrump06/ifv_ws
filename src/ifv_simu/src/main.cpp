#include "main_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp/node.hpp"

int main(int argc, char **argv)
{
   rclcpp::init(argc, argv);

   auto node = std::make_shared<MainNode>();

   node->init();
   // rclcpp::WallRate loop_rate(25);

   // while (rclcpp::ok()) {
   //    rclcpp::spin_some(node);
   //    loop_rate.sleep();
   // }
   rclcpp::spin(node);

   rclcpp::shutdown();
   return 0;
}
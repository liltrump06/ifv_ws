#include "rclcpp/rclcpp.hpp"
#include "ifv_interfaces/srv/spione.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  if (argc != 2) {
      RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: pass the input hertz to F28069M");
      return 1;
  }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("FT4222_client");
  rclcpp::Client<ifv_interfaces::srv::Spione>::SharedPtr client =
    node->create_client<ifv_interfaces::srv::Spione>("passing");

  auto request = std::make_shared<ifv_interfaces::srv::Spione::Request>();
  request->input = atoll(argv[1]);


  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);
  // Wait for the result.
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "output: %d", result.get()->output);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service passing");
  }

  rclcpp::shutdown();
  return 0;
}
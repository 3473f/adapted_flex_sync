#include "adapted_flex_sync/adapted_flex_sync_node.hpp"

namespace adapted_flex_sync {

AdaptedFlexSyncNode::AdaptedFlexSyncNode(rclcpp::NodeOptions options) :
rclcpp::Node("adapted_flex_sync_node", options) {
  // Initialize the topics
  topics_ = {{"image1", "image2"}};

  // Create the FlexSync object
  sync_ = std::make_shared<SyncPolicy>(topics_,
    std::bind(&AdaptedFlexSyncNode::flex_sync_callback, this, std::placeholders::_1),
    10);

  // Create the FlexSync subscriber
  sub_1_ = std::make_shared<FlexSyncSub>("image1", this, rclcpp::QoS(10), sync_);
  sub_2_ = std::make_shared<FlexSyncSub>("image2", this, rclcpp::QoS(10), sync_);   
}

void AdaptedFlexSyncNode::flex_sync_callback(
  const std::vector<std::shared_ptr<const image_tools::ROSCvMatContainer>>& msg) {
  // Do something with the synchronized messages
  RCLCPP_INFO(get_logger(), "Received synchronized messages");
}

}  // namespace adapted_flex_sync

#include "rclcpp_components/register_node_macro.hpp"
RCLCPP_COMPONENTS_REGISTER_NODE(adapted_flex_sync::AdaptedFlexSyncNode)
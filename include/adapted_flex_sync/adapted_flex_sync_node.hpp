#ifndef ADAPTED_FLEX_SYNC__ADAPTED_FLEX_SYNC_NODE_HPP_
#define ADAPTED_FLEX_SYNC__ADAPTED_FLEX_SYNC_NODE_HPP_

#include "flex_sync/exact_sync.hpp"
#include "flex_sync/live_sync.hpp"
#include "rclcpp/rclcpp.hpp"
#include "image_tools/cv_mat_sensor_msgs_image_type_adapter.hpp"

// This is needed for FlexSync

namespace adapted_flex_sync {

using SyncPolicy = flex_sync::ExactSync<image_tools::ROSCvMatContainer>;
using FlexSyncSub = flex_sync::Subscriber<SyncPolicy, image_tools::ROSCvMatContainer>;

class AdaptedFlexSyncNode : public rclcpp::Node {
public:
  AdaptedFlexSyncNode(rclcpp::NodeOptions options = rclcpp::NodeOptions());
  
  virtual ~AdaptedFlexSyncNode() = default;

private:
  // FlexSync callback
  void flex_sync_callback(
    const std::vector<std::shared_ptr<const image_tools::ROSCvMatContainer>>& msg);
  
  // FlexSync synchronizer
  std::shared_ptr<SyncPolicy> sync_;

  // FlexSync subscriber
  std::shared_ptr<FlexSyncSub> sub_1_;
  std::shared_ptr<FlexSyncSub> sub_2_;

  std::vector<std::vector<std::string>> topics_;
};

}  // namespace adapted_flex_sync

#endif  // ADAPTED_FLEX_SYNC__ADAPTED_FLEX_SYNC_NODE_HPP_
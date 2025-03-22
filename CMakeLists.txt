cmake_minimum_required(VERSION 3.22.1)
project(adapted_flex_sync LANGUAGES C CXX)

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

ament_auto_add_library(adapted_flex_sync_node SHARED
  src/adapted_flex_sync_node.cpp
)

rclcpp_components_register_nodes(adapted_flex_sync_node "adapted_flex_sync::AdaptedFlexSyncNode")
set(node_plugins "${node_plugins}adapted_flex_sync::AdaptedFlexSyncNode;$<TARGET_FILE:adapted_flex_sync_node>\n")

ament_auto_package()
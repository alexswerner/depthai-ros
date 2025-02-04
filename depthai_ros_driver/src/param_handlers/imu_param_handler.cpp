#include "depthai_ros_driver/param_handlers/imu_param_handler.hpp"

#include "depthai/pipeline/node/IMU.hpp"
#include "rclcpp/logger.hpp"
#include "rclcpp/node.hpp"

namespace depthai_ros_driver {
namespace param_handlers {
ImuParamHandler::ImuParamHandler(rclcpp::Node* node, const std::string& name) : BaseParamHandler(node, name) {}
ImuParamHandler::~ImuParamHandler() = default;
void ImuParamHandler::declareParams(std::shared_ptr<dai::node::IMU> imu) {
    imu->enableIMUSensor(dai::IMUSensor::ACCELEROMETER_RAW, 400);
    imu->enableIMUSensor(dai::IMUSensor::GYROSCOPE_RAW, 400);
    //   imu->enableIMUSensor(dai::IMUSensor::ROTATION_VECTOR, 400);
    imu->setBatchReportThreshold(1);
    imu->setMaxBatchReports(10);
}
dai::CameraControl ImuParamHandler::setRuntimeParams(const std::vector<rclcpp::Parameter>& /*params*/) {
    dai::CameraControl ctrl;
    return ctrl;
}
}  // namespace param_handlers
}  // namespace depthai_ros_driver
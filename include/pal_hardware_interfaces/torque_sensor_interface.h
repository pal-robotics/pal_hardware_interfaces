#ifndef _TORQUE_SENSOR_ROS_CONTROL_HARDWARE_INTERFACE_
#define _TORQUE_SENSOR_ROS_CONTROL_HARDWARE_INTERFACE_

#include <cassert>
#include <string>
#include <hardware_interface/internal/hardware_resource_manager.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/actuator_command_interface.h>

/*
namespace hardware_interface
{

class TorqueSensorHandle
{
public:
  TorqueSensorHandle(){}


  TorqueSensorHandle(const std::string& name, double* value)
    : name_(name), value_(value)
  {
    if (!value)
    {
      throw HardwareInterfaceException("Cannot create handle '" + name + "'. Torque sensor value data pointer is null.");
    }

  }

  void setValue(double value) {assert(value_); *value_ = value;}

  double getValue() const {assert(value_); return *value_;}

private:
  std::string name_;
  double* value_;
};

class TorqueSensorInterface : public HardwareResourceManager<TorqueSensorHandle> {};

//class TorqueSensorInterface : public HardwareResourceManager<CurrentLimitHandl, hardware_interface::ClaimResources>{
}
*/

namespace hardware_interface
{

/// \ref ActuatorCurrentLimitInterface for commanding actuators' max current value
class TorqueSensorInterface : public HardwareResourceManager<ActuatorHandle, DontClaimResources> {};

}



#endif

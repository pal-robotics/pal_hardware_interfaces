#ifndef _ABSOLUTE_ACTUATOR_INTERFACE_
#define _ABSOLUTE_ACTUATOR_INTERFACE_

#include <hardware_interface/internal/hardware_resource_manager.h>
#include <string>

namespace hardware_interface
{

  /** A handle used to read the state of a single actuator. */
  class AbsoluteActuatorStateHandle
  {
  public:
    AbsoluteActuatorStateHandle() : name_(), pos_(0), vel_(0){}

    /**
   * \param name The name of the actuator
   * \param pos A pointer to the storage for this actuator's position
   * \param vel A pointer to the storage for this actuator's velocity
   * \param eff A pointer to the storage for this actuator's effort (force or torque)
   */
    ActuatorStateHandle(const std::string& name, const double* pos, const double* vel, const double* eff)
      : name_(name), pos_(pos), vel_(vel), eff_(eff)
    {
      if (!pos)
      {
        throw HardwareInterfaceException("Cannot create handle '" + name + "'. Position data pointer is null.");
      }
      if (!vel)
      {
        throw HardwareInterfaceException("Cannot create handle '" + name + "'. Velocity data pointer is null.");
      }
    }

    std::string getName() const {return name_;}
    double getPosition()  const {assert(pos_); return *pos_;}
    double getVelocity()  const {assert(vel_); return *vel_;}

    const double* getPositionPtr() const {return pos_;}
    const double* getVelocityPtr() const {return vel_;}

  private:
    std::string name_;
    const double* pos_;
    const double* vel_;
  };

  /** \brief Hardware interface to support reading the state of an array of actuators
 *
 * This \ref HardwareInterface supports reading the state of an array of named
 * actuators, each of which has some position, velocity, and effort (force or
 * torque).
 *
 */
  class AbsoluteActuatorStateInterface : public HardwareResourceManager<AbsoluteActuatorStateHandle, DontClaimResources> {};

}

#endif

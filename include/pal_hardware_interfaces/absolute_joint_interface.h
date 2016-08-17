#ifndef _ABSOLUTE_JOINT_INTERFACE_
#define _ABSOLUTE_JOINT_INTERFACE_

#include <hardware_interface/internal/hardware_resource_manager.h>
#include <cassert>
#include <string>

namespace hardware_interface
{

  /** A handle used to read the state of a single joint. */
  class AbsoluteJointStateHandle
  {
  public:
    AbsoluteJointStateHandle() : name_(), pos_(0), vel_(0){}

    /**
   * \param name The name of the joint
   * \param pos A pointer to the storage for this joint's position
   * \param vel A pointer to the storage for this joint's velocity
   */
    AbsoluteJointStateHandle(const std::string& name, const double* pos, const double* vel)
      : name_(name), pos_(pos), vel_(vel)
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

  private:
    std::string name_;
    const double* pos_;
    const double* vel_;
  };

  /** \brief Hardware interface to support reading the state of an array of joints
 *
 * This \ref HardwareInterface supports reading the state of an array of named
 * joints, each of which has some position, velocity, and effort (force or
 * torque).
 *
 */
  class AbsoluteJointStateInterface : public HardwareResourceManager<AbsoluteJointStateHandle, DontClaimResources> {};

}

}

#endif

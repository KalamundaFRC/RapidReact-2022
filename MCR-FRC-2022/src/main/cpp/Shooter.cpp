#include "Shooter.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

double constexpr deadzone = 0.5;
void Shooter::RobotInit(){
  _indexMotor = new frc::PWMVictorSPX(99);
  _indexMotor ->SetInverted(false);
  _topMotor = new frc::PWMVictorSPX(99);
  _topMotor ->SetInverted(false);
  _leftCim = new frc::PWMVictorSPX(99);
  _leftCim ->SetInverted(false);
  _rightCim = new frc::PWMVictorSPX(99);
  _rightCim ->SetInverted(false);

}

void Shooter::RobotPeriodic(){
  
}
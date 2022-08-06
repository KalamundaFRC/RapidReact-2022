#pragma once
#include <frc/motorcontrol/PWMMotorController.h>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/motorcontrol/Spark.h>
#include <iostream>
#include <string>
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/XboxController.h>
#include <frc/motorcontrol/PWMVictorSPX.h>

class Shooter : public frc::TimedRobot{

private:
  void RobotInit() override;
  void RobotPeriodic() override;
  frc::PWMVictorSPX *_indexMotor;
  frc::PWMVictorSPX *_topMotor;
  frc::PWMVictorSPX *_leftCim;
  frc::PWMVictorSPX *_rightCim;
  double _indexPower = 0;
  double _topPower = 0;
  double _shooterPower = 0;
  double _shooterMaxPower = 0.8;
};
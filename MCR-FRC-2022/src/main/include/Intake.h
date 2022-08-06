#pragma once

#include <iostream>
#include <string>
#include <frc/Timer.h>
#include <frc/TimedRobot.h>
#include <frc/DriverStation.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <frc/XboxController.h>
#include <frc/motorcontrol/PWMVictorSPX.h>
//#include <frc/SpeedControllerGroup.h>
#include <frc/motorcontrol/PWMMotorController.h>
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/motorcontrol/Spark.h>

class Intake : frc::TimedRobot{
  public:
  void RobotInit() override;
  void RobotPeriodic() override;
  frc::XboxController *coDriver;

  private:
  frc::PWMVictorSPX *_intakeMotor;
  double _intakePower = 0;
  double _intakeMaxPower = 0.8;
  
};
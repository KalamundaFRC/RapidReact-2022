// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

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

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  //void RobotPeriodic() override;
   void AutonomousInit() override;
   void AutonomousPeriodic() override;
  // void TeleopInit() override;
   void TeleopPeriodic() override;   
  // void DisabledInit() override;
  // void DisabledPeriodic() override;
  // void TestInit() override;
   //void TestPeriodic() override;

  frc::XboxController *driver;
  frc::XboxController *coDriver;
  

 private:
    frc::Timer autoTimer;
    const double deadzone = 0.01;
  //drivebase
  frc::PWMVictorSPX *_frontLeftMotor;
  frc::PWMVictorSPX *_backLeftMotor;
  frc::PWMVictorSPX *_frontRightMotor;
  frc::PWMVictorSPX *_backRightMotor;
  

  double _rightPower = 0;
  double _leftPower = 0;
  double _limit = 0.8;
  double _autoLeftPower = 0;
  double _autoRightPower = 0;
  //shooter
  frc::PWMVictorSPX *_indexMotor;
  frc::PWMVictorSPX *_topMotor;
  frc::PWMVictorSPX *_leftCim;
  frc::PWMVictorSPX *_rightCim;
  double _indexPower = 0;
  double _topPower = 0;
  double _shooterPower = 0;
  double _shooterMaxPower = 0.8;
  //intake
  frc::PWMVictorSPX *_intakeMotor;
  double _intakePower = 0;
  double _intakeMaxPower = 0.8;
  //climber
  frc::PWMVictorSPX *_climberMotor;
  double _climberPower = 0;
  

};

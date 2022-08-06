// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "Drivebase.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

double constexpr deadzone = 0.05;
void Robot::RobotInit() {
  /**
   * Controllers
   */
  driver = new frc::XboxController(0);
  coDriver = new frc::XboxController(0);

 /**
   * Drivetrain motors
   */
  //PWM is for the rio, if using can, must assign individual ID
  _frontLeftMotor = new frc::PWMVictorSPX(2);
  _backLeftMotor = new frc::PWMVictorSPX(1);
  _frontRightMotor = new frc::PWMVictorSPX(3);
  _backRightMotor = new frc::PWMVictorSPX(4);

  _frontLeftMotor->SetInverted(false);
  _backLeftMotor->SetInverted(false);
  _frontRightMotor->SetInverted(true);
  _backRightMotor->SetInverted(true);
}


/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  //Drivebase
  if (driver->GetLeftY() > deadzone) {
    _leftPower = driver->GetLeftY();
  }
  if (driver->GetRightY() > deadzone) {
    _rightPower = driver->GetRightY();
  }
  _rightPower *= _limit;
  _leftPower *= _limit;
  _frontLeftMotor->Set(_leftPower);
  _backLeftMotor->Set(_leftPower);
  _frontRightMotor->Set(_rightPower);
  _backRightMotor->Set(_rightPower);
}


void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  /**
   * Controllers
   */
  driver = new frc::XboxController(0);
  coDriver = new frc::XboxController(1);

 /**
   * Drivetrain motors
   */
  //PWM is for the rio, if using can, must assign individual ID
  _frontLeftMotor = new frc::PWMVictorSPX(6);
  _backLeftMotor = new frc::PWMVictorSPX(7);
  _frontRightMotor = new frc::PWMVictorSPX(8);
  _backRightMotor = new frc::PWMVictorSPX(9);

  _frontLeftMotor->SetInverted(false);
  _backLeftMotor->SetInverted(false); 
  _frontRightMotor->SetInverted(true);
  _backRightMotor->SetInverted(true);
  //Shooter motors
  //  _indexMotor = new frc::PWMVictorSPX(99);
  // _indexMotor ->SetInverted(false);
  // _topMotor = new frc::PWMVictorSPX(99);
  // _topMotor ->SetInverted(false);
  // _leftCim = new frc::PWMVictorSPX(99);
  // _leftCim ->SetInverted(false);
  // _rightCim = new frc::PWMVictorSPX(99);
  // _rightCim ->SetInverted(false);
  //Intake motors
  _intakeMotor = new frc::PWMVictorSPX(4);
  _intakeMotor->SetInverted(true);
  //Climber motors
  _climberMotor = new frc::PWMVictorSPX(5);
  _climberMotor->SetInverted(false);


}


/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
//void Robot::RobotPeriodic() {}

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
 void Robot::AutonomousInit() {
  autoTimer.Reset();
 }
 void Robot::AutonomousPeriodic() {
  autoTimer.Start();
  if(autoTimer.Get() <= 3.0_s){
    _autoLeftPower = -0.5;
    _autoRightPower = -0.5;
  } else {
    _autoLeftPower = 0;
    _autoRightPower = 0;
    autoTimer.Stop();
  }
  _frontLeftMotor->Set(_autoLeftPower);
  _backLeftMotor->Set(_autoLeftPower);

  _frontRightMotor->Set(_autoRightPower);
  _backRightMotor->Set(_autoRightPower);
 }
  
// void Drivebase::TeleopInit() {}

void Robot::TeleopPeriodic() {
  //Drivebase
  if (driver->GetLeftY() > deadzone) {
    _leftPower = driver->GetLeftY();
  }
  if (driver->GetRightY() > deadzone) {
    _rightPower = driver->GetRightY();
  }
  _leftPower = (driver->GetLeftY())*(driver->GetLeftY())*(driver->GetLeftY());
  _rightPower = (driver->GetRightY())*(driver->GetRightY())*(driver->GetRightY());
  _rightPower *= _limit;
  _leftPower *= _limit;
  _frontLeftMotor->Set(_leftPower);
  _backLeftMotor->Set(_leftPower);
  _frontRightMotor->Set(_rightPower);
  _backRightMotor->Set(_rightPower);
  //Shooter

  //Intake
  if(coDriver->GetLeftY() > fabs(deadzone) ) {
    _intakePower = coDriver->GetLeftY();

    _intakePower *= _intakeMaxPower;  
    _intakeMotor->Set(_intakePower);
    
  }
  //Climber
  if(coDriver->GetLeftBumper()){
    _climberPower = 0.3;
    
  } else {
    _climberPower = 0;
  }
  _climberMotor->Set(_climberPower);
}


// void Robot::DisabledInit() {}

// void Robot::DisabledPeriodic() {}

// void Robot::TestInit() {}

// void Drivebase::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

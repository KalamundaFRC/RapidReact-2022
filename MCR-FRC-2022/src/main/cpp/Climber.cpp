#include "Climber.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

double constexpr deadzone = 0.5;
void Climber::RobotInit(){
//climber
  coDriver = new frc::XboxController(0);
  _climberMotor = new frc::PWMVictorSPX(99);
  _climberMotor->SetInverted(false);

}

void Climber::RobotPeriodic(){
   if(coDriver->GetLeftBumper()){
    _climberPower = 0.3;
  } else {
    _climberPower = 0;
  }

}
#include "Intake.h"
#include <fmt/core.h>
#include <frc/smartdashboard/SmartDashboard.h>

double constexpr deadzone = 0.05;
void Intake::RobotInit(){
_intakeMotor = new frc::PWMVictorSPX(99);
_intakeMotor->SetInverted(true);

}

void Intake::RobotPeriodic(){
  if(coDriver->GetLeftY() > fabs(deadzone) ) {
    _intakePower = coDriver->GetLeftY();

    _intakePower *= _intakeMaxPower;  
    _intakeMotor->Set(_intakePower);
    
  }

}
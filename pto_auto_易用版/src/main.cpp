#include "vex.h"
//----------------------------------------------------------------------------
//                                                                            
//    Module:       main.cpp                                                  
//    Author:       shen qiang Mr不着急                                               
//    Created:      {date}                                                    
//    Description:  IQ project                                                
//                                                                            
//----------------------------------------------------------------------------


int claw = 1;
extern bool c4m;
extern double kp,ki,kd;
extern double tkp,tki,tkd;
int main()
{
  kp=0.5;
  ki=0.002;
  kd=0.7;
  tkp=0.57;
  tki=0.005;
  tkd=1.1;
  pto_Lcalw.pumpOn();
  pto_Lcalw.retract(cylinder2);
  beam_Rclaw.retract(cylinder2);
  arm.setStopping(brake);
  leftM.setStopping(brake);
  rightM.setStopping(brake);      
  arm.setPosition(0, degrees);
  //UPDOWN.setPosition(0, degrees);
  arm.setPosition(0, degrees);
  TouchLED.setColor(yellow);
  beam(0);
  arm.spin(forward, -40, percent);
  wait(0.2, seconds);
  while(arm.velocity(rpm)<-10)
  {
    wait(1,msec);
  }
  arm.stop();
  wait(0.3, seconds);
  pto4c(true);
  arm.setPosition(0, degrees);
  TouchLED.setColor(yellow);
  while(TouchLED.pressing()==0)
  {
    wait(1,msec);
  }
  Brain.playNote(6, 6, 300);
  pto_Lcalw.pumpOff();
  BrainInertial.calibrate();
  while(BrainInertial.isCalibrating())
  {
    wait(1,msec);
  }
  TouchLED.setColor(green);
  delay(0.2);
  pto_Lcalw.pumpOn();
 while(TouchLED.pressing()==0)
  {
    wait(1,msec);
  } 
  BrainInertial.setRotation(0, degrees);
  vex::task autor(autorun);
  while (1)
  {
    wait(5, msec);
    if (arm.position(degrees) < 30)
    {
      if (leftdistance.objectDistance(mm) < 85 && claw == 1)
      {
        pto_Lcalw.extend(cylinder2);
      }
      else
      {
       pto_Lcalw.retract(cylinder2); 
      }
      if (rightdistance.objectDistance(mm) < 85 && claw == 1)
      {
        beam_Rclaw.extend(cylinder2);
      }
      else
      {
        beam_Rclaw.retract(cylinder2); 
      }
    }
    else
    {
      if (claw == 1)
      {
       pto_Lcalw.extend(cylinder2);
       beam_Rclaw.extend(cylinder2);
      }
      else
      {
        pto_Lcalw.retract(cylinder2); 
        beam_Rclaw.retract(cylinder2); 
      }
    }
  }
}
int autorun()//自动赛部分，调用了自定义函数，声明和使用方式在self-pro.h中
{
  run_dir_speed_dis(30, 70, 4,true);
  turnto(180);
  pto4c(false);
  wait(0.1, seconds);
  beamto(80,200);
  pinup();
  pindown();
  /**/
  return 0;
}
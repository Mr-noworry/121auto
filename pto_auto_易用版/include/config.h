using namespace vex;
extern brain Brain;
extern inertial BrainInertial;
extern controller Controller;
extern motor leftM;
extern distance leftdistance;
extern motor rightM;
extern distance rightdistance;
extern touchled TouchLED;
//extern distance Distancer;//二代距离传感器，右侧
extern pneumatic pto_Lcalw;
extern pneumatic beam_Rclaw;//气动
//extern motor_group UPDOWN; //此三行为电机组
extern motor ptoL;
extern motor ptoR;
extern motor_group arm; //此三行为电机组
extern motor armMotorA;
extern motor armMotorB;
extern optical Optical;//光电传感器
//基础配置页，对所有电机进行名称定义，方便后续调用
// 该配置页为自动赛配置页，所有电机均为自动赛使用

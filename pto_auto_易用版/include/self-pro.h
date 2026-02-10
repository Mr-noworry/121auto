void run_dir_speed(double degree,double speed);//沿着x方向以x速度走，一级封装，不自带循环，需二级封装使用或者外面加条件循环使用
int chasiss();
void run_dir_speed_dis(double degree,double speed,double dis,bool st=true);
//沿着x方向以x速度走多远，二级封装，带距离参数，st为true时结束后会停下来，false时结束后继续保持当前速度
void run_dir_speed_time(double degree,double speed,double time,bool st=true);
//沿着x方向以x速度走多长时间，二级封装，带时间参数，st为true时结束后会停下来，false时结束后继续保持当前速度
void turnto(int degree);//转向到某个角度，二级封装，带角度参数
void move(int a,int c);//直接控制左右轮速度，会根据底盘电机数量自动调用
void delay(double t);
void beam(int st);//beam的夹取与释放
void beamto(int speed,int height);//beam升降到某个高度，单位为度
void pto4c(bool m4=true);//切换四轮和两轮，true为四轮，false为两轮,两轮状态下，可以调用beam升降
//
int autorun();
void ptoLR(int plspeed,int prspeed);
//一般不调用。
void pinup();//抬pin到二层
void pindown();//扣双色或者三色
//前爪的自动夹用变量claw=1来开启，claw=0来关闭自动夹并且打开双夹，配合距离传感器使用

#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"
#define FULL_ROT = 64;

int distLeft[4], distRight[4];

void driveToEdge(){
  print("Drive to edge\n");
  drive_ramp(64, 64);
  pause(10000);
  drive_speed(0,0);
  while(1){
    
    if(input(0)){
      print("Hey\n");
      drive_speed(0,0);
      return;
   } 
  }    
}  

int main()                                    // Main function
{
  high(1);
  int yMovement;
  int xMovement;
  
   drive_getTicks(&distLeft[0], &distRight[0]);
   
   driveToEdge();
   drive_getTicks(&distLeft[1], &distRight[1]);
   yMovement = distLeft[1] - distLeft[0];
   
   
   drive_goto(26, -25);
   print("Rotate 90\n");
   drive_getTicks(&distLeft[2], &distRight[2]);
    print("Got ticks\n");
   driveToEdge();
   drive_getTicks(&distLeft[3], &distRight[3]);
   xMovement = distLeft[3] - distLeft[2];
  
   print("This white board is %d by %d ticks (x/y)", xMovement, yMovement);
}
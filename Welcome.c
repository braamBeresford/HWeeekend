#include "simpletools.h"                      // Include simple tools
#include "abdrive.h"
#include <stdbool.h> 
#define FULL_ROT = 64;

int distLeft[4], distRight[4];


void driveToEdge(){
  print("Drive to edge\n");
  print("Inputs: %d", input(12));
  drive_ramp(100, 100);
  while(1){
    if(!input(12)){
      return;
    }  
    if(input(0)){
      drive_speed(0,0);
      return;
   }
  }  
} 

void findBorder(int* yMovement, int* xMovement){
  drive_getTicks(&distLeft[0], &distRight[0]);
   
   driveToEdge();
   drive_getTicks(&distLeft[1], &distRight[1]);
   *yMovement = distLeft[1] - distLeft[0];
   drive_goto(26, -25);
   print("Rotate 90\n");
   drive_getTicks(&distLeft[2], &distRight[2]);

   driveToEdge();
   drive_getTicks(&distLeft[3], &distRight[3]);
   *xMovement = distLeft[3] - distLeft[2];
}

 
void switchLane(bool reverseDirection){
  int dir = reverse? -1: 1;
  drive_goto((dir*25), ((reverse? 1: -1)*25)); // Turn 90 degrees
  drive_goto(14,14);
  drive_goto((dir*25), ((reverse? 1: -1)*25));
}

void clean(){
  bool dir = false;
  driveToEdge(dir);
  while(true){
    if(!input(12)){
      return;
    }      
    print("Edge!\n");
    switchLane((dir=!dir));
    driveToEdge();
  }    
}  
int main()                                    // Main function
{
  high(1);
  high(26);
  int yMovement;
  int xMovement;
  while(true){
    if(input(12)){
        clean();
        //findBorder(&yMovement, &xMovement);
    }      
  }    

  
  //clean();
  return 1;
}
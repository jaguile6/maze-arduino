#include <MatrizLed.h>

MatrizLed pantalla;
//inicio = 1,1
//fin=20,0
static bool maze[32][32]=
{
{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
{1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1,},
{1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,1,0,1,},
{1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,0,1,},
{1,0,1,0,0,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,0,1,},
{1,0,1,1,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,1,0,1,0,1,1,0,0,1,1,0,0,1,},
{1,0,1,0,1,0,1,1,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,0,0,0,0,1,},
{1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,},
{1,0,0,0,1,0,1,0,1,0,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,},
{1,1,1,1,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,1,0,0,0,0,0,0,1,},
{1,0,0,0,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0,1,0,1,1,0,1,0,0,1,0,1,},
{1,0,1,1,1,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,1,0,1,1,0,1,0,0,1,0,1,},
{1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,1,1,1,1,0,1,0,0,1,0,1,},
{1,0,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,},
{1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,1,1,},
{1,1,1,1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,1,1,1,},
{1,0,0,0,1,0,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,0,0,1,0,1,},
{1,0,0,1,0,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,},
{1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,},
{1,1,0,0,1,0,0,1,1,1,0,1,1,1,0,0,0,0,1,0,0,1,0,1,0,0,0,0,0,0,0,1,},
{3,1,0,1,0,0,1,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,1,1,1,1,0,1,},
{0,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,},
{0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,1,},
{1,0,0,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,},
{0,1,0,0,0,0,1,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,},
{0,0,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,0,1,},
{1,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,0,1,1,1,1,0,1,},
{1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,0,1,0,0,1,0,1,},
{0,0,0,0,1,0,0,0,0,0,1,1,1,1,1,1,1,0,1,0,0,1,0,1,1,0,0,0,1,1,0,1,},
{0,1,1,1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,1,},
{0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,1,},
{1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
};





void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.setIntensity(0,0);
  Serial.begin(9600);
}
int x=1;
int y=1;
int movx=0;
int movy=0;
long int frame=0;
long int timer=0;

void loop() {

  
  
  while(1){
    leerJoystick();

    moverme();
    timer=millis()+50;
    while(timer>millis()){
      pintarMapa();
    }
    
    frame+=1;
  }
}




void leerJoystick(){
  if(analogRead(A1)>800){
    movx=1;
  }else if(analogRead(A1)<200){
    movx=-1;
  }else if(analogRead(A0)>800){
    movy=1;
  }else if(analogRead(A0)<200){
    movy=-1;
  }
  
}

void moverme(){
  if(frame%3==0){
      maze[y][x]=0;
      
      if(maze[y+movy][x]==0){
        y=y+movy;
      }
      if(maze[y][x+movx]==0){
        x=x+movx;
      }
      if(y==20 and x==0){
        victoria();
      }
      maze[y][x]=2;
      movx=0;
      movy=0;
    }
}


void pintarMapa(){
  int offsetX=x-x%8;
  int offsetY=y-y%8;
  int actual;

  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      actual=maze[offsetY+i][offsetX+j];
      if(actual==1){
        pantalla.setLed(0,i,j,1);
      }else if(actual==0){
        pantalla.setLed(0,i,j,0);
      }else if(actual==2){
        if(frame%3==0){
          pantalla.setLed(0,i,j,1);
        }else{
          pantalla.setLed(0,i,j,0);
        }
      }else if(actual==3){
        pantalla.setLed(0,i,j,0);
      }
    }
  }
  
}

void victoria(){
  while(1){
    pantalla.borrar();
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        pantalla.setLed(0,i,j,1);
      }
      delay(50);
    }
  }
}

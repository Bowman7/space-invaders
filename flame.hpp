#pragma once

#include"raylib.h"

class Flame{
public:
  Flame();
  ~Flame();
  void Update();
  //flame
  void DrawFlame();
  void SetPosX(int x){
    x =x;
  }
  void SetPosY(int y){
    y = y+100;
  }
  void UpdatePosLeft(){
    x-=7;
    if(x<0){
      x +=7;
    }
    
  }
  void UpdatePosRight(){
    x += 7;
    if((x+64)>1024){
      x-=7;
    }
  }
private:
  //for flame animation
  int currentFrame;
  int frameCount;
  int frameSpeed;
  Rectangle FrameRec;
  Texture2D flame;
  //Vector2 position;
  int x,y;
};

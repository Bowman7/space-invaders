#pragma once
#include"raylib.h"

class Health{

public:
  Health();
  ~Health();
  void setPos(int,int);
  void Draw();
  float GetPosX(){
    return position.x;
  }
  float GetPosY(){
    return position.y;
  }
  
  
private:
  Texture2D image;
  Vector2 position;
};

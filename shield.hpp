#pragma once
#include"raylib.h"

class Shield{
public:
  Shield();
  ~Shield();
  void DrawShield();
  void Update();
  void SetPosition(int,int);
  void Hit(){
    hitPoint--;
  };
  bool isUp(){
    return isActive;
  }
  int GetXPos(){
    return position.x;
  }
  int GetYPos(){
    return position.y;
  }
  void ResetShield(){
    hitPoint = 20;
  }
private:
  Vector2 position;
  Texture2D image;
  int hitPoint;
  bool isActive;
};

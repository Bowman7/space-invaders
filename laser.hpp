#pragma once
#include"raylib.h"

class Laser{
 public:
  Laser(){
  }
  Laser(Vector2 position,int speed);
  ~Laser(){
    UnloadTexture(image);
  }
  void Update(int);
  void DrawLaser();

  void Fire();
  void Update_X_Pos(int);

  int GetPosX(){
    return position.x;
  }
  int GetPosY(){
    return position.y;
  }
  int GetWidth(){
    return width;
  }
  int GetHeight(){
    return height;
  }
  bool IsFired(){
    return isFired;
  }
  void holdFire(){
    isFired = false;
  }
  double GetLastUpTime(){
    return lastUpdatedTime; 
  }
  void setLastUpTime(double x){
    lastUpdatedTime = x;
  }
  bool ReachHalf(int y ){
    if(y<=400){
      return true;
    }
    return false;
  }
  void SetPosX(int x){
    position.x = x;
  }
  void SetPosY(int y){
    position.y = y;
  }
  void setId(int id){
    shipId = id;
  }
  int getId(){
    return shipId;
  }
  int returnId(){
    return shipId;
  }
  void FireEnemyLaser(){
    position.y += speed;
  }

  void SetEnemyLaserTexture(){
    image= LoadTexture("Graphics/elaser.png");
  }
  void DrawLaserSheet();
  
 private:
  Vector2 position;
  int speed;
  bool isFired;
  int width;
  int height;
  double lastUpdatedTime;
  Texture2D image;
  int shipId;
  Texture2D laserSheet;
  Rectangle frameRec;
};

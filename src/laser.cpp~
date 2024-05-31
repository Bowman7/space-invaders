#include"laser.hpp"

Laser::Laser(Vector2 position,int speed){
  this->position = position;
  this->speed = speed;
  isFired = false;
  height = 10;
  width = 4;
  lastUpdatedTime = 0.0;
  image = LoadTexture("Graphics/laser.png");
  shipId = 0 ;
  laserSheet = LoadTexture("Graphics/laser-sheet.png");
  frameRec = {0.0f,0.0f,
    (float)laserSheet.width/4,
    (float)laserSheet.height
  };
}

void Laser::DrawLaser(){
  if(isFired){
    DrawTextureV(image,position,WHITE);
    
  }
}
//draw animations
void Laser::DrawLaserSheet(){
  for(int i=0;i<4;i++){
    DrawTextureRec(laserSheet,frameRec,position,WHITE);
    frameRec.x +=4.0f;
  }
  frameRec.x = 0.0f;
}

void Laser::Update(int x){


  if(!isFired){
    Update_X_Pos(x);
  }
  if(isFired && position.y > 0.0f ){
    position.y -= speed;
  }else
    {
      isFired = false;
      position.y = 650.0f;
    }
  
}

void Laser::Fire(){
  isFired = true;
}
void Laser::Update_X_Pos(int x){
  position.x = x+28;
}

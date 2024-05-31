#include"../include/flame.hpp"

Flame::Flame(){
   //for flames
  flame = LoadTexture("Graphics/torpsheet.png");
  FrameRec = {0.0f,0.0f,
    (float)flame.width/4,(float)flame.height};
  frameCount = 0;
  frameSpeed = 4;
  currentFrame = 0;
  x = (GetScreenWidth()-flame.width)/2;
  x+=96;
  y = (GetScreenHeight()-flame.height)-20;
}
Flame::~Flame(){
  UnloadTexture(flame);
}

void Flame::Update(){
  frameCount++;
  if(frameCount >= 60/frameSpeed){
    frameCount = 0;
    currentFrame++;

    if(currentFrame>4){
      currentFrame = 0;
    }
    FrameRec.x = (float)currentFrame *(float)flame.width/4;
  }
}

void Flame::DrawFlame(){
  //DrawTexture(flame,x,y,WHITE);
  DrawTextureRec(flame,FrameRec,{(float)x,(float)y},WHITE);
  
}

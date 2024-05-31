#include"../include/shield.hpp"
#include<iostream>

Shield::Shield(){
  position.x = 0;
  position.y = 0;
  hitPoint = 20;
  image = LoadTexture("Graphics/shield.png");
  isActive = true;
}
Shield::~Shield(){
  UnloadTexture(image);
}

void Shield::DrawShield(){
  //std::cout<<"position: x"<<position.x<<"posy:"<<position.y<<std::endl;
  DrawTextureV(image,position,WHITE);
  DrawText(TextFormat(" %d ",hitPoint),position.x+22,position.y+25,0,WHITE);
}

void Shield::Update(){
  if(hitPoint<=0){
    isActive = false;
  }
}
void Shield::SetPosition(int x,int y){
  position.x = x;
  position.y = y;
}

#include"../include/health.hpp"

Health::Health(){
 
  position.x = 0;
  position.y = 0;
}

Health::~Health(){
  //UnloadTexture(texture);
}

void Health::setPos(int x,int y){
  position.x = x;
  position.y = y;
  
}

void Health::Draw(){
  //DrawTextureV(texture,position,WHITE);
}

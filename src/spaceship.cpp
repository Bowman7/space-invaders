#include"../include/spaceship.hpp"


Spaceship::Spaceship(){
  isDead = false;
  image = LoadTexture("Graphics/torp.png");
  
  position.x = (GetScreenWidth()-image.width)/2;
  position.y = (GetScreenHeight()-image.height)-20;
  lastUpdatedTime = 0.0;
  moveCount = 0;
  moveFlag = 0;
  health = 3;
  shipId = 0;
  
}

Spaceship::~Spaceship(){
  UnloadTexture(image);
  UnloadTexture(image);
}
//update
void Spaceship::Update(){
  
}
//restart
void Spaceship::Restart(){
  isDead = false;
  health = 3;
}

void Spaceship::DrawShip(){
  if(!isDead){
    DrawTextureV(image,position,WHITE);
  }
}

void Spaceship::MoveLeft(){
  
  position.x -= 7;
  if(position.x < 0){
    position.x += 7;
  }
  
}

void Spaceship::MoveRight(){
  
  position.x += 7;
  if((position.x+image.width) > 1024){
    position.x -= 7;
  }}
int Spaceship::Give_X_Pos(){
  int x = position.x;
  return x;
}

//event triggered
bool Spaceship::EventTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime - lastUpdatedTime >= interval){
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}
//move stuff
void Spaceship::moveShip(){
  if(moveFlag == 0){
    position.x += 20;
  }else{
    position.x -= 20;
  }
}
//chnage flag bool
void Spaceship::changeFlag(){
  if( moveFlag == 0){
    moveFlag = 1;
  }
  if(moveFlag == 1){
    moveFlag = 0;
  }
}
//move side to side
void Spaceship::MoveSideway(){
  if(moveCount == 6){
    moveFlag = 0;
    moveCount = 0;
  }
  if(moveCount>=3){
    moveFlag = 1;
    moveShip();
    moveCount++;
  
  }
  if(moveCount<3){
    moveShip();
    moveCount++;
  }
  
  //std::cout<<"Move count: "<<moveCount<<std::endl;
  //std::cout<<"Flag: "<<moveFlag<<std::endl;

}



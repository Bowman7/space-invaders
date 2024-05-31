#pragma once
#include"raylib.h"
#include<iostream>

class Spaceship{
 public:
  Spaceship();
  ~Spaceship();
  void Update();
  void DrawShip();
  void MoveLeft();
  void MoveRight();
  void FireLaser();  
  bool isDead;
  Vector2 position;

  int Give_X_Pos();

  void LoadEnemyShipTexture(){
    UnloadTexture(image);
    image = LoadTexture("Graphics/enemy.png");
  }

  void LoadScoutTextureParent(){
    UnloadTexture(image);
    image = LoadTexture("Graphics/scout.png");
  }

  void MoveSideway();
  bool EventTriggered(double);
  void moveShip();
  void changeFlag();
  int GetHealth(){
    return health;
  }
  void ReduceHealth(){
    health--;
  }
  void Restart();
  void nextLevel();
  //void Fire();
  void setId(int x){
    shipId = x;
  }
  int getId(){
    return shipId;
  }
  
 private:
  Texture2D image;
  double lastUpdatedTime;
  int moveCount;
  int moveFlag;
  int health;
  int shipId;
  
 
  
  
};

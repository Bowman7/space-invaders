#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>
#include<random>

#include"../src/enemies.cpp"
#include"spaceship.hpp"
#include"laser.hpp"
#include"shield.hpp"
#include"health.hpp"
#include"flame.hpp"
#include"../src/explode.cpp"

class Game{
public:
  Game();
  ~Game();
  void DrawGame();
  void Update();
  void HandleInput();
  std::vector<Enemy1> GetAllEnemyShips();
  void SetAllShields();
  void DrawEnemyShips();
  void DrawShields();
  void CheckCollisionLE();
  bool EventTriggered(double );
  //for enemy laser
  void InitLaser1();
  void InitLaser2();
  int randomInt();
  void DrawEnemyLaser();
  void UpdateELaserPos();
  void FireELaser();
  bool IsHealthy();
  void Restart();
  void nextLevel();
  int validInt();
  //ship counts enemy
  int EnemyTotalShips(){
    return EnemyShipCount;
  }
  void DecreaseEnemyShip(){
    EnemyShipCount--;
  }
  int returnScore(){
    return score;
  }
  //health
  std::vector<Health> GetAllHealths();
  void DrawHealths();
  //play go sound
  void soundGameOver(){
    PlaySound(gameOver);
  };

  //set all explode pos
  std::vector<Explode> setAllExplodePos(Texture2D &tex);
  void UpdateExplodePos();
  
private:
  double lastUpdatedTime;
private:
  Spaceship spaceship;
  Laser newLaser = Laser({spaceship.position.x+52,spaceship.position.y},7);
  Laser oldLaser = Laser({spaceship.position.x+52,spaceship.position.y},7);
  Laser buffLaser = Laser({spaceship.position.x+52,spaceship.position.y},7);
  std::vector<Enemy1> EnemyShips;
  Shield shield[4];
  //enemy lasers
  Laser ELaser1 = Laser({spaceship.position.x+32,200},7);
  Laser ELaser2 = Laser({spaceship.position.x+32,400},7);
  int EnemyShipCount;
  int score;
  
  Font font = LoadFont("Font/Pixel.ttf");
  //health
  //Health health;
  std::vector<Health> healths;
  Image h_image;
  Texture2D h_texture;

  //for flames
  Flame flame;
  //music
  Music music;
  Sound shoot;
  Sound gameOver;
  Sound hurt;
  Sound enemyHit;
  Sound bbang;
  //explode
  Explode t_explode[2];
  
  
  
};

#include"game.hpp"

#include<iostream>


Game::Game(){
  EnemyShips = GetAllEnemyShips();
  
  SetAllShields();
  InitLaser1();
  InitLaser2();
  //set id
  for(int i=0;i<60;i++){
    EnemyShips[i].setId(i);
  }
  for(Enemy1 &enemy : EnemyShips){
    enemy.LoadShipTexture();
  }
  for(int i=0;i<=60;i+=5){
    EnemyShips[i+4].LoadScoutTexture();
  }
  lastUpdatedTime = 0.0;
  EnemyShipCount = EnemyShips.size();
  score  = 0;
  //health
  healths = GetAllHealths();
  h_image = LoadImage("Graphics/miniheart.png");
  h_texture = LoadTextureFromImage(h_image);
  UnloadImage(h_image);
  //load enemy alser tex
  ELaser1.SetEnemyLaserTexture();
  ELaser2.SetEnemyLaserTexture();
  //music
  //init audio device
  InitAudioDevice();
  music = LoadMusicStream("Music/song.mp3");
  PlayMusicStream(music);
  shoot = LoadSound("Music/blaster.mp3");
  gameOver = LoadSound("Music/game-over.mp3");
  hurt = LoadSound("Music/hurt.mp3");
  enemyHit = LoadSound("Music/enemyhit.mp3");
  bbang = LoadSound("Music/bbang.mp3");
  
  
}

Game::~Game(){
  
  UnloadSound(bbang);
  UnloadSound(enemyHit);
  UnloadSound(hurt);
  UnloadSound(gameOver);
  UnloadSound(shoot);
  UnloadMusicStream(music);
  CloseAudioDevice();
  UnloadTexture(h_texture);
}

void Game::DrawGame(){

  //laser
  newLaser.DrawLaser();
  oldLaser.DrawLaser();
  //ship
  spaceship.DrawShip();
  //enemy
  DrawEnemyShips();
  DrawShields();
  DrawEnemyLaser();
  //std::cout<<"ecount: "<<EnemyTotalShips()<<std::endl;
  DrawText(TextFormat("SCORE: %i",score),850,700,20,WHITE);
  //DrawTextEx(font,"$",{260,360},50,2,WHITE);

  //health
  DrawHealths();
  //draw flame animation
  flame.DrawFlame();
  //draw explosion
  t_explode[0].DrawExplosion();
  t_explode[1].DrawExplosion();
 
}

//fire update


void Game::HandleInput(){
  if(IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){
    spaceship.MoveLeft();
    flame.UpdatePosLeft();
  }
  if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){
    spaceship.MoveRight();
    flame.UpdatePosRight();
  }
  if(IsKeyPressed(KEY_SPACE)){
    std::cout<<"Fire"<<std::endl;
    if(newLaser.IsFired()){
      oldLaser.Fire();
      PlaySound(shoot);
    }
    if(newLaser.ReachHalf(newLaser.GetPosY())){
      newLaser = oldLaser;
      oldLaser = buffLaser;
      
    }
    if(!newLaser.IsFired()){
      newLaser.Fire();
      PlaySound(shoot);
    }
    
  }
  
}

void Game::Update(){

  if(!IsHealthy()){
    PlaySound(gameOver);
  }
  //for enemy laser
  if(EnemyShipCount == 0){
    ELaser1.holdFire();
    ELaser2.holdFire();
  }
  if(EnemyShipCount == 0){
    EnemyShipCount = 60;
    nextLevel();
    ELaser1.Fire();
    ELaser2.Fire();
  }
  
  newLaser.Update(spaceship.Give_X_Pos());
  oldLaser.Update(spaceship.Give_X_Pos());
  buffLaser.Update(spaceship.Give_X_Pos());

  for(Enemy1 &ship : EnemyShips){
    if(ship.EventTriggered(1)){
      ship.MoveSideway();
    }
  }

  for(int i=0;i<4;i++){
    shield[i].Update();
  }
  //fire when certain time passes
  if(EventTriggered(0.02)){
    FireELaser();
  }
  
  UpdateELaserPos();
  //update flame
  flame.Update();
  //flame.UpdatePos(spaceship.position.x);

  //update music
  UpdateMusicStream(music);

  //update explosion
  if(!t_explode[0].isExploding()){
    t_explode[0].Update();
  }
  if(!t_explode[1].isExploding()){
    t_explode[1].Update();
  }
 
}

//all healths

std::vector<Health> Game::GetAllHealths(){
  std::vector<Health> proxy;
  int xOffset = 50;
  for(int i=0;i<3;i++){
    Health health;
    health.setPos(xOffset,690);
    proxy.push_back(health);
    xOffset+=20;
  }

  return proxy;
}
//draw all healths
void Game::DrawHealths(){
  for(int i =0;i<spaceship.GetHealth();i++){
    DrawTexture(h_texture,healths[i].GetPosX(),
		healths[i].GetPosY(),WHITE);
  }
}
//restart

void Game::Restart(){
  spaceship.Restart();
  for(int i=0;i<4;i++){
    shield[i].ResetShield();
  }
  EnemyShipCount = 60;
  score = 0;
  for(Enemy1 &ship : EnemyShips){
      ship.isDead = false;
  }
}
//next level
void Game::nextLevel(){
  EnemyShipCount = 60;
  for(Enemy1 &ship : EnemyShips){
      ship.isDead = false;
  }
}
//check ships health
bool Game::IsHealthy(){
  if(spaceship.GetHealth() > 0){
    return true;
  }
  return false;
}
//for enemy laser


int Game::randomInt(){
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,59);
  int random = dist6(rng);
  return random;
}
//return valid pos number
int Game::validInt(){
  int val1 = randomInt();
  if(!EnemyShips[val1].isDead){
    return val1;
  }
  return validInt();
}
void Game::InitLaser1(){

  int val1 = validInt();
  
  //std::cout<<"val1 :"<<val1<<"val2: "<<val2<<std::endl;

  ELaser1.SetPosX(EnemyShips[val1].position.x+32);
  ELaser1.SetPosY(EnemyShips[val1].position.y);
  ELaser1.setId(val1);
  ELaser1.Fire();


}
void Game::InitLaser2(){
  int val2 = validInt();
  
  ELaser2.SetPosX(EnemyShips[val2].position.x+32);
  ELaser2.SetPosY(EnemyShips[val2].position.y);
  ELaser2.setId(val2);
  ELaser2.Fire();

}
//event trigger

//event triggered
bool Game::EventTriggered(double interval){
  double currentTime = GetTime();
  if(currentTime-lastUpdatedTime >= interval){
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}
//draw enemy laser
void Game::DrawEnemyLaser(){
  ELaser1.DrawLaser();
  ELaser2.DrawLaser();
  //std::cout<<"Val1: "<<ELaser1.returnId()<<"Val2: "<<ELaser2.returnId()<<std::endl;
}
//update e laser pos
void Game::UpdateELaserPos(){
  //check if out of bounds
  if(ELaser1.GetPosY()>720){
    if(EnemyTotalShips()>=0){
      InitLaser1();
    }
  }
  if(ELaser2.GetPosY()>=720){
    if(EnemyTotalShips()>0){
      InitLaser2();
    }

  }
  if(!ELaser1.IsFired()){
    if(EnemyShips[ELaser1.getId()].isDead == false){
      ELaser1.SetPosX(EnemyShips[ELaser1.getId()].position.x);
    }
   
  }

  if(!ELaser2.IsFired()){
    if(EnemyShips[ELaser2.getId()].isDead == false){
      ELaser2.SetPosX(EnemyShips[ELaser2.getId()].position.x);
    }
  }
  
}
//fire enemy laser
void Game::FireELaser(){
  if(ELaser1.IsFired() && ELaser1.GetPosY()<720){
    ELaser1.FireEnemyLaser();
  }

  if(ELaser2.IsFired() && ELaser2.GetPosY()<720){
    ELaser2.FireEnemyLaser();
  }
}

//for enemy ships
std::vector<Enemy1> Game::GetAllEnemyShips(){
  std::vector<Enemy1> proxyShip;
  int xOffset = 30;
  for(int x=1;x<=12;x++){
    int yOffset = 30;
    for(int y =1;y<6;y++){
      Enemy1 ship(x+xOffset,y+yOffset);
      proxyShip.push_back(ship);
      yOffset += 80;
    }
    xOffset+=60;
    if(x == 4 || x == 8){
      xOffset +=100;
    }
  }
  return proxyShip;
}

void Game::DrawEnemyShips(){
  for(Spaceship &ship: EnemyShips){
    if(!ship.isDead){
      ship.DrawShip();
    }
  }
}

//get shields
void Game::SetAllShields(){
  int offset = 150;
  for(int i=0;i<4;i++){
    shield[i].SetPosition(offset,500);
    offset+=200;
  }  
}
//display all shields
void Game::DrawShields(){
  for(int i=0;i<4;i++){
    if(shield[i].isUp()){
      shield[i].DrawShield();
    }
  }
}
void Game::CheckCollisionLE(){
  for(Enemy1 &ship: EnemyShips){
    if(!ship.isDead){
       if(newLaser.GetPosX()<(ship.position.x +64.0f) &&
	  (newLaser.GetPosX()+newLaser.GetWidth())>ship.position.x &&
	  (newLaser.GetPosY()+newLaser.GetHeight())>ship.position.y &&
	  newLaser.GetPosY() <(ship.position.y + 64.0f)
	  ){
	 PlaySound(bbang);
	 ship.isDead = true;
	 newLaser.DrawLaserSheet();
	 newLaser.holdFire();
	 DecreaseEnemyShip();
	 score+=50;
	 //explosion
	 t_explode[0].setPosition(ship.position);
	 t_explode[0].setExplode();
	
       }
       
       if(oldLaser.GetPosX()<(ship.position.x +64.0f) &&
	  (oldLaser.GetPosX()+oldLaser.GetWidth())>ship.position.x &&
	  (oldLaser.GetPosY()+oldLaser.GetHeight())>ship.position.y &&
	  oldLaser.GetPosY() <(ship.position.y + 64.0f)
	  ){
	 PlaySound(bbang);
	 ship.isDead = true;
	 oldLaser.DrawLaserSheet();
	 oldLaser.holdFire();
	 DecreaseEnemyShip();
	 score +=50;
	 //explosion
	 t_explode[1].setPosition(ship.position);
	 t_explode[1].setExplode();

	 
       }
       
    }
  }
  //shield for hero laser
  for(int i =0;i<4;i++){
    if(shield[i].isUp()){
      if(newLaser.GetPosX()<(shield[i].GetXPos() +64.0f) &&
	 (newLaser.GetPosX()+newLaser.GetWidth())>shield[i].GetXPos() &&
	 (newLaser.GetPosY()+newLaser.GetHeight())>shield[i].GetYPos() &&
	 newLaser.GetPosY() <(shield[i].GetYPos() + 64.0f)
	 ){
	PlaySound(enemyHit);
	shield[i].Hit();
	newLaser.holdFire();
      }
      if(oldLaser.GetPosX()<(shield[i].GetXPos() +64.0f) &&
	 (oldLaser.GetPosX()+oldLaser.GetWidth())>shield[i].GetXPos() &&
	 (oldLaser.GetPosY()+oldLaser.GetHeight())>shield[i].GetYPos() &&
	 oldLaser.GetPosY() <(shield[i].GetYPos() + 64.0f)
	 ){
	PlaySound(enemyHit);
	shield[i].Hit();
	oldLaser.holdFire();
      } 
    }
  }
  //shield for enemy laser
   for(int i =0;i<4;i++){
    if(shield[i].isUp()){
      if(ELaser1.IsFired()){
	if(ELaser1.GetPosX()<(shield[i].GetXPos() +64.0f) &&
	   (ELaser1.GetPosX()+newLaser.GetWidth())>shield[i].GetXPos() &&
	   (ELaser1.GetPosY()+newLaser.GetHeight())>shield[i].GetYPos() &&
	   ELaser1.GetPosY() <(shield[i].GetYPos() + 64.0f)
	   ){
	  PlaySound(enemyHit);
	  shield[i].Hit();
	  ELaser1.holdFire();
	  if(EnemyTotalShips()>=0){
	    InitLaser1();
	  }
	}
      }
      
      if(ELaser2.IsFired()){
	if(ELaser2.GetPosX()<(shield[i].GetXPos() +64.0f) &&
	   (ELaser2.GetPosX()+newLaser.GetWidth())>shield[i].GetXPos() &&
	   (ELaser2.GetPosY()+newLaser.GetHeight())>shield[i].GetYPos() &&
	   ELaser2.GetPosY() <(shield[i].GetYPos() + 64.0f)
	   ){
	  PlaySound(enemyHit);
	  shield[i].Hit();
	  ELaser2.holdFire();
	  if(EnemyTotalShips()>=0){
	    InitLaser2();
	  }
	}
      }
    }
  }
  //for enemy laser 1
  for(Enemy1 &ship : EnemyShips){
    if(!ship.isDead){
      //left right top dow

      if(ELaser1.GetPosX()<(spaceship.position.x+64.0f) &&
	 (ELaser1.GetPosX()+4.0f) > spaceship.position.x &&
	 ELaser1.GetPosY() > spaceship.position.y &&
	 (ELaser1.GetPosY()+10.0f)>spaceship.position.y &&
	 ELaser1.GetPosY()<(spaceship.position.y + 64.0f)
	 ){
	PlaySound(hurt);
	spaceship.ReduceHealth();
	if(spaceship.GetHealth()<=0){
	  spaceship.isDead = true;
	}
	ELaser1.holdFire();
	InitLaser1();
      }

      if(ELaser2.GetPosX()<(spaceship.position.x+64.0f) &&
	 (ELaser2.GetPosX()+4.0f) > spaceship.position.x &&
	 ELaser2.GetPosY() > spaceship.position.y &&
	 (ELaser2.GetPosY()+10.0f)>spaceship.position.y &&
	 ELaser2.GetPosY()<(spaceship.position.y + 64.0f)
	 ){
	PlaySound(hurt);
	spaceship.ReduceHealth();
	if(spaceship.GetHealth()<=0){
	  spaceship.isDead = true;
	}
	ELaser2.holdFire();
	InitLaser2();
      }
       
    }
  }
}

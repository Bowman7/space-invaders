#include"raylib.h"
#include"game.hpp"
#include"laser.hpp"
#define WIDTH  1024
#define HEIGHT 720

typedef enum GameScreen{
  START = 0,
  PLAY,
  GAMEOVER
}GameScreen;

int main(){
  //init window
  InitWindow(WIDTH,HEIGHT,"window");
  SetTargetFPS(60);

  //init ship
  Game game = Game();
  //Laser laser = Laser({100,100},7);
  //background
  Texture2D image = LoadTexture("Graphics/background.png");
  Color background = {0,0,0,255};

  GameScreen currentScreen = START;
  //load font
  Font font = LoadFont("Font/Pixel.ttf");
  while(!WindowShouldClose()){

    switch(currentScreen){
    case START:
      {
	if(IsKeyPressed(KEY_ENTER)){
	  currentScreen = PLAY;
	}
      }break;
      
    case PLAY:
      {
	//check for spaceships health
	if(!game.IsHealthy()){
	  currentScreen = GAMEOVER;
	}
	//Event Handling
	game.HandleInput();
	game.CheckCollisionLE();
	//Update Objects
	game.Update();
      }break;
    case GAMEOVER:{

      DrawTextEx(font,"GAME OVER",{260,300},50,2,WHITE);

      DrawText(TextFormat("SCORE: %i",game.returnScore()),300,360,30,WHITE);
      DrawTextEx(font,"Press Enter to Restart",{260,430},30,2,WHITE);
      if(IsKeyDown(KEY_ENTER)){
	game.Restart();
	currentScreen = PLAY;
      }
    }break;
    }
    
    
    //Draw Objects
    BeginDrawing();
    ClearBackground(background);
    

    switch(currentScreen){
    case START:
      {
	DrawTexture(image,0,0,WHITE);
	DrawTextEx(font,"SPACE INVADERS",{260,360},50,2,WHITE);
	DrawTextEx(font,"Press Enter",{412,430},30,2,WHITE);
	DrawTextEx(font,"SPACE: Shoot   A:MOVE-LEFT    D:MOVE-RIGHT",{260,480},20,3,WHITE);
	
	DrawTextEx(font,"ESC: Exit",{260,580},20,3,WHITE);
      }break;

    case PLAY:
      {
	
	game.DrawGame();
	//laser.DrawLaser();
      }break;
    }
    
    EndDrawing();
  }
  UnloadTexture(image);
  
  return 0;  
}

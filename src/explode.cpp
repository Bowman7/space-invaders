#include"raylib.h"
#include"iostream"

class Explode{
public:
  Explode(){
    anim= LoadTexture("Graphics/explodesheet.png");
    frameRec ={0.0f,0.0f,
      (float)anim.width/8,(float)anim.height};
    frameCount = 0;
    frameSpeed = 8;
    currentFrame = 0;
    isExplode =true;
    xPos =0;
    yPos =0;
    position.x = 0;
    position.y =0;
  };
  ~Explode(){
    
  };

  void setExplode(){
    isExplode = false;
  }
  void DrawExplosion(){
    //std::cout<<"EXplode"<<std::endl;
    if(!isExplode){
      DrawTextureRec(anim,frameRec,position,WHITE);
    }
  }
  void setPosition(Vector2 pos){
    position = pos;
  }

  //update
  void Update(){
    if(!isExplode){
      frameCount++;
      if(frameCount >= 60/frameSpeed){
	frameCount = 0;
	currentFrame++;
	if(currentFrame>8){
	  currentFrame = 0;
	  isExplode= true;
	}
	frameRec.x = (float)currentFrame*(float)anim.width/8;
      }
    }
  }
  bool isExploding(){
    return isExplode;
  }
private:
  Texture2D anim;
  Rectangle frameRec;
  int currentFrame;
  int frameCount;
  int frameSpeed;
  int isExplode;
  int xPos,yPos;
  Vector2 position;
  
};

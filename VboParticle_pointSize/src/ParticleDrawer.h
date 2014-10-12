//
//  ParticleDrawer.h
//  VboParticle
//
//  Created by kezzardrix2 on 2014/09/26.
//
//

#ifndef VboParticle_ParticleDrawer_h
#define VboParticle_ParticleDrawer_h

class ParticleDrawer{
public:
    
    static const int NUM = 1000; //パーティクルの数
    ofVbo mVbo;
    ofVec3f mVerts[NUM]; //頂点
    ofFloatColor mColors[NUM]; //色
    ofVec3f mNormals[NUM]; //法線

    ofShader mPointSprite;
    
    void setup(){
        
        for(int i = 0; i < NUM; i++){
            mVerts[i].set(ofRandomWidth(),ofRandomHeight(),0.0);
            ofFloatColor color;
            color.setHsb(ofRandom(0.0,0.2),0.5,1.0);
            mColors[i].set(color);
            
            mNormals[i].set(ofRandom(2,50),0,0);
        }
        
        mVbo.setVertexData(mVerts, NUM, GL_DYNAMIC_DRAW);
        mVbo.setColorData(mColors, NUM, GL_DYNAMIC_DRAW);
        mVbo.setNormalData(mNormals, NUM, GL_DYNAMIC_DRAW);
        
        mPointSprite.load("shaders/pointSprite.vert","shaders/pointSprite.frag");
     
    }
    
    void update(){
        
        /*ここを外すと色々ランダム
         
        for(int i = 0; i < NUM; i++){
            mVerts[i].set(ofRandomWidth(),ofRandomHeight(),0.0);
            ofFloatColor color;
            color.setHsb(ofRandom(0.0,0.2),0.5,1.0);
            mColors[i].set(color);
            mNormals[i].set(ofRandom(2,50),0.0);
        }
         */
        
        mVbo.updateVertexData(mVerts, NUM);
        mVbo.updateColorData(mColors, NUM);
        mVbo.updateNormalData(mNormals, NUM);
        
    }
    void draw(){
        
        ofEnablePointSprites();

        mPointSprite.begin();
        
        mVbo.draw(GL_POINTS,0,NUM);
        
        mPointSprite.end();
          
    }
};

#endif

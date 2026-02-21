#include <iostream>
#include <raylib.h>

#include"night.h"

//IMPLEMENTACIÓN DE LOS MÉTODOS
void FondoAula::Dibujar(Texture2D aula){
  DrawTexture(aula, x_, 0, WHITE);
}
void FondoAula::Update(){ //Ejecuta el movimiento de la imagen del fondo
  if(IsKeyDown(KEY_D))
    x_ -= 5;
  if(IsKeyDown(KEY_A))
    x_ += 5;
  if(x_ > 0)
   x_ = 0;
  if(x_ < (1280-2000))
   x_ = (1280-2000);
}


void EmpezarNoche1(){
  //DECLARACIONES
  //OBJETOS
  FondoAula a1;

  //IMAGENES
  //Creo la textura del aula
  Image foto = LoadImage("Images/AulaNoche.png");
  Texture2D aula = LoadTextureFromImage(foto);
  UnloadImage(foto);

  //BUCLE DEL JUEGO
  //Se ejecuta 60 veces por segundo
  while(WindowShouldClose() == false){ 
    //Dibujar
    BeginDrawing();
    ClearBackground(RAYWHITE);
    a1.Dibujar(aula);
    DrawFPS(20, 30);

    //Update
    a1.Update();
    

    EndDrawing();
  }
  UnloadTexture(aula);
  CloseWindow();
}
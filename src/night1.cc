#include <iostream>
#include <raylib.h>

#include"night.h"

//IMPLEMENTACIÓN DE LOS MÉTODOS
void FondoAula::Dibujar(Texture2D aula){
  DrawTexture(aula, x_, 0, WHITE);
}
void FondoAula::Update(bool abierto){ //Ejecuta el movimiento de la imagen del fondo
  if(abierto == false){
  if(IsKeyDown(KEY_D))
    x_ -= 5;
  if(IsKeyDown(KEY_A))
    x_ += 5;
  }
  if(x_ > 0)
   x_ = 0;
  if(x_ < (1280-2000))
   x_ = (1280-2000);
}
void Mapa(Texture2D mapa, bool &abierto){ //Abre y cierra el mapa
  if(IsKeyPressed(KEY_TAB)){
    if(abierto == true)
      abierto = false;
    else if(abierto == false)
      abierto = true;
  }
  if(abierto == true){
    DrawTexture(mapa, 0, 0, WHITE);
    }
}
void Camaras(Texture2D camaras, bool abierto){ //Abre y cierra el mapa
  if(abierto == true){
    DrawTexture(camaras, 0, 0, WHITE);
    }
}

void BotonNoches::dibujar(int x, int y, int ancho, int alto, const char* texto){
  DrawRectangle(x, y, ancho, alto, DARKGRAY);
  DrawText(texto, x+(10), y+(alto/4), 20, WHITE);
  x_ = x;
  y_ = y;
  ancho_ = ancho;
  alto_ = alto;
}

void BotonNoches::clicked(int opcion){
  switch (opcion)
  {
  case 1:
    std::cout << "camara 1 \n";
    break;
  
  default:
    break;
  }
}

void BotonNoches::update(int opcion){
  Vector2 mousePos = GetMousePosition();
  if ((int)mousePos.x > x_ && (int)mousePos.x < x_+ancho_ && (int)mousePos.y > y_ && (int)mousePos.y < y_+alto_) {
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
      std::cout << "CLICK \n";
      clicked(opcion);
     }
  }
}

void EmpezarNoche1(){
  //DECLARACIONES
  bool abierto = false;
  Vector2 v1, v2, v3;
  v1.x = 1030+20;
  v1.y = 350+45;
  v3.x = 1030+60;
  v3.y = 350+45;
  v2.x = 1030+40;
  v2.y = 420;

  //OBJETOS
  FondoAula a1;
  
  BotonNoches cam1;
  BotonNoches cam2;
  BotonNoches cam3;
  BotonNoches cam4;
  BotonNoches cam5;
  BotonNoches cam6;
  BotonNoches cam7;
  BotonNoches cam8;
  BotonNoches cam9;

  //IMAGENES
  //Creo la textura del aula
  Image foto = LoadImage("Images/AulaNoche.png");
  Texture2D aula = LoadTextureFromImage(foto);
  UnloadImage(foto);

  Image foto2 = LoadImage("Images/mapa.png");
  Texture2D mapa = LoadTextureFromImage(foto2);
  UnloadImage(foto2);

  Image foto3 = LoadImage("Images/camaras.png");
  Texture2D camaras = LoadTextureFromImage(foto3);
  UnloadImage(foto3);

  Image foto4 = LoadImage("Images/cam7.png");
  Texture2D camara7 = LoadTextureFromImage(foto4);
  UnloadImage(foto4);

  //BUCLE DEL JUEGO
  //Se ejecuta 60 veces por segundo
  while(WindowShouldClose() == false){ 
    //Dibujar
    BeginDrawing();
    ClearBackground(RAYWHITE);
    a1.Dibujar(aula);
    DrawFPS(20, 30);
    Mapa(mapa, abierto); //Dibujo las cámaras si están abiertas
    //DrawTexture(camara7, 0, 0, WHITE);
    Camaras(camaras, abierto);
   
    

    //Update
    a1.Update(abierto);

    //Dibujar los botones de la cámara
    if(abierto == true){
      cam1.dibujar(600, 550, 80, 45, "CAM 1");
      cam1.update(1);
      cam2.dibujar(710, 610, 80, 45, "CAM 2");
      cam2.update(2);
      cam3.dibujar(730, 550, 80, 45, "CAM 3");
      cam3.update(3);
      cam4.dibujar(730, 500, 80, 45, "CAM 4");
      cam4.update(4);
      cam5.dibujar(870, 500, 80, 45, "CAM 5");
      cam5.update(5);
      cam6.dibujar(870, 450, 80, 45, "CAM 6");
      cam6.update(6);
      cam7.dibujar(1030, 550, 80, 45, "CAM 7");
      cam7.update(7);
      cam8.dibujar(1030, 500, 80, 45, "CAM 8");
      cam8.update(8);
      cam9.dibujar(1030, 435, 80, 45, "CAM 9");
      cam9.update(9);
      DrawRectangle(1030, 350, 80, 45, DARKGRAY);
      DrawText("YOU", 1050, 365, 20, WHITE);
      
      DrawTriangle(v1, v2, v3, WHITE);
    }
   

    EndDrawing();
  }
  UnloadTexture(aula);
  CloseWindow();
}
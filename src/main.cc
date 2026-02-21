#include<iostream>
#include <raylib.h>

#include "night.h"

int main(){
  //DECLARACIONES
  //Definimos las variables
  //Creamos los objetos

  const int alto_pantalla = 800;
  const int ancho_pantalla = 1280;
  InitWindow(ancho_pantalla, alto_pantalla, "FNAF ESIT");
  SetTargetFPS(60);

  //Objetos
  class Boton{
    public:
    int x_;
    int y_;
    int ancho_; 
    int alto_;
    
    void dibujar(int x, int y, int ancho, int alto, const char* texto){
      DrawRectangle(x, y, ancho, alto, DARKGRAY);
      DrawText(texto, x+(10), y+(alto/4), 20, WHITE);
      x_ = x;
      y_ = y;
      ancho_ = ancho;
      alto_ = alto;
    }
    void clicked(int opcion){
      switch (opcion)
      {
      case 2:
        EmpezarNoche1();
        break;
      case 4:
        std::cout << "SALIR \n";
        CloseWindow();
        break;
      
      default:
        break;
      }
    }
    void update(int opcion){
      Vector2 mousePos = GetMousePosition();
      if ((int)mousePos.x > x_ && (int)mousePos.x < x_+ancho_ && (int)mousePos.y > y_ && (int)mousePos.y < y_+alto_) {
        if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
          std::cout << "CLICK \n";
          clicked(opcion);
        }
      }
    }
  };
  Boton boton_cargar;
  Boton boton_nueva;
  Boton boton_opciones;
  Boton boton_salir;

  //Imagenes
  Image fondo = LoadImage("Images/Captura.png");
  Texture2D fondoIm = LoadTextureFromImage(fondo); 
  UnloadImage(fondo);

  //BUCLE DEL JUEGO
  //Se ejecuta 60 veces por segundo

  while(WindowShouldClose() == false){ 
    //Dibujar
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawTexture(fondoIm, 0, 0, WHITE);

    boton_cargar.dibujar(30, 300, 300, 50, "Cargar Partida");
    boton_nueva.dibujar(30, 400, 300, 50, "Nueva Partida");
    boton_opciones.dibujar(30, 500, 300, 50, "Opciones");
    boton_salir.dibujar(30, 600, 300, 50, "Salir");
    DrawFPS(20, 30);

    //Update
    boton_cargar.update(1);
    boton_nueva.update(2);
    boton_opciones.update(3);
    boton_salir.update(4);
    
    EndDrawing();
  }

  UnloadTexture(fondoIm);
  CloseWindow();
  return 0;
}
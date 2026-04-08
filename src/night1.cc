#include <iostream>
#include <raylib.h>
#include <random>

#include"night.h"

bool vivo = true;

//IMPLEMENTACIÓN DE LOS MÉTODOS Y FUNCIONES
void FondoAula::Dibujar(Texture2D aula, Texture2D cesaraula, class Cesar & cesar){
  DrawTexture(aula, x_, 0, WHITE);
  if(cesar.numero_camara_ == 9){
    DrawTexture(cesaraula, x_, 0, WHITE);
  }
}
void FondoAula::Update(bool abierto){ //Ejecuta el movimiento de la imagen del fondo
  if(abierto == false){
  if(IsKeyDown(KEY_D))
    x_ -= 5;
  if(IsKeyDown(KEY_A))
    x_ += 5;
  if(IsKeyDown(KEY_S))
    std::cout << "Bajo la mesa \n";
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

void BotonNoches::dibujarrojo(int x, int y, int ancho, int alto, const char* texto){
  DrawRectangle(x, y, ancho, alto, RED);
  DrawText(texto, x+(10), y+(alto/4), 20, WHITE);
  x_ = x;
  y_ = y;
  ancho_ = ancho;
  alto_ = alto;
}

bool BotonNoches::is_clicked(){ //metodo creado para sabotear
  Vector2 mousePos = GetMousePosition();
  if ((int)mousePos.x > x_ && (int)mousePos.x < x_+ancho_ && (int)mousePos.y > y_ && (int)mousePos.y < y_+alto_) {
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
      std::cout << "CLICK \n";
      return true;
     }
  }
  return false;
}

void BotonNoches::clicked(int opcion, int &numero_camara){
  switch (opcion)
  {
  case 1:
    std::cout << "camara 1 \n";
    numero_camara = 1;
    break;
  case 2:
    std::cout << "camara 2 \n";
    numero_camara = 2;
    break;
  case 3:
    std::cout << "camara 3 \n";
    numero_camara = 3;
    break;
  case 4:
    std::cout << "camara 4 \n";
    numero_camara = 4;
    break;
  case 5:
    std::cout << "camara 5 \n";
    numero_camara = 5;
    break;
  case 6:
    std::cout << "camara 6 \n";
    numero_camara = 6;
    break;
  case 7:
    std::cout << "camara 7 \n";
    numero_camara = 7;
    break;
  case 8:
    std::cout << "camara 8 \n";
    numero_camara = 8;
    break;
  case 9:
    std::cout << "camara 9 \n";
    numero_camara = 9;
    break;
  }
}

void BotonNoches::update(int opcion, int &numero_camara){
  Vector2 mousePos = GetMousePosition();
  if ((int)mousePos.x > x_ && (int)mousePos.x < x_+ancho_ && (int)mousePos.y > y_ && (int)mousePos.y < y_+alto_) {
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
      std::cout << "CLICK \n";
      clicked(opcion, numero_camara);
     }
  }
}

void Cesar::mover(float &timer, float &delta){
  std::random_device rd;
  std::mt19937 gen(rd()); //para las probabilidades de moverse
  switch (numero_camara_){
  case 2:
    timer += delta;
    if(timer >= 20.0){
      std::bernoulli_distribution dist(0.65); //65% de probabiliad de movimiento
      if(dist(gen)){
        std::cout << "Moverse \n";
        std::cout << "Cesar está en la cámara 3 \n";
        numero_camara_ = 3;
      }
      else{
        std::cout << "No Moverse \n";
      }
      timer = 0.0;
    }
    break;
  case 3:
    timer += delta;
    if(timer >= 20.0){
      std::bernoulli_distribution dist(0.65); //65% de probabiliad de movimiento
      if(dist(gen)){
        std::cout << "Moverse \n";
        std::cout << "Cesar está en la cámara 5 \n";
        numero_camara_ = 5;
      }
      else{
        std::cout << "No Moverse \n";
      }
      timer = 0.0;
    }
    break;
  case 5:
    timer += delta;
    if(timer >= 20.0){
      std::bernoulli_distribution dist(0.65); //65% de probabiliad de movimiento
      if(dist(gen)){
        std::cout << "Moverse \n";
        std::cout << "Cesar está en la cámara 7 \n";
        numero_camara_ = 7;
      }
      else{
        std::cout << "No Moverse \n";
      }
      timer = 0.0;
    }
    break;
  case 7:
    timer += delta;
    if(timer >= 20.0){
      std::bernoulli_distribution dist(0.65); //65% de probabiliad de movimiento
      if(dist(gen) && ascensor){
        std::cout << "Moverse \n";
        std::cout << "Cesar está en la cámara 8 \n";
        numero_camara_ = 8;
      }
      else{
        std::cout << "No Moverse \n";
      }
      timer = 0.0;
    }
    break;
  case 8:
    timer += delta;
    if(timer >= 20.0){
      std::bernoulli_distribution dist(0.65); //65% de probabiliad de movimiento
      if(dist(gen)){
        std::cout << "Moverse \n";
        std::cout << "Cesar está en la cámara 9 \n";
        numero_camara_ = 9;
      }
      else{
        std::cout << "No Moverse \n";
      }
      timer = 0.0;
    }
    break;
  case 9:
    timer += delta;
    if(timer >= 3.0 && !IsKeyDown(KEY_S)){
      vivo = false;
      std::cout << "MUERTO \n";
    }
    if(timer >= 20.0){
      numero_camara_ = 5;
      timer = 0.0;
    }
    break;
  
  default:
    break;
  }
}

void DibujarAM(float &timerAM, float &deltaAM){
  timerAM += deltaAM;
  if(timerAM >= 0 && timerAM < 90)
    DrawText("12 PM", 1150, 30, 30, WHITE);
  if(timerAM >= 90 && timerAM < 180)
    DrawText("1 AM", 1150, 30, 30, WHITE);
  if(timerAM >= 180 && timerAM < 270)
    DrawText("2 AM", 1150, 30, 30, WHITE);
  if(timerAM >= 270 && timerAM < 360)
    DrawText("3 AM", 1150, 30, 30, WHITE);
  if(timerAM >= 360 && timerAM < 450)
    DrawText("4 AM", 1150, 30, 30, WHITE);
  if(timerAM >= 450 && timerAM < 540)
    DrawText("5 AM", 1150, 30, 30, WHITE);
  if(timerAM >= 540 && timerAM < 630)
    DrawText("6 AM", 1150, 30, 30, WHITE);
}

void DibujarMascara(Texture2D mascara, bool abierto){
  if(!abierto){
  if (IsKeyDown(KEY_S)) {}
  else if (IsKeyDown(KEY_W))
    DrawTexture(mascara, 0, 0, WHITE);
  }
}

//Paso como argumentos si está aberto el panel de las cámaras, la cámara actual,
//todas las texturas de las cámaras y personajes, y los objetos de los personajes.
//Si el panel está abierto comprueba si en la cámara actual hay personajes, dibuja
//el fondo actual y los personajes que se encuentren en ella.
void DibujarCamaraActual(bool abierto, int numero_camara, Texture2D camara2, Texture2D camara3, Texture2D camara7, Texture2D camara9, Texture2D camara8, Texture2D camara1, Texture2D camara4){
  if(abierto){
  switch (numero_camara){
    case 2:
      DrawTexture(camara2, 0, 0, WHITE);
    break;
    case 3:
      DrawTexture(camara3, 0, 0, WHITE);
    break;
    case 7:
      DrawTexture(camara7, 0, 0, WHITE);
    break;
    case 9:
      DrawTexture(camara9, 0, 0, WHITE);
    break;
    case 8:
      DrawTexture(camara8, 0, 0, WHITE);
    break;
    case 1:
      DrawTexture(camara1, 0, 0, WHITE);
    break;
    case 4:
      DrawTexture(camara4, 0, 0, WHITE);
    break;
  
  default:
    break;
  }
  }
}

//dibujamos el boton si estamos en la cámara 7, retornamos el valor del boton a cesar
void DibujarBotonAscensor(bool abierto, int numero_camara, class Cesar &cesar, float &timerSAB, float &deltaSAB){
  timerSAB += deltaSAB;
  if(timerSAB > 10){
    cesar.ascensor = true;
  }
  if(abierto && numero_camara == 7){
    BotonNoches b;
    b.dibujarrojo(900, 580, 110, 45, "Sabotear");
    if(b.is_clicked()){
      if(timerSAB > 20){ //cooldown
      cesar.ascensor = false;
      std::cout << "Funciona \n";
      timerSAB = 0.0;
      }
    }
    if(timerSAB > 20)
      b.dibujar(900, 580, 110, 45, "Sabotear");
  }
  if(abierto && !cesar.ascensor)
    DrawText("Ascensor Saboteado", 900, 650, 20, WHITE);
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
  int numero_camara{1};
  
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

  Cesar cesar;

  
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

  Image foto4 = LoadImage("Images/camara7.png");
  Texture2D camara7 = LoadTextureFromImage(foto4);
  UnloadImage(foto4);

  Image foto5 = LoadImage("Images/mascara.png");
  Texture2D mascara = LoadTextureFromImage(foto5);
  UnloadImage(foto5);

  Image foto6 = LoadImage("Images/cafeteria.png");
  Texture2D camara2 = LoadTextureFromImage(foto6);
  UnloadImage(foto6);

  Image foto7 = LoadImage("Images/camara3.png");
  Texture2D camara3 = LoadTextureFromImage(foto7);
  UnloadImage(foto7);

  Image foto8 = LoadImage("Images/camara9.png");
  Texture2D camara9 = LoadTextureFromImage(foto8);
  UnloadImage(foto8);

  Image foto9 = LoadImage("Images/cam8.png");
  Texture2D camara8 = LoadTextureFromImage(foto9);
  UnloadImage(foto9);

  Image foto10 = LoadImage("Images/camara1.png");
  Texture2D camara1 = LoadTextureFromImage(foto10);
  UnloadImage(foto10);

  Image foto11 = LoadImage("Images/cesaraula.png");
  Texture2D cesaraula = LoadTextureFromImage(foto11);
  UnloadImage(foto11);

  Image foto12 = LoadImage("Images/cam4.png"); //falta poner
  Texture2D camara4 = LoadTextureFromImage(foto12);
  UnloadImage(foto12);

  
  //VARIABLES DE TIEMPO
  float timer{0.0};
  float delta = GetFrameTime();

  float timerAM{0.0};
  float deltaAM = GetFrameTime();

  float timerSAB{0.0};
  float deltaSAB = GetFrameTime();

  

  //BUCLE DEL JUEGO
  //Se ejecuta 60 veces por segundo
  while(WindowShouldClose() == false){ 
    //Dibujar
    BeginDrawing();
    ClearBackground(RAYWHITE);
    a1.Dibujar(aula, cesaraula, cesar);
    Mapa(mapa, abierto); //Dibujo las cámaras si están abiertas
    //DrawTexture(camara7, 0, 0, WHITE);
    DibujarCamaraActual(abierto, numero_camara, camara2, camara3, camara7, camara9, camara8, camara1, camara4);
    DibujarBotonAscensor(abierto, numero_camara, cesar, timerSAB, deltaSAB);
    Camaras(camaras, abierto);
    DibujarMascara(mascara, abierto);
    DibujarAM(timerAM, deltaAM);
    DrawFPS(20, 30);
    

    //Update
    a1.Update(abierto);
    cesar.mover(timer, delta);

    //Dibujar los botones de la cámara
    if(abierto == true){
      cam1.dibujar(600, 550, 80, 45, "CAM 1");
      cam1.update(1, numero_camara);
      cam2.dibujar(710, 610, 80, 45, "CAM 2");
      cam2.update(2, numero_camara);
      cam3.dibujar(730, 500, 80, 45, "CAM 3");
      cam3.update(3, numero_camara);
      cam4.dibujar(730, 450, 80, 45, "CAM 4");
      cam4.update(4, numero_camara);
      cam5.dibujar(870, 500, 80, 45, "CAM 5");
      cam5.update(5, numero_camara);
      cam6.dibujar(870, 450, 80, 45, "CAM 6");
      cam6.update(6, numero_camara);
      cam7.dibujar(1030, 550, 80, 45, "CAM 7");
      cam7.update(7, numero_camara);
      cam8.dibujar(1030, 500, 80, 45, "CAM 8");
      cam8.update(8, numero_camara);
      cam9.dibujar(1030, 435, 80, 45, "CAM 9");
      cam9.update(9, numero_camara);
      DrawRectangle(1030, 350, 80, 45, DARKGRAY);
      DrawText("YOU", 1050, 365, 20, WHITE);
      
      DrawTriangle(v1, v2, v3, WHITE);
    }
   

    EndDrawing();
  }
  UnloadTexture(aula);
  UnloadTexture(mapa);
  UnloadTexture(camaras);
  UnloadTexture(camara7);
  UnloadTexture(mascara);
  UnloadTexture(camara2);
  UnloadTexture(camara3);
  UnloadTexture(camara9);
  UnloadTexture(camara8);
  UnloadTexture(camara1);
  UnloadTexture(camara4);
  UnloadTexture(cesaraula);
  
  CloseWindow();
}
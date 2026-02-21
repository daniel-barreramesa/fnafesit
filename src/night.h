#include<iostream>
#include<raylib.h>

class FondoAula{
  public:
    int x_{0};
    void Dibujar(Texture2D aula);
    void Update(bool abierto);

};

class BotonNoches{
    public:
    int x_;
    int y_;
    int ancho_; 
    int alto_;
    
    void dibujar(int x, int y, int ancho, int alto, const char* texto);
    void clicked(int opcion);
    void update(int opcion);
  };

void EmpezarNoche1();
void Mapa(Texture2D mapa, Texture2D camaras, bool &abierto);
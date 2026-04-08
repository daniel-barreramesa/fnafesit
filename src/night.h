#include<iostream>
#include<raylib.h>

class FondoAula{
  public:
    int x_{0};
    void Dibujar(Texture2D aula, Texture2D cesaraula, class Cesar & cesar);
    void Update(bool abierto);

};

class BotonNoches{
    public:
    int x_;
    int y_;
    int ancho_; 
    int alto_;
    
    void dibujar(int x, int y, int ancho, int alto, const char* texto);
    void dibujarrojo(int x, int y, int ancho, int alto, const char* texto);
    void clicked(int opcion, int &numero_camara);
    void update(int opcion, int &numero_camara);
    bool is_clicked();
  };

void EmpezarNoche1();
void Mapa(Texture2D mapa, bool &abierto);
void Camaras(Texture2D Camaras, bool abierto);
void DibujarAM(float &timerAM, float &deltaAM);
void DibujarMascara(Texture2D mascara, bool abierto);
void DibujarCamaraActual(bool abierto, int numero_camara, Texture2D camara2, Texture2D camara3, Texture2D camara7, Texture2D camara9, Texture2D camara8, Texture2D camara1, Texture2D camara4);
void DibujarBotonAscensor(bool abierto, int numero_camara, class Cesar &cesar, float &timerSAB, float &deltaSAB);

//CARLOS
class Cesar{
  public:
    int numero_camara_{2};
    void mover(float &timer, float &delta);
    bool ascensor{true}; //atributo que determina si puede tomar el ascensor o no
};
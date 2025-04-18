//---Mapeamento de Hardware---//
#define led 15

//---Variáveis Globais---//
int frequencia = 5000;
int resolucao  =    8;

//---Função Principal---//
void setup()
{
  //Configuração para o funcionamento do PWM no LED
  ledcAttach(led, frequencia, resolucao);
}

//---Loop Infinito---//
void loop()
{
  //Incrementando o brilho do LED
  for(int i=0; i<= 255; i++)
  {   
    //Mudando a intensidade do brilho do LED com uso do PWM
    ledcWrite(led, i);
    delay(15);
  }

  //Decrementando o brilho do LED
  for(int i=255; i>=0; i--)
  {
    //Mudando a intensidade do brilho do LED com uso do PWM
    ledcWrite(led, i);   
    delay(15);
  }
}

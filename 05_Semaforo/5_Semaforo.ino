//---Mapeamento de Hardware---//
#define ledVm 15
#define ledAm 4
#define ledVd 5

//---Protótipo das Funções Auxiliares---//
void configuracao();
void vermelho();
void amarelo();
void verde();

//---Função Principal---//
void setup() 
{
configuracao();  
}

//---Loop Infinito---//
void loop() 
{
verde();  
amarelo();
vermelho();
}

//---Funções Auxiliares---//
void configuracao()
{
  pinMode(ledVm,OUTPUT);
  pinMode(ledAm,OUTPUT);
  pinMode(ledVd,OUTPUT); 
}
//===========================================//
void vermelho()
{ 
  digitalWrite(ledVm,HIGH);
  digitalWrite(ledAm,LOW);
  digitalWrite(ledVd,LOW);
  delay(5000);
}
//===========================================//
void amarelo()
{  
  digitalWrite(ledVm,LOW);
  digitalWrite(ledAm,HIGH);
  digitalWrite(ledVd,LOW);
  delay(2000);
}
//===========================================//
void verde()
{ 
  digitalWrite(ledVm,LOW);
  digitalWrite(ledAm,LOW);
  digitalWrite(ledVd,HIGH);
  delay(5000);
}
//===========================================//

// Salidas sujeto ganador 0 pierde y 1 gana 
int a_pin = 2;
int b_pin = 3;
int c_pin = 4;

// Entradas sombrero colocado 0 bln y 1 ngr
int sa_pin = 12;
int sb_pin = 11;
int sc_pin = 10; 

// Valor de lectura de las entradas inician con 000
// esta combinacion no es posible ya que solo hay 2 somb bln
int sa_val = 0;
int sb_val = 0;
int sc_val = 0; 


void setup()
{
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  
  pinMode(sa_pin, INPUT);
  pinMode(sb_pin, INPUT);
  pinMode(sc_pin, INPUT);

  digitalWrite(sa_pin, HIGH);
  digitalWrite(sb_pin, HIGH);
  digitalWrite(sc_pin, HIGH);
}

void loop()
{
  sa_val = digitalRead(sa_pin);
  sb_val = digitalRead(sb_pin);
  sc_val = digitalRead(sc_pin); 
  
  if(!(sb_val) && !(sc_val) && !(sa_val))
  {
    //Nadie gana todas las luces prenden;
     digitalWrite(a_pin, HIGH);
     digitalWrite(b_pin, HIGH);
     digitalWrite(c_pin, HIGH);
  }else{
  
    if(!(sb_val) && !(sc_val) && sa_val){
      // Gana el sujeto A y su sombrero es negro!
      	digitalWrite(c_pin, LOW);
     	digitalWrite(b_pin, LOW);
      	digitalWrite(a_pin, HIGH);

    }else if ( !(sc_val) && sb_val){
      // Gana el sujeto B y su sombrero es negro!
       	digitalWrite(c_pin, LOW);
     	digitalWrite(b_pin, LOW);
      	digitalWrite(a_pin, HIGH);
    }else{
      // Gana el sujeto C y su sombrero es negro!
      	digitalWrite(a_pin, LOW);
     	digitalWrite(b_pin, LOW);
      	digitalWrite(c_pin, HIGH);
    }
  }
}
// PWM controle de saídas do motor 1 e 2 está no pino digital 3
int pwm_a = 3;
// PWM controle de saídas do motor 3 e 4 é de pino digital 11
int pwm_b = 11;
 
// Direção de controle de saídas do motor 1 e 2 é no pino digital 12
int dir_a = 12;
// Direção de controle de saídas do motor 3 e 4 é no pino digital 13
int dir_b = 13;
 
// Pausa para controle de potência do motor 1 e 2 é de pino digital 9
int brk_a = 9;
// Quebra de controle de potência do motor 3 e 4 é no pino digital 8
int brk_b = 8;

void setup ()
{
  pinMode (pwm_a, OUTPUT);
  pinMode (pwm_b, OUTPUT);
  pinMode (dir_a, OUTPUT);
  pinMode (dir_b, OUTPUT);
 
  pinMode (brk_a, OUTPUT);
  pinMode (brk_b, OUTPUT);
 
  Serial.begin (9600);
}
void loop ()
{
 // Primeiro definir a direção (na minha configuração FWD é baixo e BCK é ALTA)
  digitalWrite (dir_a, LOW); //direção do motor / Set /, 1 baixo, 2 de alta
  digitalWrite (dir_b, LOW); //direção do motor / Set /, 3 de altura, 4 baixo
 
  Serial.println ("Direção Ata");
 
  // Definir ambos os motores para funcionar em ciclo de trabalho de 100% (rápido)
  analogWrite (pwm_a, 255);
  analogWrite (pwm_b, 255);
 
  Serial.println ("Full Speed");
 
  // Usamos uma demora para definir um período para os motores para funcionar
  delay (2000);
 
  // Aplicar as quebras
  digitalWrite (brk_a, HIGH);
  digitalWrite (brk_b, HIGH);
 
  Serial.println ("Break On");
 
  // Muda a direção (na minha configuração FWD é baixo e BCK é ALTA)
  digitalWrite (dir_a, HIGH); //direção do motor / / Reverse, uma alta de 2 baixo
  digitalWrite (dir_b, HIGH); //direção do motor / Reverse /, 3 baixo, 4 de alta
 
  // Remove as quebras
  digitalWrite (brk_a, LOW);
  digitalWrite (brk_b, LOW);
 
  Serial.println ("quebrar");
  Serial.println ("Direção Bck");
 
  // Mais uma vez usar um atraso para definir um período para os motores para funcionar
  delay (2000);
}

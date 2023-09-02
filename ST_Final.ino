int motor1_arriba = 2; //relé # 2 en regleta de relés que controla al motor 1
int motor1_abajo = 3; //relé # 3 en regleta de relés que controla al motor 2
int motor2_izq = 4; //relé # 4 en regleta de relés que controla al motor 3
int motor2_der = 5; //relé # 5 en regleta de relés que controla al motor 4
int ldr1; //Valor de sombra = 1020 ; Valor de mucha luz < 800 - 700; ya en el sol la los valores minimos son de ldr1,2,3,4 = 140-150, 150-160, 185-195, 255-265
int ldr2; // desenfocando los valores son de 324,253,364,476; con sombra en el sol: 542,591,690,652 ; en la sommbra (rad.difusa) : 618, 654, 751, 740. Se midió a las 12:20 p.m. del 14-abr-23.
int ldr3; // Las diferencias soleadas entre 1y2 : 15 ; 3y4 : 77
int ldr4;
int dif_1;
int dif_2;
int umbral_1 = 15;
int umbral_2 = 13;
int comp_1;
int comp_2;
int pos_1; 
int pos_2;
// si hay sombra en 1 sube, si hay sombra en 2 baja
// si hay sombra en 3 se mueve hacia laa derecha a espaldas del concentrador
// si hay sombra en 4 se mueve hacia la izquierda a espaldas del concentrador
void setup() {
  Serial.begin(9600);
  int pos_1 = 0; // poner en la posición correcta MARCAR en soporte!
  int pos_2 = 0;
}

void loop() {
  //Medición de las 4 LDR´s
  ldr1 = analogRead(A1);
  Serial.print("ldr1:");
  Serial.println(ldr1);
  ldr2 = analogRead(A2);
  Serial.print("ldr2:");
  Serial.println(ldr2);
  ldr3 = analogRead(A3);
  Serial.print("ldr3:");
  Serial.println(ldr3);
  ldr4 = analogRead(A4);
  Serial.print("ldr4:");
  Serial.println(ldr4);
  //Diferencias entre pares de LDR´s
  dif_1 = abs(ldr1-ldr2);
  dif_2 = abs(ldr3-ldr4);
  Serial.print("dif_1: ");
  Serial.println(dif_1);
  Serial.print("dif_2: ");
  Serial.println(dif_2);
  //Comparación entre dif_1 y el umbral_1
  if (dif_1 > umbral_1) {
   if (ldr1 < ldr2 && pos_1 < 100 && pos_1 > -100){
    pos_1 = pos_1 +10 ; // sombra arriba
    digitalWrite(motor1_arriba, LOW); // Necesario para poder volver a prender
    pinMode(motor1_arriba,OUTPUT); // Necesario para la primera encendida 
    Serial.println("Moviendose hacía arriba...");
    delay(6000);
    digitalWrite(motor1_arriba, HIGH); // Necesario para apagar
    delay(6000);
   }
   else {
    pos_1 = pos_1 -10 ; // sombra abajo
    digitalWrite(motor1_abajo, LOW); // Necesario para poder volver a prender
    pinMode(motor1_abajo,OUTPUT); // Necesario para la primera encendida 
    Serial.println("Moviendose hacía abajo...");
    delay(6000);
    digitalWrite(motor1_abajo, HIGH); // Necesario para apagar
    delay(6000);
   }  
  }
  //Comparación entre dif_2 y el umbral_2
  if (dif_2 > umbral_2) {
   if (ldr3 < ldr4 && pos_2 < 100 && pos_2 > -100){
    pos_2 = pos_2 +10 ; // sombra arriba
    digitalWrite(motor2_izq, LOW); // Necesario para poder volver a prender
    pinMode(motor2_izq,OUTPUT); // Necesario para la primera encendida 
    Serial.println("Moviendose hacía izquierda...");
    delay(300);
    digitalWrite(motor2_izq, HIGH); // Necesario para apagar
    delay(300);
    digitalWrite(motor2_izq, LOW); // Necesario para poder volver a prender
    pinMode(motor2_izq,OUTPUT); // Necesario para la primera encendida 
    delay(300);
    digitalWrite(motor2_izq, HIGH); // Necesario para apagar
    delay(300);
    digitalWrite(motor2_izq, LOW); // Necesario para poder volver a prender
    pinMode(motor2_izq,OUTPUT); // Necesario para la primera encendida 
    delay(300);
    digitalWrite(motor2_izq, HIGH); // Necesario para apagar
    delay(6000);
   }
   else {
    pos_2 = pos_2 -10 ; // sombra abajo
    digitalWrite(motor2_der, LOW); // Necesario para poder volver a prender
    pinMode(motor2_der,OUTPUT); // Necesario para la primera encendida 
    Serial.println("Moviendose hacía derecha...");
    delay(300);
    digitalWrite(motor2_der, HIGH); // Necesario para apagar
    delay(300);
    digitalWrite(motor2_der, LOW); // Necesario para poder volver a prender
    pinMode(motor2_der,OUTPUT); // Necesario para la primera encendida 
    delay(300);
    digitalWrite(motor2_der, HIGH); // Necesario para apagar
    delay(300);
    digitalWrite(motor2_der, LOW); // Necesario para poder volver a prender
    pinMode(motor2_der,OUTPUT); // Necesario para la primera encendida 
    delay(300);
    digitalWrite(motor2_der, HIGH); // Necesario para apagar
    delay(6000);
   }  
 }
delay(3000);
} 
  /*if (Nuevo_valor_ldr1 < Promedio) {
   pinMode(motor1_arriba,OUTPUT);
   digitalWrite(motor1_arriba, LOW);
   //Serial.print("Motor 1: Encendido - Arriba");
   delay (10000);
   digitalWrite(motor1_arriba, HIGH);
   //Serial.print("Motor 1: Apagado");
   delay(10000);
  }
  if (Nuevo_valor_ldr2 < Promedio) {
   digitalWrite(motor1_abajo, LOW);
   pinMode(motor1_abajo,OUTPUT);
   //Serial.print("Motor 2: Encendido - Abajo");
   delay (10000);
   digitalWrite(motor1_abajo, HIGH);
   //Serial.print("Motor 2: Apagado");
   delay(10000);
  }
  if (Nuevo_valor_ldr3 < (Promedio-1)) {
   digitalWrite(motor2_izq, LOW);
   pinMode(motor2_izq,OUTPUT);
   //Serial.print("Motor 2: Encendido - Izquierda");
   delay (10000);
   digitalWrite(motor2_izq, HIGH);
   //Serial.print("Motor 2 Izquierda: Apagado");
   delay(10000);
  }  
  if (Nuevo_valor_ldr4 < Promedio) {
   digitalWrite(motor2_der, LOW);
   pinMode(motor2_der,OUTPUT);
   //Serial.print("Motor 2: Encendido - Derecha");
   delay (10000);
   digitalWrite(motor2_der, HIGH);
   //Serial.print("Motor 2 Derecha: Apagado");
   delay(10000);
  }
}
*/
  /*
  Ejemplo de encendido y apagado:
  digitalWrite(motor1_izq, LOW); // Necesario para poder volver a prender
  pinMode(motor1_izq,OUTPUT); // Necesario para la primera encendida  
  digitalWrite(motor1_izq, HIGH); // Necesario para apagar
  */

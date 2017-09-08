//nodo che pubblica i dati dai sensori e legge un dato per accendere i led

#include <Arduino.h>
#include <ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/UInt16.h>
#include <std_msgs/UInt8MultiArray.h>
#include <std_msgs/String.h>
#include <string.h>
#include <ros_lib/marta_msgs/Temperature.h>
#include <math.h>
#include "FastLED.h"









ros::NodeHandle  nh; //Nodehandle

marta_msgs::Temperature ARtemp_msg; //definisco messaggio in uscita per temperatura
std_msgs::Float64 ARvolt_msg; //e per la tensione
std_msgs::UInt16 ARwet_msg; //e per l'allagamento

ros::Publisher pub_temp("diagnostics/internal_temperature", &ARtemp_msg);  //definisco il topic per la temperatura letta da arduino
ros::Publisher pub_volt("diagnostics/voltage_level", &ARvolt_msg);  //e per la tensione
ros::Publisher pub_wet("diagnostics/awash_level", &ARwet_msg);      //e per l'allagamento


unsigned char stato[6]={'S',210,10,2,1,255}; //definisco lo stato iniziale, come variabile globale, inizializzata SSSSS

/*definizione dello stato:
 * stato[0]
 * N		Non vengono letti messaggi dal nodo nel periodo
 * B		Batteria funzionante-mostra livello batteria
 * E		Emergenza
 * I		Inizio missione
 * F		Fine missione
 * P		Mantenimento posizione
 * A		Avaria sensori
 * G		Fix GPS
 * S    Arduino non riceve lo stato (problema nel collegamento)
 * */

float livello=0;
int H=0;






unsigned long sub_timer=0;


void refresh_status(  const std_msgs::UInt8MultiArray& msg){ //funzione di aggiornamento dello stato
memcpy( stato, msg.data,6);
sub_timer=millis(); //converto la stringa nell'array di char e la inserisco nello stato globale
}









//VERSIONE DEFINITIVA 4 RIGHE, 8 COLONNE.
#define NUM_LEDS 4 //definisce il numero di led per ogni colonna
//#define DATA_PIN 4 //dice su quale pin è connessa la striscia di LED
#define ROWS 4 //NUMERO DI RIGHE
#define COLUMNS 8 //numero di colonne
#define S 255
#define V 255
CRGB leds[COLUMNS][ROWS];

int PcountB=0;
int OncountB=0;
int RcountB=0;

unsigned long previousMillis = 0;
unsigned int interval = 500;



void ledblink(unsigned char STATO[6]){//funzione che fa lampeggiare i led
  unsigned long currentMillis = millis();
  interval=1000/STATO[2];

  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;
        if ((RcountB >= STATO[5] && PcountB>=2*(STATO[3]+STATO[4])) || PcountB % 2 == 0 ){ //animazione terminata
          for (byte i = 0; i < NUM_LEDS; i++){
            for (byte j= 0; j < COLUMNS; j++){
            leds[j][i] = CRGB::Black;}}
            PcountB++;
        }

        else{
          if (OncountB >= STATO[3]){ // periodo di pausa
            for (byte i = 0; i < NUM_LEDS; i++){
              for (byte j=0; j< COLUMNS; j++){
              leds[j][i] = CRGB::Black;}}
            }

          else{ //periodo di accensione
            for (byte i = 0; i < NUM_LEDS; i++){
              for (byte j=0; j< COLUMNS; j++){
            leds[j][i] = CHSV(STATO[1],S,V);}}
          }
          OncountB++;


        if (OncountB >= STATO[4]+STATO[3]){//aggiorno
          OncountB=0;
          if (STATO[5] != 255){
          RcountB++;}
        }
        PcountB++;
      }
    FastLED.show();
  }
}



int PcountF=0;
int RcountF=0;

void ledfount(unsigned char STATO[6]){//funzione che fa lampeggiare i led
  unsigned long currentMillis = millis();
  interval=1000/STATO[2];

  if (currentMillis - previousMillis >= interval) {
      previousMillis = currentMillis;

        if (RcountF >= STATO[5] || PcountF ==0){ //spegnimento
          for (byte i = 0; i < NUM_LEDS; i++){
            for (byte j=0; j< COLUMNS; j++){
            leds[j][i] = CRGB::Black;}}
        }

         else{ //periodo di accensione

            for (byte i = 0; i < COLUMNS; i++){
              for (byte j=0; j< PcountF; j++){
            leds[i][j] = CHSV(STATO[1],S,V);}}
          }

          PcountF++;

        if (PcountF > ROWS){//aggiorno
          PcountF=0;

          if (STATO[5] != 255){
          RcountF++;}
        }


    FastLED.show();
  }
}

unsigned long PastMill=0;

void beacon_function() {
  unsigned long ActMill = millis();
  if ((ActMill - PastMill >= 1000 && ActMill-PastMill <= 1500 ) || (ActMill-PastMill >= 3500 && ActMill-PastMill <=4000)) {
    digitalWrite(13,HIGH);}
  else {
    digitalWrite(13,LOW);}
  if (ActMill-PastMill > 4000){
  PastMill = ActMill;}
}










ros::Subscriber<std_msgs::UInt8MultiArray> sub("stato", &refresh_status); //definisco il subscriber del topic stato

//ros::Subscriber<std_msgs::Float64> subtemp("diagnostics/voltage_level", &Batt_color);//definisco il subscriber dello stato batteria






void setup()
{

//VERSIONE 4x8 COLLEGAMENTI ALLE USCITE DIGITALI COPIATI DAL FILE Hippo_antenna_board.ino
  
FastLED.addLeds<WS2812B, 11, GRB>(leds[0], 4);//11
  FastLED.addLeds<WS2812B, 7, GRB>(leds[1], 4);//7
  FastLED.addLeds<WS2812B, 10, GRB>(leds[2], 4);//10
  FastLED.addLeds<WS2812B, 4, GRB>(leds[3], 4);//4
  FastLED.addLeds<WS2812B, 5, GRB>(leds[4], 4);//5
  FastLED.addLeds<WS2812B, 8, GRB>(leds[5], 4);//8
  FastLED.addLeds<WS2812B, 6, GRB>(leds[6], 4);//6
  FastLED.addLeds<WS2812B, 9, GRB>(leds[7], 4);//9
  
 pinMode(13, OUTPUT); //Beacon Flash


 // comandi per interazione con ROS
   nh.initNode();
   nh.subscribe(sub);
   nh.advertise(pub_temp);
   nh.advertise(pub_volt);
   nh.advertise(pub_wet);
}






unsigned long publisher_timer=0;

unsigned long led_timer;






void loop()
{





  if (millis() - publisher_timer > 200) {		//Loop di lettura e pubblicazione della temperatura


  int T = analogRead(A1); //legge il sensore analogico
  float R = (float(T)/(1023.0-float(T)));
  float T2 = (1/((1/298.15)+(log(R)/3950)))-273.5;  //calcola la temperatura in °C e
      ARtemp_msg.temperature = T2; //inserisce  la temperatura nel dato del messaggio
      pub_temp.publish(&ARtemp_msg); //pubblica messaggio


  int ARvolt = analogRead(A2); //legge il sensore di tensione batteria
    ARvolt_msg.data=(float(ARvolt)/1023.0)*25.2; //calcola la tensione e la inserisce nel messaggio
    pub_volt.publish(&ARvolt_msg); //pubblica messaggio


  int ARwet = analogRead(A0); //legge il sensore di allagamento
      ARwet_msg.data=ARwet;//
      pub_wet.publish(&ARwet_msg); //pubblica il messaggio

    publisher_timer = millis(); //periodo
  }







/* accensione led:

 * stato accensione
 * stato[0]		stato
 * stato[1]		colore H
 * stato[2]		Frequenza blink (velocità fontana)
 * 			0: 		Luce fissa. ignorare gli ultimi due valori
 * stato[3]		Numero blink
*      0:    Fontana
 * stato[4]		Numero pause
 * stato[5]		Numero ripetizioni sella serie
 *    255:  Infinito (fino al cambio di messaggio)
 *
 * */

// if (millis() > led_timer){ //decommentare in fondo!!

beacon_function();


if (stato[2] == 0){//accensione costante del colore indicato dalla batteria
    for (byte i = 0; i < NUM_LEDS; i++){
      for (byte j=0; j < COLUMNS; j++){
      leds[j][i] = CHSV(stato[1],S,V);}}
FastLED.show();
PcountB=0;
OncountB=0;
RcountB=0;
PcountF=0;
RcountF=0;
 }

  else if (stato[3] == 0) {//fontana

    ledfount(stato);
    PcountB=0;
    OncountB=0;
    RcountB=0;
    }

  else {//sequenza di blink
    ledblink(stato);
    PcountF=0;
    RcountF=0;
      }

/* led_timer=millis()+100;//ciclo di accensione dei led
 }
*/



//ciclo di attesa di aggiornamento dello stato
    // if (millis() > sub_timer){
    //   //
    if (millis()-sub_timer>3000){
      stato[0]='S'; //porto lo stato al valore iniziale. da problemi alla funzione che legge lo stato e accende i led
      stato[1]=210;
      stato[2]=10;
      stato[3]=2;
      stato[4]=1;
      stato[5]=255;
}
      nh.spinOnce(); //sottoscrivo allo stato


    //   sub_timer=millis()+1200; //periodo di attesa per dare tempo al nodo Host di modificare lo stato
    //
    // }





}

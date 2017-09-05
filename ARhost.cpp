//NODO ARhost

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "std_msgs/UInt8MultiArray.h"
#include "std_msgs/Float64.h"
#include "std_msgs/UInt16.h"
#include <string>
#include "marta_msgs/Countermeasure.h"
#include "marta_msgs/NavStatus.h"
#include "marta_msgs/Problem.h"
#include "marta_msgs/Temperature.h"

unsigned char stato[6]={0,0,0,0,0,0}; //variabile globale stato inizializzata a 0
char prob='0';//indice del problema
int H=0;// colore LED in formato HSV


//da utilizzare in caso di messaggi persistenti e messaggi sovrapposti

bool Mpos=true; //toggle di mantenimento posizione
bool Fgps=true; //toggle di Fix GPS
bool Start=true; //toggle di inizio missione
bool Stop=true; //toggle di fine missione

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
 * S		Non vengono ricevuti messaggi da arduino
 *
 * prob
 * 0		Non riceve messaggi dall'esterno
 * 1		Tensione batteria bassa
 * 2		Tensione batteria troppo alta
 * 3		Allagamento
 * 4		Avaria sensore allagamento
 *
 * stato accensione
 * stato[0]		stato
 * stato[1]		colore H
 * stato[2]		Frequenza blink (velocità fontana)
 * 			0: 	Luce fissa. ignorare gli ultimi due valori
 * stato[3]		Numero blink
 * 			0:Fontana
 * stato[4]		Numero pause
 * stato[5]		Numero ripetizioni della serie
 * 			255:infinito (fino al cambio del messaggio)
 *
 * */


//funzioni di callback che aggiornano lo stato


void ARtemp(const marta_msgs::Temperature::ConstPtr& msg) //aggiorna lo stato in base alla temperatura letta da arduino
{
	double temperatura = msg->temperature; //leggo il dato contenuto nel messaggio
	if (temperatura>80){
		stato[0]='E';}  //Emergenza per temperatura elevata
	else if (temperatura<0){
		stato[0]='E';}	//Emergenza per temperatura troppo bassa
	else if (stato[0] == 'N'){
		stato[0]='B';} 	//temperatura buona
	}


void ARvolt (const std_msgs::Float64::ConstPtr& msg){	//aggiorna lo stato in base alla batteria
	double voltaggio = msg->data;
	if (voltaggio<18){
		stato[0]='E'; //emergenza per tensione troppo bassa
		prob='1';}
	else if (voltaggio>26){
		stato[0]='A'; //tensione troppo alta, avaria
		prob='2';}
	else{
		H = (voltaggio-20.0)*160.0/5.2; // (V-Vmin) /[(Vmax-Vmin)/Hmax];
		if (stato[0] == 'N'){
			if (H>255){
				H=0;
				stato[0]='E';}
			else {
				stato[0]='B';} //tensione buona
			}
	}
}


void ARwet (const std_msgs::UInt16::ConstPtr& msg){
	double allagamento = msg->data;
	if (allagamento>900){
		stato[0]='E'; //allagamento
		prob='3';}
	else if (allagamento >1000){
		stato[0]='A'; //sensore in avaria
		prob='4';}
	else if (stato[0] == 'N'){
			stato[0]='B';}  //non allagato
}


void MS (const std_msgs::String::ConstPtr& msg) {
	if (stato[0]!='E'){
	std::string ms = msg->data;
	if (ms == "hp_over"){ //mantenimento posizione con messaggio persistente
		stato[0]='P';
		stato[1]=43; //protocollo accensione led in caso di hp_over
		stato[2]=3;
		stato[3]=3;
		stato[4]=1;
		stato[5]=255;
		Mpos=false;}

	else if (stato[0] == 'N'){
			stato[0]='B';}
		}
	}

void Nstatus (const marta_msgs::NavStatus::ConstPtr& msg) {
	if (stato[0]!='E'){
	bool GPSstatus= msg->gps_status; //presenza del fix GPS con messaggio "una tantum"
	if (GPSstatus == true && Fgps ==true ){
		stato[0]='G';
		stato[1]=H; //protocollo accensione led in caso di GPSfix
		stato[2]=2;
		stato[3]=6;
		stato[4]=0;
		stato[5]=1;
		Fgps=false;}
	else if (GPSstatus != true){
		Fgps=true;
		if (stato[0] == 'N'){
			stato[0]='B';}
	}
	else if (stato[0] == 'N'){
			stato[0]='B';}
		}
	}

void Cmeasure (const marta_msgs::Countermeasure::ConstPtr& msg) {
	std::string Type = msg->type; //indica la presenza di emergenze
	if ( Type != "NONE"){
		stato[0]='E';}
	else if (stato[0] == 'N'){
			stato[0]='B';}
	}

void Mission (const std_msgs::String::ConstPtr& msg) {
	if (stato[0]!='E'){
	std::string missione = msg->data;
	if (missione == "STARTED"){ //missione iniziata
		stato[0]='I';
		stato[1]=86; //protocollo accensione led in caso di inizio missione
		stato[2]=3;
		stato[3]=3;
		stato[4]=1;
		stato[5]=3;}
	else if (missione == "STOPPED"){ //missione terminata
		stato[0]='F';
		stato[1]=240; //protocollo accensione led in caso di fine missione
		stato[2]=5;
		stato[3]=0;
		stato[4]=2;
		stato[5]=10;}
	else if (stato[0] == 'N'){
			stato[0]='B';}
		}
	}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "listener");
  ros::NodeHandle n;

	//subscribers

  ros::Subscriber subARtemp = n.subscribe("diagnostics/internal_temperature", 1, ARtemp); //legge la temperatura da arduino
  ros::Subscriber subARvolt = n.subscribe("diagnostics/voltage_level", 1, ARvolt); // legge la tensione
  ros::Subscriber subARwet = n.subscribe("diagnostics/awash_level", 1, ARwet);  // legge allagamento

  ros::Subscriber subNstatus = n.subscribe("nav_status", 1, Nstatus);
  ros::Subscriber subCmeasure = n.subscribe("countermeasure", 1, Cmeasure);
  ros::Subscriber subMission = n.subscribe("mission_status", 1, Mission);
  ros::Subscriber subMS = n.subscribe("ms/ms_status", 1, MS);

  ros::Publisher pubEmergency = n.advertise<marta_msgs::Problem>("emergency", 1000); //publisher di evenetuali emergenze

  ros::Publisher pub_stat = n.advertise<std_msgs::UInt8MultiArray>("stato", 1000); //publisher dello stato

	int AnimSec=5;
  ros::Rate loop_rate(1); //frequenza di aggiornamento in Hz

	marta_msgs::Problem problema; //definisco il messaggio con cui cominicare un problema
	problema.sender="ARhost";

	//definisco il messaggio che comunica lo stato

	std_msgs::UInt8MultiArray status;

	status.layout.dim.push_back(std_msgs::MultiArrayDimension());
	status.layout.dim[0].size = 6;
	status.layout.dim[0].stride = 1;
	status.layout.dim[0].label = "bla";
	status.data.resize(6);


	while (ros::ok()){	//loop di pubblicazione dello stato

		if (stato[0]=='E' || stato[0]=='A' || stato[0]=='N'){//in caso di errore o avaria pubblica un codice che identifica il tipo di problema
			problema.problemCode=('C'+prob);
			pubEmergency.publish(problema);
			for (int i=0;i<5;i++){//viene pubblicato ogni secondo, lo stato seguente dei LED
				stato[1]=255;
				stato[2]=4;
				stato[3]=1;
				stato[4]=0;
				stato[5]=255;

				status.data[0] = stato[0]; 	//messaggio
				status.data[1] = stato[1];
				status.data[2] = stato[2];
				status.data[3] = stato[3];
				status.data[4] = stato[4];
				status.data[5] = stato[5];

				pub_stat.publish(status); //pubblico il messaggio

				loop_rate.sleep();
				}
		}

		else if (stato[0]!='B'){
			
			if (stato[5] != 255 && stato[2]!=0){
			AnimSec=(int)(1+(2*stato[3]+stato[4])*stato[5]/stato[2]);
			}
			else AnimSec=1;

			for (int i=0;i<AnimSec;i++){// Da il tempo necessario all'accensione dei led

				status.data[0] = stato[0]; 	//messaggio
				status.data[1] = stato[1];
				status.data[2] = stato[2];
				status.data[3] = stato[3];
				status.data[4] = stato[4];
				status.data[5] = stato[5];
					//pongo il messaggio pari alla variabile globale
				pub_stat.publish(status); //pubblico il messaggio
				loop_rate.sleep();
				}
			}

				else {//con stato B voglio che i led siano fissi con colore H
					stato[1]=H;
					stato[2]=0;
					stato[3]=1;
					stato[4]=1;
					stato[5]=1;

				status.data[0] = stato[0]; 	//messaggio
				status.data[1] = stato[1];
				status.data[2] = stato[2];
				status.data[3] = stato[3];
				status.data[4] = stato[4];
				status.data[5] = stato[5];
				 	//pongo il messaggio pari alla variabile globale
						pub_stat.publish(status); //pubblico il messaggio
					}

		stato[0]='N';		//se non ricevo messaggi durante lo sleep, lo stato passa ad N
		stato[1]=255; //rosso fisso
		stato[2]=0;
		stato[3]=1;
		stato[4]=1;
		stato[5]=1;
		prob=0;
		H=0;

		ros::spinOnce();

		loop_rate.sleep(); //attende un periodo, dato dalla frequenza di aggiornamento

	}

  return 0;
}

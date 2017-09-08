  Installare i pacchetti rosserial e rosserial arduino nel pc.
  
  Flashare la cartella Arduino AT328 su arduino. è un progetto platformio che contiene il nodo che va su arduino.
  
  Ricavare il nome della periferica alla quale è connesso arduino. (ad esempio ttyUSB0, ttyACM0)
  
  Inserire il nodo ARhost.cpp nel pc, in un pacchetto dal quale possa accedere a marta_msgs
  
  Comandi da terminale per lanciare i due nodi:
  1) roscore

  2) rosrun rosserial_python serial_node.py /dev/NOMEPERIFERICA
  
  3) rosrun pacchetto ARhost

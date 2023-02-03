#!/bin/bash
echo TIMER DE APAGADO 
read -p "Ingrese la duracion del timer en segundos: " timer
sudo shutdown -k +$timer
sudo killall shutdown timeout 10s

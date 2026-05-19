# Sensor de Aparcamiento

1. Introducción
Este proyecto consiste en el diseño y la implementación de un sensor de aparcamiento utilizando una placa de Arduino. El sistema mide la distancia entre el vehículo y un obstáculo mediante un sensor de ultrasonidos, y da al conductor avisos visuales y sonoros en tiempo real en función de la distancia. A medida que la distancia disminuye, se encienden de manera progresiva tres LEDs de colores (verde, amarillo y rojo) y emite pitidos cada vez mas rápidos a través de un buzzer, imitando el comportamiento de los sensores de aparcamiento que podemos encontrar en los vehículos. Adicionalmente, la distancia medida se muestra en una pantalla LCD que se actualiza en tiempo real. El contraste de la pantalla se realiza mediante un potenciómetro, dando versatilidad al sistema para diferentes condiciones lumínicas.

## Archivos

- `Sensor de aparcamiento.ino`: código principal del proyecto.

## Componentes

- Arduino UNO
- Sensor ultrasónico HC-SR04
- Pantalla LCD 16x2
- LED rojo, amarillo y verde
- Buzzer
- Potenciómetro 10k
- Resistencias 220 ohmios

## Código

El código esta escrito en C++ en el Arduino IDE. La función setup() inicializa los pines de los LEDs, el buzzer y el sensor de ultrasonidos, y enciende la pantalla LCD con LiquidCrystal. En el loop(), se envía un pulso de 10 nanosegundos al pin TRIG del sensor, después se mide la duración del pulso de respuesta con el pin ECHO mediante pulseIn(), y se convierte a centímetros con la formula distancia = duracion / 59. La distancia calculada se muestra en el LCD y en la terminal en caso de que el LCD falle. En función de la distancia que se registre, se encenderán unas luces u otras, y el buzzer pitará cada vez mas rápido indicando que el coche se esta acercando al obstáculo.

## Diagrama del proyecto
<img width="1270" height="750" alt="image" src="https://github.com/user-attachments/assets/107e4aa0-893d-408b-b7cc-4bf8184ae80d" />




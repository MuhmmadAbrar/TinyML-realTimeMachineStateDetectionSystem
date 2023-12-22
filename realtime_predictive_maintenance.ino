#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>
#include "generated_code.h"

#define N_INPUTS 50
#define N_OUTPUTS 2
#define TENSOR_ARENA_SIZE 16*2048

Eloquent::TinyML::TensorFlow::TensorFlow<N_INPUTS, N_OUTPUTS, TENSOR_ARENA_SIZE> tf;

const int arraySize = 50; // Change this based on the number of values you expect
float myArray[arraySize];

void setup() {
  pinMode(2, OUTPUT);
  pinMode(27,OUTPUT);
  Serial.begin(9600); 
  delay(2000);
  tf.begin(model_data);  
  if (!tf.isOk()) {
      Serial.print("ERROR: ");
      Serial.println(tf.getErrorMessage());
      while (true) delay(1000);
  }
}

void loop() {
  while (!Serial.available()) {
    delay(100);
  }
  String inputString = Serial.readStringUntil('\n');
  char* token = strtok(const_cast<char*>(inputString.c_str()), ",");
  int i = 0;
  while (token != NULL && i < arraySize) {
    // Convert the token to a float
    myArray[i] = atof(token);
    // Print the received value if you want to verify
    Serial.print("Received for sensor ");
    Serial.print(i+1);
    Serial.print(": ");
    Serial.println(myArray[i]);
    // Move to the next token
    token = strtok(NULL, ",");
    i++;
  }

  // Your further processing logic can go here

  float predicted = tf.predict(myArray);
  Serial.println(predicted);
  if(predicted>0.5){
    digitalWrite(2,LOW);
    digitalWrite(27,HIGH);
    Serial.println("Normal. LED GREEN");
  }
  else{
    Serial.println("Recovering. LED RED");
    digitalWrite(2,HIGH);
    digitalWrite(27,LOW );
}
  delay(1000);
}

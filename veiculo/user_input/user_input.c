

// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput(){
  char description[255];
  return getMandatoryStringFieldFromUserInput(description, "Digite a descrição do veículo: ");
}

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput(){
  char brand[255];
  return getMandatoryStringFieldFromUserInput(brand, "Digite a marca do veículo: ");
}

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput(){
  char licensePlate[255];
  return getMandatoryStringFieldFromUserInput(licensePlate, "Digite a placa do veículo: ");
}

char* getVehicleModelFromUserInput(){
  char model[255];
  return getMandatoryStringFieldFromUserInput(model, "Digite o modelo do veículo: ");
}

char* getWorkerCodeFromUserInput(){
  char code[255];
  return getMandatoryStringFieldFromUserInput(code, "Digite o código do trabalhador: ");
}

int getPositionFromUserInput(){
  char position[255];
  return getMandatoryIntegerFieldFromUserInput(position, "Digite a posição do veículo: ");
}

char getWillFromUserInput(){
  char will[255];
  return getMandatoryWillFieldFromUserInput(will);
}
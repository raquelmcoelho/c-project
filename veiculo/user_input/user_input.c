

// get the vehicle description from the user
char* getVehicleDescriptionFromUserInput(){
  char description[255];
  printf("Digite a descrição do veículo: ");
  return getMandatoryStringFieldFromUserInput(description);
}

// get the vehicle brand from the user
char* getVehicleBrandFromUserInput(){
  char brand[255];
  printf("Digite a marca do veículo: ");
  return getMandatoryStringFieldFromUserInput(brand);
}

// get the vehicle license plate from the user
char* getVehicleLicensePlateFromUserInput(){
  char licensePlate[255];
  printf("Digite a placa do veículo: ");
  return getMandatoryStringFieldFromUserInput(licensePlate);
}

char* getVehicleModelFromUserInput(){
  char model[255];
  printf("Digite o modelo do veículo: ");
  return getMandatoryStringFieldFromUserInput(model);
}

char* getWorkerCodeFromUserInput(){
  char code[255];
  printf("Digite o código do trabalhador: ");
  return getMandatoryStringFieldFromUserInput(code);
}

int getPositionFromUserInput(){
  char position[255];
  printf("Digite a posição do veículo: ");
  return getMandatoryIntegerFieldFromUserInput(position);
}
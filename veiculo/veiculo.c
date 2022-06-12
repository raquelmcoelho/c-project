#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h> /* Função toupper*/

#include "ui/user_input.c"
#include "crud/read/read.c"
#include "veiculo.h"

#ifdef DEBUG
#define DEBUG_PRINTF(...)         \
  do                              \
  {                               \
    fprintf(stderr, __VA_ARGS__); \
  } while (false)
#else
#define DEBUG_PRINTF(...) \
  do                      \
  {                       \
  } while (false)
#endif

// struct vehicle

typedef struct struct_vehicle
{
  char licensePlate[255];
  char description[255];
  char brand[255];
  char model[255];
  char workerCode[255];
  int status : 1;
} VEHICLE;

// read all the vehicles on the file vehicle_database.bin,
// put all of them on a list and return such list
VEHICLE **_getAllvehicles()
{
}

// verify if the binary file of vehicles exists^
bool fileExists(char *fileName)
{
  FILE *file = fopen(fileName, "r");
  if (file == NULL)
  {
    return false;
  }
  fclose(file);
  return true;
}

/* Lê os dados  de um registro intrduzidos pelo usuário*/
void _readVehicle(VEHICLE *vehicle)
{
  printf("Placa	: ");
  scanf("%s", &vehicle->licensePlate);
  printf("Descrição	: ");
  scanf("%s", &vehicle->description);
  printf("Marca	: ");
  scanf("%s", &vehicle->brand);
  printf("Modelo	: ");
  scanf("%s", &vehicle->model);
  printf("Código do Trabalhador	: ");
  scanf("%s", &vehicle->workerCode);
  vehicle->status = 1;
  fflush(stdin);
}

void _showVehicle(VEHICLE vehicle)
{
  printf("Placa: %s\n", vehicle.licensePlate);
  printf("Descrição: %s\n", vehicle.description);
  printf("Marca: %s\n", vehicle.brand);
  printf("Modelo: %s\n", vehicle.model);
  printf("Código do Trabalhador: %s\n", vehicle.workerCode);
}

void _insertVehicleIntoDatabase(VEHICLE vehicle)
{
  FILE *fp;
  fp = fopen("vehicle_database.bin", "r+b");
  fseek(fp, 0L, SEEK_END);
  if (fwrite(&vehicle, sizeof(vehicle), 1, fp) != 1)
    printf("Falhou a escrita do registro");
  fclose(fp);
}

int _countStoredStructs()
{
  FILE *fp;
  fp = fopen("vehicle_database.bin", "r+b");
  fseek(fp, 0L, SEEK_END);
  int size = ftell(fp);
  fclose(fp);
  return size / sizeof(VEHICLE);
}

void _showVehicleByIndex(int position)
{
  FILE *fp;
  VEHICLE vehicle;
  fp = fopen("vehicle_database.bin", "r+b");
  fseek(fp, position * sizeof(VEHICLE), SEEK_SET);
  fread(&vehicle, sizeof(VEHICLE), 1, fp);
  _showVehicle(vehicle);
  fclose(fp);
}

// create a new vehicle
void createVehicle()
{
  VEHICLE vehicle;
  // read the vehicle data
  _readVehicle(&vehicle);
  // add the vehicle to the database
  _insertVehicleIntoDatabase(vehicle);
}

// read vehicle of certain position
void readVehicleByPosition() {}

void deleteVehicle()
{
  VEHICLE vehicle;
  FILE *fp;
  long int n_reg;
  char resp;

  fp = fopen("vehicle_database.bin", "r+b");

  printf("Nº do registro a ser apagado: ");
  scanf("%ld", &n_reg);
  fflush(stdin);

  if (fseek(fp, (n_reg - 1) * sizeof(VEHICLE), SEEK_SET) != 0)
  {
    printf("Registro Inexistente ou Problemas no Posicionamento!!!");
    return;
  }
  if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
  {
    printf("Problemas na leitura do Registro!!!");
    return;
  }
  if (vehicle.status == 0)
  {
    printf("O registro já está apagado!!!\n\n");
    return;
  }

  printf("\n\nDados Atuais\n\n");
  _showVehicle(vehicle);

  printf("\n\nApagar o Registro (s/n)???: ");
  resp = getWillFromUserInput();
  fflush(stdin);
  if (toupper(resp) != 'S')
    return;

  vehicle.status = 0;
  // Recuar um Registro no Arquivo
  fseek(fp, -(long)sizeof(VEHICLE), SEEK_CUR);
  // Reescrever o Registro;
  fwrite(&vehicle, sizeof(VEHICLE), 1, fp);
  fflush(fp); /*Despejar os Dados no Disco Rígido*/
}

// read all vehicles
void readAllVehicles()
{
  VEHICLE vehicle;
  FILE *fp;
  fp = fopen("vehicle_database.bin", "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return;
  }

  while (1)
  {
    if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
      break;
    if (vehicle.status == 0)
      continue;
    printf("-----------------------------------------------------\n");
    _showVehicle(vehicle);
  }
}

// update an existing vehicle
void updateVehicle()
{
  VEHICLE vehicle;
  FILE *fp;
  long int n_reg;

  fp = fopen("vehicle_database.bin", "r+b");

  printf("Nº do registro a ser alterado: ");
  scanf("%ld", &n_reg);
  fflush(stdin);
  if (fseek(fp, (n_reg - 1) * sizeof(VEHICLE), SEEK_SET) != 0)
  {
    printf("Registro Inexistente ou Problemas no Posicionamento!!!");
    return;
  }

  if (fread(&vehicle, sizeof(VEHICLE), 1, fp) != 1)
  {
    printf("Problemas na leitura do Registro!!!");
    return;
  }

  printf("\n\nDados Atuais\n\n");
  _showVehicle(vehicle);
  printf("\n\nNovos Dados\n\n");
  _readVehicle(&vehicle);

  // Recuar um Registro no Arquivo
  fseek(fp, -(long)sizeof(VEHICLE), SEEK_CUR);
  // Reescrever o Registro;
  fwrite(&vehicle, sizeof(VEHICLE), 1, fp);
  fflush(fp); /*Despejar os Dados no Disco Rígido*/
}

void readVehiclesOfWorkerInAlphabeticalOrder() {}

typedef struct int_char_tuple_bit
{
  int index;
  char description[255];
  int status : 1;
} tuple3;

void readVehiclesInAlphabeticalOrder()
{
  VEHICLE vehicle;
  tuple3 v[_countStoredStructs()];
  FILE *fp;
  int i = 0;
  fp = fopen("vehicle_database.bin", "rb");
  if (fp == NULL)
  {
    printf("Erro ao abrir o arquivo\n");
    return;
  }

  // Read the i-th vehicle
  // Make a tuple-3 of i, the i-th description and the status
  // Add the tuple-3 to a list
  // Sort the list by the second element of the tuple-3
  // Map the list to the first element of the tuple-3
  // Such list is the indexes ordered by the description alphabetically
  // For each index in the list, show the i-th vehicle

  for (int i = 0; i < _countStoredStructs(); i++)
  {

    if (fread(&vehicle, sizeof(vehicle), 1, fp) != 1)
      break;

    v[i].index = i;
    stpcpy(v[i].description, vehicle.description);
    v[i].status = vehicle.status;
  }

  // Debug contents of tuples
  for (int i = 0; i < _countStoredStructs(); i++)
  {
  }

  // Bubble sort
  for (int i = 0; i < _countStoredStructs(); i++)
  {
    for (int j = 0; j < _countStoredStructs() - 1; j++)
    {

      if (strcmp(v[j].description, v[j + 1].description) > 0)
      {

        tuple3 aux = v[j];

        v[j] = v[j + 1];

        v[j + 1] = aux;
      }
    }
  }

  // For each index in the list, show the i-th vehicle
  for (int i = 0; i < _countStoredStructs(); i++)
  {
    if (v[i].status == 0)
      continue;
    printf("-----------------------------------------------------\n");
    _showVehicleByIndex(v[i].index);
  }
}


#include "../veiculo.h"

// função para mostrar/imprimir dados de uma veículo com base no código 
// void showVehicle(char vehicleRegistrationNumber[]);

// show vehicles of worker
// void showVehiclesOfWorker(char workerRegistrationNumber[]){}

// show vehicle by position
void showVehicleByPosition(int position){
    printf("%-20s\t%s\n", "Descrição:", descriptionOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Placa:", licensePlateOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Marca:", brandOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Modelo:", modelOfEachVehicle[position]);
    printf("%-20s\t%s\n", "Código do servidor:", workerRegistrationNumberOfVehicleOfEachVehicle[position]);
}

#include <stdio.h>

void printArray(int* nums, int size,int* index){

    for (int i=0;i<size;i++){
        if (i==index[0] || i==index[1]){
            printf("> ");

        }
        else{
            printf("  ");
        }
    }
    printf("\n");


    for (int i=0;i<size;i++)
    printf("%d ", nums[i]);
    printf("\n");
}

int ajustarArray(int* nums, int index, int objectiveIndex,int currentSum){

    if (index==objectiveIndex){

        return currentSum-nums[index];
    }
    else{
        currentSum=ajustarArray(nums,index+1,objectiveIndex,currentSum);
        return currentSum-nums[index];
    }

}

int encontrarValor(int* nums, int desde, int newIndex){

    for (int k=desde; k<newIndex; k++){
        if (*(nums+k)==*(nums+newIndex)){
            return k;
        }
    }
    return -1;
}


int maximumUniqueSubarray(int* nums, int numsSize) {
    
    int index[2];
    index[0]=0;
    index[1]=1;

    // int subArray[numsSize];
    int currentSum=nums[0];
    int bestSum=currentSum;

    // printArray(nums,numsSize,index);
    // printf("Starting CurrentSum: %d\n",currentSum);

    // recorrer el array
    for (index[1]=1;index[1]<numsSize;index[1]++){

        int foundIndex=encontrarValor(nums, index[0],index[1]);
        // printf("valor encontrado? nums[%d]: %d\n",foundIndex, nums[foundIndex]);


        if (foundIndex >= 0){
            // printf("valor encontrado? nums[%d]: %d\n",foundIndex, nums[foundIndex]);
            // verificar hasta el punto actual si currentSum > bestSum
            if (currentSum>bestSum){
                bestSum=currentSum;
                // printf("bestSum: %d\n",bestSum);
            }
            //mover index[0] hasta found index, eliminando de currentSum todos los valores desechados.
            currentSum=ajustarArray(nums,index[0],foundIndex,currentSum);
            index[0]=foundIndex+1;
            // printf("CurrentSum: %d\n",currentSum);
        }

        currentSum+=nums[index[1]];
        // printf("CurrentSum: %d\n",currentSum);
        // // agregar nuevo valor a currentSUm
        // printArray(nums,numsSize,index);
        // printf("\n");
    }

    if (currentSum>bestSum){
        return currentSum;
        
    }
    return bestSum;
}








int main(){

    // array initialization
    int arraySize=9;

    int myArray[arraySize];
    myArray[0]=5;
    myArray[1]=2;
    myArray[2]=1;
    myArray[3]=2;
    myArray[4]=5;
    myArray[5]=2;
    myArray[6]=1;
    myArray[7]=2;
    myArray[8]=5;
    // myArray[9]=6;


    //conseguir el mejor valor

    int bestValue= maximumUniqueSubarray(myArray,arraySize);
    printf("%d\n",bestValue);


    return 0;
}

using System;

namespace mySolution{




public class Solution {
    
    // private bool findNumber(int arrayNumber,int myNumber){
    //     return arrayNumber==myNumber;
    // }

    public int MaximumUniqueSubarray(int[] nums) {
        
        List<int> subArray = new List<int>();
        subArray.Add(nums[0]);
        int subSuma =nums[0];
        int bestSuma =nums[0];


        // for(short j=0; j<subArray.Count();j++){
        //         System.Console.Write(subArray[j]+" ");
        //     }
        // System.Console.WriteLine();
        // System.Console.WriteLine("sub suma: "+subSuma);
        // System.Console.WriteLine("best suma: "+bestSuma);



        for (int i=1;i<nums.Length;i++){
            
            // 1. verificar si nums[i] existe o no en subArray.

            if (subArray.Contains(nums[i])){
                if (subSuma>bestSuma){
                    bestSuma=subSuma;
                    // System.Console.WriteLine("new best suma: "+bestSuma);
                }
                //      - eliminar todos los datos a la izquierda del dato ya existente (con el dato existente incluido)
                //      - comparar subSuma y bestSuma (tambien hacer la comparacion al llegar al final del ciclo for*)
                

                int ocurrence_index=subArray.IndexOf(nums[i]);

                for (int k=0;k<=ocurrence_index;k++){
                    subSuma-=subArray[k];
                }

                subArray.RemoveRange(0,ocurrence_index+1);
            }
            else{
                //      - agregar el dato nums[i] a subArray.
                //      - subSuma+=nums[i]
                // subArray.Add(nums[i]);
                // subSuma+=nums[i];
            }
            subArray.Add(nums[i]);
            subSuma+=nums[i];

            // for(short j=0; j<subArray.Count();j++){
            //     System.Console.Write(subArray[j]+" ");
            // }
            // System.Console.WriteLine();
            // System.Console.WriteLine("sub suma: "+subSuma);
            



        }

        if (subSuma>bestSuma){
            bestSuma=subSuma;
            // System.Console.WriteLine("best suma: "+bestSuma);
        }
        
        return bestSuma;
    }



}




}
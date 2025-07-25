using System;

namespace MySolution{

// - - - - - SOLUTION START - - - - -

public class Solution {
    public int MaxSum(int[] nums) {
        
        bool[] use = new bool [101];

        bool firstPositive=false;


        int total=-100;

        int j=0;

        // no ha encontrado positivos
        for(j =0;j< nums.Length;j++){
            if (nums[j]>=0){
                firstPositive=true;
                total=0;
                break;
            }

            if (nums[j] > total){
                total = nums[j];
            }


        }

        if (firstPositive == true){
            //primer numero positivo encontrado
            for(int i =j ;i< nums.Length;i++){

                if (nums[i]>0 && use[nums[i]] == false ){
                    use[nums[i]]=true;
                    total+=nums[i];

                }


            }
        }

        


        return total;
    }
}

// - - - - - SOLUTION END - - - - -
}
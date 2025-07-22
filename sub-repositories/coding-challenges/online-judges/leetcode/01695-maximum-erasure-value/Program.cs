using mySolution;
using System;


namespace program{

    public class Program{
        static void Main (string[] args){

            Solution miSolucion = new Solution();
            int[] miArray = [5,1,6,4,8,1,7];
            // int[] miArray = [4,2,4,5,6];
            // int[] miArray = [5,2,1,2,5,2,1,2,5];


            int best = miSolucion.MaximumUniqueSubarray(miArray);



            System.Console.WriteLine(best);
        }
    }
}

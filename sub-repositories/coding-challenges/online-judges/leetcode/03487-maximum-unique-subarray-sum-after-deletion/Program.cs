using System;
using MySolution;

namespace MainProgram{

    public class MainProgramClass{
        static void Main(string[] args){

            int[] nums = new int[2];
            nums = [-89,-49];



            Solution mySolution = new Solution();

            int maximaSuma=mySolution.MaxSum(nums);

            System.Console.WriteLine(maximaSuma);

        }
    }


}
using MySolution;

using System;

namespace MainNamespace{
    public class Program{
        static void Main(string[] args){

            string myString= "cdbcbbaaabab";


            Solution mySolution = new Solution();
            int Total=mySolution.MaximumGain(myString,4,5);

            System.Console.WriteLine(Total);

        }
    }
}
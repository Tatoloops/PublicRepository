using System;

using solution_namespace;

namespace main{

public class Program{
    static void Main(string[] args){
        string myString = "hellooo    worldoooooo leeetcode";

        solution_namespace.Solution mySolution = new solution_namespace.Solution();

        System.Console.WriteLine(myString);
        myString = mySolution.MakeFancyString(myString);

        System.Console.WriteLine(myString);

    }
}


}
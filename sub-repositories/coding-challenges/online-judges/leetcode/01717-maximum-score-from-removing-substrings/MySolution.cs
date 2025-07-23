using System; // para debug

namespace MySolution{



public class Solution{
    // private void Print(List<int> APos, List<int> BPos, int Total, int CurrentIndex,string s){
    //     for (int i=0;i<s.Length;i++){
    //         if (CurrentIndex==i){
    //             System.Console.Write("> ");
    //         }
    //         else{
    //             System.Console.Write("  ");
    //         }
    //     }
    //     System.Console.WriteLine();

    //     for (int i=0;i<s.Length;i++){
    //         System.Console.Write(s[i]+" ");

    //     }
    //     System.Console.WriteLine();
    //     for (int i=0;i<s.Length;i++){
    //         System.Console.Write(i+" ");

    //     }
        
    //     //imprimir valores
    //     System.Console.WriteLine();
    //     System.Console.Write("APos:");
    //     foreach (int _ in APos) {
    //         System.Console.Write(_+" ");
    //     }
    //     System.Console.WriteLine();
    //     System.Console.Write("BPos:");
    //     foreach (int _ in BPos) {
    //         System.Console.Write(_+" ");
    //     }
    //     System.Console.WriteLine();
    //     System.Console.WriteLine();

    // }


    public int MaximumGain(string s, int x, int y){


        List<int> APositions = new List<int>();
        List<int> BPositions = new List<int>();

        // int LeftIndex=-1;
        int CurrentIndex=0;

        bool XHigher;
        if (x>y)    XHigher=true;   // x: ab
        else        XHigher=false;  // y: ba

        int Total=0;

        // System.Console.WriteLine("ab= "+x+"   ba="+y);
        // Print(APositions, BPositions, Total, CurrentIndex,s);
        //primera ocurrencia

        //1. check current letter

        if (s[CurrentIndex]=='a'){ //==a
            if (XHigher==false){
                if (BPositions.Count>0){
                    BPositions.RemoveAt(BPositions.Count-1);
                    Total+=y;
                }
                else{
                    APositions.Add(CurrentIndex);
                }
            }
            else{
                APositions.Add(CurrentIndex);
            }
        }
        else if (s[CurrentIndex]=='b'){ //==b
            if (XHigher==true){
                if (APositions.Count>0){
                    APositions.RemoveAt(APositions.Count-1);
                    Total+=x;
                }
                else{
                    BPositions.Add(CurrentIndex);
                }
            }
            else{
                BPositions.Add(CurrentIndex);
            }
        }

        // Print(APositions, BPositions, Total, CurrentIndex,s);
        // resto de las ocurrencias

        for (CurrentIndex=1;CurrentIndex<s.Length;CurrentIndex++){

            //1. check current letter

            if (s[CurrentIndex]=='a'){ //==a
                if (XHigher==false){
                    if (BPositions.Count>0){
                        BPositions.RemoveAt(BPositions.Count-1);
                        Total+=y;
                    }
                    else{
                        APositions.Add(CurrentIndex);
                    }
                }
                else{
                    APositions.Add(CurrentIndex);
                }
            }
            else if (s[CurrentIndex]=='b'){ //==b
                if (XHigher==true){
                    if (APositions.Count>0){
                        APositions.RemoveAt(APositions.Count-1);
                        Total+=x;
                    }
                    else{
                        BPositions.Add(CurrentIndex);
                    }
                }
                else{
                    BPositions.Add(CurrentIndex);
                }
            }
            else{
                // Fin de la frase
                if (s[CurrentIndex-1]!='a' && s[CurrentIndex-1]!='b'){

                }
                else{
                    //se termina la frase;
                    int AmountOfSums;
                    if (APositions.Count>BPositions.Count){
                        AmountOfSums=BPositions.Count;
                    }
                    else{
                        AmountOfSums=APositions.Count;
                    }
                    if (XHigher==true){
                        Total+= (AmountOfSums*y);
                    }
                    else{
                        Total+= (AmountOfSums*x);
                    }
                    APositions.Clear();
                    BPositions.Clear();
                }
            }
            // Print(APositions, BPositions, Total, CurrentIndex,s);
        }

        if (s[s.Length-1]=='a' || s[s.Length-1]=='b'){
            //se termina la frase;
            int AmountOfSums;
            if (APositions.Count>BPositions.Count){
                AmountOfSums=BPositions.Count;
            }
            else{
                AmountOfSums=APositions.Count;
            }
            if (XHigher==true){
                Total+= (AmountOfSums*y);
            }
            else{
                Total+= (AmountOfSums*x);
            }
        }


        return Total;
    }
}




}
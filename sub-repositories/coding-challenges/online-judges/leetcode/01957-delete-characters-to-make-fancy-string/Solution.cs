using System;

namespace solution_namespace;

public class Solution {


    public string MakeFancyString(string s) {
        
        System.Text.StringBuilder myBuilder = new System.Text.StringBuilder(s);

        for (int i=0;i< myBuilder.Length;i++){
            if (i>1){
                if (myBuilder[i]==myBuilder[i-1] && myBuilder[i]==myBuilder[i-2]){
                    // remover s[i]
                    int removing_quantity=1;
                    for (int j=i+1;j<myBuilder.Length;j++){
                        if (myBuilder[i]==myBuilder[j]){
                            removing_quantity++;
                        }
                        else{
                            break;
                        }
                    }
                    myBuilder.Remove(i,removing_quantity);


                    i-=removing_quantity;
                }
            }
        }



        return myBuilder.ToString();
    }
}
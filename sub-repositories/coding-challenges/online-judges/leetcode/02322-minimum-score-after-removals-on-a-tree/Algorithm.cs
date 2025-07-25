namespace Algorithm{

// ----- solution starts -----

public class Solution {


    // estructuras
    public struct ExtractedData{
        // int nodeIndex;
        // int xorCalculation;

        // private ExtractedData(int index, int calculation){
        //     this.nodeIndex = index; // nodo conectado al nodo actual (el nodo actual es aquel que posee esta estructura, su indice no se indica por la estructura)
        //     this.xorCalculation =calculation;
        // }

        private int nodeIndex;

        private int xorCalculation;

        public int getNodeIndex(){
            return this.nodeIndex;

        }
        public int getXorCalculation(){
            return this.xorCalculation;
        }


        public void setNodeIndex(int index){
            this.nodeIndex=index;
        }

        public void setXorCalculation(int xorCalculation){
            this.xorCalculation=xorCalculation;
        }

        // public string ToString(){
        //     return ("nodeIndex: "+this.nodeIndex+ "   -   xorCalculation: "+ this.xorCalculation);
        // }
        // private ExtractedData(int index){
        //     nodeIndex = index; // nodo conectado al nodo actual (el nodo actual es aquel que posee esta estructura, su indice no se indica por la estructura)
        //     int xorCalculation;
        // }



    }
    // metodos

    private void printConnections(int[] nums, List<ExtractedData>[] connectedNodes){
        for (int i=0;i<nums.Length;i++){

            System.Console.WriteLine("i: "+ i);

            foreach (ExtractedData _ in connectedNodes[i]){
                System.Console.WriteLine(_.ToString());
            }

            
        }
    }


    private void XorDistribution(int currentNode, int[] nums, int[][] edges, List<ExtractedData>[] connectedNodes,int previousNodeIndex,int sentValue){



        ExtractedData temporalDataRetrieved = new ExtractedData();

        temporalDataRetrieved.setNodeIndex(previousNodeIndex);
        temporalDataRetrieved.setXorCalculation( sentValue);

        // connectedNodes[previousNodeIndex]= new List<ExtractedData>();
        connectedNodes[currentNode].Add(temporalDataRetrieved);



        



        for (int i = 0; i< edges.Length;i++){
            if (currentNode == edges[i][0] && previousNodeIndex != edges[i][1]){
                
                int sentTotal=nums[currentNode];

                foreach(ExtractedData _ in connectedNodes[currentNode]){
                    if ( _.getNodeIndex() != edges[i][1]){
                        sentTotal = sentTotal ^ _.getXorCalculation();
                    }
                }

                XorDistribution(edges[i][1], nums, edges, connectedNodes, currentNode, sentTotal);

            }

            else if (currentNode == edges[i][1] && previousNodeIndex != edges[i][0]){

                int sentTotal=nums[currentNode];

                foreach(ExtractedData _ in connectedNodes[currentNode]){
                    if ( _.getNodeIndex() != edges[i][0]){
                        sentTotal = sentTotal ^ _.getXorCalculation();
                    }
                }

                XorDistribution(edges[i][0], nums, edges, connectedNodes, currentNode, sentTotal);
            }



        }


    }



    private int XorExtraction(int currentNode, int[] nums, int[][] edges, List<ExtractedData>[] connectedNodes,int previousNodeIndex){

        int total = 0;

        for (int i =0; i< edges.Length;i++){
            if (currentNode == edges[i][0] && previousNodeIndex != edges[i][1]){
                //si el nodo inicial esta conectado a alguno, comenzar a extraer XOR values;

                //anadir los nodos conectados al nodo actual a este array.
                ExtractedData temporalDataRetrieved = new ExtractedData();
                temporalDataRetrieved.setNodeIndex(edges[i][1]);
                temporalDataRetrieved.setXorCalculation( XorExtraction(edges[i][1], nums, edges, connectedNodes, currentNode));

                // connectedNodes[currentNode].Add(temporalDataRetrieved);

                total= total ^ temporalDataRetrieved.getXorCalculation();
                
            }

            else if (currentNode == edges[i][1] && previousNodeIndex != edges[i][0]){

                ExtractedData temporalDataRetrieved = new ExtractedData();
                temporalDataRetrieved.setNodeIndex(edges[i][0]);
                temporalDataRetrieved.setXorCalculation( XorExtraction(edges[i][0], nums, edges, connectedNodes, currentNode));

                // connectedNodes[currentNode].Add(temporalDataRetrieved);

                total= total ^ temporalDataRetrieved.getXorCalculation();
            }


        }

        //calculate return value
        total = total ^ nums[currentNode];

        ExtractedData temporalDataRetrieved3 = new ExtractedData();

        temporalDataRetrieved3.setNodeIndex(currentNode);
        temporalDataRetrieved3.setXorCalculation( total);

        // connectedNodes[previousNodeIndex]= new List<ExtractedData>();
        connectedNodes[previousNodeIndex].Add(temporalDataRetrieved3);


        return total;
    }


    private void XorCalculation(int[] nums, int[][] edges, List<ExtractedData>[] connectedNodes){



        // - - - - - EXTRACT PROCESS - - - - -

        // recolectar XOR de todos los nodos
        int currentNode= 0;




        int total = 0;

        for (int i =0; i< edges.Length;i++){
            if (currentNode == edges[i][0] ){
                //si el nodo inicial esta conectado a alguno, comenzar a extraer XOR values;

                //anadir los nodos conectados al nodo actual a este array.
                ExtractedData temporalDataRetrieved = new ExtractedData();
                temporalDataRetrieved.setNodeIndex(edges[i][1]);
                temporalDataRetrieved.setXorCalculation( XorExtraction(edges[i][1], nums, edges, connectedNodes, currentNode));

                // connectedNodes[currentNode].Add(temporalDataRetrieved);

                total= total ^ temporalDataRetrieved.getXorCalculation();
                
            }

            else if (currentNode == edges[i][1] ){

                ExtractedData temporalDataRetrieved = new ExtractedData();
                temporalDataRetrieved.setNodeIndex(edges[i][0]);
                temporalDataRetrieved.setXorCalculation( XorExtraction(edges[i][0], nums, edges, connectedNodes, currentNode));

                // connectedNodes[currentNode].Add(temporalDataRetrieved);

                total= total ^ temporalDataRetrieved.getXorCalculation();
            }


        }

        //calculate return value
        total = total ^ nums[currentNode];

        ExtractedData temporalDataRetrieved3 = new ExtractedData();

        temporalDataRetrieved3.setNodeIndex(currentNode);
        temporalDataRetrieved3.setXorCalculation( total);

        // connectedNodes[previousNodeIndex].Add(temporalDataRetrieved3);

        // System.Console.WriteLine("----- extract finished -----");
        // printConnections(nums,connectedNodes);
        // System.Console.WriteLine("\n----- distribution finished -----");

        // - - - - - DISTRIBUTION PROCESS - - - - -


        for (int i = 0; i< edges.Length;i++){
            if (currentNode == edges[i][0] ){
                
                int sentTotal=nums[currentNode];

                foreach(ExtractedData _ in connectedNodes[currentNode]){
                    if ( _.getNodeIndex() != edges[i][1]){
                        sentTotal = sentTotal ^ _.getXorCalculation();
                    }
                }

                XorDistribution(edges[i][1], nums, edges, connectedNodes, currentNode,sentTotal);

            }

            else if (currentNode == edges[i][1] ){

                int sentTotal=nums[currentNode];

                foreach(ExtractedData _ in connectedNodes[currentNode]){
                    if ( _.getNodeIndex() != edges[i][0]){
                        sentTotal = sentTotal ^ _.getXorCalculation();
                    }
                }

                XorDistribution(edges[i][0], nums, edges, connectedNodes, currentNode,sentTotal);
            }



        }



    }   

    private int encontrarNodo(int indexCurrentNode, int brokenEdge, List<ExtractedData>[] connectedNodes,int posibleNodo1, int posibleNodo2){

        // System.Console.WriteLine("--- encontrando nodo ---");
        // System.Console.WriteLine("--- currentnodo: "+indexCurrentNode+ "  brokenEdge: "+brokenEdge+"  posibleNodos: "+posibleNodo1+"  "+posibleNodo2);

        for (int i =0; i< connectedNodes[indexCurrentNode].Count;i++){

            if (connectedNodes[indexCurrentNode][i].getNodeIndex() != brokenEdge){

                if (connectedNodes[indexCurrentNode][i].getNodeIndex() ==posibleNodo1) {
                    // System.Console.WriteLine("--- encontrado! returning 2   (("+ posibleNodo1);
                    return 2;
                }
                else if (connectedNodes[indexCurrentNode][i].getNodeIndex() ==posibleNodo2) {
                    // System.Console.WriteLine("--- encontrado! returning 3   (("+ posibleNodo2);
                    return 3;
                }
                else {
                    // System.Console.WriteLine("--- ");
                    int nodoEncontrado= encontrarNodo(connectedNodes[indexCurrentNode][i].getNodeIndex(), indexCurrentNode, connectedNodes, posibleNodo1, posibleNodo2);
                    if (nodoEncontrado!= -1){
                        
                        return nodoEncontrado;
                    }
                    
                }
                
            }


        }
        // System.Console.WriteLine("--- no encontrado... -1");
        return -1;

    }


    //metodo principal

    public int MinimumScore(int[] nums, int[][] edges) {
        

        //calculo de xor en cada nodo/edge de nuestro mapa
        List<ExtractedData>[] connectedNodes = new List<ExtractedData>[nums.Length];
        for (int i =0;i<nums.Length;i++){
            connectedNodes[i] = new List<ExtractedData>();
        }

        // printConnections();

        XorCalculation(nums, edges, connectedNodes);

        // printConnections(nums,connectedNodes);

        //calculo de xor final

        //int currentValue;
        int minorValue=100000000;

        for (int i =0; i<edges.Length-1;i++){

            for (int j=i+1; j<edges.Length;j++){
                // por cada par de edges roto.

                


                int[] nodo = new int[4];

                nodo[0]= edges[i][0];
                nodo[1]= edges[i][1];
                nodo[2]= edges[j][0];
                nodo[3]= edges[j][1];

                int indexEncontrado=2;

                //encontrar las 3 islas

                if (nodo[0]==nodo[2]) {
                    indexEncontrado=2;
                    // System.Console.WriteLine("\n*   nodo: "+nodo[0] +" conectado a nodo: "+nodo[2]);
                }
                else if (nodo[0]==nodo[3]) {
                    indexEncontrado=3;
                    // System.Console.WriteLine("\n*   nodo: "+nodo[0] +" conectado a nodo: "+nodo[3]);
                }
                else {
                    indexEncontrado=encontrarNodo(nodo[0], nodo[1], connectedNodes, nodo[2], nodo[3]);
                    if (indexEncontrado==2){
                        // System.Console.WriteLine("\n*   nodo: "+nodo[0] +" conectado a nodo: "+nodo[2]);
                    }
                    else if (indexEncontrado==3){
                        // System.Console.WriteLine("\n*   nodo: "+nodo[0] +" conectado a nodo: "+nodo[3]);
                    }
                }



                int[] valores = new int[3];

                if (indexEncontrado== 2 ){ //nodo 0 conectado a nodo 2

                    // System.Console.WriteLine(connectedNodes[nodo[1]].Count);

                    for (int k=0;k<connectedNodes[nodo[0]].Count;k++){
                        if (connectedNodes[nodo[0]][k].getNodeIndex()==nodo[1]){
                            valores[0]=connectedNodes[nodo[0]][k].getXorCalculation();
                            break;
                        }
                        

                    }


                    for (int k=0;k<connectedNodes[nodo[2]].Count;k++){
                        if (connectedNodes[nodo[2]][k].getNodeIndex()==nodo[3]){
                            valores[1]=connectedNodes[nodo[2]][k].getXorCalculation();

                            break;
                        }

                    }

                    for (int k=0;k<connectedNodes[nodo[1]].Count;k++){
                        // System.Console.WriteLine("hola   ");
                        if (connectedNodes[nodo[1]][k].getNodeIndex()==nodo[0]){
                            valores[2]=connectedNodes[nodo[1]][k].getXorCalculation();
                            valores[2]=valores[2] ^ valores[1];

                            break;
                        }

                    }

                }
                else if (indexEncontrado ==3){ //nodo 0 conectado a nodo 3

                    for (int k=0;k<connectedNodes[nodo[0]].Count;k++){
                        if (connectedNodes[nodo[0]][k].getNodeIndex()==nodo[1]){
                            valores[0]=connectedNodes[nodo[0]][k].getXorCalculation();
                            break;
                        }

                    }


                    for (int k=0;k<connectedNodes[nodo[3]].Count;k++){
                        if (connectedNodes[nodo[3]][k].getNodeIndex()==nodo[2]){
                            valores[1]=connectedNodes[nodo[3]][k].getXorCalculation();

                            break;
                        }

                    }

                    for (int k=0;k<connectedNodes[nodo[1]].Count;k++){
                        // System.Console.WriteLine("hola   ");
                        if (connectedNodes[nodo[1]][k].getNodeIndex()==nodo[0]){
                            valores[2]=connectedNodes[nodo[1]][k].getXorCalculation();
                            valores[2]=valores[2] ^ valores[1];

                            break;
                        }

                    }

                }

                else{ // nodo 1 conectado a 2 o 3
                    if (nodo[1]==nodo[2]) {
                        indexEncontrado=2;
                        // System.Console.WriteLine("\n*   nodo: "+nodo[1] +" conectado a nodo: "+nodo[2]);
                    }
                    else if (nodo[1]==nodo[3]) {
                        indexEncontrado=3;
                        // System.Console.WriteLine("\n*   nodo: "+nodo[1] +" conectado a nodo: "+nodo[3]);
                    }
                    else {
                        indexEncontrado=encontrarNodo(nodo[1], nodo[0], connectedNodes, nodo[2], nodo[3]);
                        if (indexEncontrado==2){
                            // System.Console.WriteLine("\n*   nodo: "+nodo[1] +" conectado a nodo: "+nodo[2]);
                        }
                        else if (indexEncontrado==3){
                            // System.Console.WriteLine("\n*   nodo: "+nodo[1] +" conectado a nodo: "+nodo[3]+" alababa");
                        }
                    }

                    // System.Console.WriteLine("re - index encontrado: "+indexEncontrado);


                    if (indexEncontrado== 2 ){ //nodo 1 conectado a nodo 2

                        //System.Console.WriteLine(connectedNodes[nodo[1]].Count);

                        for (int k=0;k<connectedNodes[nodo[1]].Count;k++){
                            if (connectedNodes[nodo[1]][k].getNodeIndex()==nodo[0]){
                                // System.Console.WriteLine("conseguido valor xor: "+connectedNodes[nodo[1]][k].getXorCalculation());
                                valores[0]=connectedNodes[nodo[1]][k].getXorCalculation();
                                break;
                            }
                            
                        }


                        for (int k=0;k<connectedNodes[nodo[2]].Count;k++){
                            if (connectedNodes[nodo[2]][k].getNodeIndex()==nodo[3]){
                                // System.Console.WriteLine("conseguido valor xor: "+connectedNodes[nodo[2]][k].getXorCalculation());
                                valores[1]=connectedNodes[nodo[2]][k].getXorCalculation();
                                break;
                            }

                        }

                        for (int k=0;k<connectedNodes[nodo[0]].Count;k++){
                            // System.Console.WriteLine("hola   ");
                            if (connectedNodes[nodo[0]][k].getNodeIndex()==nodo[1]){
                                valores[2]=connectedNodes[nodo[0]][k].getXorCalculation();
                                valores[2]=valores[2] ^ valores[1];

                                break;
                            }

                        }

                    }
                    else if (indexEncontrado ==3){ //nodo 1 conectado a nodo 3

                        for (int k=0;k<connectedNodes[nodo[1]].Count;k++){
                            if (connectedNodes[nodo[1]][k].getNodeIndex()==nodo[0]){
                                valores[0]=connectedNodes[nodo[1]][k].getXorCalculation();
                                break;
                            }
                            
                        }


                        for (int k=0;k<connectedNodes[nodo[3]].Count;k++){
                            if (connectedNodes[nodo[3]][k].getNodeIndex()==nodo[2]){
                                valores[1]=connectedNodes[nodo[3]][k].getXorCalculation();

                                break;
                            }

                        }

                        for (int k=0;k<connectedNodes[nodo[0]].Count;k++){
                            // System.Console.WriteLine("hola   ");
                            if (connectedNodes[nodo[0]][k].getNodeIndex()==nodo[1]){
                                valores[2]=connectedNodes[nodo[0]][k].getXorCalculation();
                                valores[2]=valores[2] ^ valores[1];

                                break;                            
                            }

                        }

                    }







                }

                // System.Console.WriteLine("   |   valor0: "+valores[0]+"   |   valor1: "+valores[1]+"   |   valor2: "+valores[2]);

                int mayor = valores[0];
                int menor = valores[0];
                if (valores[1]>valores[0]){
                    mayor=valores[1];
                }
                else{
                    menor=valores[1];
                }

                if (valores[2]>mayor){
                    mayor=valores[2];
                }
                else if (valores[2]<menor){
                    menor=valores[2];
                }
                int currentValue=mayor-menor;

                if (currentValue < minorValue){
                    minorValue=currentValue;
                    // System.Console.WriteLine(" - nuevo minimo: "+minorValue);
                }

                // System.Console.WriteLine("- - - - -\n\n");
            }


        }



        return minorValue;
    }
}




// ----- solution ends -----

}
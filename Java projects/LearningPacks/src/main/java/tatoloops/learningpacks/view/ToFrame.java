package tatoloops.learningpacks.view;

import java.awt.Color;
import javax.swing.JLabel;
import javax.swing.JLayeredPane;

public class ToFrame {
    public static void ToFrame(String title,MatrixCell[][] matrix){
        JLayeredPane pane=new JLayeredPane();
        int heightInLabels=MatrixCell.getHeightInLabels();
        int heightInCells=MatrixCell.getHeightInCells();
        int width=MatrixCell.getWidthInCells();
        
        int labelWidth=256;
        int labelHeight=16;
        int spaceBetweenCells=8;
        
        int cellHeight=labelHeight*MatrixCell.getMaxLabelsPerCell();
        
        
        JLabel backgroundLabel=new JLabel();
        backgroundLabel.setBackground(Color.BLACK);
        backgroundLabel.setForeground(Color.white);
        backgroundLabel.setOpaque(true);
        pane.add(backgroundLabel, Integer.valueOf(0));
                    
        JLabel[][] myLabel = new JLabel[heightInLabels][width];
        //System.out.println("maxlabeslpercell: "+MatrixCell.getMaxLabelsPerCell());
        
        for (int j=0;j<heightInCells;j++){
            //System.out.println("j");
            for (int i=0;i<width;i++){
                //System.out.println("i");
                for(int tempA=0;tempA<MatrixCell.getMaxLabelsPerCell();tempA++){
                
                    //System.out.println("i: "+i+"   j: "+j + "  tempA: "+ tempA);
                    
                    int labelRow=j*2+tempA;
                    
                    int boxTop=(j)*(spaceBetweenCells+cellHeight)+spaceBetweenCells+tempA*labelHeight;
                    int boxLeft=i*(labelWidth+spaceBetweenCells)+spaceBetweenCells;
                    //System.out.println("boxTop: "+boxTop);
                    //System.out.println("boxLeft: "+boxLeft);
                    //System.out.println("j: "+j + "  i: "+i);
                    myLabel[labelRow][i] = new JLabel(matrix[j][i].getLine(tempA));
                    //System.out.println("a");
                    myLabel[labelRow][i].setBounds(boxLeft,boxTop, labelWidth, labelHeight);
                    //System.out.println("b");

                    // Add the JTextArea to your container (e.g., a JPanel or JFrame)

                    myLabel[labelRow][i].setBackground(Color.BLACK);
                    myLabel[labelRow][i].setForeground(Color.white);
                    //System.out.println("c");
                    myLabel[labelRow][i].setOpaque(true);
                    //System.out.println("d");
                    pane.add(myLabel[labelRow][i], Integer.valueOf(1));
                    //System.out.println("e");
                }
            }
        }
        
        //pane.
        int frameWidth=width*(labelWidth+spaceBetweenCells)+spaceBetweenCells;
        //System.out.println("frameWidth: "+ frameWidth);
        int frameHeight=spaceBetweenCells+(spaceBetweenCells+cellHeight)*heightInCells;
        //System.out.println("frameHeight: "+ frameHeight);
        
        
        Frame myFrame= new Frame(title, pane,frameWidth,frameHeight);
        
    }
}

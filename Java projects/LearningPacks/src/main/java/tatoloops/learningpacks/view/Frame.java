package tatoloops.learningpacks.view;

import java.awt.Color;
import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JLayeredPane;
import javax.swing.JLabel;

public class Frame {
    private JFrame myFrame;
    private ImageIcon icon;
    //private JLayeredPane paneMain;
    //public Frame (){ 
    //}
    public Frame(String title,JLayeredPane paneMain,int rawFrameWidth,int rawFrameHeight){
        //System.out.println("holaaa");
        
        int xOffset = 16;
        int yOffset = 38;
        
        int myFrameWidth= rawFrameWidth+xOffset;
        int myFrameHeight= rawFrameHeight+yOffset;

        this.myFrame = new JFrame();
        this.myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.myFrame.setTitle(title);
        this.myFrame.setResizable(false);
        
        this.myFrame.setSize(myFrameWidth,myFrameHeight);

        this.icon = new ImageIcon(FrameInformation.getICON_PATH());
        this.myFrame.setIconImage(this.icon.getImage());
        
        paneMain.setBounds(0, 0, myFrameWidth, myFrameHeight);
        this.myFrame.setLayout(null);
        this.myFrame.add(paneMain);
        this.myFrame.setVisible(true);
        this.myFrame.setEnabled(true);
    } 
    public void setSize (){
        
    }
}

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
        
        //int myFrameWidth=1000;
        //int myFrameHeight=1000;
        //String myFrameBackground = "#000000";
        
        this.myFrame = new JFrame();
        this.myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.myFrame.setTitle(title);
        this.myFrame.setResizable(false);
        
        this.myFrame.setSize(myFrameWidth,myFrameHeight);
        
        //this.myFrame.setBackground(Color.decode("#000000"));
        //this.myFrame.getContentPane().setBackground( Color.decode(myFrameBackground));
        //icons icon = new icons();
          
        this.icon = new ImageIcon(FrameInformation.getICON_PATH());
        this.myFrame.setIconImage(this.icon.getImage());
        
        
        //this.paneMain = new JLayeredPane();
        //layout null
        
        //modelado02(paneMain);
        
        /*
        
        
        
        //this.paneMain.setSize(myFrameWidth, myFrameHeight);
        
        //UI
        JLabel label01= new JLabel();
        label01.setBounds(0, 0, myFrameWidth, myFrameHeight);
        label01.setBackground(Color.BLACK);
        label01.setOpaque(true);
        this.paneMain.add(label01, Integer.valueOf(1));
        //1
        JLabel label02= new JLabel();
        label02.setBounds(10, 10, 100, 100);
        label02.setBackground(Color.BLUE);
        label02.setOpaque(true);
        this.paneMain.add(label02, Integer.valueOf(2));
        
        JLabel label03= new JLabel();
        label03.setBounds(50, 50, 100, 100);
        label03.setBackground(Color.PINK);
        label03.setOpaque(true);
        paneMain.add(label03, Integer.valueOf(3));
        */
        paneMain.setBounds(0, 0, myFrameWidth, myFrameHeight);
        this.myFrame.setLayout(null);
        this.myFrame.add(paneMain);
        this.myFrame.setVisible(true);
        this.myFrame.setEnabled(true);
    } 
    public void setSize (){
        
    }
}

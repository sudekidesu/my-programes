import java.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class q2 extends JFrame {
    JFrame ran;
    JLabel l;
    JButton b1,b2,b3;
    q2() {
        ran=new JFrame();
        ran.setSize(400,300);
        ran.setLayout(null);
        ran.setVisible(true);
        ran.setResizable(false);
        ran.setTitle("Random");
        ran.addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });
        b1=new JButton();
        b1.setBounds()
    }
    public static void main(String[] args) {
        new q2();
    }
}

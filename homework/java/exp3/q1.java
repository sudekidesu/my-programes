import java.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class q1 extends JComponent {
    JFrame cal;
    JLabel l1,l2;
    JTextField t1,t2,t3;
    JButton b1,b2,b3,b4;
    q1() {
        cal=new JFrame();
        cal.setSize(400,300);
        cal.setLayout(null);
        cal.setVisible(true);
        cal.setResizable(false);
        cal.setTitle("cal");
        cal.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                super.windowClosing(e);
                System.exit(0);
            }
        });
        l1=new JLabel();
        cal.add(l1);
        l1.setBounds(30,60,100,10);
        l1.setVisible(true);
        l1.setText("Tow numbers:");
        l2=new JLabel();
        cal.add(l2);
        l2.setBounds(30,130,100,10);
        l2.setVisible(true);
        l2.setText("The answer is:");
        t1=new JTextField();
        cal.add(t1);
        t1.setBounds(150,50,80,40);
        t1.setVisible(true);
        t2=new JTextField();
        cal.add(t2);
        t2.setBounds(250,50,80,40);
        t2.setVisible(true);
        t3=new JTextField();
        cal.add(t3);
        t3.setBounds(150,120,180,40);
        t3.setVisible(true);
        b1=new JButton();
        cal.add(b1);
        b1.setBounds(30,190,70,40);
        b1.setText("+");
        b1.setVisible(true);
        b2=new JButton();
        cal.add(b2);
        b2.setBounds(110,190,70,40);
        b2.setText("-");
        b2.setVisible(true);
        b3=new JButton();
        cal.add(b3);
        b3.setBounds(190,190,70,40);
        b3.setText("*");
        b3.setVisible(true);
        b4=new JButton();
        cal.add(b4);
        b4.setBounds(270,190,70,40);
        b4.setText("/");
        b4.setVisible(true);
        b1.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String a=t1.getText();
                String b=t2.getText();
                double ans=(double)Integer.parseInt(a)+(double)Integer.parseInt(b);
                t3.setText(String.valueOf(ans));
            }
        });
        b2.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String a=t1.getText();
                String b=t2.getText();
                double ans=(double)Integer.parseInt(a)-(double)Integer.parseInt(b);
                t3.setText(String.valueOf(ans));
            }
        });
        b3.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String a=t1.getText();
                String b=t2.getText();
                double ans=(double)Integer.parseInt(a)*(double)Integer.parseInt(b);
                t3.setText(String.valueOf(ans));
            }
        });
        b4.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                String a=t1.getText();
                String b=t2.getText();
                double ans=(double)Integer.parseInt(a)/(double)Integer.parseInt(b);
                t3.setText(String.valueOf(ans));
            }
        });
    }
    public static void main(String[] args) {
        new q1();
    }
}

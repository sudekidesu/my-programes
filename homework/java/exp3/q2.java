import java.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
class ranname extends JFrame implements ActionListener {
    JFrame ran;
    JLabel l;
    JButton b1,b2,b3;
    int num=0;
    String [] names={"    GodQi","    ShijieQi","  QiShijie","  ShijieGod","   ShijieQ","     lyl","LiuYuanlong","   LiuyueL"};
    int namenumber=8;
    Timer time;
    ranname() {
        time=new Timer(20,this);
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
        b1.setBounds(70,20,70,40);
        b1.setText("start");
        b1.setVisible(true);
        b1.addActionListener(this);
        ran.add(b1);
        b2=new JButton();
        b2.setBounds(160,20,70,40);
        b2.setText("pause");
        b2.setVisible(true);
        b2.addActionListener(this);
        ran.add(b2);
        b3=new JButton();
        b3.setBounds(250,20,70,40);
        b3.setText("continue");
        b3.setVisible(true);
        b3.addActionListener(this);
        ran.add(b3);
        l=new JLabel();
        l.setBounds(40,-10,400,300);
        l.setText(names[0]);
        l.setFont(new Font("Times New Roman",Font.BOLD,58));
        l.setVisible(true);
        ran.add(l);
    }
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==time) {
            l.setText(names[num++]);
            num%=namenumber;
        }
        else if(e.getSource()==b1)
            time.start();
        else if(e.getSource()==b2)
            time.stop();
        else if(e.getSource()==b3)
            time.restart();
    }
}
class q2 {
    public static void main(String[] args) {
        ranname r=new ranname();
    }
}

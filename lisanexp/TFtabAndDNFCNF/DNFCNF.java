import java.util.*;
import java.math.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.applet.AudioClip;
import java.io.*;
import java.applet.Applet;
import java.net.MalformedURLException;
import java.net.URI;
import java.net.URL;

//////////////////////////////////////

//贪吃蛇部分网上嫖的，网址：https://www.cnblogs.com/journal-of-xjx/p/7173863.html?utm_source=itdadao&utm_medium=referral

import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.io.IOException;
import java.util.Random;
import javax.sound.sampled.*;
import javax.swing.*;

class Tile{
    int x;
    int y;

    public Tile(int x0,int y0){
        x = x0;
        y = y0;
    }
}

class SnakeDemo extends JComponent{
    private static final long serialVersionUID = 3794762291171148906L;
    private final int MAX_SIZE = 400;
    private Tile temp = new Tile(0,0);
    private Tile temp2 = new Tile(0,0);
    private Tile head = new Tile(227,100);
    private Tile[] body = new Tile[MAX_SIZE];
    private String direction = "R";
    private String current_direction = "R";
    private boolean first_launch = false;
    private boolean iseaten = false;
    private boolean isrun = true;
    private int randomx,randomy;
    private int body_length = 5;
    private Thread run;
    private JLabel label = new JLabel("length:");
    private JLabel label2 = new JLabel("time:");
    private JLabel label3 = new JLabel();
    private JTextArea explain = new JTextArea();
    private JLabel Score = new JLabel("6");
    private JLabel Time = new JLabel("");
    private Font f = new Font("微软雅黑",Font.PLAIN,15);
    private Font f2 = new Font("微软雅黑",Font.PLAIN,13);
    private JPanel p = new JPanel();
    private int hour =0;
    private int min =0;
    private int sec =0 ;
    private boolean pause = false;

    public SnakeDemo(){
        String lookAndFeel =UIManager.getSystemLookAndFeelClassName();
        try {
            UIManager.setLookAndFeel(lookAndFeel);
        } catch (ClassNotFoundException e1) {
            e1.printStackTrace();
        } catch (InstantiationException e1) {
            e1.printStackTrace();
        } catch (IllegalAccessException e1) {
            e1.printStackTrace();
        } catch (UnsupportedLookAndFeelException e1) {
            e1.printStackTrace();
        }

        add(label);
        label.setBounds(500, 10, 80, 20);
        label.setFont(f);
        add(Score);
        Score.setBounds(500, 35, 80, 20);
        Score.setFont(f);
        add(label2);
        label2.setBounds(500, 60, 80, 20);
        label2.setFont(f);
        add(Time);
        Time.setBounds(500, 85, 80, 20);
        Time.setFont(f);
        add(p);
        p.setBounds(498, 110, 93, 1);
        p.setBorder(BorderFactory.createLineBorder(Color.black));

        add(label3);
        label3.setBounds(500, 115, 80, 20);
        label3.setFont(f);
        add(explain);
        explain.setBounds(498, 138, 100, 350);
        explain.setFont(f2);
        explain.setLineWrap(true);
        explain.setOpaque(false);

        for(int i = 0; i < MAX_SIZE;i++)
        {
            body[i] = new Tile(0,0);
        }

        addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                super.keyPressed(e);
                if(e.getKeyCode() == KeyEvent.VK_RIGHT)
                {
                    if(isrun && current_direction != "L")
                    {
                        direction = "R";
                    }
                }
                if(e.getKeyCode() == KeyEvent.VK_LEFT)
                {
                    if(isrun && current_direction != "R")
                    {
                        direction = "L";
                    }
                }
                if(e.getKeyCode() == KeyEvent.VK_UP)
                {
                    if(isrun && current_direction != "D")
                    {
                        direction = "U";
                    }
                }
                if(e.getKeyCode() == KeyEvent.VK_DOWN)
                {
                    if(isrun && current_direction != "U")
                    {
                        direction = "D";
                    }
                }
                if(e.getKeyCode() == KeyEvent.VK_ESCAPE)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int i = 0; i < MAX_SIZE;i++)
                    {
                        body[i].x = 0;
                        body[i].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                if(e.getKeyCode() == KeyEvent.VK_SPACE)
                {
                    if(!pause)
                    {
                        pause = true;
                        isrun = false;
                    }
                    else
                    {
                        pause = false;
                        isrun = true;
                    }
                }
            }
        });

        new Timer();

        setFocusable(true);
    }

    public void paintComponent(Graphics g1){
        super.paintComponent(g1);
        Graphics2D g = (Graphics2D) g1;
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING,RenderingHints.VALUE_ANTIALIAS_ON);
        g.setRenderingHint(RenderingHints.KEY_STROKE_CONTROL,RenderingHints.VALUE_STROKE_NORMALIZE);

        g.setColor(Color.red);
        g.fillRoundRect(head.x, head.y, 20, 20, 10, 10);

        g.setPaint(new GradientPaint(115,135,Color.CYAN,230,135,Color.MAGENTA,true));
        if(!first_launch)
        {
            int x = head.x;
            for(int i = 0;i < body_length;i++)
            {
                x -= 22;
                body[i].x = x;
                body[i].y = head.y;
                g.fillRoundRect(body[i].x, body[i].y, 20, 20, 10, 10);
            }
            ProduceRandom();
            g.fillOval(randomx, randomy, 19, 19);
        }
        else
        {
            for(int i = 0;i < body_length;i++)
            {
                g.fillRoundRect(body[i].x, body[i].y, 20, 20, 10, 10);
            }

            if(EatFood())
            {
                ProduceRandom();
                g.fillOval(randomx, randomy, 19, 19);
                iseaten = false;
            }
            else
            {
                g.fillOval(randomx, randomy, 19, 19);
            }
        }
        first_launch = true;
        g.setStroke( new BasicStroke(4,BasicStroke.CAP_BUTT,BasicStroke.JOIN_BEVEL));
        g.setBackground(Color.black);
        g.drawRect(2, 7, 491, 469);

        for(int i = 1;i < 22;i++)
        {
            g.setStroke( new BasicStroke(1,BasicStroke.CAP_BUTT,BasicStroke.JOIN_BEVEL));
            g.setColor(Color.black);
            g.drawLine(5+i*22,9,5+i*22,472);
            if(i <= 20)
            {
                g.drawLine(4,10+i*22,491,10+i*22);
            }
        }
    }

    public void ProduceRandom(){
        boolean flag = true;
        Random rand = new Random();
        randomx = (rand.nextInt(21) + 1) * 22 + 7;
        randomy = (rand.nextInt(20) + 1) *22 + 12;
        while(flag)
        {
            for(int i = 0;i < body_length; i++)
            {
                if(body[i].x == randomx && body[i].y == randomy)
                {
                    randomx = (rand.nextInt(21) + 1) * 22 + 7;
                    randomy = (rand.nextInt(20) + 1) *22 + 12;
                    flag = true;
                    break;
                }
                else
                {
                    if(i == body_length - 1)
                    {
                        flag = false;
                    }
                }
            }
        }
    }

    public void HitWall(){
        if(current_direction == "L")
        {
            if(head.x < 7)
            {
                new AePlayWave("over.wav").start();
                isrun = false;
                int result=JOptionPane.showConfirmDialog(null, "Game over! Try again?", "Information", JOptionPane.YES_NO_OPTION);
                if(result==JOptionPane.YES_NO_OPTION)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int i = 0; i < MAX_SIZE;i++)
                    {
                        body[i].x = 0;
                        body[i].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                else
                {
                    run.stop();
                }
            }
        }
        if(current_direction == "R")
        {
            if(head.x > 489)
            {
                new AePlayWave("over.wav").start();
                isrun = false;
                int result=JOptionPane.showConfirmDialog(null, "Game over! Try again?", "Information", JOptionPane.YES_NO_OPTION);
                if(result==JOptionPane.YES_NO_OPTION)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int i = 0; i < MAX_SIZE;i++)
                    {
                        body[i].x = 0;
                        body[i].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                else
                {
                    run.stop();
                }
            }
        }
        if(current_direction == "U")
        {
            if(head.y < 12)
            {
                new AePlayWave("over.wav").start();
                isrun = false;
                int result=JOptionPane.showConfirmDialog(null, "Game over! Try again?", "Information", JOptionPane.YES_NO_OPTION);
                if(result==JOptionPane.YES_NO_OPTION)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int i = 0; i < MAX_SIZE;i++)
                    {
                        body[i].x = 0;
                        body[i].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                else
                {
                    run.stop();
                }
            }
        }
        if(current_direction == "D")
        {
            if(head.y > 472)
            {
                new AePlayWave("over.wav").start();
                isrun = false;
                int result=JOptionPane.showConfirmDialog(null, "Game over! Try again?", "Information", JOptionPane.YES_NO_OPTION);
                if(result==JOptionPane.YES_NO_OPTION)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int i = 0; i < MAX_SIZE;i++)
                    {
                        body[i].x = 0;
                        body[i].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                else
                {
                    run.stop();
                }
            }
        }
    }

    public void HitSelf(){
        for(int i = 0;i < body_length; i++)
        {
            if(body[i].x == head.x && body[i].y == head.y)
            {
                new AePlayWave("over.wav").start();
                isrun = false;
                int result=JOptionPane.showConfirmDialog(null, "Game over! Try again?", "Information", JOptionPane.YES_NO_OPTION);
                if(result==JOptionPane.YES_NO_OPTION)
                {
                    direction = "R";
                    current_direction = "R";
                    first_launch = false;
                    iseaten = false;
                    isrun = true;
                    body_length = 5;
                    head = new Tile(227,100);
                    Score.setText("6");
                    hour =0;
                    min =0;
                    sec =0 ;
                    for(int j = 0; j < MAX_SIZE;j++)
                    {
                        body[j].x = 0;
                        body[j].y = 0;
                    }

                    run = new Thread();
                    run.start();
                    System.out.println("Start again");
                }
                else
                {
                    run.stop();
                }
                break;
            }
        }
    }

    public boolean  EatFood(){
        if(head.x == randomx && head.y == randomy)
        {
            iseaten = true;
            return true;
        }
        else
        {
            return false;
        }
    }

    public void Thread(){
        long millis = 300;
        run = new Thread() {
            public void run() {
                while (true)
                {
                    try {
                        Thread.sleep(millis);
                    } catch (InterruptedException ex) {
                        ex.printStackTrace();
                    }

                    if(!pause)
                    {
                        temp.x = head.x;
                        temp.y = head.y;
                        if(direction == "L")
                        {
                            head.x -= 22;
                        }
                        if(direction == "R")
                        {
                            head.x += 22;
                        }
                        if(direction == "U")
                        {
                            head.y -= 22;
                        }
                        if(direction == "D")
                        {
                            head.y += 22;
                        }
                        current_direction = direction;
                        for(int i = 0;i < body_length;i++)
                        {
                            temp2.x = body[i].x;
                            temp2.y = body[i].y;
                            body[i].x = temp.x;
                            body[i].y = temp.y;
                            temp.x = temp2.x;
                            temp.y = temp2.y;
                        }

                        if(EatFood())
                        {
                            body_length ++;
                            body[body_length-1].x = temp2.x;
                            body[body_length-1].y = temp2.y;
                            Score.setText("" + (body_length+1) );
                            new AePlayWave("eat.wav").start();
                        }

                        repaint();

                        HitWall();
                        HitSelf();
                    }
                }
            }
        };

        run.start();
    }

    static void SNAKE() {
        SnakeDemo t = new SnakeDemo();
        t.Thread();

        JFrame game = new JFrame();
        Image img=Toolkit.getDefaultToolkit().getImage("title.png");//窗口图标
        game.setIconImage(img);
        game.setTitle("Snake By XJX");
        game.setSize(602, 507);
        game.setResizable(false);
        game.setLocationRelativeTo(null);
        game.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        game.add(t);
        game.setVisible(true);
    }

    class Timer extends Thread{
            public Timer(){
                this.start();
            }
            @Override
            public void run() {
                while(true){
                    if(isrun){
                        sec +=1 ;
                        if(sec >= 60){
                            sec = 0;
                            min +=1 ;
                        }
                        if(min>=60){
                            min=0;
                            hour+=1;
                        }
                        showTime();
                    }

                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }

                }
            }

            private void showTime(){
                String strTime ="" ;
                if(hour < 10)
                    strTime = "0"+hour+":";
                else
                    strTime = ""+hour+":";

                if(min < 10)
                    strTime = strTime+"0"+min+":";
                else
                    strTime =strTime+ ""+min+":";

                if(sec < 10)
                    strTime = strTime+"0"+sec;
                else
                    strTime = strTime+""+sec;

                Time.setText(strTime);
            }
        }
}

class AePlayWave extends Thread {
    private String filename;
    private final int EXTERNAL_BUFFER_SIZE = 524288;

    public AePlayWave(String wavfile) {
        filename = wavfile;
    }

    public void run() {
        File soundFile = new File(filename);
        AudioInputStream audioInputStream = null;
        try {
            audioInputStream = AudioSystem.getAudioInputStream(soundFile);
        } catch (UnsupportedAudioFileException e1) {
            e1.printStackTrace();
            return;
        } catch (IOException e1) {
            e1.printStackTrace();
            return;
        }

        AudioFormat format = audioInputStream.getFormat();
        SourceDataLine auline = null;
        DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);

        try {
            auline = (SourceDataLine) AudioSystem.getLine(info);
            auline.open(format);
        } catch (LineUnavailableException e) {
            e.printStackTrace();
            return;
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }

        auline.start();
        int nBytesRead = 0;
        byte[] abData = new byte[EXTERNAL_BUFFER_SIZE];

        try {
            while (nBytesRead != -1) {
                nBytesRead = audioInputStream.read(abData, 0, abData.length);
                if (nBytesRead >= 0)
                    auline.write(abData, 0, nBytesRead);
            }
        } catch (IOException e) {
            e.printStackTrace();
            return;
        } finally {
            auline.drain();
            auline.close();
        }
    }
}



///////////////////////////////////////
class Music {
    String name="Rin.wav";
    File f = new File(name);
    URL url;
    URI uri;
    AudioClip clip;
    void setMusic(String name)
    {
        this.name=name;
    }
    Music()
    {
        try
        {
            uri=f.toURI();
            url = uri.toURL();
            clip = Applet.newAudioClip(url);
            //clip.play();
        }
        catch (MalformedURLException e)
        {
            e.printStackTrace();
            System.out.println("error!");
        }
    }
    void stopMusic()
    {
        clip.stop();
    }
    void playMusic()
    {
        clip.play();
    }
    void loopMusic()
    {
        clip.loop();
    }
}
class TFframe
{
    Music Rin;
    JFrame mf;
    JTextField Text;
    JButton jb,jbt;
    int x,y;
    boolean nya;
    boolean nyaa;
    TFframe()
    {
        nya=false;
        nyaa=false;
        Rin=new Music();
        mf=new JFrame();
        mf.setLayout(null);
        Text=new JTextField();
        mf.setTitle("DNFCNF");
        mf.setSize(600,400);
        mf.setResizable(false);
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        x=(int)(toolkit.getScreenSize().getWidth()-mf.getWidth())/2;
        y=(int)(toolkit.getScreenSize().getHeight()-mf.getHeight())/2;
        mf.setLocation(x, y);
        Text.setBounds(50,100,500,50);
        mf.setVisible(true);
        mf.setBackground(new Color(200,200,200));
        mf.add(Text);
        jb=new JButton("confirm");
        jb.setBounds(250,200,100,50);
        jb.setVisible(true);
        mf.add(jb);
        mf.addWindowListener(new WindowAdapter()
        {
            public void windowClosing(WindowEvent e)
            {
                super.windowClosing(e);
                System.exit(0);
            }
        });
        jb.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                if(DNFCNF.T.getrpn())
                {
                    if(nyaa)
                        Rin.playMusic();
                    DNFCNF.T.printTF();
                    DNFCNF.T.printDNF();
                    DNFCNF.T.printCNF();
                }
                else
                {
                    Text.setText("Illegal Expression");
                    Text.selectAll();
                }
            }
        });
        Text.addKeyListener(new KeyAdapter()
        {
            public void keyPressed(KeyEvent e)
            {
                if(e.getKeyChar()==KeyEvent.VK_ENTER )
                {
                    if(DNFCNF.T.getrpn())
                    {
                        if(nyaa)
                            Rin.playMusic();
                        DNFCNF.T.printTF();
                        DNFCNF.T.printDNF();
                        DNFCNF.T.printCNF();
                    }
                    else
                    {
                        Text.setText("Illegal Expression");
                        Text.selectAll();
                    }
                }
            }
        });
        // Text.setBackground(new Color(50,200,50));
        // jb.setBackground(new Color(200,50,50));
        //nyanyanay!!
        jbt=new JButton("nyanyanya!!");
        jbt.setBounds(250,270,100,50);
        jbt.setVisible(false);
        mf.add(jbt);
        jbt.addActionListener(
                new ActionListener()
                {
                    public void actionPerformed(ActionEvent e)
                    {
                        if(!nya)
                        {
                            nya=true;
                            Rin.loopMusic();
                        }
                        else
                        {
                            nya=false;
                            Rin.stopMusic();
                        }
                    }
                });
        //icon
        ImageIcon imageIcon = new ImageIcon(getClass().getResource("icon.png"));
        mf.setIconImage(imageIcon.getImage());
    }
}
class Answer
{
    JFrame mf;
    JScrollPane sp;
    JTextArea Text;
    Answer()
    {
        mf=new JFrame();
        Text=new JTextArea();
        sp=new JScrollPane(Text);
        Text.setLineWrap(true);
        sp.setVisible(true);
        mf.setSize(600,400);
        mf.setVisible(true);
        mf.add(sp);
        sp.setVerticalScrollBarPolicy( JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        sp.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
        // Text.setBackground(new Color(50,50,200));
        ImageIcon imageIcon = new ImageIcon(getClass().getResource("icon.png"));
        mf.setIconImage(imageIcon.getImage());
    }
}
class set
{
    int num;
    char []Element=new char[100];
    set()
    {
        num=0;
        Element[0]='0';
    }
    void clear()
    {
        num=0;
    }
    int find(char a)
    {
        int l=1,r=num,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(Element[mid]<=a)
                l=mid+1;
            else
                r=mid-1;
        }
        return l-1;
    }
    void insert(char a)
    {
        int l=find(a)+1;
        if(Element[l-1]==a)
            return;
        for(int i=num;i>=l;i--)
            Element[i+1]=Element[i];
        Element[l]=a;
        num++;
    }
}
class stackChar
{
    int n;
    char []Element=new char[10000];
    stackChar()
    {
        n=0;
    }
    void push(char a)
    {
        n++;
        Element[n]=a;
    }
    void pop()
    {
        if(n>0)
            n--;
    }
    char top()
    {
        return Element[n];
    }
    void clear()
    {
        n=0;
    }
}
class stackBool
{
    int n;
    boolean []Element=new boolean[10000];
    stackBool()
    {
        n=0;
    }
    void push(Boolean a)
    {
        n++;
        Element[n]=a;
    }
    void pop()
    {
        if(n>0)
            n--;
    }
    boolean top()
    {
        return Element[n];
    }
    void clear()
    {
        n=0;
    }
}
class symbol
{
    public static boolean cal(boolean a,char c,boolean b)
    {
        if(c=='&')
            return a&b;
        if(c=='|')
            return a|b;
        if(c=='>')
            return (!a)|b;
        if(c=='<')
            return a|(!b);
        if(c=='^')
            return a^b;
        if(c=='=')
            return ((!a)|b)&(a|(!b));
        return false;
    }
}
class judge
{
    int num;
    judge()
    {
        num=0;
    }
    boolean jud(char a,char b,char c)
    {
        if(b=='&'||b=='|'||b=='^'||b=='<'||b=='>')
        {
            if(a=='('||a=='!'||c==')')
                return false;
            else
                return true;
        }
        else if((b>='A'&&b<='Z')||(b>='a'&&b<='z'))
        {
            if(a==')'||c=='!'||c=='('||(a>='A'&&a<='Z')||(a>='a'&&a<='z')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'))
                return false;
            else
                return true;
        }
        else if(b=='('||b==')')
        {
            if(b=='(')
                num++;
            else
                num--;
            if(num>=0)
                return true;
            else
                return false;
        }
        else
            return false;
    }
}
class TFtabAndDNFCNF
{
    String rpn_;
    char []rpn=new char[10000];
    boolean []TF=new boolean[100];
    set P;
    TFframe f;
    boolean nya;
    TFtabAndDNFCNF()
    {
        f=new TFframe();
        P=new set();
        nya=false;
    }
    boolean getrpn()
    {
        rpn_="";
        boolean flag=false;
        judge J=new judge();
        Scanner cin=new Scanner(System.in);
        flag=true;
        rpn_=f.Text.getText();//cin.next();
        if(rpn_.equals("Snake"))
            SnakeDemo.SNAKE();
        else if(rpn_.equals("nya"))
        {
            if(nya==false)
            {
                nya=true;
                f.jbt.setVisible(true);
                f.nyaa=true;
            }
            else
            {
                nya=false;
                f.jbt.setVisible(false);
                f.nyaa=false;
            }
        }
        rpn_="("+rpn_+")";
        for(int i=0;i<rpn_.length();i++)
            rpn[i]=rpn_.charAt(i);
        for(int i=1;i<rpn_.length()-1;i++)
            flag=J.jud(rpn[i-1],rpn[i],rpn[i+1]);
        P.clear();
        for(int i=0;i<rpn_.length();i++)
            if((rpn[i]>='A'&&rpn[i]<='Z')||(rpn[i]>='a'&&rpn[i]<='z'))
                P.insert(rpn[i]);
        if(P.num==0||J.num>0)
            flag=false;
        cin.close();
        return flag;
    }
    void clear()
    {
        for(int i=0;i<100;i++)
            TF[i]=false;
    }
    void Next()
    {
        int i=P.num;
        while(TF[i]==true)
        {
            TF[i]=false;
            i--;
        }
        TF[i]=true;
    }
    boolean RPN()
    {
        stackChar C=new stackChar();
        stackBool B=new stackBool();
        for(int i=rpn_.length()-1;i>=0;i--)
        {
            if((rpn[i]>='A'&&rpn[i]<='Z')||(rpn[i]>='a'&&rpn[i]<='z'))
            {
                int temp=P.find(rpn[i]);
                //                System.out.println(P.Element[1]+" "+temp+" "+P.num);
                if(C.n>0&&C.top()!='!')
                    B.push(TF[temp]);
                else
                {
                    B.push(!TF[temp]);
                    C.pop();
                }
            }
            else if(rpn[i]!='(')
                C.push(rpn[i]);
            else
            {
                while(C.top()!=')')
                {
                    char c=C.top();
                    C.pop();
                    boolean a=B.top();
                    B.pop();
                    boolean b=B.top();
                    B.pop();
                    if(C.top()!='!')
                        B.push(symbol.cal(b,c,a));
                    else
                    {
                        B.push(!(symbol.cal(b,c,a)));
                        C.pop();
                    }
                }
                C.pop();
                if(C.top()=='!')
                {
                    boolean a=B.top();
                    B.pop();
                    C.pop();
                    B.push(!a);
                }
            }
        }
        return B.top();
    }
    void printTF()
    {
        Answer ans=new Answer();
        ans.mf.setLocation(f.x-50,f.y-50);
        ans.mf.setTitle("TFtab");
        ans.Text.setLineWrap(false);
        String answer="";
        clear();
        for(int i=1;i<=P.num;i++)
        {
            char temp=P.Element[i];
            answer+=String.valueOf(temp)+"\t";
        }
        answer+=rpn_+"\n";
        int k=(int)Math.pow((int)2,P.num);
        for(int i=0;i<k;i++)
        {
            for(int j=1;j<=P.num;j++)
                answer+=TF[j]?"T\t":"F\t";
            //            System.out.println("debug3");
            answer+=RPN()?"T\n":"F\n";
            Next();
        }
        //            System.out.println("debug4");
        ans.Text.setText(answer);
    }
    void printDNF()
    {
        Answer ans=new Answer();
        ans.mf.setLocation(f.x,f.y);
        ans.mf.setTitle("DNF");
        String answer="";
        clear();
        boolean flag=false;
        int k=(int)Math.pow((int)2,P.num);
        for(int i=0;i<k;i++)
        {
            if(RPN())
            {
                if(flag)
                    answer+="|";
                answer+="(";
                for(int j=1;j<=P.num;j++)
                {
                    if(TF[j])
                        answer+=String.valueOf(P.Element[j]);
                    else
                        answer+="!"+String.valueOf(P.Element[j]);
                    if(j!=P.num)
                        answer+="&";
                }
                answer+=")";
                flag=true;
            }
            Next();
        }                                    //            System.out.println("debug4");
        ans.Text.setText(answer);
    }
    void printCNF()
    {
        Answer ans=new Answer();
        ans.mf.setLocation(f.x+50,f.y+50);
        ans.mf.setTitle("CNF");
        String answer="";
        clear();
        boolean flag=false;
        int k=(int)Math.pow((int)2,P.num);
        for(int i=0;i<k;i++)
        {
            if(!RPN())
            {
                if(flag)
                    answer+="&";
                answer+="(";
                for(int j=1;j<=P.num;j++)
                {
                    if(!TF[j])
                        answer+=String.valueOf(P.Element[j]);
                    else
                        answer+="!"+String.valueOf(P.Element[j]);
                    if(j!=P.num)
                        answer+="|";
                }
                answer+=")";
                flag=true;
            }
            Next();
        }
        ans.Text.setText(answer);
    }
}
public class DNFCNF
{
    static TFtabAndDNFCNF T=new TFtabAndDNFCNF();
    public static void main(String args[])
    {

    }
}

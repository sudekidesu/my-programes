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

class Music {
    String name = "Rin.wav";
    File f = new File(name);
    URL url;
    URI uri;
    AudioClip clip;

    void setMusic(String name) {
        this.name = name;
    }

    Music() {
        try {
            uri = f.toURI();
            url = uri.toURL();
            clip = Applet.newAudioClip(url);
            // clip.play();
        } catch (MalformedURLException e) {
            e.printStackTrace();
            System.out.println("error!");
        }
    }

    void stopMusic() {
        clip.stop();
    }

    void playMusic() {
        clip.play();
    }

    void loopMusic() {
        clip.loop();
    }
}

class TFframe {
    Music Rin;
    JFrame mf;
    JTextField Text;
    JButton jb, jbt;
    int x, y;

    TFframe() {
        Rin = new Music();
        mf = new JFrame();
        mf.setLayout(null);
        Text = new JTextField();
        mf.setTitle("DNFCNF");
        mf.setSize(600, 400);
        mf.setResizable(false);
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        x = (int) (toolkit.getScreenSize().getWidth() - mf.getWidth()) / 2;
        y = (int) (toolkit.getScreenSize().getHeight() - mf.getHeight()) / 2;
        mf.setLocation(x, y);
        Text.setBounds(50, 100, 500, 50);
        mf.setVisible(true);
        mf.setBackground(new Color(200, 200, 200));
        mf.add(Text);
        jb = new JButton("confirm");
        jb.setBounds(250, 200, 100, 50);
        jb.setVisible(true);
        mf.add(jb);
        mf.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });
        jb.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                if (exp1.T.getrpn()) {
                    Rin.playMusic();
                    exp1.T.printTF();
                    exp1.T.printDNF();
                    exp1.T.printCNF();
                } else {
                    Text.setText("Illegal Expression");
                    Text.selectAll();
                }
            }
        });
        Text.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if (e.getKeyChar() == KeyEvent.VK_ENTER) {
                    if (exp1.T.getrpn()) {
                        Rin.playMusic();
                        exp1.T.printTF();
                        exp1.T.printDNF();
                        exp1.T.printCNF();
                    } else {
                        Text.setText("Illegal Expression");
                        Text.selectAll();
                    }
                }
            }
        });
        // icon
        ImageIcon imageIcon = new ImageIcon(getClass().getResource("icon.png"));
        mf.setIconImage(imageIcon.getImage());
    }
}

class Answer {
    JFrame mf;
    JScrollPane sp;
    JTextArea Text;

    Answer() {
        mf = new JFrame();
        Text = new JTextArea();
        sp = new JScrollPane(Text);
        Text.setLineWrap(true);
        sp.setVisible(true);
        mf.setSize(600, 400);
        mf.setVisible(true);
        mf.add(sp);
        sp.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        sp.setHorizontalScrollBarPolicy(ScrollPaneConstants.HORIZONTAL_SCROLLBAR_ALWAYS);
        // Text.setBackground(new Color(50,50,200));
        ImageIcon imageIcon = new ImageIcon(getClass().getResource("icon.png"));
        mf.setIconImage(imageIcon.getImage());
    }
}

class set {
    int num;
    char[] Element = new char[100];

    set() {
        num = 0;
        Element[0] = '0';
    }

    void clear() {
        num = 0;
    }

    int find(char a) {
        int l = 1, r = num, mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (Element[mid] <= a)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return l - 1;
    }

    void insert(char a) {
        int l = find(a) + 1;
        if (Element[l - 1] == a)
            return;
        for (int i = num; i >= l; i--)
            Element[i + 1] = Element[i];
        Element[l] = a;
        num++;
    }
}

class stackChar {
    int n;
    char[] Element = new char[10000];

    stackChar() {
        n = 0;
    }

    void push(char a) {
        n++;
        Element[n] = a;
    }

    void pop() {
        if (n > 0)
            n--;
    }

    char top() {
        return Element[n];
    }

    void clear() {
        n = 0;
    }
}

class stackBool {
    int n;
    boolean[] Element = new boolean[10000];

    stackBool() {
        n = 0;
    }

    void push(Boolean a) {
        n++;
        Element[n] = a;
    }

    void pop() {
        if (n > 0)
            n--;
    }

    boolean top() {
        return Element[n];
    }

    void clear() {
        n = 0;
    }
}

class symbol {
    public static boolean cal(boolean a, char c, boolean b) {
        if (c == '&')
            return a & b;
        if (c == '|')
            return a | b;
        if (c == '>')
            return (!a) | b;
        if (c == '<')
            return a | (!b);
        if (c == '^')
            return a ^ b;
        if (c == '=')
            return ((!a) | b) & (a | (!b));
        return false;
    }
}

class judge {
    int num;

    judge() {
        num = 0;
    }

    boolean jud(char a, char b, char c) {
        if (b == '&' || b == '|' || b == '^' || b == '<' || b == '>') {
            if (a == '(' || a == '!' || c == ')')
                return false;
            else
                return true;
        } else if ((b >= 'A' && b <= 'Z') || (b >= 'a' && b <= 'z')) {
            if (a == ')' || c == '!' || c == '(' || (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z')
                    || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
                return false;
            else
                return true;
        } else if (b == '(' || b == ')') {
            if (b == '(')
                num++;
            else
                num--;
            if (num >= 0)
                return true;
            else
                return false;
        } else
            return false;
    }
}

class TFtabAndDNFCNF {
    String rpn_;
    char[] rpn = new char[10000];
    boolean[] TF = new boolean[100];
    set P;
    TFframe f;

    TFtabAndDNFCNF() {
        f = new TFframe();
        P = new set();
    }

    boolean getrpn() {
        rpn_ = "";
        boolean flag = false;
        judge J = new judge();
        Scanner cin = new Scanner(System.in);
        flag = true;
        rpn_ = f.Text.getText();// cin.next();
        rpn_ = "(" + rpn_ + ")";
        for (int i = 0; i < rpn_.length(); i++)
            rpn[i] = rpn_.charAt(i);
        for (int i = 1; i < rpn_.length() - 1; i++)
            flag = J.jud(rpn[i - 1], rpn[i], rpn[i + 1]);
        P.clear();
        for (int i = 0; i < rpn_.length(); i++)
            if ((rpn[i] >= 'A' && rpn[i] <= 'Z') || (rpn[i] >= 'a' && rpn[i] <= 'z'))
                P.insert(rpn[i]);
        if (P.num == 0 || J.num > 0)
            flag = false;
        cin.close();
        return flag;
    }

    void clear() {
        for (int i = 0; i < 100; i++)
            TF[i] = false;
    }

    void Next() {
        int i = P.num;
        while (TF[i] == true) {
            TF[i] = false;
            i--;
        }
        TF[i] = true;
    }

    boolean RPN() {
        stackChar C = new stackChar();
        stackBool B = new stackBool();
        for (int i = rpn_.length() - 1; i >= 0; i--) {
            if ((rpn[i] >= 'A' && rpn[i] <= 'Z') || (rpn[i] >= 'a' && rpn[i] <= 'z')) {
                int temp = P.find(rpn[i]);
                // System.out.println(P.Element[1]+" "+temp+" "+P.num);
                if (C.n > 0 && C.top() != '!')
                    B.push(TF[temp]);
                else {
                    B.push(!TF[temp]);
                    C.pop();
                }
            } else if (rpn[i] != '(')
                C.push(rpn[i]);
            else {
                while (C.top() != ')') {
                    char c = C.top();
                    C.pop();
                    boolean a = B.top();
                    B.pop();
                    boolean b = B.top();
                    B.pop();
                    if (C.top() != '!')
                        B.push(symbol.cal(b, c, a));
                    else {
                        B.push(!(symbol.cal(b, c, a)));
                        C.pop();
                    }
                }
                C.pop();
                if (C.top() == '!') {
                    boolean a = B.top();
                    B.pop();
                    C.pop();
                    B.push(!a);
                }
            }
        }
        return B.top();
    }

    void printTF() {
        Answer ans = new Answer();
        ans.mf.setLocation(f.x - 50, f.y - 50);
        ans.mf.setTitle("TFtab");
        ans.Text.setLineWrap(false);
        String answer = "";
        clear();
        for (int i = 1; i <= P.num; i++) {
            char temp = P.Element[i];
            answer += String.valueOf(temp) + "\t";
        }
        answer += rpn_ + "\n";
        int k = (int) Math.pow((int) 2, P.num);
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= P.num; j++)
                answer += TF[j] ? "T\t" : "F\t";
            // System.out.println("debug3");
            answer += RPN() ? "T\n" : "F\n";
            Next();
        }
        // System.out.println("debug4");
        ans.Text.setText(answer);
    }

    void printDNF() {
        Answer ans = new Answer();
        ans.mf.setLocation(f.x, f.y);
        ans.mf.setTitle("DNF");
        String answer = "";
        clear();
        boolean flag = false;
        int k = (int) Math.pow((int) 2, P.num);
        for (int i = 0; i < k; i++) {
            if (RPN()) {
                if (flag)
                    answer += "|";
                answer += "(";
                for (int j = 1; j <= P.num; j++) {
                    if (TF[j])
                        answer += String.valueOf(P.Element[j]);
                    else
                        answer += "!" + String.valueOf(P.Element[j]);
                    if (j != P.num)
                        answer += "&";
                }
                answer += ")";
                flag = true;
            }
            Next();
        } // System.out.println("debug4");
        ans.Text.setText(answer);
    }

    void printCNF() {
        Answer ans = new Answer();
        ans.mf.setLocation(f.x + 50, f.y + 50);
        ans.mf.setTitle("CNF");
        String answer = "";
        clear();
        boolean flag = false;
        int k = (int) Math.pow((int) 2, P.num);
        for (int i = 0; i < k; i++) {
            if (!RPN()) {
                if (flag)
                    answer += "&";
                answer += "(";
                for (int j = 1; j <= P.num; j++) {
                    if (!TF[j])
                        answer += String.valueOf(P.Element[j]);
                    else
                        answer += "!" + String.valueOf(P.Element[j]);
                    if (j != P.num)
                        answer += "|";
                }
                answer += ")";
                flag = true;
            }
            Next();
        }
        ans.Text.setText(answer);
    }
}

public class exp1 {
    static TFtabAndDNFCNF T=new TFtabAndDNFCNF();

    public static void main(String args[]) {
    }
}

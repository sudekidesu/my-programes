import java.*;
import java.util.*;
abstract class People {
    String pName;
    String pSex;
    Calendar pBirth=Calendar.getInstance();
    /**
     * @param pName the pName to set
     */
    public void setpName(String pName) {
    	this.pName = pName;
    }
    /**
     * @param pSex the pSex to set
     */
    public void setpSex(String pSex) {
    	this.pSex = pSex;
    }
    /**
     * @param pBirth the pBirth to set
     */
    public void setpBirth(int y,int m,int d) {
    	this.pBirth.set(y,m,d);
    }
    /**
     *@return the pname
     */
    public String getpName() {
        return pName;
    }
    /**
     *@return the psex
     */
    public String getpSex() {
        return pSex;
    }
    /**
     *@return the pBirth

     */
    public Calendar getpBirth() {
        return pBirth;
    }
    public abstract String toDescstring();
}
class Student extends People{
    String sNo;
    String sMajor;
    /**
     *@param sNo the sNo to setpSet
     */
    public void setsNo(String sNo) {
        this.sNo=sNo;
    }
    /**
     *@param sMajor the sMajor to setsNo
     */
    public void setsMajor(String sMajor) {
        this.sMajor=sMajor;
    }
    /**
     *@return the sNo
     */
    public String getsNo() {
        return sNo;
    }
    /**
     *@return the setsMajor
     */
    public String getsMajor() {
        return sMajor;
    }
    public String toDescstring() {
        return "学号："+sNo+"\n"+"姓名："+pName+"\n"+"性别："+pSex+"\n"+"年龄："+String.valueOf(2018-pBirth.get(Calendar.YEAR))+"\n"+"专业："+sMajor+"\n";
    }
}
class Employee extends People{
    String sNo;
    int sSalary;
    /**
     *@param sNo the sNo to setpSet
     */
    public void setsNo(String sNo) {
        this.sNo=sNo;
    }
    /**
     *@param sSalary the sSalary to setsSalary
     */
    public void setsSalary(int sSalary) {
        this.sSalary=sSalary;
    }
    /**
     *@return the sNo
     */
    public String getsNo() {
        return sNo;
    }
    /**
     *@return the setsSalary
     */
    public int getsSalary() {
        return sSalary;
    }
    public String toDescstring() {
        return "工号："+sNo+"\n"+"姓名："+pName+"\n"+"性别："+pSex+"\n"+"年龄："+String.valueOf(2018-pBirth.get(Calendar.YEAR))+"\n"+"薪水："+String.valueOf(sSalary)+"\n";
    }
}
class Ex2 {
    public static void main(String[] args) {
        Student p1=new Student();
        p1.setsNo("B17010101");
        p1.setpName("张三");
        p1.setpSex("男");
        p1.setpBirth(1999,9,9);
        p1.setsMajor("软件工程");
        Employee p2=new Employee();
        p2.setsNo("J07010101");
        p2.setpName("李四");
        p2.setpSex("女");
        p2.setpBirth(1979,8,9);
        p2.setsSalary(2980);
        System.out.print(p1.toDescstring());
        System.out.print(p2.toDescstring());
    }
}

import java.*;
class MyRectangle {
    int Width,Length;
    /**
     * @param width the width to set
     */
    public void setWidth(int width) {
    	this.Width = width;
    }
    /**
     * @param length the length to set
     */
    public void setLength(int length) {
    	this.Length = length;
    }
    /**
     * @return the width
     */
    public int getWidth() {
    	return Width;
    }
    /**
     * @return the length
     */
    public int getLength() {
    	return Length;
    }
    /**
     * @return the Area
     */
    public int getArea() {
        return Width*Length;
    }
    @Override
    public String toString() {
        return "Width:"+String.valueOf(Width)+"\n"+"Length:"+String.valueOf(Length)+"\n";
    }
}
class MyCuboid extends MyRectangle {
    int Height;
    /**
     * @param height the height to set
     */
    public void setHeight(int height) {
    	this.Height = height;
    }
    /**
     * @return the height
     */
    public int getHeight() {
    	return Height;
    }
    /**
     * @return the Volumn
     */
    public int getVolumn() {
        return Width*Length*Height;
    }
    /**
     * @return the Area
     */
    public int getArea() {
        return Width*Length*2+Width*Height*2+Length*Height*2;
    }
    @Override
    public String toString() {
        return super.toString()+"Height:"+String.valueOf(Height)+"\n";
    }
}
class Ex1 {
    public static void main(String args[]) {
        MyCuboid a=new MyCuboid();
        a.setWidth(1);
        a.setLength(2);
        a.setHeight(3);
        System.out.print(a.toString());
    }
}

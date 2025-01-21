package lap;

public class InheritancePoint2D {
    
}
class Point2D{
    private float x;
    private float y;
    public Point2D(){}
    public Point2D(float x, float y){
        this.x = x;
        this.y = y;
    }
    public float getX() {
        return x;
    }
    public void setX(float x) {
        this.x = x;
    }
    public float getY() {
        return y;
    }
    public void setY(float y) {
        this.y = y;
    }
    public void setXY(float x, float y){
        this.x=x;
        this.y=y;
    }
    public float[] getXY(){
        float[] XY = new float[2];
        XY[0]=this.x;
        XY[1]=this.y;
        return XY;
    }
    @Override
    public String toString()
    {
        return "Point 2D: \n X:"+this.x+",/n Y:"+this.y+"\n";
    }
}
class Point3D extends Point2D{
    private float z;
    public Point3D(){
        super();
        this.z=0;
    }
    public Point3D(float x, float y, float z){
        super(x,y);
        this.z = z;
    }
    public float getZ() {
        return z;
    }
    public void setZ(float z) {
        this.z = z;
    }
    public void setXYZ(float x, float y, float z){
        super.setXY(x, y);
        this.z = z;
    }
    public float[] getXYZ(){
        float[] result = new float[3];
        result[0] = super.getX();
        result[1] = super.getY();
        result[2] = this.z;
        return result;
    }
    @Override
    public String toString()
    {
        return "Poin 3D: {"+super.toString()+"Z:"+this.z+"\n";
    }
}

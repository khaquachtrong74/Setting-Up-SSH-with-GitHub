package lap;

public class PhanSo {
    private int tuSo;
    private int mauSo;

    public PhanSo(int tuSo, int mauSo) {
        this.tuSo = tuSo;
        this.mauSo = mauSo;
    }

    public PhanSo(int tuSo) {
        this(tuSo, 1);
    }

    public PhanSo() {
        this(0, 1);
    }

    public int getTuSo() {
        return tuSo;
    }

    public void setTuSo(int tuSo) {
        this.tuSo = tuSo;
    }

    public int getMauSo() {
        return mauSo;
    }

    public void setMauSo(int mauSo) {
        this.mauSo = mauSo;
    }
     public PhanSo cong(PhanSo other) {
        int tu = this.tuSo * other.mauSo + other.tuSo * this.mauSo;
        int mau = this.mauSo * other.mauSo;
        return new PhanSo(tu, mau);
    }
    public static int ucln(int a, int b){
        a = Math.abs(a);
        b = Math.abs(b);
        while(a != b){
            if(a > b) a-=b;
            else if(a < b) b-=a;
            else return a;
        }
        return 1;
    }
    public void rutGon(){
        int t = ucln(tuSo, mauSo);
        tuSo /= t;
        mauSo /= t;
    }
    public int soSanh(PhanSo A){
        int val1 = this.tuSo/this.mauSo;
        int val2 = A.tuSo/A.mauSo;
        if(val1 > val2) return 1;
        else if(val1 < val2 ) return -1;
        else return 0;
    }
    @Override
    public String toString(){
        return tuSo + "/" + mauSo;
    }
}

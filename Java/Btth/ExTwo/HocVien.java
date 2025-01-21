package Btth.ExTwo;

import java.sql.Date;

public class HocVien {
    private static int dem;
    private int maSoHocVien;
    private String hoTen;
    private Date date;
    private String queQuan;
    private double toan;
    private double nguVan;
    private double anhVan;
    private String ngaySinhStr;
    

    public HocVien(String hoTen, Date d, String queQuan) {
        this.maSoHocVien = dem;
        dem++;
        this.hoTen = hoTen;
        this.date = d;
        this.queQuan = queQuan;
    }
    
    public HocVien(String hoTen, String ngaySinh, String queQuan) {
        this.maSoHocVien = dem;
        dem++;
        this.hoTen = hoTen;
        this.ngaySinhStr = ngaySinh;
        this.queQuan = queQuan;
    }

    public HocVien(String hoTen,String ngaySinhStr, String queQuan, double toan, double nguVan, double anhVan) {
        this.hoTen = hoTen;
        this.queQuan = queQuan;
        this.toan = toan;
        this.nguVan = nguVan;
        this.anhVan = anhVan;
        this.ngaySinhStr = ngaySinhStr;
    }

    public static int getDem() {
        return dem;
    }



    public int getMaSoHocVien() {
        return maSoHocVien;
    }



    public String getHoTen() {
        return hoTen;
    }



    public Date getDate() {
        return date;
    }



    public String getQueQuan() {
        return queQuan;
    }
    @Override
    public String toString(){
        return String.format("Họ tên :%s|Quê quán: %s", hoTen, queQuan);
    }



    public void setToan(double toan) {
        this.toan = toan;
    }



    public void setNguVan(double nguVan) {
        this.nguVan = nguVan;
    }



    public void setAnhVan(double anhVan) {
        this.anhVan = anhVan;
    }



    public double getToan() {
        return toan;
    }



    public double getNguVan() {
        return nguVan;
    }



    public double getAnhVan() {
        return anhVan;
    }

}

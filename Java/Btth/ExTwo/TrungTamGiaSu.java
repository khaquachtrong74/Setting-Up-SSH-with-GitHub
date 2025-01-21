package Btth.ExTwo;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;

public class TrungTamGiaSu {
    private ArrayList<HocVien> dsHocVien;

    public TrungTamGiaSu(ArrayList<HocVien> dsHocVien) {
        this.dsHocVien = dsHocVien;
    }

    public TrungTamGiaSu() {
        this.dsHocVien = new ArrayList<>();
    }

    public void ThemHocVien(HocVien A) {
        dsHocVien.add(A);
        System.out.println("Đã thêm học viên thành công!");
    }

    public void hienThiHocVien() {
        if (dsHocVien.isEmpty()) {
            System.out.println("Danh sách rỗng nhé !");
        } else {
            System.out.println("Danh sách học viên gồm: ");
            for (HocVien hocVien : dsHocVien) {
                System.out.println(hocVien.toString());
            }
        }
    }

    public HocVien TimKiemHocVien(int maSo) {
        for (HocVien hocVien : dsHocVien) {
            if (hocVien.getMaSoHocVien() == maSo)
                return hocVien;
        }
        return null;
    }

    public HocVien TimKiemHocVien(String hoTen) {
        for (HocVien hocVien : dsHocVien) {
            if (hocVien.getHoTen() == hoTen) {
                return hocVien;
            }
        }
        return null;
    }

    public void nhapDiem(double toan, double van, double anh, int maSo) {
        HocVien tmp = TimKiemHocVien(maSo);
        if (tmp != null) {
            tmp.setToan(toan);
            tmp.setAnhVan(anh);
            tmp.setNguVan(van);
            System.out.println("Đã thêm điểm thành công!");
            return;
        }
        System.out.println("Không tìm thấy sinh viên để nhập điểm!");
    }

    // nếu tổng 3 môn cao hơn 26 điểm thì sẽ được học bổng
    public boolean isHocBong(HocVien A) {
        double sum = A.getAnhVan() + A.getNguVan() + A.getToan();
        return (sum >= 26 ? true : false);
    }

    public void capNhapDSHocBong(String fileName) {
        try (FileWriter writer = new FileWriter(fileName)) {
            ArrayList<HocVien> dSHocBong = new ArrayList<>();
            for (HocVien hocVien : dsHocVien) {
                if (isHocBong(hocVien)) {
                    dSHocBong.add(hocVien);
                }
            }
            writer.write("Danh sách học viên nhận học bổng:\n");
            writer.write("================================:\n");
            for (HocVien hocVien : dsHocVien) {
                writer.write(String.format("%d-%s-%d", hocVien.getMaSoHocVien(), hocVien.getHoTen(),
                        (hocVien.getAnhVan() + hocVien.getToan() + hocVien.getNguVan()) / 3));
            }
        } catch (IOException e) {
            System.out.println("Lỗi khi ghi file: " + e);
        }
    }

    public void nhapDanhSachHocVienTuFile(String fileName) throws FileNotFoundException {
        Scanner scanner = new Scanner(new File(fileName));
        SimpleDateFormat f = new SimpleDateFormat("dd/MM/yyyy");
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            String[] fields = line.split(",");
            if (fields.length == 6) {
                try {
                    String hoTen = fields[0].trim();
                    String queQuan = fields[1].trim();
                    String ngaySinhStr = fields[2].trim();
                    double anhVan = Double.parseDouble(fields[3].trim());
                    double nguVan = Double.parseDouble(fields[4].trim());
                    double toan = Double.parseDouble(fields[5].trim());

                    // Tạo đối tượng HocVien và thêm vào danh sách
                    HocVien hocVien = new HocVien(hoTen, ngaySinhStr, queQuan, toan, nguVan, anhVan);
                    dsHocVien.add(hocVien);

                } catch (Exception e) {
                    System.out.println("Lỗi khi đọc dòng: " + line);
                }
            }    
        }
        scanner.close();
    }

}
